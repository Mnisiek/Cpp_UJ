
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<double>> read_matrix(const string& file_name, unsigned int rows, unsigned int columns);

void write_matrix(vector<vector<double>>& matrix, const string& file_name);

vector<vector<double>> multiply(vector<vector<double>>& matrix_A, vector<vector<double>>& matrix_B);

int main()
{
    unsigned int matrix_A_rows, matrix_A_columns;
    unsigned int matrix_B_rows, matrix_B_columns;

    // pobieranie danych o rozmiarze macierzy
    cout << "Liczba wierszy macierzy A: " << endl;
    cin >> matrix_A_rows;

    cout << "Liczba kolumn macierzy A: "<< endl;
    cin >> matrix_A_columns;

    cout << "Liczba wierszy macierzy B: "<< endl;
    cin >> matrix_B_rows;

    cout << "Liczba kolumn macierzy B: "<< endl;
    cin >> matrix_B_columns;


    // macierze są zapisane w postaci wektora o elementach będących wektorami typu double
    vector<vector<double>> matrix_A = read_matrix("matrix_A.txt", matrix_A_rows, matrix_A_columns);
    vector<vector<double>> matrix_B = read_matrix("matrix_B.txt", matrix_B_rows, matrix_B_columns);

    vector<vector<double>> matrix_C = multiply(matrix_A, matrix_B);

    write_matrix(matrix_C, "matrix_C.txt");
}


// funkcja do wczytywania macierzy z pliku, zwraca macierz w postaci wektora
vector<vector<double>> read_matrix(const string& file_name, unsigned int rows, unsigned int columns)
{
    // otwarcie pliku do odczytu
    fstream file;
    file.open(file_name.c_str(), fstream::in);

    vector<vector<double>> matrix;

    double element;
    vector<double> row;

    // wczytywanie danych z pliku i zapisywanie ich do wektora
    for (int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            file >> element;
            row.push_back(element);
        }
        matrix.push_back(row);
        row.clear();
    }

    return matrix;
}

// funkcja zapisująca macierz do pliku o podanej nazwie
void write_matrix(vector<vector<double>>& matrix, const string& file_name)
{
    // otwarcie pliku do zapisu
    fstream file;
    file.open(file_name.c_str(), fstream::out);

    // zapisane poszczególnych elementów wektora do pliku
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            file << element << " ";
        }
        file << "\n";
    }

}


vector<vector<double>> multiply(vector<vector<double>>& matrix_A, vector<vector<double>>& matrix_B)
{
    int rows_A = matrix_A.size();
    int cols_A = matrix_A[0].size();
    int rows_B = matrix_B.size();
    int cols_B = matrix_B[0].size();

    if (cols_A != rows_B) {
        cout << "Błąd. Liczba kolumn pierwszej macierzy nie równa się liczbie wierszy drugiej macierzy" << endl;
        return vector<vector<double>>(0);
    }

    // algorytm mnożenia macierzy
    vector<vector<double>> matrix_C(rows_A, vector<double>(cols_B, 0));
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            for (int k = 0; k < cols_A; ++k) {
                matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }

    return matrix_C;
}