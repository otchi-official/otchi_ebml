#include "otchi_ebml/elements/ebml_type.h"

#include <ostream>

std::ostream& otchi::ebml::operator<<(std::ostream& os, const EbmlType& type)
{
	switch (type)
	{
	case EbmlType::SignedInteger:
		os << "Signed Integer";
		break;
	case EbmlType::UnsignedInteger:
		os << "Unsigned Integer";
		break;
	case EbmlType::Double:
		os << "Double";
		break;
	case EbmlType::String:
		os << "String";
		break;
	case EbmlType::Utf8:
		os << "UTF 8";
		break;
	case EbmlType::Date:
		os << "Date";
		break;
	case EbmlType::Master:
		os << "Master";
		break;
	case EbmlType::Binary:
		os << "Binary";
		break;
	}
	return os;
}
