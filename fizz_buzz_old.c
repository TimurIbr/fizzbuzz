#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int multiple_5_exam (char * exam_number){
	if(exam_number == NULL){
		return 0;
	}
	int exam_digit, i;
	for(i = strlen(exam_number) - 1; i >= 0; --i){
		if(isdigit(exam_number[i]))
			break;
	}
	exam_digit = exam_number[i] - '0';
	if((exam_digit == 0) || (exam_digit == 5))
		return 1;
	else 
		return 0;
	return 0;
}
int multiple_3_exam (char * exam_number){
	if(exam_number == NULL){
                return 0;
        }
	int exam_digit, digits_sum = 0, start_of_number = 0, end_of_number = 0;
	int i;
	for(i = 0; exam_number[i] != 0; ++i){
		if(isdigit(exam_number[i])){
			start_of_number = 1;
			if(end_of_number){
				perror("Not a natiral number");
				return -1;
			}
			for(exam_digit = exam_number[i] - '0';
					exam_digit >= 3;
					exam_digit -= 3);
			digits_sum += exam_digit;
			digits_sum >= 3 ? digits_sum -= 3 : 1;
		}
		else{
			if(start_of_number)
				end_of_number = 1;
		}
	}
	if((digits_sum == 0) && (start_of_number))
		return 1;
	return 0;
}

#define Max_of_numbers 20
#define Max_of_digits 50
#define Multiple_3_word "FIZZ"
#define Multiple_5_word "BUZ"

int main(int ac, char ** av){
	int i, j, is_written = 0, need_of_free = 0;
	char c;
	char output[20];
	output[0] = 0;
	//char numbers_list[Max_of_numbers][Max_of_digits];
	char** numbers_list;
	int numbers_list_size;
	if(ac > 1){
		numbers_list = av + 1;
		numbers_list_size = ac - 1;
	}
	else{
		need_of_free = 1;
		numbers_list = (char**)malloc(Max_of_numbers * sizeof(char*));
		i = 0;
		do
		{	numbers_list[i] = (char*)malloc(Max_of_digits);
    			scanf("%s%c", numbers_list[i], &c);
			++i;
		}while(c!='\n');
		numbers_list_size = i;
	}
//	printf("%d\n", numbers_list_size);
	for(i = 0; i < numbers_list_size; ++i){
		if(multiple_3_exam(numbers_list[i])){
			strcat(output, Multiple_3_word);
			is_written = 1;
		}
		if(multiple_5_exam(numbers_list[i])){
			strcat(output, Multiple_5_word);
			is_written = 1;
		}
		printf("%s\n", is_written ? output : numbers_list[i] );
		is_written = 0;
		output[0] = 0;
	}
	if(need_of_free){
		for(i = 0; i < numbers_list_size; ++i)
			free(numbers_list[i]);
		free(numbers_list);
	}
	return 0;
}
/*	for(i = 1; i <  ac; ++i){
		len = strlen(av[i]);
		strcpy(str, av[i]);
		if ((str[len - 1] == '5') || (str[len - 1] == '0')){
			printf("FIIZZ");
			is_written = 1;
		}
		for(j = 0; str[j] != 0; ++j){
			if(isalnum(str[j]) == 0)
				continue;
			for(;(str[j])>= '3'; str[j] = str[j] - 3);
			sum += str[j] - '0';
			sum >= 3 ? sum = sum - 3 : 1;
		//	printf("\nsum == %d \n", sum);
		}
		if(sum == 0){
			printf("BUZZ");
			is_written = 1;
		}
		sum = 0;
		if(is_written){
			is_written = 0;
		}else{
			printf(av[i]);
		}
		printf("\n");

	}*/
	/*for (i = 1; i < ac; ++i)
		printf(av[i]);*/

