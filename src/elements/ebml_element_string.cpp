#include "otchi_ebml/elements/ebml_element_string.h"

#include <fstream>
#include <cassert>

using namespace otchi::ebml;

EbmlType EbmlElement<EbmlType::String>::get_type() const
{
	return EbmlType::String;
}

void EbmlElement<EbmlType::String>::decode(std::ifstream& ifstream)
{
	const auto buffer = new char[get_content_size()];
	ifstream.read(buffer, get_content_size());
	buffer[get_content_size()] = '\0';
	const std::string s{buffer};
	*value_ = s;
}

std::string EbmlElement<3>::get_value() const
{
	assert(value_ != nullptr && "Value accessed without being initialized");
	return *value_;
}

void EbmlElement<3>::print() const
{
	std::cout << get_name() << std::dec << " [" << get_position() << ", "
		<< get_element_size() << "]" << ": " << get_value();
}
