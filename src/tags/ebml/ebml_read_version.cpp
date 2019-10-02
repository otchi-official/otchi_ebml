#include "otchi_ebml/tags/ebml/ebml_read_version.h"

using namespace otchi::ebml;

std::string EbmlReadVersion::get_name() const
{
	return "EbmlReadVersion";
}

ebml_id EbmlReadVersion::get_id() const 
{
	return ebml_read_version_id;
}

EbmlPath EbmlReadVersion::get_path() const
{
	return EbmlPath{ "1*1(\\EBML\\EBMLReadVersion)" };
}

std::string EbmlReadVersion::get_description() const
{
	return "The minimum EBML version an EBML Reader has to support to read this EBML Document. The EBMLReadVersion Element MUST be less than or equal to EBMLVersion.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> EbmlReadVersionFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new EbmlReadVersion(id_size, data_size, data_content_size, position, parent));
};
