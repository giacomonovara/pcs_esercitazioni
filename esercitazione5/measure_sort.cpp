#include <iostream>
#include <vector>
#include "sort.hpp"
#include <algorithm>

//RANDFILLER
int main_rf(void)
{
    randfiller rf; /* instantiate a randfiller */
    std::vector<int> vi;
    vi.resize(10);
    rf.fill(vi, 30, 50); /* use it on vectors */
    print_vector(vi);
    std::vector<float> vf;
    vf.resize(5);
    rf.fill(vf, 1.5f, 7.5f);
    print_vector(vf);
    std::vector<double> vd;
    vd.resize(8);
    rf.fill(vd, 1.5, 7.5);
    print_vector(vd);
    return 0;
}

//CONTATORE
timecounter::timecounter()
{}
void
timecounter::tic(void)
{
    start_time = std::chrono::high_resolution_clock::now();
    running = true;
}
double
timecounter::toc(void)
{
    if (!running) {
        throw std::runtime_error("timecounter not running");
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    running = false;
    return elapsed.count();
}

//MAIN
int main() {
    randfiller rf;
    timecounter timer;
    std::vector<double> bub_arr(100);
    std::vector<double> ins_arr(100);
    std::vector<double> sel_arr(100);
    std::vector<double> sort_arr(100);
    std::vector<double> merge_arr(100);
    std::vector<double> quick_arr(100);
    for (int i=1; i<=100; i++)
    {
        std::vector<int> v(i);
        rf.fill(v, -50,50);
        std::vector<int> v_da_ord = v;
        std::cout << "/////////////////////////////\n";
        std::cout <<  "Dimensione:" << v.size() << "  \n";
        //sort (predefinita)
        timer.tic();
        std::sort(v.begin(), v.end());
        double durata_sort = timer.toc();
        std::cout << "Durata Sort: " << durata_sort << "   ";
        //bubble
        v = v_da_ord;
        timer.tic();
        bubble_sort(v);
        double durata_b = timer.toc();
        std::cout << "Durata Bubble: " << durata_b << "   ";
        //insertion
        v = v_da_ord;
        timer.tic();
        insertion_sort(v,0,v.size()-1);
        double durata_i = timer.toc();
        std::cout << "Durata Insertion: " << durata_i << "   ";
        //selection
        v = v_da_ord;
        timer.tic();
        selection_sort(v);
        double durata_s = timer.toc();
        std::cout << "Durata Selection: " << durata_s << "   ";
        //mergesort
        v = v_da_ord;
        timer.tic();
        int p = 0;
        int r = v.size()-1;
        mergesort(v,p,r);
        double durata_m = timer.toc();
        std::cout << "Durata Merge: " << durata_m << "   ";
        //quicksort
        v = v_da_ord;
        timer.tic();
        quicksort(v,p,r);
        double durata_q = timer.toc();
        std::cout << "Durata Quick: " << durata_q << "   \n";
        //salvo i tempi
        sort_arr[i-1] = durata_sort;
        bub_arr[i-1] = durata_b;
        ins_arr[i-1] = durata_i;
        sel_arr[i-1] = durata_s;
        merge_arr[i-1] = durata_m;
        quick_arr[i-1] = durata_q;
    }
    return 0;
}