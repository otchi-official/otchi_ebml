#include "otchi_ebml/elements/ebml_element_utf8.h"

#include <cassert>
#include <fstream>

using namespace otchi::ebml;

EbmlType EbmlElement<EbmlType::Utf8>::get_type() const
{
	return EbmlType::Utf8;
}

void EbmlElement<EbmlType::Utf8>::decode(std::ifstream& ifstream)
{
	const auto buffer = new char[get_content_size()];
	ifstream.read(buffer, get_content_size());
	buffer[get_content_size()] = '\0';
	const std::string s{buffer};
	*value_ = s;
}

std::string EbmlElement<EbmlType::Utf8>::get_value() const
{
	assert(value_ != nullptr && "Trying to get value of object before it was decoded");
	return *value_;
}

void EbmlElement<EbmlType::Utf8>::print() const
{
	std::cout << get_name() << std::dec << " [" << get_position() << ", "
		<< get_element_size() << "]" << ": " << get_value();
}
