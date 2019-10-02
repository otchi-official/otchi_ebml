#include "otchi_ebml/tags/ebml/doc_type.h"

using namespace otchi::ebml;

std::string DocType::get_name() const
{
	return "DocType";
}

ebml_id DocType::get_id() const 
{
	return doc_type_id;
}

EbmlPath DocType::get_path() const
{
	return EbmlPath{ "1*1(\\EBML\\DocType)" };
}

std::string DocType::get_description() const
{
	return "A string that describes and identifies the content of the EBML Body that follows this EBML Header.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> DocTypeFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new DocType(id_size, data_size, data_content_size, position, parent));
};
