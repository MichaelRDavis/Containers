#include "Containers/Array.h"
#include "Containers/DynamicArray.h"
#include "Containers/LinkedList.h"
#include "Containers/Stack.h"
#include <iostream>

int main()
{
	TArray<int32_t, 5> MyArray;
	MyArray.Fill(0);

	for (int32_t i = 0; i < MyArray.MaxNumElements(); i++)
	{
		MyArray[i] = i;
	}

	std::cout << MyArray.At(0) << std::endl;
	std::cout << MyArray.At(4) << std::endl;

	std::cout << MyArray.Front() << std::endl;
	std::cout << MyArray.Back() << std::endl;

	std::cout << MyArray.Data() << std::endl;

	TDynamicArray<int32_t> MyDynamicArray;
	MyDynamicArray.AddElement(0);
	MyDynamicArray.AddElement(1);
	MyDynamicArray.AddElement(2);
	MyDynamicArray.AddElement(3);
	MyDynamicArray.AddElement(4);

	MyDynamicArray.RemoveElement(2);

	for (int32_t i = 0; i < MyDynamicArray.GetSize(); i++)
	{
		std::cout << MyDynamicArray[i] << std::endl;
	}

	TLinkedList<int32_t> MyLinkedList;
	MyLinkedList.InsertBefore(5);
	MyLinkedList.InsertAfter(0);

	TStack<int32_t> MyStack;
	MyStack.Add(5);

	return 0;
}