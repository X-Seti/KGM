#ifndef CIMGPeekData_H
#define CIMGPeekData_H

#include "eIMGVersion.h"

class CIMGPeekData
{
public:
	CIMGPeekData(void);

public:
	void			setIMGVersion(eIMGVersion eIMGVersionValue) { m_eIMGVersion = eIMGVersionValue; }
	eIMGVersion		getIMGVersion(void) { return m_eIMGVersion; }

	void			setEncrypted(bool bEncrypted) { m_bEncrypted = bEncrypted; }
	bool			isEncrypted(void) { return m_bEncrypted; }

private:
	eIMGVersion		m_eIMGVersion;
	bool			m_bEncrypted;
};

#endif