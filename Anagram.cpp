#include <assert.h>
#include <string>

/** 
* Function returns true if word_1 and word_2 are anagrams to each other. Otherwise false.
* Case sensitivity doesn't matter.
*/
bool check_if_anagram(const std::string &word_1, const std::string &word_2)
{
	return false;
}

void test_cases()
{
	bool answer = check_if_anagram("LordVader", "VaderLord");
	assert(answer == true);

	answer = check_if_anagram("silent", "listen");
	assert(answer == true);

	answer = check_if_anagram("funeral", "real fun");
	assert(answer == true);

	answer = check_if_anagram("Tieto", "Tietonator",);
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

