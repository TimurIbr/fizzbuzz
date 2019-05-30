#include <regex>
#include <iostream>
#include <string>
#include "fizzbuzz.hpp"
/*const std:: string multiple_3_word = "FIZZ";
const std:: string multiple_5_word = "BUZZ";*/

/* this function checks if number (presented as string) is divisible by 5 or not */
#define this_function_name "int is_multiple_5 (std::string exam_string))"
int is_multiple_5 (std::string exam_string){ 
	if(exam_string.length() == 0){
		std::cerr << "function "<< this_function_name << " received empty exam_string" << std::endl;
		return -1;
	}
	int exam_digit, i;
	if( !(isdigit(exam_string[0]) || (exam_string[0] == '-'))){
		std::cerr << "function "<< this_function_name << " received not a number" << std::endl;
		return -1;
	}
  	for(i = 1; i < exam_string.length(); ++i){
    		if( !(isdigit(exam_string[i]))  ){
			std::cerr << "function "<< this_function_name << " received not a number" << std::endl;
      			return -1;
		}
  	}
	exam_digit = exam_string[exam_string.length() - 1] - '0';
	if((exam_digit == 0) || (exam_digit == 5))
		return 1;
	else 
		return 0;
	std::cerr << "something went wrong in function " << this_function_name << std::endl;
	return -1;
}
#undef this_function_name

#define this_function_name "int is_multiple_3 (std::string exam_string))"
/* this function checks if number (presented as string) is divisible by 3 or not */
int is_multiple_3 (std::string exam_string){ 
    int i;
	if(exam_string.length() == 0){
		std::cerr << "function "<< this_function_name << " received empty exam_string" << std::endl;
		return -1;
	}
  	if( !(isdigit(exam_string[0]) || (exam_string[0] == '-')) ){
		std::cerr << "function "<< this_function_name << " received not a number" << std::endl;
		return -1;
	}
  	for(i = 1; i < exam_string.length(); ++i){
    		if( !(isdigit(exam_string[i]))  ){
			std::cerr << "function "<< this_function_name << " received not a number" << std::endl;
      			return -1;
		}
  	}
	int exam_digit, digits_sum = 0;
	for(i = (exam_string[0] == '-' ? 1 : 0); i < exam_string.length(); ++i){
			for(exam_digit = exam_string[i] - '0';
		            exam_digit >= 3;
					exam_digit -= 3
					);
			digits_sum += exam_digit;
			digits_sum >= 3 ? digits_sum -= 3 : 1;
	}
	if(digits_sum == 0)
	    return 1;
	else
	    return 0;
	std::cerr << "something went wrong in function " << this_function_name << std::endl;
	return -1;
}
#undef this_function_name

/* this function  prints in  out_str  word, which should be outpoted in fizzbuzz instead of exam_str*/
#define this_function_name "void output_forming(std::string exam_str, std::string* out_str)"
void output_forming(std::string exam_str, std::string* out_str){
    if(out_str == NULL){
        std::cerr << "function "<< this_function_name << " received NULL as std::string* out_str, which is unexpected" << std::endl;
    }
    *out_str = "";
    if(is_multiple_3(exam_str))
        *out_str += multiple_3_word;
    if(is_multiple_5(exam_str))
        *out_str += multiple_5_word;
    if(out_str->length() == 0)
        *out_str = exam_str;
}
#undef this_function_name

/* this function  prints in  gen_out_str  changed word sequence, 
which was recived as  inp_str . Each word in the sequence will be changed by  output_forming  function.*/
#define this_function_name "void output_forming(std::string exam_str, std::string* out_str)"
void fizzbuzz_ing(std::string inp_str, std::string* gen_out_str){
	if(gen_out_str == NULL){
        	std::cerr << "function "<< this_function_name << " received NULL as std::string* gen_out_str, which is unexpected" << std::endl;
    	}
	std::string out_str, exam_str;
	std::smatch numbers;
	std::regex reg_not_numbers("([\\w]*[a-zA-Z]+[0-9]+[\\w]*|[\\w]*[0-9]+[a-zA-Z]+[\\w]*)"); 
	inp_str = std:: regex_replace(inp_str, reg_not_numbers, ""); //delites not numbers in inp_str (input of function)
	std::regex reg_numbers("(-?[0-9]+)"); 
	while(std:: regex_search(inp_str, numbers, reg_numbers)){ //searches numbers in inp_str (input of function)
	    exam_str = numbers[1];
	    output_forming(exam_str, &out_str);
	    inp_str = numbers.suffix().str();
	    *gen_out_str += out_str + "\n";
	}
}
#undef this_function_name
