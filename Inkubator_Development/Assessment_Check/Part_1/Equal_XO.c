#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "stdbool.h"

/**
* Function checks if a string has the same amount of 'x' and 'o's. Function must be case insensitive.
*/
bool XO(const char *word, const int length)
{
	int i = 0, xCount = 0, oCount = 0;

	// Iterujemy po otrzymanym slowie
	for(i=0; i<length; ++i){
		// Jezeli X lub O wystepuje, to zwiekszamy liczniki
		if(word[i]=='x' || word[i]=='X') xCount++;
		if(word[i]=='o' || word[i]=='O') oCount++;
	}

	if(xCount == oCount) return true;
	else return false;

}

void test_cases()
{
	bool answer = XO("ooxx", strlen("ooxx"));
	assert(answer == true);

	answer = XO("xooxx", strlen("xooxx"));
	assert(answer == false);

	answer = XO("ooxXm", strlen("ooxXm"));
	assert(answer == true);

	answer = XO("zzoo", strlen("zzoo"));
	assert(answer == false);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
