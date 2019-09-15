#include "otchi_ebml/ebml_parser.h"


int main() {
    using namespace otchi_ebml;
    auto parser = EBMLParser("test1.mkv");
    auto elements = parser.parse();
    elements[0]->print();
    return 0;
}