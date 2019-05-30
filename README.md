# fizzbuzz
DESCRIPTION

This is a task from class.

Task: 

	1. Read a number sequance.
	2. Write the sequance withe the following changes:
		a) If the number is dividable by 3 - write FIZZ instead.
		b) If the number is dividable by 5 - write BUZZ instead.
		c) If the number is dividable by 3 and 5 - write FIZZBUZZ instead.
		d) Otherwise write the number itself.
	3. Also it is forbidden to use division operation and operation of receiving the remainder.

TO BUILD

make -- builds program fizzbuzz and fizzbuzz_tests

USAGE
	fizzbuzz:
fizzbuzz takes number sequence from console input.
	fizzbuzz_tests:
fizzbuzz_tests reads testing number sequence from fizzbuzz_tests.txt and 
checks results with fizzbuzz_test_answers.txt, errors are printed in tests_log.txt .
fizzbuzz_test_answers.txt should printed by tester.
If there is no fizzbuzz_tests.txt default tests will be used insted.

