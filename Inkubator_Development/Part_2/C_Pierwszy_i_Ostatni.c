#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lowest_and_highest(char *inputString){
	int interval[2];
	int returnInterval[2] = {-1, -1};
	int *days;
	char *token;
	char* tempString = (char*)malloc(strlen(inputString) * sizeof(char));
    strcpy(tempString, inputString);

	

	token = strtok(tempString, " ");
	interval[0] = strtol(token, NULL, 10);
	token = strtok(tempString, "\n");
	interval[1] = strtol(token, NULL, 10);
	
	

	//TO NA WPROWADZONE DNI
	// while(token != NULL){

	// 	token = strtok(tempString, " \n");
	// }

	//return &przedzial;
}

void test_cases(){
	char *inputString = NULL;
	int *answer;
	
	inputString = "7 3\n1 3 5 3 4 3";
	lowest_and_highest(inputString);
	// answer = lowest_and_highest(inputString);
    // assert( answer[0] == 2 && answer[1] == 7 );
}


int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
