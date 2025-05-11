// Napisz kod, ktory wczyta jako parametr uruchomienia lancuch znakowy np.
// prog.exe "1, 2, 3: A teraz przystapimy do testow..."
// i wpisze go na ekran po zamianie na wielkie litery
// *** 1 pkt ***

#include <iostream>
#include <string>
#include <algorithm>


int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        std::cout << "Niepoprawna liczba argumentów" << std::endl;
        return -1;
    }
    
    std::string str = argv[1];
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    std::cout << str << std::endl;

    return 0;
}
