#ifndef CWindowControl_Progress_H
#define CWindowControl_Progress_H

#include "Types.h"
#include "Window/Window Controls/CWindowControl.h"
#include "Window/Window Controls/Components/CWindowControlComponent_Text.h"
#include "Window/Window Controls/Components/CWindowControlComponent_Rectangle.h"

class CWindowControl_Progress : public CWindowControl, public CWindowControlComponent_Text, public CWindowControlComponent_Rectangle
{
public:
	CWindowControl_Progress(void) :
		CWindowControl(WINDOW_CONTROL_PROGRESS),
		m_uiMaxTicks(0),
		m_uiCurrentTicks(0),
		m_uiProgressFillColour(0),
		m_bCompletionPercentageShown(false)
	{};
	
	void									render(void);
	
	void									setMaxTicks(uint32 uiMaxTicks) { m_uiMaxTicks = uiMaxTicks; }
	uint32									getMaxTicks(void) { return m_uiMaxTicks; }
	
	void									setCurrentTicks(uint32 uiCurrentTicks) { m_uiCurrentTicks = uiCurrentTicks; }
	uint32									getCurrentTicks(void) { return m_uiCurrentTicks; }
	
	void									setProgressFillColour(uint32 uiProgressFillColour) { m_uiProgressFillColour = uiProgressFillColour; }
	uint32									getProgressFillColour(void) { return m_uiProgressFillColour; }

	void									setCompletionPercentageShown(bool bCompletionPercentageShown) { m_bCompletionPercentageShown = bCompletionPercentageShown; }
	bool									isCompletionPercentageShown(void) { return m_bCompletionPercentageShown; }
	
private:
	uint32									m_uiMaxTicks;
	uint32									m_uiCurrentTicks;
	uint32									m_uiProgressFillColour;
	uint8									m_bCompletionPercentageShown			: 1;
};

#endif