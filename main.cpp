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
#include <ctime>
#include <stack>

#include "otchi_ebml/ebml_value.h"
#include <otchi_ebml/types/ebml_clock.h>

#include "otchi_ebml/ebml_parser.h"


/*struct EbmlTag {
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
            {0x1A45DFA3, {"EBML",                    otchi_ebml::EbmlType::kMaster}},
            {0x4286,     {"EBMLVersion",             otchi_ebml::EbmlType::kUInt}},
            {0x42F7,     {"EBMLReadVersion",         otchi_ebml::EbmlType::kUInt}},
            {0x42F2,     {"EBMLMaxIDLength",         otchi_ebml::EbmlType::kUInt}},
            {0x42F3,     {"EBMLMaxSizeLength",       otchi_ebml::EbmlType::kUInt}},
            {0x4282,     {"DocType",                 otchi_ebml::EbmlType::kString}},
            {0x4287,     {"DocTypeVersion",          otchi_ebml::EbmlType::kUInt}},
            {0x4285,     {"DocTypeReadVersion",      otchi_ebml::EbmlType::kUInt}},
            {0x4281,     {"DocTypeExtension",        otchi_ebml::EbmlType::kMaster}},
            {0x4283,     {"DocTypeExtensionName",    otchi_ebml::EbmlType::kString}},
            {0x4284,     {"DocTypeExtensionVersion", otchi_ebml::EbmlType::kUInt}},
            {}
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

    int readId(int *s = nullptr) {
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

        if (s)
            *s = static_cast<int>(size + 1);

        int value{initialBit << 8u * size};
        auto *buffer = new unsigned char[size];
        fs_.read(reinterpret_cast<char *>(buffer), size);
        for (unsigned int i = 0; i < size; i++) {
            value += buffer[i] << 8u * (size - i - 1);
        }
        return value;
    }

    long long readSize(int *s = nullptr) {
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

        if (s)
            *s = static_cast<int>(size + 1);

        auto buffer = new unsigned char[size];
        fs_.read(reinterpret_cast<char *>(buffer), size);
        for (unsigned int i = 0; i < size; i++) {
            value += buffer[i] << 8u * (size - i - 1);
        }
        return value;
    }

    int readInteger(unsigned int length, bool isSigned) {
        if (length > 8 || length < 1)
            throw std::range_error("Length is out of range");

        auto buffer = new unsigned char[length];
        fs_.read(reinterpret_cast<char *>(buffer), length);
        int value{0};
        for (unsigned int i = 0; i < length; i++) {
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
        fs_.read(reinterpret_cast<char *>(&d), size);
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

    std::chrono::system_clock::time_point readDate(long long size) {
        using namespace std::chrono;

        auto nano = readInteger(size, false);
        auto n = duration_cast<system_clock::duration>(nanoseconds(nano));
        auto epoch = duration_cast<system_clock::duration>(nanoseconds(978303600000000000));

        auto t = duration_cast<seconds>(n + epoch);
        auto g = system_clock::from_time_t(t.count());
        return g;
    }


    std::vector<otchi_ebml::EbmlMaster *> parse(std::streamoff from = 0, std::streamoff to = -1) {
        if (to < 0) {
            to = size();
        }

        // Set cursor to start
        fs_.seekg(from, std::ios_base::beg);

        std::vector<otchi_ebml::EbmlMaster *> masterNodes;
        std::stack<otchi_ebml::EbmlMaster *> roots{};

        while (fs_.tellg() < to) {
            std::cout << "Current pos " << fs_.tellg() << std::endl;
            auto node = parseNode(to);

            // Ignore nodes we don't want to capture.
            if (!node)
                continue;

            while (!roots.empty()) {
                auto top = roots.top();
                // Append the node to the current root if it didnt surpass the limit of the root node yet.
                if (node->getStart() < (top->getStart() + top->getSize())) {
                    top->append(node);
                    break;
                } else {
                    roots.pop();
                }
            }

            if (roots.empty()) {
                if (node->getType() != otchi_ebml::EbmlType::kMaster)
                    throw std::runtime_error("Invalid node. Can't get a non master node as a root node");
                masterNodes.push_back(dynamic_cast<otchi_ebml::EbmlMaster *>(node));
                roots.push(dynamic_cast<otchi_ebml::EbmlMaster *>(node));
                continue;
            }

        }
        return masterNodes;
    }

    otchi_ebml::EBMLElement *parseNode(std::streamoff to) {
        long long start = fs_.tellg();
        int id;
        long long totalSize{};
        try {
            int s;
            id = readId(&s);
            totalSize += s;
        } catch (std::runtime_error &error) {
            std::cerr << error.what() << std::endl;
            return nullptr;
        }
        int s;
        long long contentSize = readSize(&s);
        totalSize += s + contentSize;
        if (contentSize == 0b01111111) {
            std::cerr << "Don't know how to handle element with unknown contentSize: " << contentSize << std::endl;
            contentSize = to - fs_.tellg();
        }

        std::tuple<std::string, otchi_ebml::EbmlType> tag;
        if (tags.count(id)) {
            tag = tags[id];
        } else {
            fs_.seekg(contentSize + fs_.tellg());
            std::cout << "Skipping tag with id: " << std::hex << id << std::endl;
            return nullptr;
        }
        std::cout << "Found " << std::get<0>(tag) << " Tag" << std::endl;

        otchi_ebml::EBMLElement *node = nullptr;

        switch (std::get<1>(tag)) {
            case otchi_ebml::EbmlType::kSInt:
                return new otchi_ebml::EbmlInt{start, contentSize, totalSize, readInteger(contentSize, true)};
            case otchi_ebml::EbmlType::kUInt:
                return new otchi_ebml::EbmlUnsignedInt{start, contentSize, totalSize,
                                                       static_cast<unsigned int>(readInteger(contentSize,
                                                                                             false))};
            case otchi_ebml::EbmlType::kDouble:
                return new otchi_ebml::EbmlDouble{start, contentSize, totalSize, readDouble(contentSize)};
            case otchi_ebml::EbmlType::kString:
                return new otchi_ebml::EbmlString{start, contentSize, totalSize, readString(contentSize)};
            case otchi_ebml::EbmlType::kUTF8:
                return new otchi_ebml::EbmlUtf8{start, contentSize, totalSize, readUnicode(contentSize)};
            case otchi_ebml::EbmlType::kBinary:
                return new otchi_ebml::EbmlBinary{start, contentSize, totalSize, readBinary(contentSize)};
            case otchi_ebml::EbmlType::kDate:
                return new otchi_ebml::EbmlDate{start, contentSize, totalSize, readDate(contentSize)};
            case otchi_ebml::EbmlType::kMaster:
                return new otchi_ebml::EbmlMaster{start, contentSize, totalSize, {}};
        }
    }

};
*/
int main() {
    using namespace otchi_ebml;
    auto parser = EBMLParser("test1.mkv");
    auto element = dynamic_cast<EBMLHead*>(parser.parseNode());
    return 0;
}