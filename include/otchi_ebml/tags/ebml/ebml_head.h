///
/// Created by Jorge Paravicini on 2019-09-19
/// Copyright (c) 2019 Otchi Org. All Rights reserved
///

#ifndef INCLUDE_OTCHI_EBML_EBML_HEAD_H
#define INCLUDE_OTCHI_EBML_EBML_HEAD_H

#include "otchi_ebml/elements/ebml_element_master.h"
#include "otchi_ebml/types/ebml_path.h"
#include "otchi_ebml/elements/ebml_element_factory.h"
#include "ebml_tags.h"

namespace otchi::ebml {

	class EbmlHead final : public EbmlElement<EbmlType::Master> {
	public:
		using EbmlElement<EbmlType::Master>::EbmlElement;

		static constexpr ebml_id ebml_head_id = 0x1A45DFA3;

		[[nodiscard]] std::string get_name() const override;

		[[nodiscard]] ebml_id get_id() const override;

		[[nodiscard]] EbmlPath get_path() const override;

		[[nodiscard]] std::string get_description() const override;
	};

	class EbmlHeadFactory final : public IEbmlElementFactory {
	public:
		std::shared_ptr<AbstractEbmlElement> create(
			ebml_size id_size, ebml_size data_size,
			ebml_size data_content_size, ebml_position position,
			std::weak_ptr<AbstractEbmlElement> parent) override;
	};
}

#endif //INCLUDE_OTCHI_EBML_EBML_HEAD_H
