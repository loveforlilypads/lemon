////////////////////////////////////////////////////////////////////////////////
// Lemon Example Two: Test Suites
//
// Time-stamp: <Last modified 2010-02-23 03:28:02 by Eric Scrivner>
//
// Description:
//   Provides a set of unit-tests using Lemon to showcase a method for test
// suites.
////////////////////////////////////////////////////////////////////////////////
#include "../lemon.h"

////////////////////////////////////////////////////////////////////////////////
// Function: factorial
//
// Computes the factorial of the given number
int factorial(int n) {
	if (n < 2) return 1;

	int result = 1;
	while (n > 1) {
		result *= n;
		--n;
	}

	return result;
}

////////////////////////////////////////////////////////////////////////////////
// Function: is_prime
//
// Uses the Sieve of Eratosthenes to determine if the given number is prime.
bool is_prime(int n) {
	if (n < 2) return false;

	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
// Function: factorial_test_suite
//
// Returns the result of running all factorial tests
bool factorial_test_suite() {
	Lemon lemon(5);

	// Test 1: The factorial function handles negative numbers as expected
	lemon.is(factorial(-5), 1, "(-5)! = 1");

	// Test 2: Factorial of zero is one
	lemon.is(factorial(0), 1, "0! = 1");

	// Test 3: Factorial of one is one
	lemon.is(factorial(1), 1, "1! = 1");

	// Test 4: Factorial of 2 is 2
	lemon.is(factorial(2), 2, "2! = 2");

	// Test 5: Factorial of 5 is 120
	lemon.is(factorial(5), 120, "5! = 120");

	return lemon.end();
}

////////////////////////////////////////////////////////////////////////////////
// Function: is_prime_test_suite
//
// Returns the result of running all is_prime tests
bool is_prime_test_suite() {
	Lemon lemon(7);

	lemon.not_ok(is_prime(-5), "Negative numbers are not prime.");

	lemon.not_ok(is_prime(0), "Zero is not prime.");

	lemon.not_ok(is_prime(1), "One is not prime.");

	lemon.ok(is_prime(2), "Two is prime.");

	lemon.ok(is_prime(3), "Three is prime.");

	lemon.not_ok(is_prime(9), "Nine is not prime.");

	lemon.ok(is_prime(113), "113 is prime.");

	return lemon.end();
}

int main(int argc, char* argv[]) {
	Lemon lemon(2);

	lemon.diag("Factorial Suite");
	lemon.ok(factorial_test_suite(), "Factorial test suite passes");

	lemon.diag("IsPrime Suite");
	lemon.ok(is_prime_test_suite(), "IsPrime test suite passes");

	lemon.end();

	return 0;
}