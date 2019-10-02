#include "otchi_ebml/tags/ebml/ebml_version.h"

using namespace otchi::ebml;

std::string EbmlVersion::get_name() const
{
	return "EbmlVersion";
}

ebml_id EbmlVersion::get_id() const 
{
	return ebml_version_id;
}

EbmlPath EbmlVersion::get_path() const
{
	return EbmlPath{ "1*1(\\EBML\\EBMLVersion)" };
}

std::string EbmlVersion::get_description() const
{
	return "The version of EBML specifications used to create the EBML Document. The version of EBML defined in this document is 1, so EBMLVersion SHOULD be 1.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> EbmlVersionFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new EbmlVersion(id_size, data_size, data_content_size, position, parent));
};
