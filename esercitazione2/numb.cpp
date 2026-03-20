#include <iostream>
#include <cmath>
#include <algorithm> // Per std::swap

int main() {
    static const int N = 5;
    double arr[N] = {-1, 1, 2, -4, 3};
    double minimo = arr[0];
    double massimo = arr[0];
    double somma = arr[0];
    int i = 0;
    for (i; i<N-1; i++)
    {
        if (arr[i+1]<minimo)   //calcolo minimo
        {
            minimo = arr[i+1];
        }
        if (arr[i+1]>massimo)   //calcolo massimo
        {
            massimo = arr[i+1];
        }
        somma = somma+arr[i+1];  //per calcolo media
    }
    double media = somma/N;
    int j = 0;    //calcolo deviazione standard
    double stdev = 0;
    for(j; j<N; j++)
    {
        stdev = stdev + pow(arr[j]-media,2);
    }
    stdev = sqrt(stdev/N);
    std::cout << "Minimo: " << minimo << "\n";
    std::cout << "Massimo: " << massimo << "\n";
    std::cout << "Media: " << media << "\n";
    std::cout << "StDev: " << stdev << "\n";
    bool scambi = true;   //se ho fatto scambi = true
    while (scambi)
    {
        int k = 0;
        scambi = false;
        for (k; k<N-1; k++)   //ciclo su tutti gli elementi 
        {
            if (arr[k]>arr[k+1])
            {
                float a= arr[k];
                float b = arr[k+1];
                arr[k] = b;   //scambio i due elementi
                arr[k+1] = a;
                scambi = true;  // segno che c'è stato uno scambio
            }
        }
        
    }
    int h = 0;   //stampo l'array ordinato 
    for (h; h<N; h++)
    {
        std::cout << arr[h] << " ";
    }
    return 0;
}