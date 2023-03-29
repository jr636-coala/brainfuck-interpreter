#include <iostream>
#include "/usr/include/jlib/fileio.h"
#include "brainfuck.h"

int main()
{
	Brainfuck b((char(*)())&std::getchar);
	std::cout << b.run(JLib::FileIO::loadFileToString("../program1_shronked.bf")) << '\n';
	return 0;
}
