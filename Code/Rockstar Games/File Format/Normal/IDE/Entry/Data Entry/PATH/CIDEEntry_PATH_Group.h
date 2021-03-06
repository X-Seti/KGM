#ifndef CIDEEntry_PATH_Group_H
#define CIDEEntry_PATH_Group_H

#include "IDE/Entry/Data Entry/CIDEEntry_PATH.h"
#include "Pool/CVectorPool.h"
#include <string>

struct CIDEEntry;

class CIDEEntry_PATH_Group : public CIDEEntry_PATH, public CVectorPool<CIDEEntry*>
{
public:
	CIDEEntry_PATH_Group(CIDEFormat *pIDEFormat) :
		CIDEEntry_PATH(pIDEFormat, IDE_PATH_GROUP),
		m_uiObjectId(0)
	{
	};

	void							unload(void);

	void							unserialize(void);
	void							serialize(void);

	void							setGroupType(std::string& strGroupType) { m_strGroupType = strGroupType; }
	std::string&					getGroupType(void) { return m_strGroupType; }

	void							setObjectId(uint32 uiObjectId) { m_uiObjectId = uiObjectId; }
	uint32							getObjectId(void) { return m_uiObjectId; }

	void							setModelName(std::string& strModelName) { m_strModelName = strModelName; }
	std::string&					getModelName(void) { return m_strModelName; }

private:
	// GTA III era only
	std::string						m_strGroupType;
	uint32							m_uiObjectId;
	std::string						m_strModelName;
};

#endif