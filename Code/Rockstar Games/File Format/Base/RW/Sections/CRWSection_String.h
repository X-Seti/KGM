#ifndef CRWSection_String_H
#define CRWSection_String_H

#include "../CRWSection.h"
#include <string>

class CRWSection_String : public CRWSection
{
public:
	CRWSection_String(void);

	void							unserialize(void);
	void							serialize(void);

	void							setData(std::string& strData) { m_strData = strData; }
	std::string&					getData(void) { return m_strData; }

private:
	std::string						m_strData;
};

#endif