#include "otchi_ebml/ebml_parser.h"


int main() {

    using namespace otchi;
    auto parser = EBMLParser("test1.mkv");
    auto elements = parser.parse();
    parser.close();

    for (auto element : elements) {
        element->print();
    }

    return 0;
}