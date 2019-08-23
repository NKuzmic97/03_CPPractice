#include <iostream>
#include <string>

enum class ErrorType {
	NoError,
	FirstWordContainsNumber,
	SecondWordContainsNumber,
	WordsNotSameLength
};

ErrorType CheckLength(const char* word1, const char* word2);
ErrorType CheckForNumbers(const char* word1, const char* word2);
void SortString(char* word);
void IsAnagram(const char* word1,const char* word2);
void CheckForNumberAndLength(const char* word1,const char* word2);
void Input(const char * word1, const char * word2);
void ConvertToLowercase(char* word1, char* word2);

int main() {
	// Code to check are two words anagrams

	// User writes two words.
	char word1[20];
	char word2[20];

	// Gets input
	Input(word1, word2);

	//Checks for number in words and if is the same length
	CheckForNumberAndLength(word1, word2);

// Algorithm checks whetever the words are anagram

	// Convert all chars to lowercase
	ConvertToLowercase(word1, word2);

	//Sort letters by ascending order.
	SortString(word1);
	SortString(word2);

	//Check if word1 is same as word2.
	IsAnagram(word1, word2);
}

void CheckForNumberAndLength(const char* word1, const char* word2)
{
	if (
		CheckForNumbers(word1, word2) != ErrorType::NoError
		&&
		CheckLength(word1, word2) != ErrorType::NoError
		) 
	{
		Input(word1,word2);
	}
}
void Input(const char * word1, const char * word2)
{
	std::cout << "Enter first word: ";
	std::cin >> const_cast<char*>(word1);
	std::cout << "Enter second word: ";
	std::cin >> const_cast<char*>(word2);
}
void IsAnagram(const char* word1, const char* word2)
{
	for (int i = 0; i < strlen(word1); i++) {
		if (word1[i] != word2[i]) break;
		std::cout << "Words are anagrams!";
		return;
	}
	std::cout << "Word not anagrams!\n";
	return;
}
void SortString(char* word)
{
	for (int i = 0; i < strlen(word) - 1; i++) {
		for (int j = i + 1; j < strlen(word); j++) {
			if (word[i] > word[j]) {
				char temp = word[j];
				word[j] = word[i];
				word[i] = temp;
			}
		}
	}
}
void ConvertToLowercase(char* word1, char* word2) {
	for (int i = 0; i < strlen(word1); i++) {
		word1[i] = tolower(word1[i]);
		word2[i] = tolower(word2[i]);
	}
}
ErrorType CheckForNumbers(const char* word1, const char* word2) {
	//Iterate over whole word1.
	for (int i = 0; i != '\0'; i++) {
		if (isdigit(word1[i])) {
			std::cout << "Error! You have a digit in first word! \n";
			return ErrorType::FirstWordContainsNumber;
		}
		if (isdigit(word2[i])) {
			std::cout << "Error! You have a digit in second word! \n";
			return ErrorType::SecondWordContainsNumber;
		}
	}
	return ErrorType::NoError;
}
ErrorType CheckLength(const char* word1, const char* word2) {
	int LengthWord1 = 0, LengthWord2 = 0;
	// Iterate over two words at the same time.
	for (int i = 0; i != '\0'; i++) {
		if (word1[i] != '\0') LengthWord1++;
		if (word2[i] != '\0') LengthWord2++;
	}
	if (LengthWord1 != LengthWord2) return ErrorType::WordsNotSameLength;
	return ErrorType::NoError;
}