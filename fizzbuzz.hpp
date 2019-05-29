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
int is_multiple_3 (std::string exam_string); 
/* this function checks if number (presented as string) is divisible by 3 or not*/
void output_forming(std::string exam_str, std::string* out_str); 
/* this function prints in  out_str  word, which should be outpoted in fizzbuzz instead of exam_str 
(in fact it might be exam_str)*/
void fizzbuzz_ing(std::string inp_str, std::string* gen_out_str);
/* this function  prints in  gen_out_str  changed word sequence, 
which was recived as  inp_str . Each word in the sequence will be changed by  output_forming  function.*/

#endif
