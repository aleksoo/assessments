#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
* Function duplicates letters based on their index. Each index means how many times the letter needs to be duplicated.
* See test cases for examples.
*/

char* accumulate(const char *word, const int length)
{
	if(length == 0)
		return "";
	int newLength = 0, counter = 0;

	for(int i = 1; i <= length; ++i){
		newLength+=i;		
	}
	newLength += length - 1;
	char* newString = (char*)malloc(newLength * sizeof(char) + 1);
	newString[newLength] = '\0';

	for(int i = 0; i < newLength; ++i){		
		for(int j = 0; j <= counter; ++j){
			if(j == 0) newString[i] = toupper(word[counter]);
			else newString[i] = tolower(word[counter]);
			++i;
		}
		++counter;
		if(i < newLength){
			newString[i] = '-';
		}		
	}	
	
	return newString;
}

void test_cases()
{
	char* result = accumulate("abcd", strlen("abcd"));
	assert(strcmp(result, "A-Bb-Ccc-Dddd") == 0);
	free(result);

	result = accumulate("cwAt", strlen("cwAt"));
	assert(strcmp(result, "C-Ww-Aaa-Tttt") == 0);
	free(result);

	result = accumulate("cw", strlen("cw"));
	assert(strcmp(result, "C-Ww") == 0);
	free(result);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
