/*
Napisz program, który wykorzystując <filesystem>, poprosi o podanie ścieżki do danego katalogu, a następnie wypisze nazwy wszystkich zwykłych plików oraz ich rozmiar. Należy zwrócić uwagę na rozpoznawanie rodzajów plików tak, żeby program wypisywał tylko zwykłe pliki oraz ich rozmiar, a jeśli ich nie ma, odpowiednią informację.
*/

#include <iostream>
#include <string>
#include <filesystem>

using namespace std;


int main() {
    bool has_files;
    string str_path; // ścieżka podana przez użytkownika
    
    cout << "Podaj sciezke do katalogu: ";
    getline(cin, str_path);
    filesystem::path path(str_path); // konwersja na obiekt klasy filesystem

    // obsługa błedów wywołania programu
    if (!(filesystem::exists(path))) {
        cout << "Podana sciezka nie istnieje" << endl;
        return -1;
    }
    if (!(filesystem::is_directory(path))) {
        cout << "Podana sciezka nie jest katalogiem" << endl;
        return -1;
    }

    has_files = false;

    // pętla for each przebiega po całej zawartości katalogu
    for (const auto& element : filesystem::directory_iterator(path)) {

        // sprawdzenie, czy plik jest zwykłym plikiem
        if (filesystem::is_regular_file(element)) {

            // wypisanie nazwy pliku regularnego oraz jego rozmiaru
            cout << element.path().filename().string() << " - rozmiar " << filesystem::file_size(element) << " bytes" << endl;

            has_files = true; // ustawiamy flagę na true
        }
    }

    if (! (has_files)) {
        cout << "Brak zwyklych plikow w katalogu." << endl;
    }

    return 0;
}
