#include <iostream>
#include <vector>
#include "sort.hpp"
#include "randfiller.h"

int main() {
    randfiller rf;
    for (int i = 0; i < 100; i++) {
        int size = rand() % 101; 
        std::vector<int> v(size);
        rf.fill(v, -50, 50);
        selection_sort(v);
        bool boo = *is_sorted(v);
        if (boo == false) {
            std::cerr << "Errore nel test_selection_sort\n";
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> v_stringa = {
        "Tigliole", "Baldichieri", "Monale", "Celle", "San Martino",
        "Castellero", "Cortandone", "Revigliasco", "Villafranca", "Cantarana"
    };
    selection_sort(v_stringa);
    print_vector(v_stringa);
    bool boo_s = *is_sorted(v_stringa);
    if (boo_s== false) {
        std::cerr << "Errore test_selection_sort sulle stringhe\n";
        return EXIT_FAILURE;
    }
    std::cout << "Test_selection_sort riuscito\n";
    return EXIT_SUCCESS;
}
