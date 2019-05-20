all: fizzbuzz_gen fizzbuzz_testing

fizzbuzz_gen: fizzbuzz.o main.cpp
	g++ -std=c++14 -o fizzbuzz.o main.cpp -o fizzbuzz

fizzbuzz_testing: fizzbuzz.o fizzbuzz_tests.cpp
	g++ --std=c++14 fizzbuzz.o fizzbuzz_tests.cpp -o fizzbuzz_tests
  
fizzbuzz.o: fizzbuzz.cpp
  g++ -std=c++14 -c fizzbuzz.cpp
