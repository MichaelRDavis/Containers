#pragma once

class CAllocator
{
public:
	CAllocator()
	{

	}

	~CAllocator()
	{

	}

	virtual void* Allocate(size_t Size) = 0;
};