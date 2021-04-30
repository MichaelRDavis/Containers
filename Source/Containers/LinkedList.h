#pragma once

template<class T>
class TLinkedList
{
public:
	TLinkedList();
	~TLinkedList();

	int32_t Num() const;

	void Clear();

	void InsertBefore(const T& Value);

	void InsertAfter(const T& Value);

private:
	int32_t NumElements;
};

template<class T>
void TLinkedList<T>::Clear()
{

}

template<class T>
int32_t TLinkedList<T>::Num() const
{
	return NumElements;
}

template<class T>
void TLinkedList<T>::InsertAfter(const T& Value)
{
	
}	

template<class T>
void TLinkedList<T>::InsertBefore(const T& Value)
{
	
}

template<class T>
TLinkedList<T>::~TLinkedList()
{
	
}

template<class T>
TLinkedList<T>::TLinkedList()
{
	
}

