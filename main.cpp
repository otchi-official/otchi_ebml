#include "otchi_ebml/ebml_parser.h"
#include <chrono>


int main() {
    auto now = std::chrono::system_clock::now();

    using namespace otchi_ebml;
    auto parser = EBMLParser("test1.mkv");
    auto elements = parser.parse();

    auto end = std::chrono::system_clock::now();
    auto difference = std::chrono::duration_cast<std::chrono::milliseconds>(end - now).count();
    std::cout << difference << std::endl;

    for (auto element : elements) {
        element->print();
    }

    return 0;
}