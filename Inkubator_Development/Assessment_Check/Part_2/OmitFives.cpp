#include <assert.h>
#include <iostream>

/**
* Function takes a 'start' and 'end' number of a range, and should return the count of all numbers except numbers with 5 in it.
* For example: start = 4, end = 8. It should return 4, because: 4, 6, 7, 8
*/
int numbers_without_five(int start, int end)
{
	int counter = 0; 
	for(int i = start; i <= end; ++i){
		int temp = i, flag = 1;

		do{
			if(temp % 10 == 5){
				flag = 0;
				break;
			}
		} while(temp /= 10);
		
		if(flag)
			counter++;
	}
	return counter;
}

void test_cases()
{
	int answer = numbers_without_five(4, 8);
	assert(answer == 4);

	answer = numbers_without_five(1, 9);
	assert(answer == 8);

	answer = numbers_without_five(4, 17);
	assert(answer == 12);

	answer = numbers_without_five(34, 55);
	assert(answer == 14);

	answer = numbers_without_five(34, 55);
	assert(answer == 14);

}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
