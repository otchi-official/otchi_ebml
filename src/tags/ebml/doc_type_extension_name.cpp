#include "otchi_ebml/tags/ebml/doc_type_extension_name.h"

using namespace otchi::ebml;

std::string DocTypeExtensionName::get_name() const
{
	return "DocTypeExtensionName";
}

ebml_id DocTypeExtensionName::get_id() const
{
	return doc_type_extension_name_id;
}

EbmlPath DocTypeExtensionName::get_path() const
{
	return EbmlPath{ R"(1*1(\EBML\DocTypeExtension\Name))" };
}

std::string DocTypeExtensionName::get_description() const
{
	return "The name of the DocTypeExtension to differentiate it from other DocTypeExtension of the same DocType+DocTypeVersion tuple. A DocTypeExtensionName value MUST be unique within the EBML Header.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> DocTypeExtensionNameFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new DocTypeExtensionName(id_size, data_size, data_content_size, position, parent));
};
