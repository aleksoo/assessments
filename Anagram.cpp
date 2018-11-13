#include <assert.h>
#include <string>
#include <iostream>
#include <algorithm>

/** 
* Function returns true if word_1 and word_2 are anagrams to each other. Otherwise false.
* Case sensitivity doesn't matter.
*/
bool check_if_anagram(const std::string &word_1, const std::string &word_2)
{

	// Sprawdzamy czy ktorys ze stringow nie jest pusty
	if(!(word_1.size() && word_2.size())) return false;

	// Tworzymy kopie word_2
	std::string word_2_copy = word_2;

	// Iterujemy przez litery word_1 i usuwamy z tymczasowego napotkane litery
	for(char singleLetter1 : word_1){
		int place = word_2_copy.find(singleLetter1);
		if(place+1) word_2_copy.erase(place, 1);		
	}

	// Usuwamy z kopii drugiego slowa spacje
	word_2_copy.erase(std::remove(word_2_copy.begin(), word_2_copy.end(), ' ') , word_2_copy.end());

	// Jezeli zostaly nam jakies litery to znaczy, ze nie jest to anagram
	if(word_2_copy.size()) return false;
	else return true;
}

void test_cases()
{
	bool answer = check_if_anagram("LordVader", "VaderLord");
	assert(answer == true);

	answer = check_if_anagram("silent", "listen");
	assert(answer == true);

	answer = check_if_anagram("funeral", "real fun");
	assert(answer == true);

	answer = check_if_anagram("Tieto", "Tietonator");
	assert(answer == false);

	answer = check_if_anagram("Football", "Basketball");
	assert(answer == false);

	answer = check_if_anagram("F", "");
	assert(answer == false);
}

int main()
{
	test_cases();
}

