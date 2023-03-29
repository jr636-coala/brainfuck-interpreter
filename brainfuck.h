#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <string>
#include <vector>

class Brainfuck {
public:
	Brainfuck(char (*getchar)());
	~Brainfuck();
	void reset();
	std::string run(const std::string& program);

	Brainfuck(const Brainfuck&) = delete;
private:


	struct BF {
		std::vector<char> cell;
		char (*getchar)();
		int pointer;
		std::string program;
		int programIndex;
		std::string output;
	}b;

	const struct {
		char character;
		void(*function)(BF&);
	}command[8] = {
		{'>', [](BF& b){b.pointer++; if(b.pointer == b.cell.size()) b.cell.push_back(0);}},

		{'<', [](BF& b){b.pointer--; if (b.pointer < 0) b.pointer = 0;}},

		{'+', [](BF& b){b.cell[b.pointer]++;}},

		{'-', [](BF& b){b.cell[b.pointer]--;}},

		{'.', [](BF& b){b.output += b.cell[b.pointer];}},

		{',', [](BF& b){b.cell[b.pointer] = (*b.getchar)();}},

		{'[', [](BF& b){if(!b.cell[b.pointer]){int i,k=b.programIndex;i=k;do i=b.program.find(']',i)+1,k=b.program.find('[',k+1);while(k<i&&k!=-1);b.programIndex=i-1;}}},

		{']', [](BF& b){int i,k=b.programIndex;i=k;do i=b.program.rfind(']',i-1),k=b.program.rfind('[',k);while(k--<i);b.programIndex=k;}}
	};
};

#endif // BRAINFUCK_H
