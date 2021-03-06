#ifndef CIMGEntry_Version1Or2_H
#define CIMGEntry_Version1Or2_H

#include "Types.h"
#include "Namespace.h"

#pragma pack(push, 1)
struct RG::CIMGEntry_Version1Or2
{
	uint32			m_uiOffsetInSectors;
	uint32			m_uiSizeInSectors;
	uint8			m_szName[24];
};
#pragma pack(pop)

#endif