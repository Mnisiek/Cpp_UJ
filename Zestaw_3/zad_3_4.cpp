
#include "sha256.h"
#include <iostream>
#include <string>
#include <chrono>

#define MAX_NOUCE 100000000

int mine(int block_number, std::string transactions, std::string previous_hash, int prefix_zeros);

int main(int argc, char* argv[])
{   
    // Argumenty wywołania: numer_bloku liczba_wiodących_zer
    if (argc != 3) {
        std::cout << "Błąd, niepoprawna liczba argumentów." << std::endl << "Argumenty wywołania: numer_bloku liczba_wiodących_zer" << std::endl;
        return 1;
    }

    // dane do przykładowego wywołania
    std::string transactions = "Bank_A ---> Bank_B ---> Bank_C ---> Bank_D";
    std::string previous_hash = "a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e";

    auto start_time = std::chrono::high_resolution_clock::now();
    mine(std::stoll(argv[1], NULL, 10), transactions, previous_hash, std::stoll(argv[2], NULL, 10));
    auto end_time = std::chrono::high_resolution_clock::now();

    // pomiar czasu działania programu
    auto time_duration = (std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count())*(1e-9);

    std::cout << "Wykopanie Bitcoina trwało " << time_duration << " sekund." << std::endl;

    return 0; 
}


// funkcja kopiąca bitcoina
int mine(int block_number, std::string transactions, std::string previous_hash, int prefix_zeros)
{
    int i;
    SHA256 sha256;
    std::string new_hash;

    std::string prefix_str = std::string(prefix_zeros, '0');

    for (unsigned long long nounce = 0; nounce < MAX_NOUCE; ++nounce) {
        std::string text = std::to_string(block_number) + transactions + previous_hash + std::to_string(nounce);

        new_hash = sha256(text);

        // sprawdzamy, czy występuje podana liczba zer na początku
        for (i = 0; i < prefix_zeros; ++i) {
            if (new_hash[i] != '0')
                break;
        }

        if (i == prefix_zeros) {
            std::cout << "Gratulacje, udało Ci się wykopać Bitcoina!" << std::endl << "Liczba prób: " << nounce << std::endl << new_hash << std::endl;

            return 0;
        }
    }

    std::cout << "Nie udało się wykopać Bitcoina." << std::endl << "Liczba prób: " << MAX_NOUCE << std::endl;

    return 1;
}
