#ifndef CIDEEntry_TOBJ_H
#define CIDEEntry_TOBJ_H

#include "Types.h"
#include "IDE/Entry/CIDEEntry_Data.h"
#include "CVector3D.h"
#include <string>
#include <vector>

class CIDEEntry_TOBJ : public CIDEEntry_Data
{
public:
	CIDEEntry_TOBJ(CIDEFormat *pIDEFormat) :
		CIDEEntry_Data(pIDEFormat, IDE_SECTION_TOBJ),
		m_uiTokenCount(0),
		m_uiObjectId(0),
		m_uiClumpCount(0),
		m_uiFlags(0),
		m_uiTimeOn(0),
		m_uiTimeOff(0),
		m_uiUnknown2(0),
		m_vecBoundingBoxLowerLeftCorner{ 0.0f, 0.0f, 0.0f },
		m_vecBoundingBoxUpperRightCorner{ 0.0f, 0.0f, 0.0f },
		m_vecBoundingSphereCenterPosition{ 0.0f, 0.0f, 0.0f },
		m_fBoundingSphereRadius(0.0f),
		m_uiNightFlags(0)
	{
	};

	void						unserialize(void);
	void						serialize(void);

	void						setTokenCount(uint32 uiTokenCount) { m_uiTokenCount = uiTokenCount; }
	uint32						getTokenCount(void) { return m_uiTokenCount; }

	void						setObjectId(uint32 uiObjectId) { m_uiObjectId = uiObjectId; }
	uint32						getObjectId(void) { return m_uiObjectId; }

	void						setModelName(std::string& strModelName) { m_strModelName = strModelName; }
	std::string&				getModelName(void) { return m_strModelName; }

	void						setTXDName(std::string& strTXDName) { m_strTXDName = strTXDName; }
	std::string&				getTXDName(void) { return m_strTXDName; }

	void						setClumpCount(uint32 uiClumpCount) { m_uiClumpCount = uiClumpCount; }
	uint32						getClumpCount(void) { return m_uiClumpCount; }

	void						setDrawDistances(std::vector<float32>& vecDrawDistances) { m_vecDrawDistances = vecDrawDistances; }
	std::vector<float32>&		getDrawDistances(void) { return m_vecDrawDistances; }

	void						setFlags(uint32 uiFlags) { m_uiFlags = uiFlags; }
	uint32						getFlags(void) { return m_uiFlags; }

	void						setTimeOn(uint32 uiTimeOn) { m_uiTimeOn = uiTimeOn; }
	uint32						getTimeOn(void) { return m_uiTimeOn; }

	void						setTimeOff(uint32 uiTimeOff) { m_uiTimeOff = uiTimeOff; }
	uint32						getTimeOff(void) { return m_uiTimeOff; }

	void						setUnknown1(uint32 uiUnknown2) { m_uiUnknown2 = uiUnknown2; }
	uint32						getUnknown1(void) { return m_uiUnknown2; }

	void						setBoundingBoxLowerLeftCorner(CVector3D& vecBoundingBoxLowerLeftCorner) { m_vecBoundingBoxLowerLeftCorner = vecBoundingBoxLowerLeftCorner; }
	CVector3D&					getBoundingBoxLowerLeftCorner(void) { return m_vecBoundingBoxLowerLeftCorner; }

	void						setBoundingBoxUpperRightCorner(CVector3D& vecBoundingBoxUpperRightCorner) { m_vecBoundingBoxUpperRightCorner = vecBoundingBoxUpperRightCorner; }
	CVector3D&					getBoundingBoxUpperRightCorner(void) { return m_vecBoundingBoxUpperRightCorner; }

	void						setBoundingSphereCenterPosition(CVector3D& vecBoundingSphereCenterPosition) { m_vecBoundingSphereCenterPosition = vecBoundingSphereCenterPosition; }
	CVector3D&					getBoundingSphereCenterPosition(void) { return m_vecBoundingSphereCenterPosition; }

	void						setBoundingSphereRadius(float32 fBoundingSphereRadius) { m_fBoundingSphereRadius = fBoundingSphereRadius; }
	float32						getBoundingSphereRadius(void) { return m_fBoundingSphereRadius; }

	void						setLODModel(std::string& strLODModel) { m_strLODModel = strLODModel; }
	std::string&				getLODModel(void) { return m_strLODModel; }

	void						setNightFlags(uint32 uiNightFlags) { m_uiNightFlags = uiNightFlags; }
	uint32						getNightFlags(void) { return m_uiNightFlags; }

private:
	uint32						m_uiTokenCount;

	// GTA III era & GTA IV
	std::string					m_strModelName;
	std::string					m_strTXDName;
	std::vector<float32>		m_vecDrawDistances;
	uint32						m_uiFlags;
	uint32						m_uiUnknown2;

	// GTA III era only
	uint32						m_uiObjectId;
	uint32						m_uiClumpCount;
	uint32						m_uiTimeOn;
	uint32						m_uiTimeOff;

	// GTA IV only
	CVector3D					m_vecBoundingBoxLowerLeftCorner;
	CVector3D					m_vecBoundingBoxUpperRightCorner;
	CVector3D					m_vecBoundingSphereCenterPosition;
	float32						m_fBoundingSphereRadius;
	std::string					m_strLODModel;
	uint32						m_uiNightFlags;
};

#endif