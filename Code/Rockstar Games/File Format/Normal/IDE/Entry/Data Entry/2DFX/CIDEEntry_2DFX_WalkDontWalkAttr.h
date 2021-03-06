#ifndef CIDEEntry_2DFX_WalkDontWalkAttr_H
#define CIDEEntry_2DFX_WalkDontWalkAttr_H

#include "IDE/Entry/Data Entry/CIDEEntry_2DFX.h"
#include <string>

class CIDEEntry_2DFX_WalkDontWalkAttr : public CIDEEntry_2DFX
{
public:
	CIDEEntry_2DFX_WalkDontWalkAttr(CIDEFormat *pIDEFormat) :
		CIDEEntry_2DFX(pIDEFormat, _2DFX_WALK_DONT_WALK_ATTR)
	{
	};

	void						unserialize(void);
	void						serialize(void);
};

#endif