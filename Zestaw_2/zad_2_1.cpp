/*
Napisz program, który wczyta z pliku ASCII tekst, a następnie go wyjustuj (czyli wyrówna do lewej i prawej krawędzi) przy zadanej jako stały parametr szerokości kolumny i wyświetli na ekranie. Ponieważ w przypadku konsoli nie mamy zmiennej szerokości fontów, to „wyrównywanie” trzeba wykonać poprzez sprytne, w miarę jednorodne, dodawanie spacji w danej linii.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define SZEROKOSC 30 // szerokość kolumny tekstu

using namespace std;

struct WYRAZY // struktura przechowująca napis i jego długość
{
    string wyraz;
    unsigned int dlugosc;
};


int main()
{
    int i, j; // zmienne do iterowania
    int k, suma; // liczba spacji, długości budowanego wiersza
    string line;
    vector <WYRAZY> word_list; 
    fstream file;
    string file_name = "tekst.txt";
    string word;
    file.open(file_name.c_str(), fstream::in);

    while (file >> word) { // zapisywanie pojedynczych słów w kontenerze
        word_list.push_back({word, word.length()});
    }

    i = 0;
    while (i < word_list.size()) {
        // bez justowania, przechodzimy do nastepnego wyrazu
        if (word_list[i].dlugosc >= SZEROKOSC) {
            cout << word_list[i].wyraz << endl; 
            i++;
            continue;
        }
        for (suma = 0, line = ""; i < word_list.size() && (suma + word_list[i].dlugosc) < SZEROKOSC; i++) {
            line += word_list[i].wyraz; // dopisywanie wyrazu do wiersza
            suma += word_list[i].dlugosc;
            if (i + 1 < word_list.size()) {
                if ((suma + word_list[i+1].dlugosc) < SZEROKOSC) {
                    line += " "; // dodawanie pojedynczej spacji
                    suma += 1;
                }
            }
        }

        j = 0;
        k = 2;
        // dodawanie spacji w celu wyjustowania
        while (suma < SZEROKOSC && k < SZEROKOSC) {
            if (line[j] == ' ') {
                line.insert(j, " ");
                j += k;
                suma++;
            }
            else {
                j++;
            }

            if (j == line.size() - 1) {
                j = 0;
                k++;
            }
        }

        cout << line << endl; // wypiswanie wiersza wyjustowanego tekstu
    }

    return 0;
}
