//
// Created by jorge on 9/15/2019.
//

#include "otchi_ebml/tags/ebml/ebml_tags.h"
#include "otchi_ebml/tags/ebml/ebml_head.h"
#include "otchi_ebml/tags/ebml/ebml_doc_type.h"
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

using namespace otchi_ebml;

std::unordered_map<EBMLId, IEBMLElementFactory *> EBMLTags::getEbmlHeadTags() {
    static std::unordered_map<EBMLId, IEBMLElementFactory *> tags{
            {EBMLHeadID, new EBMLHeadFactory()},
            {EBMLVersionId, new EBMLVersionFactory()},
            {EBMLReadVersionId, new EBMLReadVersionFactory()},
            {EBMLMaxIdLengthId, new EBMLMaxIdLengthFactory()},
            {EBMLMaxSizeLengthId, new EBMLMaxSizeLengthFactory()},
            {EBMLDocTypeId, new EBMLDocTypeFactory()},
            {DocTypeVersionId, new DocTypeVersionFactory()},
            {DocTypeExtensionId, new DocTypeExtensionFactory()},
            {DocTypeExtensionNameId, new DocTypeExtensionNameFactory()},
			{DocTypeExtensionVersionId, new DocTypeExtensionVersionFactory()},
			{CRC_32Id, new CRC_32Factory()},
			{DocTypeReadVersionId, new DocTypeReadVersionFactory()},
			};
    return tags;
}