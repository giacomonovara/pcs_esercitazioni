#include <iostream>
#include <vector>
#include "sort.hpp"
#include "randfiller.h"
#include "timecounter.h"
#include <algorithm>

int main() {
    randfiller rf;
    timecounter timer;
    //salvo i risultati nei vettori per poi fare il plot
    double bub_arr[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    double ins_arr[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    double sel_arr[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    double sort_arr[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i=1; i<=12; i++)
    {
        int j = pow(2,i+1);
        std::vector<int> v(j);
        rf.fill(v, -50,50);
        std::cout << "/////////////////////////////\n";
        std::cout <<  "Dimensione:" << v.size() << "  \n";
        //sort (predefinita)
        timer.tic();
        std::sort(v.begin(), v.end());
        double durata_sort = timer.toc();
        std::cout << "Durata Sort: " << durata_sort << "   ";
        //bubble
        timer.tic();
        bubble_sort(v);
        double durata_b = timer.toc();
        std::cout << "Durata Bubble: " << durata_b << "   ";
        //insertion
        timer.tic();
        insertion_sort(v);
        double durata_i = timer.toc();
        std::cout << "Durata Insertion: " << durata_i << "   ";
        //selection
        timer.tic();
        selection_sort(v);
        double durata_s = timer.toc();
        std::cout << "Durata Selection: " << durata_s << "\n";
        //salvo i tempi nei quattro array sopra definiti
        sort_arr[i-1] = durata_sort;
        bub_arr[i-1] = durata_b;
        ins_arr[i-1] = durata_i;
        sel_arr[i-1] = durata_s;
    }
    return 0;
}