#include "otchi_ebml/tags/ebml/ebml_max_size_length.h"

using namespace otchi::ebml;

std::string EbmlMaxSizeLength::get_name() const
{
	return "EbmlMaxSizeLength";
}

ebml_id EbmlMaxSizeLength::get_id() const 
{
	return ebml_max_size_length_id;
}

EbmlPath EbmlMaxSizeLength::get_path() const
{
	return EbmlPath{ "1*1(\\EBML\\EBMLMaxSizeLength)" };
}

std::string EbmlMaxSizeLength::get_description() const
{
	return "The EBMLMaxSizeLength Element stores the maximum permitted length in octets of the expressions of all Element Data Sizes to be found within the EBML Body. The EBMLMaxSizeLength Element documents an upper bound for the length of all Element Data Size expressions within the EBML Body and not an upper bound for the value of all Element Data Size expressions within the EBML Body. EBML Elements that have an Element Data Size expression which is larger in octets than what is expressed by EBMLMaxSizeLength Element are invalid.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> EbmlMaxSizeLengthFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new EbmlMaxSizeLength(id_size, data_size, data_content_size, position, parent));
};
