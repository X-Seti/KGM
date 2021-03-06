#ifndef CRWEntry_2dEffect_SlotmachineWheel_H
#define CRWEntry_2dEffect_SlotmachineWheel_H

#include "Types.h"
#include "RW/Entries/C2dEffect.h"
#include <string>

class CRWEntry_2dEffect_SlotmachineWheel : public C2dEffect
{
public:
	CRWEntry_2dEffect_SlotmachineWheel(void);

	void							unserialize(void);
	void							serialize(void);

	void							setWheelIndex(int32 iWheelIndex) { m_iWheelIndex = iWheelIndex; }
	int32							getWheelIndex(void) { return m_iWheelIndex; }

private:
	int32							m_iWheelIndex;
};

#endif