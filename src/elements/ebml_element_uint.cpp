#include "otchi_ebml/elements/ebml_element_uint.h"

#include <cassert>
#include <fstream>

using namespace otchi::ebml;

EbmlType EbmlElement<EbmlType::UnsignedInteger>::get_type() const
{
	return EbmlType::UnsignedInteger;
}

void EbmlElement<EbmlType::UnsignedInteger>::decode(std::ifstream& ifstream)
{
	if (get_content_size() > 8 || get_content_size() < 1)
		throw std::range_error("Length is out of range");

	const auto length = get_content_size();

	const auto buffer = new unsigned char[length];
	ifstream.read(reinterpret_cast<char*>(buffer), length);
	auto value{0};
	for (unsigned int i = 0; i < length; i++)
	{
		value += buffer[i] << 8u * (length - i - 1);
	}
	*value_ = value;
}

unsigned EbmlElement<EbmlType::UnsignedInteger>::get_value() const
{
	assert(value_ != nullptr && "Trying to get value of object before it was decoded");
	return *value_;
}

void EbmlElement<EbmlType::UnsignedInteger>::print() const
{
	std::cout << get_name() << std::dec << " [" << get_position() << ", "
		<< get_element_size() << "]" << ": " << get_value();
}
