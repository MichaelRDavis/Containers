#pragma once

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cassert>

/**
 * Standard stack allocated array with a fixed number of elements
 */
template<typename T, int32_t Elements>
class TArray
{
public:
	TArray();
	TArray(const TArray<T, Elements>& Other);
	~TArray();

	/** Returns an element at the specified index */
	T& At(int32_t Index);
	const T& At(int32_t Index) const;

	/** Allows for standard array indexing */
	T& operator[](int32_t Index);
	const T& operator[](int32_t Index) const;

	/** Returns the first element within the array */
	T& Front();
	const T& Front() const;

	/** Returns the last element within the array */
	T& Back();
	const T& Back() const;

	/** Returns a copy of the array */
	T* Data();
	const T* Data() const;

	/** Fill the array with a specified value */
	void Fill(const T& Value);

	/** Clears the array */
	void Clear();

	/** Returns true if the array is empty */
	bool IsEmpty() const;

	/** Returns the number of elements within the array */
	int32_t NumElements() const;

	/** Returns the maximum umber of elements within the array */
	int32_t MaxNumElements() const;

	/** Returns the size of the array in bytes */
	size_t ArraySize() const;

private:
	T ArrayPtr[Elements];
	int32_t Size;
};

template<typename T, int32_t Elements>
int32_t TArray<T, Elements>::MaxNumElements() const
{
	return Elements;
}

template<typename T, int32_t Elements>
void TArray<T, Elements>::Fill(const T& Value)
{
	
}

template<typename T, int32_t Elements>
size_t TArray<T, Elements>::ArraySize() const
{
	return Elements * sizeof(T);
}

template<typename T, int32_t Elements>
void TArray<T, Elements>::Clear()
{
	Size = 0;
}

template<typename T, int32_t Elements>
TArray<T, Elements>::TArray(const TArray<T, Elements>& Other)
{
	*this = Other;
}

template<typename T, int32_t Elements>
int32_t TArray<T, Elements>::NumElements() const
{
	return Size;
}

template<typename T, int32_t Elements>
bool TArray<T, Elements>::IsEmpty() const
{
	return Elements == 0;
}

template<typename T, int32_t Elements>
const T* TArray<T, Elements>::Data() const
{
	return ArrayPtr;
}

template<typename T, int32_t Elements>
T* TArray<T, Elements>::Data()
{
	return ArrayPtr;
}

template<typename T, int32_t Elements>
const T& TArray<T, Elements>::Back() const
{
	return ArrayPtr[Elements - 1];
}

template<typename T, int32_t Elements>
T& TArray<T, Elements>::Back()
{
	return ArrayPtr[Elements - 1];
}

template<typename T, int32_t Elements>
const T& TArray<T, Elements>::Front() const
{
	return ArrayPtr[0];
}

template<typename T, int32_t Elements>
T& TArray<T, Elements>::Front()
{
	return ArrayPtr[0];
}

template<typename T, int32_t Elements>
const T& TArray<T, Elements>::operator[](int32_t Index) const
{
	return ArrayPtr[Index];
}

template<typename T, int32_t Elements>
T& TArray<T, Elements>::operator[](int32_t Index)
{
	return ArrayPtr[Index];
}

template<typename T, int32_t Elements>
const T& TArray<T, Elements>::At(int32_t Index) const
{
	return ArrayPtr[Index];
}

template<typename T, int32_t Elements>
T& TArray<T, Elements>::At(int32_t Index)
{
	return ArrayPtr[Index];
}

template<typename T, int32_t Elements>
TArray<T, Elements>::~TArray()
{
	
}

template<typename T, int32_t Elements>
TArray<T, Elements>::TArray()
{
	Size = 0;
}
