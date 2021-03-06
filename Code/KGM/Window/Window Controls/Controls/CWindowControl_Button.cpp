#include "CWindowControl_Button.h"
#include "Math/CMathUtility.h"
#include "GDIPlus/CGDIPlusUtility.h"
#include "Event/CEventManager.h"

// input
void		CWindowControl_Button::onMouseDown(CVector2ui32& vecCursorPosition)
{
	if (isPointInControl(vecCursorPosition))
	{
		CEventManager::getInstance()->setEventHogged(true);
	}
}

void		CWindowControl_Button::onMouseUp(CVector2ui32& vecCursorPosition)
{
	if (isPointInControl(vecCursorPosition))
	{
		CEventManager::getInstance()->triggerEvent("onPressButton", this);
	}
}

// render
void		CWindowControl_Button::render(void)
{
	if (doesHaveFill())
	{
		CGDIPlusUtility::drawRectangleFill(getPosition(), getSize(), getFillColour());
	}
	if (doesHaveBorder())
	{
		CGDIPlusUtility::drawRectangleBorder(getPosition(), getSize(), getLineColour());
	}
	CGDIPlusUtility::drawText(getPosition(), getSize(), getText(), getTextColour(), getFontSize(), isBold());
}