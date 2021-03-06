#ifndef CVectorPool_H
#define CVectorPool_H

#include "Types.h"
#include <vector>

template <class T>
class CVectorPool
{
public:
	bool									isEntryAtIndex(uint32 uiEntryIndex);
	uint32									getEntryCount(void);
	std::vector<T>&							getEntries(void) { return m_vecEntries; }
	T										getEntryByIndex(uint32 uiEntryIndex);
	T										getFirstEntry(void);
	T										getLastEntry(void);
	void									addEntry(T pEntry);
	virtual void							removeAllEntries(void);
	virtual void							removeEntry(T pEntry);
	uint32									getIndexByEntry(T pEntry);
	void									setEntryByIndex(uint32 uiEntryIndex, T pEntry);
	void									swapEntries(T pEntry1, T pEntry2);

protected:
	uint32									getNextEntryIndex(void);

protected:
	std::vector<T>							m_vecEntries;
};




template <class T>
bool				CVectorPool<T>::isEntryAtIndex(uint32 uiEntryIndex)
{
	return uiEntryIndex < m_vecEntries.size();
}

template <class T>
uint32				CVectorPool<T>::getEntryCount(void)
{
	return m_vecEntries.size();
}

template <class T>
T					CVectorPool<T>::getEntryByIndex(uint32 uiEntryIndex)
{
	if (isEntryAtIndex(uiEntryIndex))
	{
		return m_vecEntries[uiEntryIndex];
	}
	return nullptr;
}

template <class T>
void				CVectorPool<T>::removeAllEntries(void)
{
	/*
	//if (m_bUnloadable)
	//{
		for (auto pEntry : getEntries())
		{
			pEntry->unload();
		}
	//}
	*/
	for (auto pEntry : m_vecEntries)
	{
		pEntry->unload();
		delete pEntry;
	}
	m_vecEntries.clear();
}

template <class T>
void				CVectorPool<T>::addEntry(T pEntry)
{
	m_vecEntries.push_back(pEntry);
}

template <class T>
void				CVectorPool<T>::removeEntry(T pEntry)
{
	std::vector<T>::iterator it = std::find(m_vecEntries.begin(), m_vecEntries.end(), pEntry);
	m_vecEntries.erase(it);
	pEntry->unload();
	delete pEntry;
}

template <class T>
uint32				CVectorPool<T>::getNextEntryIndex(void)
{
	return m_vecEntries.size();
}

template <class T>
T					CVectorPool<T>::getFirstEntry(void)
{
	return m_vecEntries[0];
}

template <class T>
T					CVectorPool<T>::getLastEntry(void)
{
	return m_vecEntries[m_vecEntries.size() - 1];
}

template <class T>
uint32				CVectorPool<T>::getIndexByEntry(T pEntry)
{
	for (uint32 i = 0, j = m_vecEntries.size(); i < j; i++)
	{
		if (m_vecEntries[i] == pEntry)
		{
			return i;
		}
	}
	return -1;
}

template <class T>
void				CVectorPool<T>::setEntryByIndex(uint32 uiEntryIndex, T pEntry)
{
	m_vecEntries[uiEntryIndex] = pEntry;
}

template <class T>
void				CVectorPool<T>::swapEntries(T pEntry1, T pEntry2)
{
	uint32 uiEntryIndex1 = getIndexByEntry(pEntry1);
	uint32 uiEntryIndex2 = getIndexByEntry(pEntry2);
	setEntryByIndex(uiEntryIndex1, pEntry2);
	setEntryByIndex(uiEntryIndex2, pEntry1);
}

#endif