//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_UTF8_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_UTF8_H

#include <cassert>

#include "ebml_element.h"

namespace otchi::ebml
{
	template <>
	class EbmlElement<EbmlType::Utf8> : public AbstractEbmlElement
	{
		std::unique_ptr<std::string> value_;

	public:

		using AbstractEbmlElement::AbstractEbmlElement;

		[[nodiscard]] EbmlType get_type() const override final;

		void decode(std::ifstream& ifstream) override;

		[[nodiscard]] std::string get_value() const;

		void print() const override;
	};
}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_UTF8_H
