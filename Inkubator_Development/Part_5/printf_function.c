#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h> // va_list, va_start, va_end

char *mr_asprintf(const char* inputString, ...){
    va_list args;
    va_start(args, inputString);
    int i = 0, j = 0, k = 0;
    char buff[100] = {0}, tmp[20];
    

    while(inputString && inputString[i]){
        if(inputString[i] == '{' && inputString[i + 2] == '}'){
            ++i;
            switch(inputString[i]){ // na koniec dodaje tego bracketa w kazdym wypadku
                case 'i': // czemu nie dzialaja dwa argumenty?
                    snprintf(tmp, 20, "%d", va_arg(args, int));
                    strncpy(&buff[j], tmp, strlen(tmp));
                    j += strlen(tmp);
                    ++j;
                    break;
                case 's': // 
                    snprintf(tmp, 20, "%s", va_arg(args, char*));
                    strncpy(&buff[j], tmp, strlen(tmp));
                    j += strlen(tmp);
                    k = 0;
                    break;
                case '{':
                    snprintf(tmp, 1, "%s", va_arg(args, char*));
                    strncpy(&buff[j], tmp, sizeof(char));
                    ++j;
                    ++i;
                    break;
            }
        } else {
            buff[j] = inputString[i];
            ++j;
        }
        ++i;
    }
    va_end(args);
    char *returnString = (char*)malloc( strlen(buff) * sizeof(char));
    strncpy(returnString, buff, strlen(buff));
    printf("TEST: %s\n", returnString);
    return returnString;
}

void test_cases(){
    char* test = NULL;
    // test = mr_asprintf("Gaius Julius Caesar Augustus Germanicus");
    // printf("%s\n", test);
    // assert(!strcmp(test, "Gaius Julius Caesar Augustus Germanicus"));
    // free(test);

    // test = mr_asprintf("Nickname: {s}", "Caligula");
    // printf("%s\n", test);
    // assert(!strcmp(test, "Nickname: Caligula"));
    // free(test);

    // test = mr_asprintf("Number: {i} {i}", 10, 20);
    // printf("%s\n", test);
    // assert(!strcmp(test, "Number: 10 20"));
    // free(test);

    // test = mr_asprintf("Number: {i ");
    // printf("%s\n", test);
    // assert(!strcmp(test, "Number: {i"));
    // free(test);

    // test = mr_asprintf("Bracket: {{");
    // printf("%s\n", test);
    // assert(!strcmp(test, "Bracket: {"));
    // free(test);

    // test = mr_asprintf("Literal: {s}", 'c');
    // printf("%s\n", test);
    // assert(!strcmp(test, "Literal: c"));
    // free(test);

}


int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
