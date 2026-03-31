#include <iostream>
#include "razionale.hpp"
int main(void)
{
    razionale<int> a(2,3);
    razionale<int> b(1,-12);
    razionale<int> c=a*b;
    std::cout<<c<<"\n";

    razionale<int> r(-2,3);
    razionale<int> s = r.operator/=({-3, 1});
    std::cout << r << "\n";
    std::cout << s << "\n";
    return 0;
}