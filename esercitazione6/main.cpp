#include <iostream>
#include <algorithm>
#include "archi.hpp"

int main() {
    //inizializzo due archi e testo le due operazioni < e ==
    arco_non_direzionato<int> a(4,3);
    arco_non_direzionato<int> b(3,6);
    std::cout<<"A: " <<a<<" B: "<<b<<"\n";
    bool minor = a<b;
    bool uguale = a==b;
    std::cout << "A minore di B? " << std::boolalpha <<minor << "\n";
    std::cout << "A uguale a B? "<< std::boolalpha <<uguale << "\n";
    grafo_non_direzionato<int> grafo_uno;
    std::cout << "\nGrafo G\n";
    //inizializzo un grafo di 6 nodi
    grafo_uno.add_edge(arco_non_direzionato<int>(1,2));
    grafo_uno.add_edge(arco_non_direzionato<int>(2,3));
    grafo_uno.add_edge(arco_non_direzionato<int>(1,3));
    grafo_uno.add_edge(arco_non_direzionato<int>(4,2));
    grafo_uno.add_edge(arco_non_direzionato<int>(6,5));
    grafo_uno.add_edge(arco_non_direzionato<int>(1,5));
    //mostro tutti i nodi/archi
    std::set<int> nodi = grafo_uno.all_nodes();
    std::vector<arco_non_direzionato<int>> archi = grafo_uno.all_edges();
    std::cout << "Nodi: ";
    for (int nodo:nodi) 
    {
        std::cout << "|" << nodo << "|";
    }
    std::cout << "\nArchi: ";
    for (const arco_non_direzionato<int>& arco : archi) 
    {
        std::cout << "|" << arco << "|"; 
    }
    //vicini (neighbours)
    int nodo = 1;
    auto vicini = grafo_uno.neighbours(nodo); // Dovrebbe restituire {2, 3}
    std::cout << "\nVicini nodo " << nodo << ": ";
    for (int v : vicini) {
        std::cout << "|" << v << "|"; 
    }
    //edge_number/at
    arco_non_direzionato<int> c(2,3);
    int pos_richiesta = 4;
    int pos = grafo_uno.edge_number(c);
    arco_non_direzionato<int> arco = grafo_uno.edge_at(pos_richiesta);
    std::cout << "\nPosizione arco " << c << ": " << pos;
    std::cout << "\nArco in posizione "<< pos_richiesta <<": "<< arco;
    //differenza
    grafo_non_direzionato<int> g_primo;
    g_primo.add_edge(arco_non_direzionato<int>(1,2));
    g_primo.add_edge(arco_non_direzionato<int>(1,6));
    g_primo.add_edge(arco_non_direzionato<int>(2,4));
    std::vector<arco_non_direzionato<int>> archi_g_primo = g_primo.all_edges();
    std::cout << "\nArchi di G': ";
    for (const arco_non_direzionato<int>& arco : archi_g_primo) 
    {
        std::cout << "|" << arco << "|"; 
    }
    grafo_non_direzionato<int> g_diff = grafo_uno - g_primo;
    std::vector<arco_non_direzionato<int>> archi_diff = g_diff.all_edges();
    std::cout << "\nArchi in G ma non in G': ";
    for (const arco_non_direzionato<int>& arco : archi_diff) 
    {
        std::cout << "|" << arco << "|"; 
    }
    grafo_non_direzionato<int> g_diff_due = g_primo - grafo_uno;
    std::vector<arco_non_direzionato<int>> archi_diff_due = g_diff_due.all_edges();
    std::cout << "\nArchi in G' ma non in G: ";
    for (const arco_non_direzionato<int>& arco : archi_diff_due) 
    {
        std::cout << "|" << arco << "|"; 
    }
    return 0;
}