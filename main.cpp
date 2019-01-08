#include "textClipBorad.h"
#include <iostream>

int main(){
	std::string getClipBoard = textClipBorad::GetTextFromClipboard();
	std::cout << getClipBoard.c_str() << std::endl;
	getClipBoard.append("x");
	std::cout << textClipBorad::CopyToClipboard(getClipBoard.c_str(), getClipBoard.length()) << std::endl;
	return 0;
}
