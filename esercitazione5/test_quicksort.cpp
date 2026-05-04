#include <iostream>
#include <vector>
#include "sort.hpp"

int main() {
    randfiller rf;
    int p = 0;
    for (int i = 0; i < 100; i++){
        int size = rand() % 101;   //Nota: ho cercato su internet come generare numeri casuali 
        std::vector<int> v(size);
        rf.fill(v, -50, 50);
        int r = v.size()-1;
        quicksort(v,p,r);
        bool boo = *is_sorted(v);
        if (boo == false) {
            std::cerr << "Errore nel test_quick_sort\n";
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> v_stringa = {
        "Tigliole", "Baldichieri", "Monale", "Celle", "San Martino",
        "Castellero", "Cortandone", "Revigliasco", "Villafranca", "Cantarana"
    };
    int r = v_stringa.size()-1;
    quicksort(v_stringa,p,r);
    print_vector(v_stringa);
    bool boo_s = *is_sorted(v_stringa);
    if (boo_s== false) {
        std::cerr << "Errore test_quick_sort sulle stringhe\n";
        return EXIT_FAILURE;
    }
    std::cout << "Test_quick_sort riuscito\n";
    return EXIT_SUCCESS;
}