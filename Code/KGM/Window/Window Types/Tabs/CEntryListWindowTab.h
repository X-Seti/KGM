#ifndef CEntryListWindowTab_H
#define CEntryListWindowTab_H

#include <Windows.h>
#include "IMG/CIMGFormat.h"
#include "CFilterOptions.h"
#include "Window/CWindowTab.h"
#include <string>
#include <vector>

class CEntryListWindow;
class CIMGFormat;
class CIMGEntry;
class CDBFormat;
class CListCtrl; // temp

class CEntryListWindowTab : public CWindowTab
{
public:
	CEntryListWindowTab(void) :
		m_pWindow(nullptr),
		m_bRestoringFilterOptions(false),
		m_bIMGModifiedSinceRebuild(false),
		m_uiOverwriteEntryOption(0)
	{};

	void						unload(void);

	bool						onTabFormatReady(void);

	void						setIMGFile(CIMGFormat *pIMGFile) { m_pIMGFile = pIMGFile; }
	CIMGFormat*					getIMGFile(void) { return m_pIMGFile; }

	void						setSearchText(std::string strSearchText) { m_strSearchText = strSearchText; }
	std::string					getSearchText(void) { return m_strSearchText; }

	bool						isOverwriteEntryOptionSet(void) { return getOverwriteEntryOption() != 0; }
	void						resetOverwriteEntryOption(void) { setOverwriteEntryOption(0); }
	void						setOverwriteEntryOption(uint32 uiOption) { m_uiOverwriteEntryOption = uiOption; }
	uint32						getOverwriteEntryOption(void) { return m_uiOverwriteEntryOption; }

	void						setListViewHwnd(HWND hWnd) { m_hListViewHwnd = hWnd; }
	HWND						getListViewHwnd(void) { return m_hListViewHwnd; }

	//CListCtrl*					getListView(void) { return (CListCtrl*)CWnd::FromHandle(getListViewHwnd()); } // todo
	CListCtrl*					getListView(void) { return nullptr; } // todo

	bool						isRestoringFilterOptions(void) { return m_bRestoringFilterOptions; }

	void						log(std::string strText, bool bExtendedModeOnly = false);
	void						clearLogs(void);
	std::vector<std::string>&	getLogLinesGUI(void) { return m_vecLogLinesGUI; }
	std::vector<std::string>&	getLogLinesBasic(void) { return m_vecLogLinesBasic; }
	std::vector<std::string>&	getLogLinesExtended(void) { return m_vecLogLinesExtended; }

	void						addEntryViaFile(std::string strEntryFilePath, std::string strEntryName = "");
	void						addEntryViaData(std::string strEntryName, std::string strEntryData);
	void						replaceEntryViaFile(std::string strEntryName, std::string strEntryFilePath, std::string strNewEntryName = "");
	void						replaceEntryViaData(std::string strEntryName, std::string& strEntryData, std::string strNewEntryName = "");
	void						addOrReplaceEntryViaFile(std::string strEntryFilePath, std::string strEntryName = ""); // if entry with name already exists, then it is replaced, otherwise it is added.
	void						addOrReplaceEntryViaData(std::string strEntryName, std::string strEntryData); // if entry with name already exists, then it is replaced, otherwise it is added.
	void						addOrReplaceEntryViaFileAndSettings(std::string strEntryFilePath, std::string strEntryName = ""); // entry is added or replaced depending on settings.
	void						addOrReplaceEntryViaDataAndSettings(std::string strEntryName, std::string strEntryData); // entry is added or replaced depending on settings.
	void						removeEntry(CIMGEntry *pIMGEntry);

	void						addColumnsToMainListView(void);
	void						readdAllEntriesToMainListView(void);
	void						addAllEntriesToMainListView(void);
	void						addEntryToMainListView(CIMGEntry *pIMGEntry);
	void						updateEntryInMainListView(CIMGEntry *pIMGEntry);
	uint32						getMainListViewItemIndexByItemData(CIMGEntry *pIMGEntry);
	CIMGEntry*					getEntryByName(std::string strEntryName);

	void						rebuild(std::string strIMGPath = "", bool bLog = true);
	uint32						merge(std::string strPath, std::vector<std::string>& vecImportedEntryNames);
	void						splitSelectedEntries(std::string strPath, eIMGVersion eIMGVersion, bool bDeleteFromSource, std::vector<std::string>& vecSplitEntryNames);
	void						replace(std::vector<std::string>& vecPaths, std::vector<std::string>& vecReplacedEntryNames);
	void						searchText(void);

	void						setIMGModifiedSinceRebuild(bool bState) { m_bIMGModifiedSinceRebuild = bState; }
	bool						getIMGModifiedSinceRebuild(void) { return m_bIMGModifiedSinceRebuild; } // todo - rename to has..Been.. instead of get

	void						updateEntryCountText(void);
	void						updateIMGText(void);

	void						storeFilterOptions(void);
	void						restoreFilterOptions(void);
	bool						isFilterActive(void);
	
	void						sortEntries(void);
	
	void						onEntryChange(CIMGEntry *pIMGEntry);
	void						loadProtectedEntryStates(void);

	void						loadFilter_Type(void);
	void						loadFilter_Version(void);
	void						unloadFilter_Type(void);
	void						unloadFilter_Version(void);

	void						reassignEntryIds(void);

	std::vector<CIMGEntry*>		getSelectedEntries(void);

	void						setActiveFilter(std::string strFilterName, std::string strValue) { m_umapActiveFilterValues[strFilterName] = strValue; }
	std::string					getActiveFilter(std::string strFilterName) { return m_umapActiveFilterValues[strFilterName]; }

	void						checkToApplyCompression(CIMGEntry *pIMGEntry);

	void						checkForUnknownRWVersionEntries(void);
	
	void						setWindow(CEntryListWindow *pEntryListWindow) { m_pWindow = pEntryListWindow; }
	CEntryListWindow*			getWindow(void) { return m_pWindow; }

	CDBFormat*					m_pDBFile; // todo - make private

private:
	bool						checkForErrors(void);
	void						initTab(void);

	void						loadProtectedEntryState(CIMGEntry *pIMGEntry);

private:
	CEntryListWindow*			m_pWindow;
	CIMGFormat*					m_pIMGFile;
	std::vector<std::string>	m_vecLogLinesGUI;
	std::vector<std::string>	m_vecLogLinesBasic;
	std::vector<std::string>	m_vecLogLinesExtended;
	std::string					m_strSearchText;
	CFilterOptions				m_filterOptions;
	bool						m_bRestoringFilterOptions;
	HWND						m_hListViewHwnd;
	bool						m_bIMGModifiedSinceRebuild;
	std::unordered_map<std::string, std::string>	m_umapActiveFilterValues;
	uint32						m_uiOverwriteEntryOption;
};

#endif