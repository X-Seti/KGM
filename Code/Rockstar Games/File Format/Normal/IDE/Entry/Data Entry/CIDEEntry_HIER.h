#ifndef CIDEEntry_HIER_H
#define CIDEEntry_HIER_H

#include "Types.h"
#include "IDE/Entry/CIDEEntry_Data.h"
#include <string>

class CIDEEntry_HIER : public CIDEEntry_Data
{
public:
	CIDEEntry_HIER(CIDEFormat *pIDEFormat) :
		CIDEEntry_Data(pIDEFormat, IDE_SECTION_HIER),
		m_uiObjectId(0)
	{
	};

	void						unserialize(void);
	void						serialize(void);

	void						setObjectId(uint32 uiObjectId) { m_uiObjectId = uiObjectId; }
	uint32						getObjectId(void) { return m_uiObjectId; }

	void						setModelName(std::string& strModelName) { m_strModelName = strModelName; }
	std::string&				getModelName(void) { return m_strModelName; }

	void						setTXDName(std::string& strTXDName) { m_strTXDName = strTXDName; }
	std::string&				getTXDName(void) { return m_strTXDName; }

private:
	// GTA III era & GTA IV
	uint32						m_uiObjectId;
	std::string					m_strModelName;
	std::string					m_strTXDName;
};

#endif