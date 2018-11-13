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
	std::cout << "Word_1 = " << word_1 << ", Word_2 = " << word_2 << std::endl;
	std::string temp = word_2;
	//temp.erase(std::remove(temp.begin(), temp.end(), ' ') , temp.end());
	std::cout << "String2: " <<  temp << std::endl;

	
	for(char singleLetter1 : word_1){
		std::cout << singleLetter1 << std::endl;
		temp.erase(temp.find(singleLetter1), 1);		
	}

	temp.erase(std::remove(temp.begin(), temp.end(), ' ') , temp.end());
	std::cout << "Test: " << temp << ", Size: " << temp.size() << std::endl;

	if(temp.size()) return false;
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

