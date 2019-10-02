#include "otchi_ebml/tags/ebml/doc_type_extension.h"

using namespace otchi::ebml;

std::string DocTypeExtension::get_name() const
{
	return "DocTypeExtension";
}

ebml_id DocTypeExtension::get_id() const 
{
	return doc_type_extension_id;
}

EbmlPath DocTypeExtension::get_path() const
{
	return EbmlPath{ "0*(\\EBML\\DocTypeExtension)" };
}

std::string DocTypeExtension::get_description() const
{
	return "A DocTypeExtension adds extra Elements to the main DocType+DocTypeVersion tuple it's attached to. An EBML Reader MAY know these extra Elements and how to use them. A DocTypeExtension MAY be used to iterate between experimental Elements before they are integrated in a regular DocTypeVersion. Reading one DocTypeExtension version of a DocType+DocTypeVersion tuple doesn't imply one should be able to read upper versions of this DocTypeExtension.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> DocTypeExtensionFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new DocTypeExtension(id_size, data_size, data_content_size, position, parent));
};
