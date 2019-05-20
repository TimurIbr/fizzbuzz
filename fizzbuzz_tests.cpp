#include <cassert>
#include <regex>
#include <iostream>
#include <string>
#include "fizzbuzz.h"
// # == FIZZ; @ == BUZZ; #@ == FIZZBUZZ
int main(int ac, char ** av){
	int i;
	const int num_of_cases = 5;
  std::string test_case[num_of_cases];
  std::string test_case_out[num_of_cases];
  std::string test_case_answer[num_of_cases];
  test_case[0] = "1       90";
  test_case_answer[0] = "1 #@ ";
  test_case[1] = "1 2 3 4 5 6 7 8 9 10";
  test_case_answer[1] = "1 2 # 4 @ # 7 8 # @ ";
  test_case[2] = "12 25 37 49 56 90";
  test_case_answer[2] = "# @ 37 49 56 #@ ";
  test_case[3] = "12345689 123456789 123456890 1234567890 ";
  test_case_answer[3] = "12345689 # @ #@ ";
  test_case[4] = "999999999999999999999999999999999999999";
  test_case_answer[4] = "# ";
	std::regex reg_into_andl_ ("[\\s]");
	std::regex reg_into_FIZZ ("(#)");
	std::regex reg_into_BUZZ ("(@)");
	for(i = 0; i < num_of_cases; ++i){
	   test_case_out[i] = "";
	   test_case_answer[i] = std:: regex_replace(test_case_answer[i], reg_into_FIZZ, multiple_3_word);
	   test_case_answer[i] = std:: regex_replace(test_case_answer[i], reg_into_BUZZ, multiple_5_word);
	   test_case_answer[i] = std:: regex_replace(test_case_answer[i], reg_into_endl, "\n");
	}
	for(i = 0; i < num_of_cases; ++i){
	   fizzbuzz_ing(test_case[i], test_case_out + i);
	   assert((test_case_answer[i] == test_case_out[i]) && "FIZZBUZZ fault") ;
	}
	return 0;
}
