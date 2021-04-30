#pragma once

#include <cstdint>

class CString
{
public:
	CString();
	CString(const CString& Other);
	CString(const char* String);
	~CString();

private:
	int32_t Length;
	char* StringData;
};