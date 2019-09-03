#include <iostream>
#include <filesystem>
#include <fstream>
#include <utility>
#include <sstream>
#include <map>
#include <vector>
#include <exception>
#include <type_traits>


class EbmlInt: EbmlValue {
    int n_;
public:

    explicit EbmlInt(int n): n_{n} {

    }

    EbmlType getType() override {
        return EbmlType::kSInt;
    }
};

template <class T>
class EbmlTag {
    static_assert(std::is_base_of<EbmlValue, T>::value, "T has to be of type: EbmlValue");
    T value_;

public:

    explicit EbmlTag(T value): value_{std::move(value)} {
    }

    virtual int getId() = 0;
    virtual std::string getName() = 0;


};

class InfoTag: public EbmlTag<EbmlInt> {
public:
    InfoTag(): EbmlTag(EbmlInt(1)) {

    }
};



class Ebml {
public:
    std::filesystem::path path_;
    std::basic_ifstream<unsigned char> fs_;
    std::streampos size_;

    explicit Ebml(std::filesystem::path path)
            : path_{std::move(path)} {
        open();
    }


    void open() {
        if (!fs_.is_open()) {
            fs_.open(path_, std::ios::binary | std::ios::ate);
            size_ = fs_.tellg();
            fs_.seekg(0, std::ios::beg);
        } else {
            std::cout << "File already open" << std::endl;
        }
    }

    void close() {
        if (fs_.is_open())
            fs_.close();
    }

    [[nodiscard]] std::streampos size() const {
        return size_;
    }

    int position() {
        return fs_.tellg();
    }

    int readId() {
        unsigned char initialBit;
        fs_.read(&initialBit, 1);
        std::stringstream ss;
        ss << std::hex << (int) initialBit;

        if (initialBit & 0b10000000u) {
            ss << initialBit;
        } else if (initialBit & 0b01000000u) {
            ss << getNextHex(1);
        } else if (initialBit & 0b00100000u) {
            ss << getNextHex(2);
        } else if (initialBit & 0b00010000u) {
            ss << getNextHex(3);
        } else {
            throw std::runtime_error("Invalid element ID");
        }

        int result = 0;
        ss >> std::hex >> result;
        return result;
    }

    long long readSize() {
        unsigned char initialBit;
        fs_.read(&initialBit, 1);
        std::stringstream ss;
        ss << std::hex;

        if (initialBit & 0b10000000u) {
            ss << (int) (initialBit & 0b01111111u);
        } else if (initialBit & 0b01000000u) {
            ss << (int) (initialBit & 0b01111111u);
            ss << getNextHex(1);
        } else if (initialBit & 0b00100000u) {
            ss << (int) (initialBit & 0b00111111u);
            ss << getNextHex(2);
        } else if (initialBit & 0b00010000u) {
            ss << (int) (initialBit & 0b00011111u);
            ss << getNextHex(3);
        } else if (initialBit & 0b00001000u) {
            ss << (int) (initialBit & 0b00001111u);
            ss << getNextHex(4);
        } else if (initialBit & 0b00000100u) {
            ss << (int) (initialBit & 0b00000111u);
            ss << getNextHex(5);
        } else if (initialBit & 0b00000010u) {
            ss << (int) (initialBit & 0b00000011u);
            ss << getNextHex(6);
        } else if (initialBit & 0b00000001u) {
            ss << (int) (initialBit & 0b00000001u);
            ss << getNextHex(7);
        } else {
            throw std::length_error("Undefined element size");
        }
        long long result = 0;
        ss >> std::hex >> result;
        return result;
    }

    int read_integer(int length, bool isSigned) {
        if (length > 8 || length < 1)
            throw std::range_error("Length is out of range");

        std::stringstream ss;
        ss << std::hex;
        ss << getNextHex(length);

        int value = 0;
        ss >> std::hex >> value;

        if (isSigned) {
            unsigned int nbits = (8 - length) + 8 * (length - 1);
            if (value >= (1u << (nbits - 1))) {
                value -= static_cast<int>(1u << nbits);
            }
        }
        return value;
    }

    std::string getNextHex(const int n) {
        auto *buffer = new unsigned char[n];
        fs_.read(buffer, n);
        std::stringstream ss;
        for (int i = 0; i < n; i++) {
            ss << std::hex << (int) buffer[i];
        }
        return ss.str();
    }

    std::map<EbmlType, std::vector<EbmlTag<EbmlType>>> parse(int from = 0, int to = -1) {
        if (to < 0) {
            to = size();
        }
        fs_.seekg(from, std::ios_base::beg);
        std::map<EbmlType, std::vector<EbmlTag<EbmlType >>> node{};

        while (fs_.tellg() < to) {
            int id = -1;
            try {
                id = readId();
            } catch (std::runtime_error &error) {
                std::cerr << error.what() << std::endl;
                return node;
            }
            long long size = readSize();
            if (size == 0b01111111) {
                std::cerr << "Don't know how to handle element with unknown size: " << size << std::endl;
                size = to - fs_.tellg();
            }


        }

    }

};

int main() {

    std::filesystem::path path = "test1.mkv";
    auto ebml = Ebml(path);
    while (ebml.fs_.tellg() < ebml.size()) {
        std::cout << ebml.readSize() << std::endl;
    }
    return 0;
}