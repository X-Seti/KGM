#ifndef CVectorUtility_H
#define CVectorUtility_H

#include "Types.h"
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

class CVectorUtility
{
public:
	static std::vector<std::string>					combineVectors(std::vector<std::string>& vecVector1, std::vector<std::string>& vecVector2);
	static void										addToVector(std::vector<std::string>& vecVector1, std::vector<std::string>& vecVector2);
	static std::deque<std::string>					convertVectorToDeque(std::vector<std::string>& vecVector);
	static std::unordered_map<std::string, bool>	convertVectorToUnorderedMap(std::vector<std::string>& vecVector);
	static std::vector<std::string>					toUpperCase(std::vector<std::string> vecVector);
	static std::vector<std::string>					removeDuplicates(std::vector<std::string>& vecVector);
	static uint32									findKey(std::vector<std::string>& vecVector, std::string& strValue);
	static void										addUniqueEntry(std::vector<std::string>& vecVector, std::string& strValue);
	static std::vector<std::string>					getUniqueEntries(std::vector<std::string>& vecVector1, std::vector<std::string>& vecVector2);
	static bool										isIn(std::vector<std::string>& vecVector1, std::string& strLookFor);
	static void										sortAZCaseInsensitive(std::vector<std::string>& vecVector);
};

#endif