#pragma once
#include <iostream>
#include <concepts>
#include <optional>

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
void insertion_sort(std::vector<I>& vett)
{
    int n = vett.size();
    for (int i = 1; i<n; i++)
    {
        I value = vett[i];
        int j = i-1;
        while (j>=0 && vett[j]>value)
        {
            std::swap(vett[j+1], vett[j]);
            j = j-1;
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

#include <optional>
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