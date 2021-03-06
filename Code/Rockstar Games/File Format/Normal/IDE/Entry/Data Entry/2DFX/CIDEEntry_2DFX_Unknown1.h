#ifndef CIDEEntry_2DFX_Unknown1_H
#define CIDEEntry_2DFX_Unknown1_H

#include "IDE/Entry/Data Entry/CIDEEntry_2DFX.h"
#include "CVector3D.h"

class CIDEEntry_2DFX_Unknown1 : public CIDEEntry_2DFX
{
public:
	CIDEEntry_2DFX_Unknown1(CIDEFormat *pIDEFormat) :
		CIDEEntry_2DFX(pIDEFormat, _2DFX_UNKNOWN_1),
		m_uiUnknown2(0),
		m_vecUnknown3{ 0.0f, 0.0f, 0.0f },
		m_uiUnknown4(0)
	{
	};

	void						unserialize(void);
	void						serialize(void);

	void						setUnknown2(uint32 uiUnknown2) { m_uiUnknown2 = uiUnknown2; }
	uint32						getUnknown2(void) { return m_uiUnknown2; }

	void						setUnknown3(CVector3D& vecUnknown3) { m_vecUnknown3 = vecUnknown3; }
	CVector3D&					getUnknown3(void) { return m_vecUnknown3; }

	void						setUnknown4(uint32 uiUnknown4) { m_uiUnknown4 = uiUnknown4; }
	uint32						getUnknown4(void) { return m_uiUnknown4; }

private:
	// GTA III era only
	uint32						m_uiUnknown2;
	CVector3D					m_vecUnknown3;
	uint32						m_uiUnknown4;
};

#endif