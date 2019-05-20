all: fizzbuzz_gen fizzbuzz_testing

fizzbuzz_gen: fizzbuzz.o main.cpp
	g++ -std=gnu++11 -o fizzbuzz.o main.cpp -o fizzbuzz

fizzbuzz_testing: fizzbuzz.o fizzbuzz_tests.cpp
	g++ -std=gnu++11 fizzbuzz.o fizzbuzz_tests.cpp -o fizzbuzz_tests
  
fizzbuzz.o: fizzbuzz.cpp
  g++ -std=gnu++11 -c fizzbuzz.cpp
