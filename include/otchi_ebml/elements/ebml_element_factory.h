//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_FACTORY_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_FACTORY_H

#include "ebml_element.h"
#include "otchi_ebml/types/ebml_alias.h"

namespace otchi::ebml {

    class IEbmlElementFactory {
    public:

		IEbmlElementFactory();

		virtual ~IEbmlElementFactory() = default;
		IEbmlElementFactory(const IEbmlElementFactory&) = delete;
		IEbmlElementFactory& operator =(IEbmlElementFactory const&) = delete;
		IEbmlElementFactory(IEbmlElementFactory&&) = delete;
		IEbmlElementFactory& operator=(IEbmlElementFactory&&) = delete;
    	
	    virtual std::shared_ptr<AbstractEbmlElement> create(
                ebml_size id_size,
                ebml_size data_size,
                ebml_size data_content_size,
                ebml_position position,
				std::weak_ptr<AbstractEbmlElement> parent = std::weak_ptr<AbstractEbmlElement>()) = 0;
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_FACTORY_H
