#include <regex>
#include <iostream>
#include <string>
int is_multiple_5 (std::string exam_string){
	if(exam_string.length() == 0){
		return -1;
	}
	int exam_digit, i;
  for(i = 0; i < exam_string.length(); ++i){
    if( !isdigit(exam_string[i]))
      return -1;
  }
	exam_digit = exam_string[exam_string.length() - 1] - '0';
	if((exam_digit == 0) || (exam_digit == 5))
		return 1;
	else 
		return 0;
	return -1;
}
int is_multiple_3 (std::string exam_string){
	if(exam_string.length() == 0){
		return -1;
	}
  for(i = 0; i < exam_string.length(); ++i){
    if( !isdigit(exam_string[i]))
      return -1;
  }
	int exam_digit, digits_sum = 0;
	int i;
	for(i = 0; i < exam_string.length(); ++i){
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
	return -1;
}

int main(int ac, char ** av){
    const std:: string multiple_3_word = "FIZZ";
    const std:: string multiple_5_word = "BUZZ";
	int i;
	std::string inp_str, out_str, exam_str;
	getline(std::cin, inp_str, '\n');
	std::smatch numbers;
	std::regex reg("([0-9]+)"); 
	std:: regex_search(inp_str, numbers, reg);
	while(std:: regex_search(inp_str, numbers, reg)){
	    out_str = "";
	    exam_str = numbers[1];
	    if(is_multiple_3(exam_str))
	        out_str += multiple_3_word;
	    if(is_multiple_5(exam_str))
	        out_str += multiple_5_word;
	    if(out_str.length() == 0)
	        out_str = exam_str;
	    std::cout << out_str << std::endl;
	    inp_str = numbers.suffix().str();
	}
	return 0;
}
