#pragma once
#include <string>
#include "TMemory.cpp"

template <typename T>
class TMemory
{
private:
	T _FNumber;
	bool _FState;
public:
	TMemory();
	TMemory(const T &FNumber);
	~TMemory();

	void store(const T &FNumber);
	void add(const T &FNumber);
	void clear();
	T getFNumber();
	bool getFState();
	std::string readFState();
	std::string readFNumber();
};


template<typename T>
TMemory<T>::TMemory(const T &FNumber)
{
	_FNumber = FNumber;
	_FState = true;
}

template<typename T>
TMemory<T>::TMemory() : _FNumber(T()), _FState(false)
{
}

template<typename T>
TMemory<T>::~TMemory()
{
}

template<typename T>
void TMemory<T>::store(const T &FNumber)
{
	_FNumber = FNumber;
	_FState = true;
}

template<typename T>
void TMemory<T>::add(const T &FNumber)
{
	if (!_FState)
	{
		_FNumber = FNumber;
		_FState = true;
	}
	else
	{
		_FNumber += FNumber;
	}
}

template<typename T>
void TMemory<T>::clear()
{
	_FNumber = T();
	_FState = false;
}

template<typename T>
T TMemory<T>::getFNumber()
{
	return _FNumber;
}

template<typename T>
bool TMemory<T>::getFState()
{
	return _FState;
}

template<typename T>
std::string TMemory<T>::readFState()
{
	if (_FState)
		return std::string("_On");
	else
		return std::string("_Off");
}

/*
template<typename T>
std::string TMemory<T>::readFNumber()
{

	return ;
}*/

