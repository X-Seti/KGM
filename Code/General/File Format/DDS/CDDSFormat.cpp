#include "CDDSFormat.h"
#include "Data Stream/CDataReader.h"
#include "Data Stream/CDataWriter.h"
#include "File/CFileUtility.h"
#include "Memory/CMemoryUtility.h"
#include "DDS/CDDSFormat_Header_DDS_HEADER.h"
#include "DDS/CDDSFormat_Header_DDS_PIXELFORMAT_Part1.h"
#include "DDS/CDDSFormat_Header_DDS_HEADER_DXT10.h"
#include "DDS/CDDSFormat_Header_DDS_PIXELFORMAT_Part2.h"
#include "D3D10.h"

using namespace std;

CDDSFormat::CDDSFormat(void) :
	CFormat(true, LITTLE_ENDIAN),
	m_uiWidth(0),
	m_uiHeight(0),
	m_uiBPP(0)
{
}

void				CDDSFormat::unserialize(void)
{
	CDataReader *pDataReader = CDataReader::getInstance();

	// file header
	uint32 uiMagicNumber = pDataReader->readUint32(); // 0x20534444

	// DDS_HEADER structure
	CDDSFormat_Header_DDS_HEADER *pHeader1 = pDataReader->readStruct<CDDSFormat_Header_DDS_HEADER>();

	// DDS_PIXELFORMAT structure
	CDDSFormat_Header_DDS_PIXELFORMAT_Part1 *pHeader2 = pDataReader->readStruct<CDDSFormat_Header_DDS_PIXELFORMAT_Part1>();

	if (pHeader2->m_uiFlags2 == 4/*DDPF_FOURCC*/ && string((char*)&pHeader2->m_ucFourCC, 4) == "DX10")
	{
		// DDS_HEADER_DXT10 structure
		CDDSFormat_Header_DDS_HEADER_DXT10 *pHeader3 = pDataReader->readStruct<CDDSFormat_Header_DDS_HEADER_DXT10>();
		delete pHeader3;
	}

	// DDS_HEADER structure continued
	CDDSFormat_Header_DDS_PIXELFORMAT_Part2 *pHeader4 = pDataReader->readStruct<CDDSFormat_Header_DDS_PIXELFORMAT_Part2>();

	// raster data
	m_strRasterData = pDataReader->readString(pHeader1->m_uiWidth * pHeader1->m_uiHeight * (pHeader2->m_uiRGBBitCount / 8));

	// copy from raw structs to wrapper structs
	m_uiWidth = pHeader1->m_uiWidth;
	m_uiHeight = pHeader1->m_uiHeight;
	m_uiBPP = pHeader2->m_uiRGBBitCount / 8;

	// clean up
	delete pHeader1;
	delete pHeader2;
	delete pHeader4;
}

void				CDDSFormat::serialize(void)
{
	CDataWriter *pDataWriter = CDataWriter::getInstance();

	bool bCompressedRasterData = true;

	// file header
	uint32 uiMagicNumber = 0x20534444;
	pDataWriter->write(uiMagicNumber);

	// DDS_HEADER structure
	uint32
		uiSize = 124,
		uiFlags = 1 | 2 | 4 | 0x1000,
		uiPitchOrLinearSize,
		uiDepth = 0,
		uiMipMapCount = 1,
		uiReserved1 = 0
	;
	if (bCompressedRasterData)
	{
		uiFlags |= 0x80000;
		uiPitchOrLinearSize = m_strRasterData.length();
	}
	else
	{
		uiFlags |= 8;
		uiPitchOrLinearSize = m_uiWidth * 4;
	}
	pDataWriter->write(uiSize);
	pDataWriter->write(uiFlags);
	pDataWriter->write(m_uiHeight);
	pDataWriter->write(m_uiWidth);
	pDataWriter->write(uiPitchOrLinearSize);
	pDataWriter->write(uiDepth);
	pDataWriter->write(uiMipMapCount);
	for (uint32 i = 0; i < 11; i++)
	{
		pDataWriter->write(uiReserved1);
	}

	// DDS_PIXELFORMAT structure
	uint32
		uiSize2 = 32,
		uiFlags2,
		uiRGBBitCount = 32,
		uiABitMask = 0xFF000000,
		uiBBitMask = 0x00FF0000,
		uiGBitMask = 0x0000FF00,
		uiRBitMask = 0x000000FF
	;
	if (bCompressedRasterData)
	{
		uiFlags2 = 0x4;
	}
	else
	{
		uiFlags2 = 0x40;
	}
	string
		strFourCC = "";
	if (bCompressedRasterData)
	{
		strFourCC = "DXT1";
	}
	else
	{
		strFourCC.append(4, '\0');
	}
	pDataWriter->write(uiSize2);
	pDataWriter->write(uiFlags2);
	pDataWriter->write(strFourCC);
	pDataWriter->write(uiRGBBitCount);
	pDataWriter->write(uiRBitMask);
	pDataWriter->write(uiGBitMask);
	pDataWriter->write(uiBBitMask);
	pDataWriter->write(uiABitMask);

	//if (uiFlags2 == DDPF_FOURCC && strFourCC == "DX10")
	if (uiFlags2 == 4 && strFourCC == "DX10")
	{
		// DDS_HEADER_DXT10 structure
		uint32 uiDXGIFormat = DXGI_FORMAT_R8G8B8A8_UINT;
		uint32 uiD3D10ResourceDimension = D3D10_RESOURCE_DIMENSION_TEXTURE2D;
		int32 iMiscFlag = 0;
		int32 iArraySize = 0;
		int32 iMiscFlag2 = 0;
		pDataWriter->write(uiDXGIFormat);
		pDataWriter->write(uiD3D10ResourceDimension); // D3D10_RESOURCE_DIMENSION - assume 4 bytes
		pDataWriter->write(iMiscFlag);
		pDataWriter->write(iArraySize);
		pDataWriter->write(iMiscFlag2);
	}

	// DDS_HEADER structure continued
	uint32
		uiCaps = 0x1000,
		uiCaps2 = 0,
		uiCaps3 = 0,
		uiCaps4 = 0,
		uiReserved2 = 0
	;
	pDataWriter->write(uiCaps);
	pDataWriter->write(uiCaps2);
	pDataWriter->write(uiCaps3);
	pDataWriter->write(uiCaps4);
	pDataWriter->write(uiReserved2);

	// data
	pDataWriter->write(m_strRasterData);
}