#include <iostream>
#include <vector>
#include "sort.hpp"

int main() {
    randfiller rf;
    for (int i = 0; i < 100; i++) {
        int size = rand() % 101; 
        std::vector<int> v(size);
        rf.fill(v, -50, 50);
        insertion_sort(v,0,v.size()-1);
        bool boo = *is_sorted(v);
        if (boo == false) {
            std::cerr << "Errore nel test_insertion_sort\n";
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> v_stringa = {
        "Tigliole", "Baldichieri", "Monale", "Celle", "San Martino",
        "Castellero", "Cortandone", "Revigliasco", "Villafranca", "Cantarana"
    };
    insertion_sort(v_stringa,0,v_stringa.size()-1);
    print_vector(v_stringa);
    bool boo_s = *is_sorted(v_stringa);
    if (boo_s== false) {
        std::cerr << "Errore test_insertion_sort sulle stringhe\n";
        return EXIT_FAILURE;
    }
    std::cout << "Test_insertion_sort riuscito\n";
    return EXIT_SUCCESS;
}
