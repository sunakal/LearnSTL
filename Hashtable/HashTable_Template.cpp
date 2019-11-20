// TemplMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
template <typename K, typename V> class Hashtable;
template <typename K,typename V>
class HNode
{
private:
	K _key;
	V _value;
	HNode<K, V> *next;
public:
	HNode() 
	{
		next = nullptr;
	}
	HNode(const K& key, const V& value) :_key(key), _value(value)
	{

	}
	void operator=(const V& value)
	{
	   
		_value = value;
	}
	~HNode()
	{
		delete next;
	}
	
	friend class Hashtable<K, V>;

};

template <typename K,typename V>
class Hashtable
{
private:
	HNode<K, V> **table;
	int capacity;
public:
	Hashtable(int size = 101)
	{
		capacity = size;
		table = new HNode<K, V>*[capacity];
		for (int i = 0; i < capacity; i++)
			table[i] = nullptr;

	}

	int hashfunc(const string& key)
	{
		int hashCode = 401;
		int len = key.length();
		for (int i = 0; i < len; i++)
			hashCode = ((hashCode << 4 )+ key[i]) % capacity;
		return hashCode;
	}
	int hashfunc(int key) // specialize only one member
	{
		return key % capacity;
	}
	void insert(const K& key, const V&val)
	{
		HNode<K, V> *tmp = new HNode<K, V>(key, val);
		int hashval = hashfunc(key);
		HNode<K, V> *curr = table[hashval];
		if (curr != nullptr)
		{
			if (curr->_key == key)
			{
				curr->_value = val;
				return;
			}
			tmp->next = curr;
		}
		table[hashval] = tmp;
	}
	const V& getVal(const K& key)
	{
		int hashval = hashfunc(key);
		HNode<K, V> *curr = table[hashval];
		while (curr != nullptr)
		{
			if (curr->_key == key)
			{
				return curr->_value;
			}
			curr = curr->next;
		}
		
		return curr->_value;
	}
	void remove(const K& key)
	{
		int hashVal = hashfunc(key);
		HNode<K, V> *curr = table[hashVal];
		if (curr->_key == key)
		{
			table[hashVal] = curr->next;
		}
		else
		{
			HNode<K, V> *prev = nullptr;
				while (curr != nullptr)
				{
					if (curr->_key == key)
					{
						prev->next = curr->next;
						delete curr;
						return;
					}
					prev = curr;
					curr = curr->next;
				}
		}
	}
	HNode<K,V>& operator[](const K& key)
	{
		HNode<K, V> *tmp = new HNode<K, V>();
		int hashval = hashfunc(key);
		HNode<K, V> *curr = table[hashval];
		if (curr != nullptr)
		{
			if (curr->_key == key)
				return *curr;
			tmp->next = curr;
		}
		tmp->_key = key;
		table[hashval] = tmp;
		return *tmp;
	}
	void printDict()
	{
		for (int i = 0; i < capacity; i++)
		{
			HNode<K, V> *curr = table[i];
			while (curr != nullptr)
			{
				cout << "{ " << curr->_key << "," << curr->_value << "}";
				curr = curr->next;
			}
		}
	}

};

int main()
{
	Hashtable<string, string>myTable(201);
	myTable["Kall"] = "sun";
	myTable.printDict();
	Hashtable<string,string> *table = new Hashtable<string,string>(201);
	(*table)["Kal"]= "Sundaram";
	table->insert("Kalyan", "Sundaram");
	table->insert("sen", "raja");
	table->insert("raja", "mani");
	table->insert("mee", "anand");
	table->insert("dhi", "raj");
	table->printDict();
	table->remove("Kalyan");
	cout << "...After removing..." << endl;
	table->printDict();
	Hashtable<int, int> *mtable = new Hashtable<int, int>(201);
	mtable->insert(10, 100);
	cout << table->getVal("mee") << endl;
	cout << mtable->getVal(10) << endl;

    std::cout << "Hello World!\n"; 
}
