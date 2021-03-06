#ifndef CIPLEntry_PATH_Node_H
#define CIPLEntry_PATH_Node_H

#include "Types.h"
#include "IPL/Entry/Data Entry/CIPLEntry_PATH.h"
#include "CVector3D.h"

class CIPLEntry_PATH_Node : public CIPLEntry_PATH
{
public:
	CIPLEntry_PATH_Node(CIPLFormat *pIPLFormat) :
		CIPLEntry_PATH(pIPLFormat, IPL_PATH_NODE),
		m_uiNodeType(0),
		m_uiNextNode(0),
		m_uiIsCrossRoad(0),
		m_vecPosition{ 0.0f, 0.0f, 0.0f },
		m_fMedian(0.0f),
		m_uiLeftLaneCount(0),
		m_uiRightLaneCount(0),
		m_uiSpeedLimit(0),
		m_uiFlags(0),
		m_fSpawnRate(0.0f)
	{
	};

	void							unserialize(void);
	void							serialize(void);

	void							setNodeType(uint32 uiNodeType) { m_uiNodeType = uiNodeType; }
	uint32							getNodeType(void) { return m_uiNodeType; }

	void							setNextNode(uint32 uiNextNode) { m_uiNextNode = uiNextNode; }
	uint32							getNextNode(void) { return m_uiNextNode; }

	void							setIsCrossRoad(uint32 uiIsCrossRoad) { m_uiIsCrossRoad = uiIsCrossRoad; }
	uint32							getIsCrossRoad(void) { return m_uiIsCrossRoad; }

	void							setPosition(CVector3D& vecPosition) { m_vecPosition = vecPosition; }
	CVector3D&						getPosition(void) { return m_vecPosition; }

	void							setMedian(float32 fMedian) { m_fMedian = fMedian; }
	float32							getMedian(void) { return m_fMedian; }

	void							setLeftLaneCount(uint32 uiLeftLaneCount) { m_uiLeftLaneCount = uiLeftLaneCount; }
	uint32							getLeftLaneCount(void) { return m_uiLeftLaneCount; }

	void							setRightLaneCount(uint32 uiRightLaneCount) { m_uiRightLaneCount = uiRightLaneCount; }
	uint32							getRightLaneCount(void) { return m_uiRightLaneCount; }

	void							setSpeedLimit(uint32 uiSpeedLimit) { m_uiSpeedLimit = uiSpeedLimit; }
	uint32							getSpeedLimit(void) { return m_uiSpeedLimit; }

	void							setFlags(uint32 uiFlags) { m_uiFlags = uiFlags; }
	uint32							getFlags(void) { return m_uiFlags; }

	void							setSpawnRate(float32 fSpawnRate) { m_fSpawnRate = fSpawnRate; }
	float32							getSpawnRate(void) { return m_fSpawnRate; }

private:
	// GTA VC only
	uint32							m_uiNodeType;
	uint32							m_uiNextNode;
	uint32							m_uiIsCrossRoad;
	CVector3D						m_vecPosition;
	float32							m_fMedian;
	uint32							m_uiLeftLaneCount;
	uint32							m_uiRightLaneCount;
	uint32							m_uiSpeedLimit;
	uint32							m_uiFlags;
	float32							m_fSpawnRate;
};

#endif