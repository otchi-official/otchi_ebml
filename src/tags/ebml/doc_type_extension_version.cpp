#include "otchi_ebml/tags/ebml/doc_type_extension_version.h"

using namespace otchi::ebml;

std::string DocTypeExtensionVersion::get_name() const
{
	return "DocTypeExtensionVersion";
}

ebml_id DocTypeExtensionVersion::get_id() const
{
	return doc_type_extension_version_id;
}

EbmlPath DocTypeExtensionVersion::get_path() const
{
	return EbmlPath{ R"(1*1(\EBML\DocTypeExtension\Version))" };
}

std::string DocTypeExtensionVersion::get_description() const
{
	return "The version of the DocTypeExtension. Different DocTypeExtensionVersion values of the same DocType+DocTypeVersion+DocTypeExtensionName tuple MAY contain completely different sets of extra Elements. An EBML Reader MAY support multiple versions of the same DocTypeExtension, only one or none.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> DocTypeExtensionVersionFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new DocTypeExtensionVersion(id_size, data_size, data_content_size, position, parent));
};
