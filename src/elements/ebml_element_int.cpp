#include "otchi_ebml/elements/ebml_element_int.h"

#include <cassert>
#include <fstream>

using namespace otchi::ebml;

EbmlType EbmlElement<EbmlType::SignedInteger>::get_type() const
{
	return EbmlType::SignedInteger;
}

void EbmlElement<EbmlType::SignedInteger>::decode(std::ifstream& ifstream)
{
	if (get_content_size() > 8 || get_content_size() < 1)
		throw std::range_error("Length is out of range");

	const auto buffer = new unsigned char[get_content_size()];
	ifstream.read(reinterpret_cast<char*>(buffer), get_content_size());
	auto value{ 0 };
	for (ebml_size i = 0; i < get_content_size(); i++)
	{
		value += buffer[i] << 8u * (get_content_size() - i - 1);
	}

	// Make signed
	const auto bits = 8 - get_content_size() + 8 * (get_content_size() - 1);
	if (static_cast<unsigned int>(value) >= (1u << (bits - 1)))
	{
		value -= static_cast<int>(1u << bits);
	}

	*value_ = value;
}

int EbmlElement<EbmlType::SignedInteger>::get_value() const
{
	assert(value_ != nullptr && "Get Value called before being initialized.");
	return *value_;
}

void EbmlElement<EbmlType::SignedInteger>::print() const
{
	std::cout << get_name() << std::dec << " [" << get_position() << ", "
		<< get_element_size() << "]" << ": " << get_value();
}

