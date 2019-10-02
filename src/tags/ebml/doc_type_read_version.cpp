#include "otchi_ebml/tags/ebml/doc_type_read_version.h"

using namespace otchi::ebml;

std::string DocTypeReadVersion::get_name() const
{
	return "DocTypeReadVersion";
}

ebml_id DocTypeReadVersion::get_id() const 
{
	return doc_type_read_version_id;
}

EbmlPath DocTypeReadVersion::get_path() const
{
	return EbmlPath{ "1*1(\\EBML\\DocTypeReadVersion)" };
}

std::string DocTypeReadVersion::get_description() const
{
	return "The minimum DocType version an EBML Reader has to support to read this EBML Document. The value of the DocTypeReadVersion Element MUST be less than or equal to the value of the DocTypeVersion Element.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> DocTypeReadVersionFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new DocTypeReadVersion(id_size, data_size, data_content_size, position, parent));
};
