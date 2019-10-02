#include "otchi_ebml/tags/ebml/doc_type_version.h"

using namespace otchi::ebml;

std::string DocTypeVersion::get_name() const
{
	return "DocTypeVersion";
}

ebml_id DocTypeVersion::get_id() const 
{
	return doc_type_version_id;
}

EbmlPath DocTypeVersion::get_path() const
{
	return EbmlPath{ "1*1(\\EBML\\DocTypeVersion)" };
}

std::string DocTypeVersion::get_description() const
{
	return "The version of DocType interpreter used to create the EBML Document.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> DocTypeVersionFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new DocTypeVersion(id_size, data_size, data_content_size, position, parent));
};
