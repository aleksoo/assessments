#include <assert.h>
#include <stdio.h>
#include <math.h>

/**
* Given a number, return the maximum number that could be formed with digits of the number given.
* For example: number = 7389, return 9873
*/
int form_the_largest_number(int number)
{
	int originalNumber = number, digitsNo = 0, biggestNumber = 0, power=0, singleDigit;

	while(number/=10){
		++digitsNo;
	}	

	number = originalNumber;
	
	for(singleDigit=9; singleDigit>=0; --singleDigit){
		number = originalNumber;
		for(number; number>0; number/=10){
			if(number%10 == singleDigit){
				biggestNumber += singleDigit*pow(10, digitsNo);
				--digitsNo;	
			}
		}
	}

	return biggestNumber;
}

void test_cases()
{
	int result = form_the_largest_number(213);
	assert(result == 321);

	result = form_the_largest_number(7389);
	assert(result == 9873);

	result = form_the_largest_number(63729);
	assert(result == 97632);

	result = form_the_largest_number(566797);
	assert(result == 977665);
}

int main()
{
	test_cases();
}

