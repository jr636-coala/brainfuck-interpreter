#include "brainfuck.h"

// debug
#include <iostream>

Brainfuck::Brainfuck(char (*getchar)()) {
	this->b.getchar = getchar;
	this->reset();
}

Brainfuck::~Brainfuck() {

}

void Brainfuck::reset() {
	this->b.cell.clear();
	this->b.cell.push_back(0);
	this->b.pointer = 0;
	this->b.output = "";
};

std::string Brainfuck::run(const std::string& program) {
	this->b.program = program;
	this->b.programIndex = 0;
	// Go through each character in the program
	while(this->b.programIndex < this->b.program.length()) {
		if(0){ //Debug
			for (int i = 8; i--;) {
				if (this->b.program[this->b.programIndex] == this->command[i].character) {
					std::cout << this->b.programIndex << " : " << this->b.program[this->b.programIndex] << " cell=>" << (int)this->b.cell[this->b.pointer] << '\n';
					std::getchar();
				}
			}
		}

		// For each of the commands
		for (int i = 8; i--;) {
			// Check whether this is the correct command
			if (this->b.program[this->b.programIndex] == this->command[i].character) {
				// Execute the command then break the for loop
				(*this->command[i].function)(this->b);
				break;
			}
		}

		this->b.programIndex++;
	}
	return this->b.output;
}
