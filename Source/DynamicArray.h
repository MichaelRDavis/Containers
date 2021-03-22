#pragma once

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>

constexpr int32_t DEFAULT_SIZE{10};
constexpr int32_t GROWTH_FACTOR{10};

template<typename T>
class TDynamicArray
{
public:
	TDynamicArray();
	TDynamicArray(const TDynamicArray<T>& Other);
	~TDynamicArray();

	T& operator[](int32_t Index);
	const T& operator[](int32_t Index) const;

	T& Front();
	const T& Front() const;

	T& Back();
	const T& Back() const;

	T* GetData();
	const T* GetData() const;

	bool IsEmpty() const;
	int32_t GetMaxSize() const;
	int32_t GetSize() const;

	void Clear();

	void Insert(const T& Value, int32_t Index);

	void AddElement(const T& Value);
	void AddElement(const T&& Value);

	void RemoveElement(const T& Value);
	void RemoveElement(const T&& Value);

	void RemoveAt(int32_t Index);

	int32_t Find(const T& Value, int32_t Index);

	void Resize(int32_t NewSize);

private:
	T* ArrayPtr;
	int32_t Size;
	int32_t NumElements;
};

template<typename T>
int32_t TDynamicArray<T>::GetSize() const
{
	return NumElements;
}

template<typename T>
void TDynamicArray<T>::Resize(int32_t NewSize)
{
	T* TempArray;
	int32_t Index;

	TempArray = ArrayPtr;
	Size = Index;
}

template<typename T>
int32_t TDynamicArray<T>::Find(const T& Value, int32_t Index)
{
	for (int32_t i = 0; i < NumElements; i++)
	{
		if (ArrayPtr[i] == Value)
		{
			return i;
		}
	}

	return -1;
}

template<typename T>
void TDynamicArray<T>::RemoveAt(int32_t Index)
{
	if (Index < 0 || Index >= 0)
	{
		return;
	}

	if (Index >= 0)
	{
		NumElements--;
		for (int32_t i = Index; i < NumElements; i++)
		{
			ArrayPtr[i] = ArrayPtr[i + 1];
		}
	}
}

template<typename T>
void TDynamicArray<T>::RemoveElement(const T&& Value)
{
	int32_t Index = Find(Value);
	if (Index >= 0)
	{
		NumElements--;
		for (int32_t i = Index; i < NumElements; i++)
		{
			ArrayPtr[i] = ArrayPtr[i + 1];
		}
	}
}

template<typename T>
void TDynamicArray<T>::RemoveElement(const T& Value)
{
	int32_t Index = Find(Value);
	if (Index >= 0)
	{
		NumElements--;
		for (int32_t i = Index; i < NumElements; i++)
		{
			ArrayPtr[i] = ArrayPtr[i + 1];
		}
	}
}

template<typename T>
void TDynamicArray<T>::AddElement(const T&& Value)
{
	if (NumElements == Size)
	{
		Size += GROWTH_FACTOR;
		T* NewArray = reinterpret_cast<T*>(realloc(ArrayPtr, Size * sizeof(ArrayPtr)));
		ArrayPtr = NewArray;
	}

	ArrayPtr[NumElements] = Value;
	NumElements++;
}

template<typename T>
void TDynamicArray<T>::AddElement(const T& Value)
{
	if (NumElements == Size)
	{
		Size += GROWTH_FACTOR;
		T* NewArray = reinterpret_cast<T*>(realloc(ArrayPtr, Size * sizeof(ArrayPtr)));
		ArrayPtr = NewArray;
	}

	ArrayPtr[NumElements] = Value;
	NumElements++;
}

template<typename T>
void TDynamicArray<T>::Insert(const T& Value, int32_t Index)
{
	ArrayPtr[Index] = Value;
}

template<typename T>
void TDynamicArray<T>::Clear()
{
	for (int32_t i = 0; i < NumElements; i++)
	{
		ArrayPtr[i].~T();
	}

	free(ArrayPtr);
	ArrayPtr = nullptr;
	Size = 0;
	NumElements = 0;
}

template<typename T>
int32_t TDynamicArray<T>::GetMaxSize() const
{
	return Size;
}

template<typename T>
bool TDynamicArray<T>::IsEmpty() const
{
	return NumElements <= 0;
}

template<typename T>
const T* TDynamicArray<T>::GetData() const
{
	return ArrayPtr;
}

template<typename T>
T* TDynamicArray<T>::GetData()
{
	return ArrayPtr;
}

template<typename T>
const T& TDynamicArray<T>::Back() const
{
	return ArrayPtr[NumElements - 1];
}

template<typename T>
T& TDynamicArray<T>::Back()
{
	return ArrayPtr[NumElements - 1];
}

template<typename T>
const T& TDynamicArray<T>::Front() const
{
	return ArrayPtr[NumElements];
}

template<typename T>
T& TDynamicArray<T>::Front()
{
	return ArrayPtr[NumElements];
}

template<typename T>
const T& TDynamicArray<T>::operator[](int32_t Index) const
{
	return ArrayPtr[Index];
}

template<typename T>
T& TDynamicArray<T>::operator[](int32_t Index)
{
	return ArrayPtr[Index];
}

template<typename T>
TDynamicArray<T>::TDynamicArray(const TDynamicArray<T>& Other)
{
	ArrayPtr = nullptr;
	*this = Other;
}

template<typename T>
TDynamicArray<T>::TDynamicArray()
{
	Size = DEFAULT_SIZE;
	NumElements = 0;
	ArrayPtr = reinterpret_cast<T*>(malloc(NumElements * sizeof(ArrayPtr)));
	memset(ArrayPtr, 0, NumElements * sizeof(ArrayPtr));
}

template<typename T>
TDynamicArray<T>::~TDynamicArray()
{
	ArrayPtr = nullptr;
	NumElements = 0;
	Size = 0;
}