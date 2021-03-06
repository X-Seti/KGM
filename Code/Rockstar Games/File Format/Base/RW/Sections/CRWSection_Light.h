#ifndef CRWSection_Light_H
#define CRWSection_Light_H

#include "../CRWSection.h"
#include <string>

class CRWSection_Light : public CRWSection
{
public:
	CRWSection_Light(void);

	void							unserialize(void);
	void							serialize(void);

	void							setData(std::string& strData) { m_strData = strData; }
	std::string&					getData(void) { return m_strData; }

private:
	std::string						m_strData;
};

#endif