#include <assert.h>
#include <iostream>
#include <string>
#include <vector> 
#include <sstream> // stringstream
#include <algorithm> // transform
#include <map>
#include <utility>

bool is_pair(const char &one, const char &two){
	if((one == '(' && two == ')')
	|| (one == '[' && two == ']') 
	|| (one == '{' && two == '}'))
		return true;
	else
		return false;
}

std::string directions(const std::string& inputDirections){
    std::map<std::string, std::string> mapDirections = { {"NORTH", "SOUTH"}, {"EAST", "WEST"}, {"SOUTH", "NORTH"}, {"WEST", "EAST"} };
    // TODO: JAKIES ZABEZPIECZENEI SPRAWDZAJACE PIERWSZY I OSTATNI ZNAK, CZYLI CZY JEST KLAMRA??????

    std::string stringDirections = inputDirections;
    if(!is_pair(stringDirections.front(), stringDirections.back()))
        return " ";
    std::pair<char, char> brackets(stringDirections.front(), stringDirections.back());
    stringDirections.erase(0, 1).pop_back(); // Usuwam klamry
    stringDirections.erase(std::remove( stringDirections.begin(), stringDirections.end(), ','), stringDirections.end() ); // Usuwam przecinki
    stringDirections.erase(std::remove( stringDirections.begin(), stringDirections.end(), '"'), stringDirections.end() ); // Usuwam cudzyslowia

    std::stringstream streamDirections;
    std::transform(stringDirections.begin(), stringDirections.end(), stringDirections.begin(), ::toupper);
    streamDirections << stringDirections; // TO NIE DZIALA

    std::vector<std::string> directions; // vector na pojedyncze strony

    std::string singleDirection;
    while(getline(streamDirections, singleDirection, ' ')){
        //poiterowac po wektorze czy nie ma przeciwnosci, moze zmapowac gora 1 prawo 2 dol 3 lewo 4
        if(singleDirection == "")
            continue;

        // std::cout << "TEST: " << singleDirection << ' ' << mapDirections[singleDirection] << std::endl;
        if(directions.size()){ // SPRAWDZENIE SINGLEDIRECTION
            // std::cout << "TesT: "<< directions.back() << " AA: " << mapDirections[singleDirection] << std::endl;
            if(directions.back() == mapDirections[singleDirection]){
                directions.pop_back();
            } else {
                directions.push_back(singleDirection);
            }
        } else {
            directions.push_back(singleDirection);
        }
        
    }
    
    std::string returnString;
    returnString += brackets.first;
    returnString += ' ';
    for(std::string singiel : directions){
        returnString += '"' + singiel + '"' + ' ';
    }
    returnString += brackets.second;
        

    return returnString;
}

void test_cases(){
    std::string inputDirections;
    std::string answerString;

    inputDirections = "[North, South, South, East, West, North, West]";
    answerString = directions(inputDirections);
    std::cout << answerString << std::endl;
    assert(answerString == "[ \"WEST\" ]");	

       inputDirections = "( \"NORTH\", \"SOUTH\", \"SOUTH\", \"EAST\", \"WEST\", \"NORTH\", \"WEST\" )";
    answerString = directions(inputDirections);
    std::cout << answerString << std::endl;
    assert(answerString == "( \"WEST\" )");	

    inputDirections = "{ \"North\", \"South\", \"South\", \"East\", \"West\", \"North\", \"West\" }";
    answerString = directions(inputDirections);
    std::cout << answerString << std::endl;
    assert(answerString == "{ \"WEST\" }");	

    inputDirections = "{ \"North\", \"South\", \"South\",  \"North\" }";
    answerString = directions(inputDirections);
    std::cout << answerString << std::endl;
    assert(answerString == "{ }");	
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
