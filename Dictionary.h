#pragma once

#include <vector>
#include <string>

using namespace std;

template<typename K, typename V>
class Dictionary
{
private:
	vector<K> keys;
	vector<V> values;

public:
	Dictionary()
	{
		keys = {};
		values = {};
	}

	void Add(K key, V value)
	{
		keys.push_back(key);
		values.push_back(value);
	}

	V* Get(K key)
	{
		int index = -1;
		for (int i = 0; i < keys.size(); i++)
		{
			if (keys[i] == key)
			{
				index = i;
				break;
			}
		}

		if (index != -1)
		{
			return &values[index];
		}

		return 0;
	}

	V* operator[](K key)
	{
		return Get(key);
	}
};

template<typename gradeType>
class GradesDictionary : public Dictionary<string, gradeType>
{
};

class GradesSymbolDictionary : public GradesDictionary<string>
{
};

class GradesArkamDictionary : public GradesDictionary<int>
{
};