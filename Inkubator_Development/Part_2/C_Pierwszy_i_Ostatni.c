#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int* lowest_and_highest(const char *inputString){
	bool flag = true;
	int days, counter = 0;
	long price;	
	long *valueOfTheDay = NULL;
	long* votd = NULL;
	int daysInterval[2] = {-1, -1};
	//daysInterval[0] = -1;
	//daysInterval[1] = -1;
	char *token = NULL;
	char *tempString = (char*)malloc( (strlen(inputString) + 1) * sizeof(char) );
    strcpy(tempString, inputString);

	token = strtok(tempString, " \n");
	days = strtol(token, NULL, 10);
	if( days < 1 || days > 100000 )
		return daysInterval;

	token = strtok(NULL, " \n");
	price = strtol(token, NULL, 10);	
	if( price < 1 || price > 1000000000 )
		return daysInterval;

	token = strtok(NULL, " \n");
	valueOfTheDay = (long*)malloc( days * sizeof(long)) ;
	while(token != NULL){					
		*(valueOfTheDay + counter) = strtol(token, NULL, 10);
		++counter;	
		token = strtok(NULL, " \n");
	}
	
	for(int i = 0; i < counter; ++i){
		if( *(valueOfTheDay + i) == price ){
			daysInterval[1] = i + 1;
			if(flag){
				daysInterval[0] = i + 1;
				flag = false;
			}			
		}			
	}

	free(valueOfTheDay);
	free(token);
	free(tempString);
	return daysInterval;
}

void test_cases(){
	int *answer = NULL;

	answer = lowest_and_highest("0 3\n1 3 5 2 3 4 3");
	assert( answer[0] == -1 && answer[1] == -1 );

	answer = lowest_and_highest("7 3\n1 3 5 2 3 4 3");
    assert( answer[0] == 2 && answer[1] == 7 );

	answer = lowest_and_highest("17 3\n1 3 5 2 3 4 3 4 1 6 8 3 8 3 5 1 7");
    assert( answer[0] == 2 && answer[1] == 14 );

	answer = lowest_and_highest("4 2\n2 3 4 5");	
    assert( answer[0] == 1 && answer[1] == 1 );

	answer = lowest_and_highest("3 2\n5 3 1");
    assert( answer[0] == -1 && answer[1] == -1 );

}


int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
