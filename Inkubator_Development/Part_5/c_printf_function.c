#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

char *mr_asprintf(char * inputString, ...){
    va_list v1;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    va_start(v1, inputString);

    while(inputString && inputString[i]){

    }
}

void test_cases(){
    
}


int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
