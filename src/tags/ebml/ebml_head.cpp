#include "otchi_ebml/tags/ebml/ebml_head.h"

using namespace otchi::ebml;

std::string EbmlHead::get_name() const
{
	return "EBML";
}

ebml_id EbmlHead::get_id() const 
{
	return ebml_head_id;
}

EbmlPath EbmlHead::get_path() const
{
	return EbmlPath{ "1*1(\\EBML)" };
}

std::string EbmlHead::get_description() const
{
	return "Set the EBML characteristics of the data to follow. Each EBML Document has to start with this.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> EbmlHeadFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new EbmlHead(id_size, data_size, data_content_size, position, parent));
};
