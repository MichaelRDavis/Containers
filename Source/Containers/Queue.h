#pragma once

template<typename T>
class TQueue
{
public:
	TQueue();
	~TQueue();

private:
	T* ArrayPtr;
};