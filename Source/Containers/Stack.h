#pragma once

#include <cstdint>

template<typename T>
class TStack
{
public:
	TStack()
	{
		StackArray = reinterpret_cast<T*>(malloc(NumElements * sizeof(StackArray)));
		StackTop = -1;
		StackSize = DEFAULT_SIZE;
		NumElements = 0;
	}

	~TStack()
	{
		free(StackArray);
	}

	/**	Inserts an elements to the top of the stack */
	void Add(const T& Element)
	{
		if (NumElements == StackSize)
		{
			// TODO: Reallocate the stack
		}

		StackArray[++StackTop] = Element;
		NumElements++;
	}

	/**	Inserts an elements to the top of the stack */
	void Add(T&& Element)
	{
		if (NumElements == StackSize)
		{
			// TODO: Reallocate the stack
		}

		StackArray[++StackTop] = Element;
		NumElements++;
	}

	/** Returns a reference to the top most element in the stack */
	T& Top()
	{
		if (!IsEmpty())
		{
			return StackArray[StackTop];
		}

		return nullptr;
	}

	/** Returns a reference to the top most element in the stack */
	const T& Top() const
	{
		if (!IsEmpty())
		{
			return StackArray[StackTop];
		}

		return nullptr;
	}

	/** Returns true if the stack is empty */
	bool IsEmpty() const
	{
		return NumElements == 0;
	}

	/** Returns the number of elements in the stack */
	int32_t Num() const
	{
		return NumElements;
	}

private:
	T* StackArray;
	int32_t StackTop;
	int32_t StackSize;
	int32_t NumElements;

	const int32_t DEFAULT_SIZE{ 10 };
	const int32_t GROWTH_FACTOR{ 10 };
};