#include "otchi_ebml/tags/ebml/ebml_max_id_length.h"

using namespace otchi::ebml;

std::string EbmlMaxIdLength::get_name() const
{
	return "EbmlMaxIdLength";
}

ebml_id EbmlMaxIdLength::get_id() const 
{
	return ebml_max_id_length_id;
}

EbmlPath EbmlMaxIdLength::get_path() const
{
	return EbmlPath{ "1*1(\\EBML\\EBMLMaxIDLength)" };
}

std::string EbmlMaxIdLength::get_description() const
{
	return "The EBMLMaxIDLength Element stores the maximum permitted length in octets of the Element IDs to be found within the EBML Body. An EBMLMaxIDLength Element value of four is RECOMMENDED, though larger values are allowed.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> EbmlMaxIdLengthFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new EbmlMaxIdLength(id_size, data_size, data_content_size, position, parent));
};
