#include <regex>
#include <iostream>
#include <string>
#include "fizzbuzz.h"

int main(int ac, char ** av){
	int i;
	std::string inp_str, out_str;
	getline(std::cin, inp_str, '\n');
	fizzbuzz_ing(inp_str, &out_str);
	std::cout << out_str << std::endl;
	return 0;
}
