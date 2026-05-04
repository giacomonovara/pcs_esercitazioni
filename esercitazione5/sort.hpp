#pragma once
#include <vector>
#include <iostream>
#include <concepts>
#include <optional>
// per timecounter
#include <chrono>
// per randfiller
#include <random>
#include <type_traits>

class randfiller {
private:
    std::mt19937 gen;

public:
    randfiller()
        : gen(std::random_device{}())
    {}

    explicit randfiller(unsigned int seed)
        : gen(seed)
    {}

    void reseed() {
        gen.seed(std::random_device{}());
    }

    void reseed(unsigned int seed) {
        gen.seed(seed);
    }

    template <typename T> requires std::integral<T>
    void fill(std::vector<T>& vec, T min, T max) {
        std::uniform_int_distribution<T> dist(min, max);
        for (auto& v : vec) {
            v = dist(gen);
        }
    }

    template <typename T> requires std::floating_point<T>
    void fill(std::vector<T>& vec, T min, T max) {
        std::uniform_real_distribution<T> dist(min, max);
        for (auto& v : vec) {
            v = dist(gen);
        }
    }
};

class timecounter {

    std::chrono::high_resolution_clock::time_point start_time;
    bool running = false;

public:
            timecounter();
    void    tic(void);
    double  toc(void);
};

template<typename B>
void bubble_sort(std::vector<B>& vett)
{
    int n = vett.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = n-1; j>=i+1; j--)
        {
            if (vett[j] < vett[j-1])
            {
                std::swap(vett[j], vett[j-1]);
            }
        }
    }
} 

template<typename I>
void insertion_sort(std::vector<I>& vett, int p, int r)
{
    for (int i=p+1; i<=r; i++)
    {
        I value = vett[i];
        int j = i-1;
        while (j>=p && vett[j]>value)
        {
            std::swap(vett[j+1], vett[j]);
            j=j-1;
        }
        vett[j+1] = value;
    }
}

template<typename S>
void selection_sort(std::vector<S>& vett)
{
    int n = vett.size();
    for (int i = 0; i < n-1; ++i)
    {
        int min = i;
        for (int j=i+1; j <= n-1; ++j)
        {
            if (vett[j]<vett[min])
            {
                min = j;
            }
        }
        std::swap(vett[i], vett[min]);
    }
}


    // if constexpr (std::is_same_v<M, std::string>) {
    //     // Per le stringhe, una stringa di caratteri "molto alti" funge da infinito
    //     L[n1] = "\xff\xff\xff"; 
    //     R[n2] = "\xff\xff\xff";
    // } else {
    //     // Per i numeri (int, float, etc.)
    //     L[n1] = std::numeric_limits<M>::has_infinity ? 
    //             std::numeric_limits<M>::infinity() : 
    //             std::numeric_limits<M>::max();
    //     R[n2] = L[n1];
    // }

#include<limits>
template<typename M>
void merge(std::vector<M>& A, int p, int q, int r) 
{
    int n1 = q-p+1;
    int n2 = r-q;
    std::vector<M> L(n1);
    std::vector<M> R(n2);
    for (int i = 0; i<n1; i++) 
    {
        L[i] = A[p+i];
    }
    for (int j = 0; j<n2; j++) 
    {
        R[j] = A[q+1+j];
    }
    int i = 0;
    int j = 0;
    for (int k = p; k<=r; k++) 
    {
        if (i<n1 && (j>=n2 || L[i]<=R[j]))
        {
            A[k] = L[i];
            i = i+1;
        } else {
            A[k] = R[j];
            j = j+1;
        }
    }
}

template<typename MS>
void mergesort(std::vector<MS>& A, int p, int r) {
    if (p<r) 
    {
        int q = ((p+r)/2);
        mergesort(A,p,q);
        mergesort(A,q +1,r);
        merge(A,p,q,r);
    }
}

template<typename P>
int partition(std::vector<P>& A, int p, int r)
{
    P x = A[r];
    int i = p-1;
    for (int j=p; j<=r-1; j++)
    {
        if (A[j]<=x)
        {
            i = i+1;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i+1], A[r]);
    return i+1;
}

template<typename Q>
void quicksort(std::vector<Q>& A, int p, int r)
{
    //facendo un po' di simulazioni ho visto che l'algoritmo che "batte" più spesso il quicksort è l'insertionsort
    //e lo fa più o meno fino a quando i vettori hanno lunghezza 14
    if ((r-p)<=14)
    {
        if (p<r) {
            insertion_sort(A,p,r);
        }
    }
    else 
    {
        if (p<r)
        {
            int q = partition(A,p,r);
            quicksort(A,p,q-1);
            quicksort(A,q +1,r);
        }
    }
}

template<typename T>
std::optional<bool>
is_sorted(const std::vector<T>& vett)
{
    if (vett.size() == 0) {
    return {};
    }
    else {
        bool sorted = true;
        for (int i = 0; i < vett.size()-1; i++) {
            if (vett[i]>vett[i+1])
            {
                sorted = false;
                break;
            }
        }
        return sorted;
    }
}

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}