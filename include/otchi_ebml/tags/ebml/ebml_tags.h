//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_TAGS_H
#define INCLUDE_OTCHI_EBML_EBML_TAGS_H

#include <unordered_map>

#include "otchi_ebml/elements/ebml_element_factory.h"


namespace otchi::ebml
{
	class EbmlTags
	{
	public:
		static std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>> get_ebml_head_tags();
		static std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>> get_global_tags();
	};

	std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>> operator+(
		std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>>& t1,
		std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>>& t2);
}

#endif //INCLUDE_OTCHI_EBML_EBML_TAGS_H
