//
// Created by jorge on 9/15/2019.
//

#include "otchi_ebml/tags/ebml/ebml_tags.h"
#include "otchi_ebml/tags/ebml/ebml_head.h"
#include "otchi_ebml/tags/ebml/doc_type.h"
#include "otchi_ebml/tags/ebml/ebml_version.h"
#include "otchi_ebml/tags/ebml/ebml_read_version.h"
#include "otchi_ebml/tags/ebml/ebml_max_id_length.h"
#include "otchi_ebml/tags/ebml/ebml_max_size_length.h"
#include "otchi_ebml/tags/ebml/doc_type_version.h"
#include "otchi_ebml/tags/ebml/doc_type_extension.h"
#include "otchi_ebml/tags/ebml/doc_type_extension_name.h"
#include "otchi_ebml/tags/ebml/doc_type_extension_version.h"
#include "otchi_ebml/tags/ebml/crc_32.h"
#include "otchi_ebml/tags/ebml/doc_type_read_version.h"
#include "otchi_ebml/tags/ebml/void_element.h"

using namespace otchi::ebml;

std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>> EbmlTags::get_ebml_head_tags() {
	static std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>> tags{
			{EbmlHead::ebml_head_id, std::make_shared<IEbmlElementFactory>(EbmlHeadFactory())},
			{EbmlVersion::ebml_version_id, std::make_shared<IEbmlElementFactory>(EbmlVersionFactory())},
			{EbmlReadVersion::ebml_read_version_id, std::make_shared<IEbmlElementFactory>(EbmlReadVersionFactory())},
			{EbmlMaxIdLength::ebml_max_id_length_id, std::make_shared<IEbmlElementFactory>(EbmlMaxIdLengthFactory())},
			{EbmlMaxSizeLength::ebml_max_size_length_id, std::make_shared<IEbmlElementFactory>(EbmlMaxSizeLengthFactory())},
			{DocType::doc_type_id, std::make_shared<IEbmlElementFactory>(DocTypeFactory())},
			{DocTypeVersion::doc_type_version_id, std::make_shared<IEbmlElementFactory>(DocTypeVersionFactory())},
			{DocTypeReadVersion::doc_type_read_version_id, std::make_shared<IEbmlElementFactory>(DocTypeReadVersionFactory())},
			{DocTypeExtension::doc_type_extension_id, std::make_shared<IEbmlElementFactory>(DocTypeExtensionFactory())},
			{DocTypeExtensionName::doc_type_extension_name_id, std::make_shared<IEbmlElementFactory>(DocTypeExtensionNameFactory())},
			{DocTypeExtensionVersion::doc_type_extension_version_id, std::make_shared<IEbmlElementFactory>(DocTypeExtensionVersionFactory())}
	};
	return tags;
}

std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>> EbmlTags::get_global_tags()
{
	static std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>> tags{
			{Crc32::crc_32_id, std::make_shared<IEbmlElementFactory>(Crc32Factory())},
			{VoidElement::void_element_id, std::make_shared<IEbmlElementFactory>(VoidElementFactory())}
	};

	return tags;
}

std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>> otchi::ebml::operator+(
	std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>>& t1,
	std::unordered_map<ebml_id, std::shared_ptr<IEbmlElementFactory>>& t2)
{
	t1.insert(t2.begin(), t2.end());
	return t1;
}
