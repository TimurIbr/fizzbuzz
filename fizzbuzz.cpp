#include <regex>
#include <iostream>
#include <string>
const std:: string multiple_3_word = "FIZZ";
const std:: string multiple_5_word = "BUZZ";
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
  for(int i = 0; i < exam_string.length(); ++i){
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

void output_forming(std::string exam_str, std::string* out_str){
    *out_str = "";
    if(is_multiple_3(exam_str))
        *out_str += multiple_3_word;
    if(is_multiple_5(exam_str))
        *out_str += multiple_5_word;
	if(out_str->length() == 0)
        *out_str = exam_str;
}

int main(int ac, char ** av){
	int i;
	std::string inp_str, out_str, exam_str;
	getline(std::cin, inp_str, '\n');
	std::smatch numbers;
	std::regex reg_not_numbers("([\\w]*[a-zA-Z]+[0-9]+[\\w]*|[\\w]*[0-9]+[a-zA-Z]+[\\w]*)"); 
	inp_str = std:: regex_replace(inp_str, reg_not_numbers, "");
	std::regex reg_numbers("([0-9]+)"); 
	while(std:: regex_search(inp_str, numbers, reg_numbers)){
	    exam_str = numbers[1];
	    output_forming(exam_str, &out_str);
	    std::cout << out_str << std::endl;
	    inp_str = numbers.suffix().str();
	}
	return 0;
}
