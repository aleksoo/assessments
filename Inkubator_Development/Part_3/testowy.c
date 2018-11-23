#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char myString[8] = "abc d ef";
    char *token = NULL;

    token = strtok(myString, " ");
    printf("%s\n", token);
    token = strtok(NULL, " ");

    printf("%s\n", token);

    token = strtok(myString, " ");
    printf("%s\n", token);
    token = strtok(NULL, " ");

    printf("%s\n", token);


    return 0;
}