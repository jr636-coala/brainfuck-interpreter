#include <iostream>
#include <stdio.h>
#include <string>
#include "brainfuck.h"


std::string loadFileToString(
		const std::string& filePath);

int main()
{
	Brainfuck b((char(*)())&std::getchar);
	std::cout << b.run(loadFileToString("../program1_shronked.bf")) << '\n';
	return 0;
}

std::string loadFileToString(
		const std::string& filePath)
{
	FILE* file = fopen(filePath.c_str(), "rb");
	if (!file) {
		return "";
	}
	std::fseek(file, 0, SEEK_END);
	long length = std::ftell(file);
	std::fseek(file, 0, SEEK_SET);
	length -= std::ftell(file);
	char* buffer = new char[static_cast<unsigned long>(length+1)];
	std::fread(buffer, 1, static_cast<unsigned long>(length), file);
	buffer[length] = '\0';
	std::string out(buffer);
	delete [] buffer;
	return out;
}
