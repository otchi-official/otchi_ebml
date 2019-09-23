#include "otchi_ebml/ebml_parser.h"
#include <chrono>


int main() {
    auto now = std::chrono::system_clock::now();
    using namespace otchi_ebml;
    auto parser = EBMLParser("test1.mkv");
    auto elements = parser.parse();
    auto maxOccurs = elements[0]->maxOccurs();
    if (maxOccurs) {
        std::cout << maxOccurs.value() << std::endl;
    }
    auto end = std::chrono::system_clock::now();
    auto difference = std::chrono::duration_cast<std::chrono::microseconds>(end - now).count();
    std::cout << difference << std::endl;
    for (auto element : elements) {
        element->print();
    }


    std::cout << dynamic_cast<EBMLElement<EBMLType::kMaster>*>(elements[1])->getChildren().size() << std::endl;
    return 0;
}