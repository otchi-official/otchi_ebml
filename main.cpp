#include "otchi_ebml/ebml_parser.h"


int main() {
    using namespace otchi_ebml;
    auto parser = EBMLParser("test1.mkv");
    auto elements = parser.parse();
    auto maxOccurs = elements[0]->maxOccurs();
    if (maxOccurs) {
        std::cout << maxOccurs.value() << std::endl;
    }

    elements[0]->print();
    return 0;
}