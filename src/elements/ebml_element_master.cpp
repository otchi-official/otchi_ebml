#include "otchi_ebml/elements/ebml_element_master.h"

#include <iostream>

using namespace otchi::ebml;

EbmlType EbmlElement<EbmlType::Master>::get_type() const
{
	return EbmlType::Master;
}

std::vector<std::shared_ptr<AbstractEbmlElement>> EbmlElement<EbmlType::Master>::get_children() const
{
	return children_;
}

void EbmlElement<EbmlType::Master>::append(const std::shared_ptr<AbstractEbmlElement>& element)
{
	children_.push_back(element);
}

void EbmlElement<EbmlType::Master>::print(const int index) const
{
	for (auto i = 0; i < index; i++)
	{
		std::cout << "\t";
	}
	std::cout << std::dec << get_name() << " [" << get_position() << ", "
		<< get_element_size() << "]" << std::endl;
	for (const auto& child : children_)
	{
		if (child->get_type() == EbmlType::Master)
		{
			std::dynamic_pointer_cast<EbmlElement<EbmlType::Master>>(child)->print(index + 1);
		}
		else
		{
			for (auto i = 0; i < index + 1; i++)
			{
				std::cout << "\t";
			}
			child->print();
			std::cout << std::endl;
		}
	}
}

void EbmlElement<EbmlType::Master>::print() const
{
	print(0);
}
