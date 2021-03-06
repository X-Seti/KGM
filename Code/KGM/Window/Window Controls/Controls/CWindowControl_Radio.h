#ifndef CWindowControl_Radio_H
#define CWindowControl_Radio_H

#include "Types.h"
#include "Window/Window Controls/CWindowControl.h"
#include "Window/Window Controls/Components/CWindowControlComponent_Rectangle.h"
#include "Window/Window Controls/Components/CWindowControlComponent_Text.h"

class CWindowControl_Radio : public CWindowControl, public CWindowControlComponent_Rectangle, public CWindowControlComponent_Text
{
public:
	CWindowControl_Radio(void) :
		CWindowControl(WINDOW_CONTROL_RADIO),
		CWindowControlComponent_Rectangle(),
		CWindowControlComponent_Text(),
		m_uiIconRightMargin(5),
		m_uiGroupId(0),
		m_bChecked(false)
	{};
	
	void									onMouseUp(CVector2ui32& vecCursorPosition);

	void									render(void);

	bool									isPointInControl(CVector2ui32& vecPoint);

	void									setIconRightMargin(uint32 uiIconRightMargin) { m_uiIconRightMargin = uiIconRightMargin; }
	uint32									getIconRightMargin(void) { return m_uiIconRightMargin; }
	
	void									setChecked(bool bChecked) { m_bChecked = bChecked; }
	bool									isChecked(void) { return m_bChecked; }
	
	void									setGroupId(uint32 uiGroupId) { m_uiGroupId = uiGroupId; }
	uint32									getGroupId(void) { return m_uiGroupId; }
	
private:
	uint32									m_uiIconRightMargin; // in pixels
	uint32									m_uiGroupId;
	uint8									m_bChecked			: 1;
};

#endif