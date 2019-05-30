#include <cassert>
#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include "fizzbuzz.hpp"
// # == FIZZ; @ == BUZZ; #@ == FIZZBUZZ
void tests_legeda(std::string* test_case_answer){
	try {
    	std::regex reg_into_endl ("[\\s]");
    	std::regex reg_into_FIZZ ("(#)");
    	std::regex reg_into_BUZZ ("(@)");
        *test_case_answer = std::regex_replace (*test_case_answer, reg_into_FIZZ, std::string(multiple_3_word) );
	*test_case_answer = std::regex_replace (*test_case_answer, reg_into_BUZZ, std::string(multiple_5_word) );
	*test_case_answer = std::regex_replace (*test_case_answer, reg_into_endl, std::string("\n") );
    	}
	catch (const std::regex_error& re) {
        std::cout << "regex_error caught: " << re.what() << std::endl;
    	}
    
}
const int num_of_cases = 5;
std::string def_test_case[num_of_cases] = {"-1       90",
                                            "1 -2 3 -4 -5 6 7 8 -9 10",
                                            "12 25 -37 49 56 -90",
                                            "12345689 123456789 123456890 1234567890 ",
                                            "999999999999999999999999999999999999999"
                                            };
std::string def_test_case_answer[num_of_cases] = {"-1 #@ ",
                                            "1 -2 # -4 @ # 7 8 # @ ",
                                            "# @ -37 49 56 #@ ",
                                            "12345689 # @ #@ ",
                                            "# "
                                            };
/*def_test_case[0] = "-1       90";
def_test_case_answer[0] = "-1 #@ ";
def_test_case[1] = "1 -2 3 4 -5 6 7 8 -9 10";
def_test_case_answer[1] = "1 -2 # 4 @ # 7 8 # @ ";
def_test_case[2] = "12 25 -37 49 56 -90";
def_test_case_answer[2] = "# @ -37 49 56 #@ ";
def_test_case[3] = "12345689 123456789 123456890 1234567890 ";
def_test_case_answer[3] = "12345689 # @ #@ ";
def_test_case[4] = "999999999999999999999999999999999999999";
def_test_case_answer[4] = "# ";
*/
int main (int ac, char **av){
    int i;
    int is_default_test_using = 0;
    std::ifstream tests_inp;
    std::ifstream tests_answer_inp;
    std::ofstream tests_log;
    tests_log.open ("tests_log.txt");
    if (!tests_log.is_open ())
	    std::cerr << "No logfiles" << std::endl;
    tests_inp.open ("fizzbuzz_tests.txt");
    tests_answer_inp.open ("fizzbuzz_test_answers.txt");
    if(!tests_inp.is_open()){
        std::cout << "no input file named " << "fizzbuzz_tests.txt" << std::endl << "default tests used" << std::endl;
        is_default_test_using = 1;
    }
    if(!tests_answer_inp.is_open()){
        std::cout << "no answers input file named " << "fizzbuzz_test_answers.txt" << std::endl << "default tests used" << std::endl;
        is_default_test_using = 1;
    }
    std::string test_case;
    std::string test_case_answer;
    std::string test_case_out;
    for( i = 0; getline(tests_inp, test_case) && getline(tests_answer_inp, test_case_answer) || is_default_test_using; ++i){
        if(is_default_test_using){
            if(i >= num_of_cases)
                break;
            test_case = def_test_case[i];
            test_case_answer = def_test_case_answer[i];
        }
        test_case_out = "";
        tests_legeda(&test_case_answer);
	tests_log << "\tcase # " << i << std::endl;
	try {
		fizzbuzz_ing (test_case, &test_case_out);
	}
	catch (const std::regex_error& re) {
       		std::cout << "regex_error caught in fizzbuzz: " << re.what() << std::endl;
    }
	    
	    tests_log << "\tcase input:\n" << test_case << std::endl;
	    tests_log << "\texpecting answer:\n" << test_case_answer << std::endl;
	    tests_log << "\tprogram out:\n" << test_case_out << std::endl;
	    assert ((test_case_answer == test_case_out) && "FIZZBUZZ fault: see ./tests_log.txt");
	    tests_log << "\tcase # " << i << " Succed" << std::endl;
	    //std::cout << test_case_out[i] << "\n";
    }
    tests_log << "\tALL tests Succed" << std::endl;
    if(tests_inp.is_open())
        tests_inp.close();
    if(tests_answer_inp.is_open())
        tests_answer_inp.close();
    tests_log.close();
    return 0;
}
