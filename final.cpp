#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Errore: numero errato di parametri inseriti\n";
    }
    else {
        string filename = argv[1]; 
        ifstream ifs(filename);
        if (ifs.fail()){
            std::cerr << "Errore: nome inserito non valido\n";
        }
        if (ifs.is_open()) {
            cout << "Capoluogo  TempMedia\n";
            while (!ifs.eof()) {
                string capoluogo;
                double temperatura_1;
                double temperatura_2;
                double temperatura_3;
                double temperatura_4;
                ifs >> capoluogo >> temperatura_1 >> temperatura_2 >> temperatura_3 >> temperatura_4;
                double media = (temperatura_1+temperatura_2+temperatura_3+temperatura_4)/4.0;
                cout << capoluogo << " | " << media << "\n";
            }
        }
        return 0;
    }
}
