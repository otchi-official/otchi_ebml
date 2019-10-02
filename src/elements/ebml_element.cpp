#include "otchi_ebml/elements/ebml_element.h"

#include <cassert>
#include <utility>

using namespace otchi::ebml;

AbstractEbmlElement::AbstractEbmlElement(const ebml_size id_size, const ebml_size data_size, const ebml_size data_content_size,
                                 const ebml_position position, std::weak_ptr<AbstractEbmlElement> parent)
	: id_size_{id_size}, data_size_{data_size}, content_size_{data_content_size}, position_{position},
	  parent_{std::move(parent)}
{
}

otchi::ebml_size AbstractEbmlElement::get_element_size() const
{
	return id_size_ + data_size_ + content_size_;
}

bool AbstractEbmlElement::validate_value() const
{
	return true;
}

std::optional<int> AbstractEbmlElement::min_occurs() const
{
	if (get_path().at(0) == '*')
		return std::nullopt;
	const auto n = std::stoi(get_path().substr(0, 1));
	return n;
}

std::optional<int> AbstractEbmlElement::max_occurs() const
{
	const auto asterisk_pos = get_path().at(0) == '*' ? 0 : 1;
	assert(get_path().at(asterisk_pos) == '*');

	try
	{
		const auto n = std::stoi(get_path().substr(asterisk_pos + 1, asterisk_pos + 1));
		return n;
	}
	catch (const std::exception&)
	{
		return std::nullopt;
	}
}

std::string AbstractEbmlElement::get_description() const
{
	return "";
}

std::weak_ptr<AbstractEbmlElement> AbstractEbmlElement::get_parent() const
{
	return parent_;
}

void AbstractEbmlElement::print() const
{
	std::cout << get_name() << "<" << get_type() << ">";
}

otchi::ebml_size AbstractEbmlElement::get_id_size() const
{
	return id_size_;
}

otchi::ebml_size AbstractEbmlElement::get_data_size() const
{
	return data_size_;
}

otchi::ebml_size AbstractEbmlElement::get_content_size() const
{
	return content_size_;
}

otchi::ebml_position AbstractEbmlElement::get_position() const
{
	return position_;
}
