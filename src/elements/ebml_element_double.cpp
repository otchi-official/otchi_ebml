#include "otchi_ebml/elements/ebml_element_double.h"

#include <cassert>
#include <fstream>

using namespace otchi::ebml;

EbmlType EbmlElement<EbmlType::Double>::get_type() const
{
	return EbmlType::Double;
}

void EbmlElement<EbmlType::Double>::decode(std::ifstream& ifstream)
{
	double d;
	ifstream.read(reinterpret_cast<char*>(&d), get_content_size());
	*value_ = d;
}

double EbmlElement<EbmlType::Double>::get_value() const
{
	assert(value_ != nullptr && "Value has not been initialized");
	return *value_;
}

void EbmlElement<EbmlType::Double>::print() const
{
	std::cout << get_name() << std::dec << " [" << get_position() << ", "
		<< get_element_size() << "]" << ": " << get_value();
}
