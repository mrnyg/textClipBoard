#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

BOOL CopyToClipboard(const char* pszData, const int nDataLen);
std::string GetTextFromClipboard();
int main(){
	std::string getClipBoard = GetTextFromClipboard();
	std::cout << getClipBoard.c_str() << std::endl;
	getClipBoard.append("x");
	std::cout << CopyToClipboard(getClipBoard.c_str(), getClipBoard.length()) << std::endl;
	return 0;
}

BOOL CopyToClipboard(const char* pszData, const int nDataLen)
{
	//
	if (::OpenClipboard(NULL))
	{
		::EmptyClipboard();
		HGLOBAL clipbuffer;
		char *buffer;
		clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, nDataLen + 1);
		buffer = (char *)::GlobalLock(clipbuffer);
		strcpy(buffer, pszData);
		::GlobalUnlock(clipbuffer);
		::SetClipboardData(CF_TEXT, clipbuffer);
		::CloseClipboard();
		return TRUE;
	}
	return FALSE;
}

std::string GetTextFromClipboard()
{
	std::string retStr;
	//打开剪切板（占用）
	if (::OpenClipboard(NULL))
	{
		//获得剪贴板数据
		HGLOBAL hMem = GetClipboardData(CF_TEXT);
		if (NULL != hMem)
		{
			char* lpStr = (char*)::GlobalLock(hMem);
			if (NULL != lpStr)
			{
				retStr = lpStr;
				::GlobalUnlock(hMem);
			}
		}
		::CloseClipboard();
		return retStr;
	}
	return retStr;
}
