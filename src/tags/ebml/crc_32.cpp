#include "otchi_ebml/tags/ebml/crc_32.h"

using namespace otchi::ebml;

std::string Crc32::get_name() const
{
	return "CRC-32";
}

ebml_id Crc32::get_id() const 
{
	return crc_32_id;
}

EbmlPath Crc32::get_path() const
{
	return EbmlPath{ "*1((1*\\)\\CRC-32)" };
}

std::string Crc32::get_description() const
{
	return "The CRC-32 Element contains a 32-bit Cyclic Redundancy Check value of all the Element Data of the Parent Element as stored except for the CRC-32 Element itself. When the CRC-32 Element is present, the CRC-32 Element MUST be the first ordered EBML Element within its Parent Element for easier reading. All Top-Level Elements of an EBML Document that are Master Elements SHOULD include a CRC-32 Element as a Child Element. The CRC in use is the IEEE-CRC-32 algorithm as used in the [@!ISO.3309.1979] standard and in section 8.1.1.6.2 of [@!ITU.V42.1994], with initial value of 0xFFFFFFFF. The CRC value MUST be computed on a little endian bitstream and MUST use little endian storage.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> Crc32Factory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new Crc32(id_size, data_size, data_content_size, position, parent));
};
