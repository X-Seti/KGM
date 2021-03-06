#ifndef CRWSection_Clump_H
#define CRWSection_Clump_H

#include "../CRWSection.h"

class CRWSection_Clump : public CRWSection
{
public:
	CRWSection_Clump(void);

	void							unserialize(void);
	void							serialize(void);

	void							setAtomicallyLinkedObjectCount(uint32 uiAtomicallyLinkedObjectCount) { m_uiAtomicallyLinkedObjectCount = uiAtomicallyLinkedObjectCount; }
	uint32							getAtomicallyLinkedObjectCount(void) { return m_uiAtomicallyLinkedObjectCount; }

	void							setLightCount(uint32 uiLightCount) { m_uiLightCount = uiLightCount; }
	uint32							getLightCount(void) { return m_uiLightCount; }

	void							setCameraCount(uint32 uiCameraCount) { m_uiCameraCount = uiCameraCount; }
	uint32							getCameraCount(void) { return m_uiCameraCount; }

	bool							doesHaveLightAndCameraCounts(void); // todo

private:
	uint32							m_uiAtomicallyLinkedObjectCount;
	uint32							m_uiLightCount;
	uint32							m_uiCameraCount;
};

#endif