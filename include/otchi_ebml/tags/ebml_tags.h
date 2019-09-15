//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_TAGS_H
#define INCLUDE_OTCHI_EBML_EBML_TAGS_H
class ReferenceBlock : public EBMLElement<EBMLType::kSInt> {
public:
    using EBMLElement<EBMLType::kSInt>::EBMLElement;

    [[nodiscard]] std::string getName() const override {
        return "Reference Block";
    }

    [[nodiscard]] EBMLId getId() const override {
        return 0xFB;
    }

    [[nodiscard]] bool isMandatory() const override {
        return false;
    }

    [[nodiscard]] bool multipleAllowed() const override {
        return true;
    }

    [[nodiscard]] std::string getDescription() const override {
        return "Timestamp of another frame used as a reference (ie: B or P frame)."
               " The timestamp is relative to the block it's attached to.";
    }

};

class ReferenceBlocKFactory: public IEBMLElementFactory {
public:
    EBMLBaseElement *create(EBMLIdSize idSize, EBMLDataSize dataSize, EBMLContentSize dataContentSize) override {
        return new ReferenceBlock(idSize, dataSize, dataContentSize);
    }
};
#endif //INCLUDE_OTCHI_EBML_EBML_TAGS_H
