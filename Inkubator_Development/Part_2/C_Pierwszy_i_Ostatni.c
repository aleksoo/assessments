#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int* lowest_and_highest(char *inputString){
	bool flag = true;
	int days;
	long price;
	static int daysInterval[2] = {-1, -1};
	long *valueOfTheDay;
	int size = 0;
	char *token;
	char *tempString = (char*)malloc(strlen(inputString) * sizeof(char));
    strcpy(tempString, inputString);

	token = strtok(tempString, " \n");
	days = strtol(token, NULL, 10);
	if( days < 1 || days > 100000 )
		return daysInterval;

	token = strtok(NULL, "\n");
	price = strtol(token, NULL, 10);	
	if( price < 1 || price > 1000000000 )
		return daysInterval;

	token = strtok(NULL, " \n");
	while(token != NULL){		
		++size;
		if(size <= days){
			valueOfTheDay = realloc(valueOfTheDay, size * sizeof(long));
			*(valueOfTheDay + size - 1) = strtol(token, NULL, 10); // Subtracting 1 to keep index of int array correct.		
		}
		token = strtok(NULL, " \n");
	}

	// PRZEITEROWAC PRZEZ DAYS
	for(int i = 0; i < size; ++i){
		if(*(valueOfTheDay + i) == price){
			printf("codochuja %ld %ld\n", *(valueOfTheDay + i), price);
			daysInterval[1] = i + 1; // Added 1 to get correct day.
			if(flag){
				daysInterval[0] = i + 1;
				flag = false;
			}			
		}			
	}

	free(token);
	free(tempString);
	return daysInterval;
}

void test_cases(){
	char *inputString = NULL;
	int *answer = malloc( 2 * sizeof(int));

	inputString = "0 3\n1 3 5 2 3 4 3";
	answer = lowest_and_highest(inputString);
	assert( answer[0] == -1 && answer[1] == -1 );
	
	inputString = "7 3\n1 3 5 2 3 4 3";
	answer = lowest_and_highest(inputString);
	//printf("%d %d\n", answer[0], answer[1]);
    assert( answer[0] == 2 && answer[1] == 7 );

	inputString = "4 2\n 2 3 4 5";
	answer = lowest_and_highest(inputString);
	//printf("%d %d\n", answer[0], answer[1]);
    assert( answer[0] == 1 && answer[1] == 1 );

	inputString = "3 2\n 5 3 1";
	answer = lowest_and_highest(inputString);
	printf("%d %d\n", answer[0], answer[1]);
    assert( answer[0] == -1 && answer[1] == -1 );

	free(inputString);
	free(answer);
}


int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
