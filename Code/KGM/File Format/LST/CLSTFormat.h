#ifndef CLSTFormat_H
#define CLSTFormat_H

#include "CFormat.h"
#include "Pool/CVectorPool.h"
#include "CLSTSection.h"
#include <string>
#include <vector>

class CLSTFormat : public CFormat, public CVectorPool<CLSTSection*>
{
public:
	CLSTFormat(void) : CFormat(false) {};

	void								unload(void);

	CLSTSection*						getEntryByName(std::string strName);
	bool								doesEntryExistByName(std::string strName);

private:
	void								unserialize(void);
	void								serialize(void);

	void								unserializeLine(void);
};

#endif