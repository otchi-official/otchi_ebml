#include "otchi_ebml/elements/ebml_element_binary.h"

#include <iterator>
#include <fstream>
#include <cassert>

using namespace otchi::ebml;

EbmlType EbmlElement<EbmlType::Binary>::get_type() const
{
	return EbmlType::Binary;
}

void EbmlElement<EbmlType::Binary>::decode(std::ifstream& ifstream)
{
	const auto buffer = new char[get_content_size()];
	ifstream.read(buffer, get_content_size());
	const std::vector<char> vector{buffer, buffer + get_content_size()};

	*value_ = vector;
}

const std::vector<char>& EbmlElement<EbmlType::Binary>::get_value() const
{
	assert(value_ != nullptr && "Trying to get value of binary before it was decoded");
	return *value_;
}

void EbmlElement<EbmlType::Binary>::print() const
{
	std::cout << get_name() << ": <BINARY>";
}
