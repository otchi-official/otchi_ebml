#include "otchi_ebml/elements/ebml_element_date.h"

#include <fstream>
#include <cassert>

using namespace otchi::ebml;

EbmlType EbmlElement<EbmlType::Date>::get_type() const
{
	return EbmlType::Date;
}

void EbmlElement<EbmlType::Date>::decode(std::ifstream& ifstream)
{
	using namespace std::chrono;

	const auto buffer = new unsigned char[get_content_size()];
	ifstream.read(reinterpret_cast<char *>(buffer), get_content_size());
	auto nano{0};
	for (ebml_size i = 0; i < get_content_size(); i++)
	{
		nano += buffer[i] << 8u * (get_content_size() - i - 1);
	}

	// TODO: Needs to be tested, pretty sure this is wrong.
	const auto n = duration_cast<system_clock::duration>(nanoseconds(nano));
	const auto epoch = duration_cast<system_clock::duration>(nanoseconds(978303600000000000));

	const auto t = duration_cast<seconds>(n + epoch);
	const auto g = system_clock::from_time_t(t.count());
	*value_ = g;
}

ebml_clock::time_point EbmlElement<EbmlType::Date>::get_value() const
{
	assert(value_ != nullptr && "Trying to get value of object before it was decoded");
	return *value_;
}
