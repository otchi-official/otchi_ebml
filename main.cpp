#include <iostream>
#include <filesystem>
#include <fstream>
#include <utility>
#include <sstream>
#include <map>
#include <vector>
#include <exception>
#include <type_traits>
#include <chrono>

#include "otchi_ebml/ebml_value.h"


struct EbmlTag {
    int id;
    std::string name;
    otchi_ebml::EbmlType type;
};


class Ebml {
public:
    std::filesystem::path path_;
    std::ifstream fs_;
    std::streampos size_;
    std::map<int, std::tuple<std::string, otchi_ebml::EbmlType>> tags{
            {0x18538067, {"", otchi_ebml::EbmlType::kMaster}}
    };
    //std::vector<EbmlTag> tags{{0x18538067, "Segment", otchi_ebml::EbmlType::kMaster }};

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

    std::streamoff position() {
        return fs_.tellg();
    }

    int readId() {
        unsigned char initialBit;
        fs_.read(reinterpret_cast<char *>(&initialBit), 1);

        unsigned int size{0};
        if (initialBit & 0b10000000u) {
            size = 0;
        } else if (initialBit & 0b01000000u) {
            size = 1;
        } else if (initialBit & 0b00100000u) {
            size = 2;
        } else if (initialBit & 0b00010000u) {
            size = 3;
        } else {
            throw std::runtime_error("Invalid element ID");
        }

        int value{initialBit << 8u * size};
        auto* buffer = new unsigned char[size];
        fs_.read(reinterpret_cast<char *>(buffer), size);
        for (unsigned int i = 0; i < size; i++) {
            value += buffer[i] << 8u * (size - i - 1);
        }
        return value;
    }

    long long readSize() {
        unsigned char initialBit;
        fs_.read(reinterpret_cast<char *>(&initialBit), 1);

        long long value{0};
        unsigned int size{0};

        if (initialBit & 0b10000000u) {
            value += (initialBit & 0b01111111u);
        } else if (initialBit & 0b01000000u) {
            size = 1;
            value += (initialBit & 0b00111111u) << 8u * size;
        } else if (initialBit & 0b00100000u) {
            size = 2;
            value += (initialBit & 0b00011111u) << 8u * size;
        } else if (initialBit & 0b00010000u) {
            size = 3;
            value += (initialBit & 0b00001111u) << 8u * size;
        } else if (initialBit & 0b00001000u) {
            size = 4;
            value += (initialBit & 0b00000111u) << 8u * size;
        } else if (initialBit & 0b00000100u) {
            size = 5;
            value += (initialBit & 0b00000011u) << 8u * size;
        } else if (initialBit & 0b00000010u) {
            size = 6;
            value += (initialBit & 0b00000001u) << 8u * size;
        } else if (initialBit & 0b00000001u) {
            size = 7;
        } else {
            throw std::length_error("Undefined element size");
        }

        auto buffer = new unsigned char[size];
        fs_.read(reinterpret_cast<char*>(buffer), size);
        for (unsigned int i = 0; i < size; i++) {
            value += buffer[i] << 8u * (size - i - 1);
        }
        return value;
    }

    int readInteger(unsigned int length, bool isSigned) {
        if (length > 8 || length < 1)
            throw std::range_error("Length is out of range");

        auto buffer = new unsigned char[length];
        fs_.read(reinterpret_cast<char*>(buffer), length);
        int value{0};
        for (unsigned int i = 0; i < length; i ++) {
            value += buffer[i] << 8u * (length - i - 1);
        }
        if (isSigned) {
            unsigned int nbits = (8 - length) + 8 * (length - 1);
            if (value >= (1u << (nbits - 1))) {
                value -= static_cast<int>(1u << nbits);
            }
        }
        return value;
    }

    double readDouble(long long size) {
        double d;
        fs_.read(reinterpret_cast<char*>(&d), size);
        return d;
    }

    std::string readString(long long size) {
        auto buffer = new char[size];
        fs_.read(buffer, size);
        buffer[size] = '\0';
        std::string s{buffer};
        return s;
    }

    std::string readUnicode(long long size) {
        return readString(size);
    }

    std::vector<char> readBinary(long long size) {
        std::vector<char> vector;
        fs_.read(&vector[0], size);
        return vector;
    }

    std::chrono::time_point readDate(long long size) {
        auto clock = adaptec
    }



    otchi_ebml::EbmlMaster parse(std::streamoff from = 0, std::streamoff to = -1) {
        if (to < 0) {
            to = size();
        }

        // Set cursor to start
        fs_.seekg(from, std::ios_base::beg);
        otchi_ebml::EbmlMaster masterNode{};

        while (fs_.tellg() < to) {
            int id = -1;
            try {
                id = readId();
            } catch (std::runtime_error &error) {
                std::cerr << error.what() << std::endl;
                return masterNode;
            }
            long long size = readSize();
            if (size == 0b01111111) {
                std::cerr << "Don't know how to handle element with unknown size: " << size << std::endl;
                size = to - fs_.tellg();
            }
            std::tuple<std::string, otchi_ebml::EbmlType> tag;
            if (tags.count(id)) {
                tag = tags[id];
            } else {
                fs_.seekg(size);
            }

            otchi_ebml::EbmlValue *node;

            switch (std::get<1>(tag)) {
                case otchi_ebml::EbmlType::kSInt:
                    node = new otchi_ebml::EbmlInt{readInteger(size, true)};
                case otchi_ebml::EbmlType::kUInt:
                    node = new otchi_ebml::EbmlUnsignedInt{static_cast<unsigned int>(readInteger(size, false))};
                case otchi_ebml::EbmlType::kDouble:
                    node = new otchi_ebml::EbmlDouble{readDouble(size)};
                case otchi_ebml::EbmlType::kString:
                    node = new otchi_ebml::EbmlString{readString(size)};
                case otchi_ebml::EbmlType::kUTF8:
                    node = new otchi_ebml::EbmlUtf8{readUnicode(size)};
                case otchi_ebml::EbmlType::kBinary:
                    node = new otchi_ebml::EbmlBinary{readBinary(size)};
                case otchi_ebml::EbmlType::kMaster:
                    node = nullptr;
                case otchi_ebml::EbmlType::kDate:
                    node =
            }


        }

    }

};

int main() {
    std::cout << u8"ä" << std::endl;
    std::filesystem::path path = "test1.mkv";
    auto ebml = Ebml(path);
    ebml.fs_.seekg(8);
    std::cout << ebml.readUnicode(8) << std::endl;


    /*std::filesystem::path path = "test1.mkv";
    auto ebml = Ebml(path);
    while (ebml.fs_.tellg() < ebml.size()) {
        std::cout << ebml.readSize() << std::endl;
    }*/
    return 0;
}