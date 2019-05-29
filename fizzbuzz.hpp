#ifndef _fizzbuzz_
#define _fizzbuzz_
#include <regex>
#include <iostream>
#include <string>
const std:: string multiple_3_word = "FIZZ"; 
/* this word will replace divisible by 3 numbers in output*/
const std:: string multiple_5_word = "BUZZ"; 
/* this word will replace divisible by 5 numbers in output*/
int is_multiple_5 (std::string exam_string); 
/* this function checks if number (presented as string) is divisible by 5 or not */
/* returns 1 if number is divisible by 5, 0 if is not, -1 if error
exam_string is number, which is analysed by function*/
int is_multiple_3 (std::string exam_string); 
/* this function checks if number (presented as string) is divisible by 3 or not*/
/* returns 1 if number is divisible by 3, 0 if is not, -1 if error
exam_string is number, which is analysed by function*/
void output_forming(std::string exam_str, std::string* out_str); 
/* this function prints in  out_str  word, which should be outpoted in fizzbuzz instead of exam_str 
(in fact it might be exam_str)*/
/*std::string* out_str is pointer to output buffer, not NULL
std::string exam_str is number, which will be checked on divisiblity and printed into buffer, if it isn't divisible by 3 or 5*/
void fizzbuzz_ing(std::string inp_str, std::string* gen_out_str);
/* this function  prints in  gen_out_str  changed word sequence, 
which was recived as  inp_str . Each word in the sequence will be changed by  output_forming  function.*/
/*std::string* gen_out_str is pointer to output buffer, not NULL
std::string exam_str is sequence of numbers, which will be checked on divisiblity and printed into buffer, if they aren't divisible by 3 or 5*/

#endif
