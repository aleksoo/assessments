#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>


char* highest_scoring_word(const char* string);
int word_eval(const char* string);
void test_cases();


int main(){
    //highest_scoring_word("raz dwa trzy");
    //printf("Najwiekszy string: %s\n", highest_scoring_word("razzz dwa trzy trzz"));
    test_cases();
    return 0;
}

void test_cases(){
    
    int answerInt = word_eval("aaa");
    assert(answerInt == 3);

    answerInt = word_eval("ba");
    assert(answerInt == 3);

    answerInt = word_eval("cab");
    assert(answerInt == 6);

    answerInt = word_eval("");
    assert(answerInt == 0);

    char* answerString = highest_scoring_word("zzz bacbac");
    printf("o chuj chodzi: %s\n", answerString);
    assert(answerString == "zzz"); // jakiegos compare zrobic

    answerString = highest_scoring_word("aaa c");
    assert(answerString == "");

    answerString = highest_scoring_word("");
    assert(answerString == "");


}

char* highest_scoring_word(const char* string){
    if(!strlen(string))
        return string;
    int highestScore = 0, tempScore = 0;
    char* token;
    char* highestWord;
    char* tempString = (char*)malloc( strlen(string) * sizeof(char) );
    strcpy(tempString, string);

    token = strtok(tempString," ,."); 
    highestWord = (char*)malloc( strlen(token) * sizeof(char) );
    strcpy(highestWord, token);

    while(token!=NULL){
        tempScore = word_eval(token);
        printf("Slowo %s ma wartosc %d\n", token, tempScore);
        if(tempScore > highestScore){
            highestWord = realloc(highestWord, sizeof(token));
            strcpy(highestWord, token);
            highestScore = tempScore;
            printf("Nowe najwyzej punktowane slowo to %s z %d\n", highestWord, highestScore);
        }
        token = strtok(NULL," ,.");
    }
    printf("Najwyzej punktowane slowo to %s z punktacja %d\n", highestWord, highestScore);
    return highestWord;
}

int word_eval(const char* string){
    int score=0;
    int i;

    char* lowerString = (char*)malloc(strlen(string)*sizeof(char));
    for(i=0; i < strlen(string); ++i){
        lowerString[i]=tolower(string[i]);
    }

    for(i=0; i < strlen(lowerString); ++i){
        score+=(int)lowerString[i]-96;
    }

    return score;
}