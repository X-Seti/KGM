#ifndef CIMGEntry_H
#define CIMGEntry_H

#include "eCompressionAlgorithm.h"
#include "Math/CMathUtility.h"
#include "Namespace.h"
#include <string>

class CIMGFormat;
class CRWVersion;
class CCOLVersion;
class CRageResourceType;
class CIMGEntry_Fastman92;

class CIMGEntry
{
public:
	CIMGEntry(void);
	CIMGEntry(CIMGFormat *pIMGFile);

	void					unload(void) {};

	void					unserializeVersion1Or2(RG::CIMGEntry_Version1Or2 *pRGIMGEntry);
	void					unserializeVersion3(RG::CIMGEntry_Version3 *pRGIMGEntry);
	void					unserializeVersionFastman92(CIMGEntry_Fastman92 *pRawIMGEntry);

	void					setIMGFile(CIMGFormat *pIMGFile) { m_pIMGFile = pIMGFile; }
	CIMGFormat*				getIMGFile(void) { return m_pIMGFile; }

	void					setEntryOffset(uint32 uiEntryOffsetInBytes) { m_uiEntryOffset = uiEntryOffsetInBytes; } // in bytes
	uint32					getEntryOffset(void) { return m_uiEntryOffset; } // in bytes
	void					setEntryOffsetInSectors(uint32 uiEntryOffsetInSectors) { m_uiEntryOffset = CMathUtility::convertSectorsToBytes(uiEntryOffsetInSectors); } // in sectors (1 sector = 2048 bytes)
	uint32					getEntryOffsetInSectors(void) { return CMathUtility::convertBytesToSectors(m_uiEntryOffset); } // in sectors (1 sector = 2048 bytes)

	void					setEntrySize(uint32 uiEntrySize); // in bytes
	uint32					getEntrySize(void) { return m_uiEntrySize; } // in bytes
	uint32					getPaddedEntrySize(void); // in bytes
	void					setEntrySizeInSectors(uint32 uiEntrySizeInSectors) { m_uiEntrySize = CMathUtility::convertSectorsToBytes(uiEntrySizeInSectors); } // in sectors (1 sector = 2048 bytes)
	uint32					getEntrySizeInSectors(void) { return CMathUtility::convertBytesToSectors(getPaddedEntrySize()); } // in sectors (1 sector = 2048 bytes)

	void					setEntryName(std::string& strEntryName) { m_strEntryName = strEntryName; } // dynamic length
	std::string&			getEntryName(void) { return m_strEntryName; }  // dynamic length

	void					setEntryExtension(std::string& strEntryExtension) { m_strEntryExtension = strEntryExtension; }
	std::string&			getEntryExtension(void) { return m_strEntryExtension; }

	void					setRWVersionByVersionCC(uint32 uiRWVersionCC);
	void					setRWVersion(CRWVersion *pRWVersion) { m_pRWVersion = pRWVersion; }
	CRWVersion*				getRWVersion(void) { return m_pRWVersion; }

	void					setRageResourceTypeByIdentifier(uint32 uiResourceType);
	void					setRageResourceType(CRageResourceType *pRageResourceType) { m_pRageResourceType = pRageResourceType; }
	CRageResourceType*		getRageResourceType(void) { return m_pRageResourceType; }

	void					setFlags(uint16 usFlags) { m_uiFlags = usFlags; }
	uint16					getFlags(void) { return m_uiFlags; }

	void					setUncompressedSize(uint32 uiUncompressedSize) { m_uiUncompressedSize = uiUncompressedSize; } // in bytes
	uint32					getUncompressedSize(void) { return m_uiUncompressedSize; } // in bytes
	void					setUncompressedSizeInSectors(uint32 uiUncompressedSizeInSectors) { m_uiUncompressedSize = CMathUtility::convertSectorsToBytes(uiUncompressedSizeInSectors); } // in sectors (1 sector = 2048 bytes)
	uint32					getUncompressedSizeInSectors(void) { return CMathUtility::convertBytesToSectors(m_uiUncompressedSize); } // in sectors (1 sector = 2048 bytes)

	void					setCompression(uint8 ucCompressionMethod) { m_uiFlags = (m_uiFlags & 4294967280) | ucCompressionMethod; } // old - todo - remove?
	uint8					getCompression(void) { return m_uiFlags & 0xF; } // old
	//bool					isCompressed(void) { return getCompression() != 0; } // old

	void					setCompressionAlgorithmId(eCompressionAlgorithm eCompressionAlgorithmValue) { m_eCompressionAlgorithm = eCompressionAlgorithmValue; }
	eCompressionAlgorithm	getCompressionAlgorithmId(void) { return m_eCompressionAlgorithm; }
	bool					isCompressed(void) { return m_eCompressionAlgorithm != IMGCOMPRESSION_UNKNOWN && m_eCompressionAlgorithm != IMGCOMPRESSION_NONE; }

	void					setCompressionLevel(uint32 uiCompressionLevel) { m_uiCompressionLevel = uiCompressionLevel; }
	uint32					getCompressionLevel(void) { return m_uiCompressionLevel; }

	void					setEncrypted(bool bIsEncrypted) { m_bIsEncrypted = bIsEncrypted; }
	bool					isEncrypted(void) { return m_bIsEncrypted; }

	void					setNewEntry(bool bNewEntry) { m_bNewEntry = bNewEntry; }
	bool					isNewEntry(void) { return m_bNewEntry; }

	void					setReplacedEntry(bool bReplacedEntry) { m_bReplacedEntry = bReplacedEntry; }
	bool					isReplacedEntry(void) { return m_bReplacedEntry; }

	void					setProtectedEntry(bool bProtectedEntry) { m_bProtectedEntry = bProtectedEntry; }
	bool					isProtectedEntry(void) { return m_bProtectedEntry; }

	void					setFileCreationDate(uint32 uiFileCreationDate) { m_uiFileCreationDate = uiFileCreationDate; }
	uint32					getFileCreationDate(void) { return m_uiFileCreationDate; }

	void					setEntryData(std::string strEntryData, bool bIsNew = false);
	std::string				getEntryData(void);
	std::string				getEntrySubData(uint32 uiStart, uint32 uiLength);
	//std::string				getEntryDecompressedData(void);
	//std::string				getEntryCompressedData(void);

	bool					canBeRead(void);

	void					saveEntry(std::string strFilePath);
	void					saveEntryByMemory(std::string strFilePath, std::string& strEntryData);

	static uint32			getEntryDataPadLength(uint32 uiUnpaddedDataLength);
	static uint32			getVersion3IMGSizeDeduction(uint32 uiDataLength);

	bool					isModelFile(void);
	bool					isTextureFile(void);
	bool					isCollisionFile(void);
	bool					isDFFFile(void);
	bool					isTXDFile(void);
	bool					isCOLFile(void);
	bool					isWTDFile(void);

	void					setCOLVersion(CCOLVersion *pCOLVersion) { m_pCOLVersion = pCOLVersion; }
	CCOLVersion*			getCOLVersion(void) { return m_pCOLVersion; }
	
	void					applyCompression(eCompressionAlgorithm eCompressionAlgorithmValue, uint32 uiCompressionLevel = 0);

	bool					doesHaveUnknownVersion(void); // checks for RW version (DFF/TXD) or COL version. Unknown file extension counts as unknown RW version. IPL files are skipped.

	CIMGEntry*				clone(CIMGFormat *pIMGFile);

	std::string				getVersionText(void);

private:
	CIMGFormat*				m_pIMGFile;
	uint32					m_uiEntryOffset; // in bytes
	uint32					m_uiEntrySize; // in bytes
	std::string				m_strEntryName;
	std::string				m_strEntryExtension;
	uint32					m_uiFlags;
	union
	{
		CRWVersion*			m_pRWVersion; // version 1/2 IMG
		CCOLVersion*		m_pCOLVersion; // version 1/2 IMG
	};
	union {
		struct { // IMG version 3 (encrypted / unencrypted)
			CRageResourceType*	m_pRageResourceType;
		};
		struct { // IMG version fastman92
			uint32	m_uiUncompressedSize; // in bytes
		};
	};
	uint8					m_bNewEntry : 1;
	uint8					m_bReplacedEntry : 1;
	uint8					m_bProtectedEntry : 1;
	uint8					m_bIsEncrypted : 1;
	uint32					m_uiFileCreationDate;
	eCompressionAlgorithm	m_eCompressionAlgorithm;
	uint32					m_uiCompressionLevel;
};

#endif