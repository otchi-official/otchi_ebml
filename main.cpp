#include "otchi_ebml/ebml_parser.h"


int main() {
    using namespace otchi_ebml;
    auto parser = EBMLParser("test1.mkv");
    auto elements = parser.parse();
    auto maxOccurs = elements[0]->maxOccurs();
    if (maxOccurs) {
        std::cout << maxOccurs.value() << std::endl;
    }

    for (auto element : elements) {
        element->print();
    }


    std::cout << dynamic_cast<EBMLElement<EBMLType::kMaster>*>(elements[1])->getChildren().size() << std::endl;
    return 0;
}