#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h> // va_list, va_start, va_end

char *mr_asprintf(const char* inputString, ...){
    va_list args;
    va_start(args, inputString);
    int i = 0, j = 0, bufferSize = 100;
    char buff[100] = {'\0'}, tmp[20];
    memset(buff, '\0', bufferSize*sizeof(char));
    

    while(inputString && inputString[i]){
        if(inputString[i] == '\0')
            break;

        if(inputString[i] == '{'){
            ++i;
            switch(inputString[i]){
                case 'i':
                    snprintf(tmp, 20, "%d", va_arg(args, int));
                    strncpy(&buff[j], tmp, strlen(tmp));
                    j += strlen(tmp);
                    i += 2;
                    break;
                case 's': 
                    snprintf(tmp, 20, "%s", va_arg(args, char*));
                    strncpy(&buff[j], tmp, strlen(tmp));
                    j += strlen(tmp);
                    i += 2;
                    break;
                case '{':
                    buff[j] = inputString[i];
                    ++j;
                    ++i;
                    break;
            }
        } else {
            buff[j] = inputString[i];
            ++j;
            ++i;
        }
        
    }
    va_end(args);
    char *returnString = (char*)malloc( (strlen(buff) + 1)* sizeof(char*));
    strncpy(returnString, buff, strlen(buff));
    printf("TEST: %s\n", returnString);
    return returnString;
}

void test_cases(){
    char* test = NULL;

    test = mr_asprintf("Gaius Julius Caesar Augustus Germanicus");
    printf("%s\n", test);
    assert(!strcmp(test, "Gaius Julius Caesar Augustus Germanicus"));
    free(test);
    

    test = mr_asprintf("Nickname: {s}", "Caligula");
    printf("%s\n", test);
    assert(!strcmp(test, "Nickname: Caligula"));
    free(test);

    test = mr_asprintf("N: {i} {i} ", 10, 20);
    printf("%s\n", test);
    assert(!strcmp(test, "N: 10 20 "));
    free(test);

    test = mr_asprintf("Literal: {s}", "c");
    printf("%s\n", test);
    assert(!strcmp(test, "Literal: c"));
    free(test);

    test = mr_asprintf("Bracket: {{ abcd");
    printf("%s\n", test);
    assert(!strcmp(test, "Bracket: { abcd"));
    free(test);

}


int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
