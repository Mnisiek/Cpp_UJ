// Napisz kod, ktory wyznacza statystyke czestosci wystepowania 
// danej litery alfabetu w obiekcie std::string i wypisuje 5 o najwiekszej 
// czestosci wystepowania, a jesli czestosc jest taka sama, to wybierze te
// o nizszym kodzie ASCII. Litery wielkie i male traktowac tak samo!
// *** 2 pkt ***

#include <iostream>
#include <string>
#include <algorithm>

#define N_LETTER 26
#define N_RESULT 5

struct LetterOccurences
{
	char letter;
	unsigned int occurences;
};


void count_occurences(std::string str);


int main() {
	// wykorzystaj ponizsze obiekty std::string do wypisania wynikow
	std::string s1 {"The quick brown fox jumps over a lazy dog"};
	std::string s2 {"Abrakadabra adres biszkopt zadanie"};
	std::string s3 {"ASTEROIDA przeleciala niedaleko Ziemi i sie rozbila na Ksiezycu"};

	std::cout << "String 1:" << std::endl;
	count_occurences(s1);
	std::cout << "String 2:" << std::endl;
	count_occurences(s2);
	std::cout << "String 3:" << std::endl;
	count_occurences(s3);

	return 0;
}


void count_occurences(std::string str)
{
	unsigned int frequency_array[N_LETTER] = {};
	unsigned int index;
	LetterOccurences result_array[N_RESULT] = {};

	// for (int i = 0; i < N_LETTER; i++) {
	// 	frequency_array[i] = 0;
	// }

	// for (int i = 0; i < N_RESULT; i++) {
	// 	result_array[i].occurences = 0;
	// }

	std::transform(str.begin(), str.end(), str.begin(), ::tolower);

	for (auto letter: str) {
		index = letter - 'a';
		if (index > 0 && index < N_LETTER) {
			frequency_array[index] += 1;
		}
	}

	for (int i = 0; i < N_LETTER; i++) {
		for (int j = 0; j < N_RESULT; j++) {
			if (frequency_array[i] > result_array[j].occurences) {
				result_array[j].letter = (i + 'a');
				result_array[j].occurences = frequency_array[i];
				break;
			}
		}
	}

	for (auto c: result_array) {
		std::cout << c.letter << ": " << c.occurences << std::endl;
	}
	
}

