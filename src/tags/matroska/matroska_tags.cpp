//
// Created by paravicinij on 19.09.2019.
//

#include "otchi_ebml/tags/matroska/matroska_tags.h"
#include "otchi_ebml/tags/matroska/ebmlmaxidlength.h"
#include "otchi_ebml/tags/matroska/ebmlmaxsizelength.h"
#include "otchi_ebml/tags/matroska/segment.h"
#include "otchi_ebml/tags/matroska/seekhead.h"
#include "otchi_ebml/tags/matroska/seek.h"
#include "otchi_ebml/tags/matroska/seekid.h"
#include "otchi_ebml/tags/matroska/seekposition.h"
#include "otchi_ebml/tags/matroska/info.h"
#include "otchi_ebml/tags/matroska/segmentuid.h"
#include "otchi_ebml/tags/matroska/segmentfilename.h"
#include "otchi_ebml/tags/matroska/prevuid.h"
#include "otchi_ebml/tags/matroska/prevfilename.h"
#include "otchi_ebml/tags/matroska/nextuid.h"
#include "otchi_ebml/tags/matroska/nextfilename.h"
#include "otchi_ebml/tags/matroska/segmentfamily.h"
#include "otchi_ebml/tags/matroska/chaptertranslate.h"
#include "otchi_ebml/tags/matroska/chaptertranslateeditionuid.h"
#include "otchi_ebml/tags/matroska/chaptertranslatecodec.h"
#include "otchi_ebml/tags/matroska/chaptertranslateid.h"
#include "otchi_ebml/tags/matroska/timestampscale.h"
#include "otchi_ebml/tags/matroska/duration.h"
#include "otchi_ebml/tags/matroska/dateutc.h"
#include "otchi_ebml/tags/matroska/title.h"
#include "otchi_ebml/tags/matroska/muxingapp.h"
#include "otchi_ebml/tags/matroska/writingapp.h"
#include "otchi_ebml/tags/matroska/cluster.h"
#include "otchi_ebml/tags/matroska/timestamp.h"
#include "otchi_ebml/tags/matroska/silenttracks.h"
#include "otchi_ebml/tags/matroska/silenttracknumber.h"
#include "otchi_ebml/tags/matroska/position.h"
#include "otchi_ebml/tags/matroska/prevsize.h"
#include "otchi_ebml/tags/matroska/simpleblock.h"
#include "otchi_ebml/tags/matroska/blockgroup.h"
#include "otchi_ebml/tags/matroska/block.h"
#include "otchi_ebml/tags/matroska/blockvirtual.h"
#include "otchi_ebml/tags/matroska/blockadditions.h"
#include "otchi_ebml/tags/matroska/blockmore.h"
#include "otchi_ebml/tags/matroska/blockaddid.h"
#include "otchi_ebml/tags/matroska/blockadditional.h"
#include "otchi_ebml/tags/matroska/blockduration.h"
#include "otchi_ebml/tags/matroska/referencepriority.h"
#include "otchi_ebml/tags/matroska/referenceblock.h"
#include "otchi_ebml/tags/matroska/referencevirtual.h"
#include "otchi_ebml/tags/matroska/codecstate.h"
#include "otchi_ebml/tags/matroska/discardpadding.h"
#include "otchi_ebml/tags/matroska/slices.h"
#include "otchi_ebml/tags/matroska/timeslice.h"
#include "otchi_ebml/tags/matroska/lacenumber.h"
#include "otchi_ebml/tags/matroska/framenumber.h"
#include "otchi_ebml/tags/matroska/blockadditionid.h"
#include "otchi_ebml/tags/matroska/delay.h"
#include "otchi_ebml/tags/matroska/sliceduration.h"
#include "otchi_ebml/tags/matroska/referenceframe.h"
#include "otchi_ebml/tags/matroska/referenceoffset.h"
#include "otchi_ebml/tags/matroska/referencetimestamp.h"
#include "otchi_ebml/tags/matroska/encryptedblock.h"
#include "otchi_ebml/tags/matroska/tracks.h"
#include "otchi_ebml/tags/matroska/trackentry.h"
#include "otchi_ebml/tags/matroska/tracknumber.h"
#include "otchi_ebml/tags/matroska/trackuid.h"
#include "otchi_ebml/tags/matroska/tracktype.h"
#include "otchi_ebml/tags/matroska/flagenabled.h"
#include "otchi_ebml/tags/matroska/flagdefault.h"
#include "otchi_ebml/tags/matroska/flagforced.h"
#include "otchi_ebml/tags/matroska/flaglacing.h"
#include "otchi_ebml/tags/matroska/mincache.h"
#include "otchi_ebml/tags/matroska/maxcache.h"
#include "otchi_ebml/tags/matroska/defaultduration.h"
#include "otchi_ebml/tags/matroska/defaultdecodedfieldduration.h"
#include "otchi_ebml/tags/matroska/tracktimestampscale.h"
#include "otchi_ebml/tags/matroska/trackoffset.h"
#include "otchi_ebml/tags/matroska/maxblockadditionid.h"
#include "otchi_ebml/tags/matroska/name.h"
#include "otchi_ebml/tags/matroska/language.h"
#include "otchi_ebml/tags/matroska/languageietf.h"
#include "otchi_ebml/tags/matroska/codecid.h"
#include "otchi_ebml/tags/matroska/codecprivate.h"
#include "otchi_ebml/tags/matroska/codecname.h"
#include "otchi_ebml/tags/matroska/attachmentlink.h"
#include "otchi_ebml/tags/matroska/codecsettings.h"
#include "otchi_ebml/tags/matroska/codecinfourl.h"
#include "otchi_ebml/tags/matroska/codecdownloadurl.h"
#include "otchi_ebml/tags/matroska/codecdecodeall.h"
#include "otchi_ebml/tags/matroska/trackoverlay.h"
#include "otchi_ebml/tags/matroska/codecdelay.h"
#include "otchi_ebml/tags/matroska/seekpreroll.h"
#include "otchi_ebml/tags/matroska/tracktranslate.h"
#include "otchi_ebml/tags/matroska/tracktranslateeditionuid.h"
#include "otchi_ebml/tags/matroska/tracktranslatecodec.h"
#include "otchi_ebml/tags/matroska/tracktranslatetrackid.h"
#include "otchi_ebml/tags/matroska/video.h"
#include "otchi_ebml/tags/matroska/flaginterlaced.h"
#include "otchi_ebml/tags/matroska/fieldorder.h"
#include "otchi_ebml/tags/matroska/stereomode.h"
#include "otchi_ebml/tags/matroska/alphamode.h"
#include "otchi_ebml/tags/matroska/oldstereomode.h"
#include "otchi_ebml/tags/matroska/pixelwidth.h"
#include "otchi_ebml/tags/matroska/pixelheight.h"
#include "otchi_ebml/tags/matroska/pixelcropbottom.h"
#include "otchi_ebml/tags/matroska/pixelcroptop.h"
#include "otchi_ebml/tags/matroska/pixelcropleft.h"
#include "otchi_ebml/tags/matroska/pixelcropright.h"
#include "otchi_ebml/tags/matroska/displaywidth.h"
#include "otchi_ebml/tags/matroska/displayheight.h"
#include "otchi_ebml/tags/matroska/displayunit.h"
#include "otchi_ebml/tags/matroska/aspectratiotype.h"
#include "otchi_ebml/tags/matroska/colourspace.h"
#include "otchi_ebml/tags/matroska/gammavalue.h"
#include "otchi_ebml/tags/matroska/framerate.h"
#include "otchi_ebml/tags/matroska/colour.h"
#include "otchi_ebml/tags/matroska/matrixcoefficients.h"
#include "otchi_ebml/tags/matroska/bitsperchannel.h"
#include "otchi_ebml/tags/matroska/chromasubsamplinghorz.h"
#include "otchi_ebml/tags/matroska/chromasubsamplingvert.h"
#include "otchi_ebml/tags/matroska/cbsubsamplinghorz.h"
#include "otchi_ebml/tags/matroska/cbsubsamplingvert.h"
#include "otchi_ebml/tags/matroska/chromasitinghorz.h"
#include "otchi_ebml/tags/matroska/chromasitingvert.h"
#include "otchi_ebml/tags/matroska/range.h"
#include "otchi_ebml/tags/matroska/transfercharacteristics.h"
#include "otchi_ebml/tags/matroska/primaries.h"
#include "otchi_ebml/tags/matroska/maxcll.h"
#include "otchi_ebml/tags/matroska/maxfall.h"
#include "otchi_ebml/tags/matroska/masteringmetadata.h"
#include "otchi_ebml/tags/matroska/primaryrchromaticityx.h"
#include "otchi_ebml/tags/matroska/primaryrchromaticityy.h"
#include "otchi_ebml/tags/matroska/primarygchromaticityx.h"
#include "otchi_ebml/tags/matroska/primarygchromaticityy.h"
#include "otchi_ebml/tags/matroska/primarybchromaticityx.h"
#include "otchi_ebml/tags/matroska/primarybchromaticityy.h"
#include "otchi_ebml/tags/matroska/whitepointchromaticityx.h"
#include "otchi_ebml/tags/matroska/whitepointchromaticityy.h"
#include "otchi_ebml/tags/matroska/luminancemax.h"
#include "otchi_ebml/tags/matroska/luminancemin.h"
#include "otchi_ebml/tags/matroska/projection.h"
#include "otchi_ebml/tags/matroska/projectiontype.h"
#include "otchi_ebml/tags/matroska/projectionprivate.h"
#include "otchi_ebml/tags/matroska/projectionposeyaw.h"
#include "otchi_ebml/tags/matroska/projectionposepitch.h"
#include "otchi_ebml/tags/matroska/projectionposeroll.h"
#include "otchi_ebml/tags/matroska/audio.h"
#include "otchi_ebml/tags/matroska/samplingfrequency.h"
#include "otchi_ebml/tags/matroska/outputsamplingfrequency.h"
#include "otchi_ebml/tags/matroska/channels.h"
#include "otchi_ebml/tags/matroska/channelpositions.h"
#include "otchi_ebml/tags/matroska/bitdepth.h"
#include "otchi_ebml/tags/matroska/trackoperation.h"
#include "otchi_ebml/tags/matroska/trackcombineplanes.h"
#include "otchi_ebml/tags/matroska/trackplane.h"
#include "otchi_ebml/tags/matroska/trackplaneuid.h"
#include "otchi_ebml/tags/matroska/trackplanetype.h"
#include "otchi_ebml/tags/matroska/trackjoinblocks.h"
#include "otchi_ebml/tags/matroska/trackjoinuid.h"
#include "otchi_ebml/tags/matroska/tricktrackuid.h"
#include "otchi_ebml/tags/matroska/tricktracksegmentuid.h"
#include "otchi_ebml/tags/matroska/tricktrackflag.h"
#include "otchi_ebml/tags/matroska/trickmastertrackuid.h"
#include "otchi_ebml/tags/matroska/trickmastertracksegmentuid.h"
#include "otchi_ebml/tags/matroska/contentencodings.h"
#include "otchi_ebml/tags/matroska/contentencoding.h"
#include "otchi_ebml/tags/matroska/contentencodingorder.h"
#include "otchi_ebml/tags/matroska/contentencodingscope.h"
#include "otchi_ebml/tags/matroska/contentencodingtype.h"
#include "otchi_ebml/tags/matroska/contentcompression.h"
#include "otchi_ebml/tags/matroska/contentcompalgo.h"
#include "otchi_ebml/tags/matroska/contentcompsettings.h"
#include "otchi_ebml/tags/matroska/contentencryption.h"
#include "otchi_ebml/tags/matroska/contentencalgo.h"
#include "otchi_ebml/tags/matroska/contentenckeyid.h"
#include "otchi_ebml/tags/matroska/contentencaessettings.h"
#include "otchi_ebml/tags/matroska/aessettingsciphermode.h"
#include "otchi_ebml/tags/matroska/contentsignature.h"
#include "otchi_ebml/tags/matroska/contentsigkeyid.h"
#include "otchi_ebml/tags/matroska/contentsigalgo.h"
#include "otchi_ebml/tags/matroska/contentsighashalgo.h"
#include "otchi_ebml/tags/matroska/cues.h"
#include "otchi_ebml/tags/matroska/cuepoint.h"
#include "otchi_ebml/tags/matroska/cuetime.h"
#include "otchi_ebml/tags/matroska/cuetrackpositions.h"
#include "otchi_ebml/tags/matroska/cuetrack.h"
#include "otchi_ebml/tags/matroska/cueclusterposition.h"
#include "otchi_ebml/tags/matroska/cuerelativeposition.h"
#include "otchi_ebml/tags/matroska/cueduration.h"
#include "otchi_ebml/tags/matroska/cueblocknumber.h"
#include "otchi_ebml/tags/matroska/cuecodecstate.h"
#include "otchi_ebml/tags/matroska/cuereference.h"
#include "otchi_ebml/tags/matroska/cuereftime.h"
#include "otchi_ebml/tags/matroska/cuerefcluster.h"
#include "otchi_ebml/tags/matroska/cuerefnumber.h"
#include "otchi_ebml/tags/matroska/cuerefcodecstate.h"
#include "otchi_ebml/tags/matroska/attachments.h"
#include "otchi_ebml/tags/matroska/attachedfile.h"
#include "otchi_ebml/tags/matroska/filedescription.h"
#include "otchi_ebml/tags/matroska/filename.h"
#include "otchi_ebml/tags/matroska/filemimetype.h"
#include "otchi_ebml/tags/matroska/filedata.h"
#include "otchi_ebml/tags/matroska/fileuid.h"
#include "otchi_ebml/tags/matroska/filereferral.h"
#include "otchi_ebml/tags/matroska/fileusedstarttime.h"
#include "otchi_ebml/tags/matroska/fileusedendtime.h"
#include "otchi_ebml/tags/matroska/chapters.h"
#include "otchi_ebml/tags/matroska/editionentry.h"
#include "otchi_ebml/tags/matroska/editionuid.h"
#include "otchi_ebml/tags/matroska/editionflaghidden.h"
#include "otchi_ebml/tags/matroska/editionflagdefault.h"
#include "otchi_ebml/tags/matroska/editionflagordered.h"
#include "otchi_ebml/tags/matroska/chapteratom.h"
#include "otchi_ebml/tags/matroska/chapteruid.h"
#include "otchi_ebml/tags/matroska/chapterstringuid.h"
#include "otchi_ebml/tags/matroska/chaptertimestart.h"
#include "otchi_ebml/tags/matroska/chaptertimeend.h"
#include "otchi_ebml/tags/matroska/chapterflaghidden.h"
#include "otchi_ebml/tags/matroska/chapterflagenabled.h"
#include "otchi_ebml/tags/matroska/chaptersegmentuid.h"
#include "otchi_ebml/tags/matroska/chaptersegmenteditionuid.h"
#include "otchi_ebml/tags/matroska/chapterphysicalequiv.h"
#include "otchi_ebml/tags/matroska/chaptertrack.h"
#include "otchi_ebml/tags/matroska/chaptertrackuid.h"
#include "otchi_ebml/tags/matroska/chapterdisplay.h"
#include "otchi_ebml/tags/matroska/chapstring.h"
#include "otchi_ebml/tags/matroska/chaplanguage.h"
#include "otchi_ebml/tags/matroska/chaplanguageietf.h"
#include "otchi_ebml/tags/matroska/chapcountry.h"
#include "otchi_ebml/tags/matroska/chapprocess.h"
#include "otchi_ebml/tags/matroska/chapprocesscodecid.h"
#include "otchi_ebml/tags/matroska/chapprocessprivate.h"
#include "otchi_ebml/tags/matroska/chapprocesscommand.h"
#include "otchi_ebml/tags/matroska/chapprocesstime.h"
#include "otchi_ebml/tags/matroska/chapprocessdata.h"
#include "otchi_ebml/tags/matroska/tags.h"
#include "otchi_ebml/tags/matroska/tag.h"
#include "otchi_ebml/tags/matroska/targets.h"
#include "otchi_ebml/tags/matroska/targettypevalue.h"
#include "otchi_ebml/tags/matroska/targettype.h"
#include "otchi_ebml/tags/matroska/tagtrackuid.h"
#include "otchi_ebml/tags/matroska/tageditionuid.h"
#include "otchi_ebml/tags/matroska/tagchapteruid.h"
#include "otchi_ebml/tags/matroska/tagattachmentuid.h"
#include "otchi_ebml/tags/matroska/simpletag.h"
#include "otchi_ebml/tags/matroska/tagname.h"
#include "otchi_ebml/tags/matroska/taglanguage.h"
#include "otchi_ebml/tags/matroska/taglanguageietf.h"
#include "otchi_ebml/tags/matroska/tagdefault.h"
#include "otchi_ebml/tags/matroska/tagstring.h"
#include "otchi_ebml/tags/matroska/tagbinary.h"

using namespace otchi_ebml;

std::unordered_map<EBMLId, IEBMLElementFactory *> MatroskaTags::getMatroskaTags() {
    static std::unordered_map<EBMLId, IEBMLElementFactory *> tags
    {
			{EBMLMaxIDLengthId, new EBMLMaxIDLengthFactory()},
			{EBMLMaxSizeLengthId, new EBMLMaxSizeLengthFactory()},
			{SegmentId, new SegmentFactory()},
			{SeekHeadId, new SeekHeadFactory()},
			{SeekId, new SeekFactory()},
			{SeekIDId, new SeekIDFactory()},
			{SeekPositionId, new SeekPositionFactory()},
			{InfoId, new InfoFactory()},
			{SegmentUIDId, new SegmentUIDFactory()},
			{SegmentFilenameId, new SegmentFilenameFactory()},
			{PrevUIDId, new PrevUIDFactory()},
			{PrevFilenameId, new PrevFilenameFactory()},
			{NextUIDId, new NextUIDFactory()},
			{NextFilenameId, new NextFilenameFactory()},
			{SegmentFamilyId, new SegmentFamilyFactory()},
			{ChapterTranslateId, new ChapterTranslateFactory()},
			{ChapterTranslateEditionUIDId, new ChapterTranslateEditionUIDFactory()},
			{ChapterTranslateCodecId, new ChapterTranslateCodecFactory()},
			{ChapterTranslateIDId, new ChapterTranslateIDFactory()},
			{TimestampScaleId, new TimestampScaleFactory()},
			{DurationId, new DurationFactory()},
			{DateUTCId, new DateUTCFactory()},
			{TitleId, new TitleFactory()},
			{MuxingAppId, new MuxingAppFactory()},
			{WritingAppId, new WritingAppFactory()},
			{ClusterId, new ClusterFactory()},
			{TimestampId, new TimestampFactory()},
			{SilentTracksId, new SilentTracksFactory()},
			{SilentTrackNumberId, new SilentTrackNumberFactory()},
			{PositionId, new PositionFactory()},
			{PrevSizeId, new PrevSizeFactory()},
			//{SimpleBlockId, new SimpleBlockFactory()},
			{BlockGroupId, new BlockGroupFactory()},
			{BlockId, new BlockFactory()},
			{BlockVirtualId, new BlockVirtualFactory()},
			{BlockAdditionsId, new BlockAdditionsFactory()},
			{BlockMoreId, new BlockMoreFactory()},
			{BlockAddIDId, new BlockAddIDFactory()},
			{BlockAdditionalId, new BlockAdditionalFactory()},
			{BlockDurationId, new BlockDurationFactory()},
			{ReferencePriorityId, new ReferencePriorityFactory()},
			{ReferenceBlockId, new ReferenceBlockFactory()},
			{ReferenceVirtualId, new ReferenceVirtualFactory()},
			{CodecStateId, new CodecStateFactory()},
			{DiscardPaddingId, new DiscardPaddingFactory()},
			{SlicesId, new SlicesFactory()},
			{TimeSliceId, new TimeSliceFactory()},
			{LaceNumberId, new LaceNumberFactory()},
			{FrameNumberId, new FrameNumberFactory()},
			{BlockAdditionIDId, new BlockAdditionIDFactory()},
			{DelayId, new DelayFactory()},
			{SliceDurationId, new SliceDurationFactory()},
			{ReferenceFrameId, new ReferenceFrameFactory()},
			{ReferenceOffsetId, new ReferenceOffsetFactory()},
			{ReferenceTimestampId, new ReferenceTimestampFactory()},
			{EncryptedBlockId, new EncryptedBlockFactory()},
			{TracksId, new TracksFactory()},
			{TrackEntryId, new TrackEntryFactory()},
			{TrackNumberId, new TrackNumberFactory()},
			{TrackUIDId, new TrackUIDFactory()},
			{TrackTypeId, new TrackTypeFactory()},
			{FlagEnabledId, new FlagEnabledFactory()},
			{FlagDefaultId, new FlagDefaultFactory()},
			{FlagForcedId, new FlagForcedFactory()},
			{FlagLacingId, new FlagLacingFactory()},
			{MinCacheId, new MinCacheFactory()},
			{MaxCacheId, new MaxCacheFactory()},
			{DefaultDurationId, new DefaultDurationFactory()},
			{DefaultDecodedFieldDurationId, new DefaultDecodedFieldDurationFactory()},
			{TrackTimestampScaleId, new TrackTimestampScaleFactory()},
			{TrackOffsetId, new TrackOffsetFactory()},
			{MaxBlockAdditionIDId, new MaxBlockAdditionIDFactory()},
			{NameId, new NameFactory()},
			{LanguageId, new LanguageFactory()},
			{LanguageIETFId, new LanguageIETFFactory()},
			{CodecIDId, new CodecIDFactory()},
			{CodecPrivateId, new CodecPrivateFactory()},
			{CodecNameId, new CodecNameFactory()},
			{AttachmentLinkId, new AttachmentLinkFactory()},
			{CodecSettingsId, new CodecSettingsFactory()},
			{CodecInfoURLId, new CodecInfoURLFactory()},
			{CodecDownloadURLId, new CodecDownloadURLFactory()},
			{CodecDecodeAllId, new CodecDecodeAllFactory()},
			{TrackOverlayId, new TrackOverlayFactory()},
			{CodecDelayId, new CodecDelayFactory()},
			{SeekPreRollId, new SeekPreRollFactory()},
			{TrackTranslateId, new TrackTranslateFactory()},
			{TrackTranslateEditionUIDId, new TrackTranslateEditionUIDFactory()},
			{TrackTranslateCodecId, new TrackTranslateCodecFactory()},
			{TrackTranslateTrackIDId, new TrackTranslateTrackIDFactory()},
			{VideoId, new VideoFactory()},
			{FlagInterlacedId, new FlagInterlacedFactory()},
			{FieldOrderId, new FieldOrderFactory()},
			{StereoModeId, new StereoModeFactory()},
			{AlphaModeId, new AlphaModeFactory()},
			{OldStereoModeId, new OldStereoModeFactory()},
			{PixelWidthId, new PixelWidthFactory()},
			{PixelHeightId, new PixelHeightFactory()},
			{PixelCropBottomId, new PixelCropBottomFactory()},
			{PixelCropTopId, new PixelCropTopFactory()},
			{PixelCropLeftId, new PixelCropLeftFactory()},
			{PixelCropRightId, new PixelCropRightFactory()},
			{DisplayWidthId, new DisplayWidthFactory()},
			{DisplayHeightId, new DisplayHeightFactory()},
			{DisplayUnitId, new DisplayUnitFactory()},
			{AspectRatioTypeId, new AspectRatioTypeFactory()},
			{ColourSpaceId, new ColourSpaceFactory()},
			{GammaValueId, new GammaValueFactory()},
			{FrameRateId, new FrameRateFactory()},
			{ColourId, new ColourFactory()},
			{MatrixCoefficientsId, new MatrixCoefficientsFactory()},
			{BitsPerChannelId, new BitsPerChannelFactory()},
			{ChromaSubsamplingHorzId, new ChromaSubsamplingHorzFactory()},
			{ChromaSubsamplingVertId, new ChromaSubsamplingVertFactory()},
			{CbSubsamplingHorzId, new CbSubsamplingHorzFactory()},
			{CbSubsamplingVertId, new CbSubsamplingVertFactory()},
			{ChromaSitingHorzId, new ChromaSitingHorzFactory()},
			{ChromaSitingVertId, new ChromaSitingVertFactory()},
			{RangeId, new RangeFactory()},
			{TransferCharacteristicsId, new TransferCharacteristicsFactory()},
			{PrimariesId, new PrimariesFactory()},
			{MaxCLLId, new MaxCLLFactory()},
			{MaxFALLId, new MaxFALLFactory()},
			{MasteringMetadataId, new MasteringMetadataFactory()},
			{PrimaryRChromaticityXId, new PrimaryRChromaticityXFactory()},
			{PrimaryRChromaticityYId, new PrimaryRChromaticityYFactory()},
			{PrimaryGChromaticityXId, new PrimaryGChromaticityXFactory()},
			{PrimaryGChromaticityYId, new PrimaryGChromaticityYFactory()},
			{PrimaryBChromaticityXId, new PrimaryBChromaticityXFactory()},
			{PrimaryBChromaticityYId, new PrimaryBChromaticityYFactory()},
			{WhitePointChromaticityXId, new WhitePointChromaticityXFactory()},
			{WhitePointChromaticityYId, new WhitePointChromaticityYFactory()},
			{LuminanceMaxId, new LuminanceMaxFactory()},
			{LuminanceMinId, new LuminanceMinFactory()},
			{ProjectionId, new ProjectionFactory()},
			{ProjectionTypeId, new ProjectionTypeFactory()},
			{ProjectionPrivateId, new ProjectionPrivateFactory()},
			{ProjectionPoseYawId, new ProjectionPoseYawFactory()},
			{ProjectionPosePitchId, new ProjectionPosePitchFactory()},
			{ProjectionPoseRollId, new ProjectionPoseRollFactory()},
			{AudioId, new AudioFactory()},
			{SamplingFrequencyId, new SamplingFrequencyFactory()},
			{OutputSamplingFrequencyId, new OutputSamplingFrequencyFactory()},
			{ChannelsId, new ChannelsFactory()},
			{ChannelPositionsId, new ChannelPositionsFactory()},
			{BitDepthId, new BitDepthFactory()},
			{TrackOperationId, new TrackOperationFactory()},
			{TrackCombinePlanesId, new TrackCombinePlanesFactory()},
			{TrackPlaneId, new TrackPlaneFactory()},
			{TrackPlaneUIDId, new TrackPlaneUIDFactory()},
			{TrackPlaneTypeId, new TrackPlaneTypeFactory()},
			{TrackJoinBlocksId, new TrackJoinBlocksFactory()},
			{TrackJoinUIDId, new TrackJoinUIDFactory()},
			{TrickTrackUIDId, new TrickTrackUIDFactory()},
			{TrickTrackSegmentUIDId, new TrickTrackSegmentUIDFactory()},
			{TrickTrackFlagId, new TrickTrackFlagFactory()},
			{TrickMasterTrackUIDId, new TrickMasterTrackUIDFactory()},
			{TrickMasterTrackSegmentUIDId, new TrickMasterTrackSegmentUIDFactory()},
			{ContentEncodingsId, new ContentEncodingsFactory()},
			{ContentEncodingId, new ContentEncodingFactory()},
			{ContentEncodingOrderId, new ContentEncodingOrderFactory()},
			{ContentEncodingScopeId, new ContentEncodingScopeFactory()},
			{ContentEncodingTypeId, new ContentEncodingTypeFactory()},
			{ContentCompressionId, new ContentCompressionFactory()},
			{ContentCompAlgoId, new ContentCompAlgoFactory()},
			{ContentCompSettingsId, new ContentCompSettingsFactory()},
			{ContentEncryptionId, new ContentEncryptionFactory()},
			{ContentEncAlgoId, new ContentEncAlgoFactory()},
			{ContentEncKeyIDId, new ContentEncKeyIDFactory()},
			{ContentEncAESSettingsId, new ContentEncAESSettingsFactory()},
			{AESSettingsCipherModeId, new AESSettingsCipherModeFactory()},
			{ContentSignatureId, new ContentSignatureFactory()},
			{ContentSigKeyIDId, new ContentSigKeyIDFactory()},
			{ContentSigAlgoId, new ContentSigAlgoFactory()},
			{ContentSigHashAlgoId, new ContentSigHashAlgoFactory()},
			{CuesId, new CuesFactory()},
			{CuePointId, new CuePointFactory()},
			{CueTimeId, new CueTimeFactory()},
			{CueTrackPositionsId, new CueTrackPositionsFactory()},
			{CueTrackId, new CueTrackFactory()},
			{CueClusterPositionId, new CueClusterPositionFactory()},
			{CueRelativePositionId, new CueRelativePositionFactory()},
			{CueDurationId, new CueDurationFactory()},
			{CueBlockNumberId, new CueBlockNumberFactory()},
			{CueCodecStateId, new CueCodecStateFactory()},
			{CueReferenceId, new CueReferenceFactory()},
			{CueRefTimeId, new CueRefTimeFactory()},
			{CueRefClusterId, new CueRefClusterFactory()},
			{CueRefNumberId, new CueRefNumberFactory()},
			{CueRefCodecStateId, new CueRefCodecStateFactory()},
			{AttachmentsId, new AttachmentsFactory()},
			{AttachedFileId, new AttachedFileFactory()},
			{FileDescriptionId, new FileDescriptionFactory()},
			{FileNameId, new FileNameFactory()},
			{FileMimeTypeId, new FileMimeTypeFactory()},
			{FileDataId, new FileDataFactory()},
			{FileUIDId, new FileUIDFactory()},
			{FileReferralId, new FileReferralFactory()},
			{FileUsedStartTimeId, new FileUsedStartTimeFactory()},
			{FileUsedEndTimeId, new FileUsedEndTimeFactory()},
			{ChaptersId, new ChaptersFactory()},
			{EditionEntryId, new EditionEntryFactory()},
			{EditionUIDId, new EditionUIDFactory()},
			{EditionFlagHiddenId, new EditionFlagHiddenFactory()},
			{EditionFlagDefaultId, new EditionFlagDefaultFactory()},
			{EditionFlagOrderedId, new EditionFlagOrderedFactory()},
			{ChapterAtomId, new ChapterAtomFactory()},
			{ChapterUIDId, new ChapterUIDFactory()},
			{ChapterStringUIDId, new ChapterStringUIDFactory()},
			{ChapterTimeStartId, new ChapterTimeStartFactory()},
			{ChapterTimeEndId, new ChapterTimeEndFactory()},
			{ChapterFlagHiddenId, new ChapterFlagHiddenFactory()},
			{ChapterFlagEnabledId, new ChapterFlagEnabledFactory()},
			{ChapterSegmentUIDId, new ChapterSegmentUIDFactory()},
			{ChapterSegmentEditionUIDId, new ChapterSegmentEditionUIDFactory()},
			{ChapterPhysicalEquivId, new ChapterPhysicalEquivFactory()},
			{ChapterTrackId, new ChapterTrackFactory()},
			{ChapterTrackUIDId, new ChapterTrackUIDFactory()},
			{ChapterDisplayId, new ChapterDisplayFactory()},
			{ChapStringId, new ChapStringFactory()},
			{ChapLanguageId, new ChapLanguageFactory()},
			{ChapLanguageIETFId, new ChapLanguageIETFFactory()},
			{ChapCountryId, new ChapCountryFactory()},
			{ChapProcessId, new ChapProcessFactory()},
			{ChapProcessCodecIDId, new ChapProcessCodecIDFactory()},
			{ChapProcessPrivateId, new ChapProcessPrivateFactory()},
			{ChapProcessCommandId, new ChapProcessCommandFactory()},
			{ChapProcessTimeId, new ChapProcessTimeFactory()},
			{ChapProcessDataId, new ChapProcessDataFactory()},
			{TagsId, new TagsFactory()},
			{TagId, new TagFactory()},
			{TargetsId, new TargetsFactory()},
			{TargetTypeValueId, new TargetTypeValueFactory()},
			{TargetTypeId, new TargetTypeFactory()},
			{TagTrackUIDId, new TagTrackUIDFactory()},
			{TagEditionUIDId, new TagEditionUIDFactory()},
			{TagChapterUIDId, new TagChapterUIDFactory()},
			{TagAttachmentUIDId, new TagAttachmentUIDFactory()},
			{SimpleTagId, new SimpleTagFactory()},
			{TagNameId, new TagNameFactory()},
			{TagLanguageId, new TagLanguageFactory()},
			{TagLanguageIETFId, new TagLanguageIETFFactory()},
			{TagDefaultId, new TagDefaultFactory()},
			{TagStringId, new TagStringFactory()},
			{TagBinaryId, new TagBinaryFactory()}

    };
    return tags;
}

