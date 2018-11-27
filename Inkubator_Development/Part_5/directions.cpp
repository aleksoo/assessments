#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <locale>

std::string directions(const std::string& inputDirections){
    std::map<std::string, std::string> mapDirections = { {"north", "south"}, {"east", "west"}, {"south", "north"}, {"west", "east"} };
    // TODO: JAKIES ZABEZPIECZENEI SPRAWDZAJACE PIERWSZY I OSTATNI ZNAK, CZYLI CZY JEST KLAMRA
    std::string stringDirections = inputDirections;
    stringDirections.erase(0, 1).pop_back(); // Usuwam klamry
    stringDirections.erase(std::remove( stringDirections.begin(), stringDirections.end(), ','), stringDirections.end() ); // Usuwam przecinki

    std::stringstream streamDirections;
    streamDirections << std::tolower(stringDirections); // TO NIE DZIALA

    std::vector<std::string> directions; // vector na pojedyncze strony

    std::string singleDirection;
    while(getline(streamDirections, singleDirection, ' ')){
        //poiterowac po wektorze czy nie ma przeciwnosci, moze zmapowac gora 1 prawo 2 dol 3 lewo 4
        // SPRAWDZIC CZY VECTOR JEST PUSTY
        std::cout << "TEST: " << singleDirection << ' ' << mapDirections[singleDirection] << std::endl;
        if(directions.size()){
            std::cout << "TesT: "<< directions.back() << " AA: " << mapDirections[singleDirection] << std::endl;
            if(directions.back() == mapDirections[singleDirection]){
                directions.pop_back();
            } else {
                directions.push_back(singleDirection);
            }
        } else {
            directions.push_back(singleDirection);
        }
        
    }
    
    for(std::string singiel : directions)
        std::cout << singiel << std::endl;

    return "aa";

}

void test_cases(){
    std::string inputDirections;
    std::string answerString;

    inputDirections = "[North, South, South, East, West, North, West]";
    answerString = directions(inputDirections);
    assert(answerString == "WEST");	
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
