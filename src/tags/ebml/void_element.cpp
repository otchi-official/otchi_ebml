#include "otchi_ebml/tags/ebml/void_element.h"

using namespace otchi::ebml;

std::string VoidElement::get_name() const
{
	return "Void";
}

ebml_id VoidElement::get_id() const 
{
	return void_element_id;
}

EbmlPath VoidElement::get_path() const
{
	return EbmlPath{ "*((*\\)\\Void)" };
}

std::string VoidElement::get_description() const
{
	return "Used to void data or to avoid unexpected behaviors when using damaged data. The content is discarded. Also used to reserve space in a sub-element for later use.";
}

// Factory

std::shared_ptr<AbstractEbmlElement> VoidElementFactory::create(
	const ebml_size id_size, const ebml_size data_size,
	const ebml_size data_content_size, const ebml_position position,
	const std::weak_ptr<AbstractEbmlElement> parent)
{
	return std::shared_ptr(new VoidElement(id_size, data_size, data_content_size, position, parent));
};
