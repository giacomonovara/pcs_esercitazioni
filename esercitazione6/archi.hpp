#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map> 
#pragma once

template <typename A>
class arco_non_direzionato {
public:
    A nodo_1;
    A nodo_2;

    arco_non_direzionato(int n1, int n2) {
        if (n1<=n2)
        {
            nodo_1 = n1;
            nodo_2 = n2;
        }
        else
        {
            nodo_1 = n2;
            nodo_2 = n1;
        }
    }
    //from
    int from() const
    {
        return nodo_1;
    }
    //to
    int to() const
    {
        return nodo_2;
    }
    //ordinare gli archi
    bool operator<(const arco_non_direzionato& other) const 
    {
        if (nodo_1 != other.nodo_1) {
            if (nodo_1 < other.nodo_1)
            {
                return true;
            }
        }
        else
        {
            if (nodo_2 < other.nodo_2) 
            {
                return true;
            }
        }
        return false;
    }
    //se due archi sono uguali
    bool operator==(const arco_non_direzionato& other) const 
    {   
        if ((nodo_1==other.nodo_1) && (nodo_2==other.nodo_2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
//stampa
template <typename S>
std::ostream& operator<<(std::ostream& os, const arco_non_direzionato<S>& arco) {
    return os << "(" << arco.nodo_1 << " <---> " << arco.nodo_2 << ")";
};

template <typename G>
class grafo_non_direzionato {
public:
    std::set<arco_non_direzionato<G>> grafo;
    //default e copia
    grafo_non_direzionato() 
        {};
    grafo_non_direzionato(const grafo_non_direzionato& other);
    
    //neighbours
    std::set<G> neighbours(const G& nodo) const 
    {
        std::set<G> vicini;
        for (const auto& arco : grafo)
        {
            if (arco.from() == nodo) 
            {
                vicini.insert(arco.to());
            }
            else if (arco.to() == nodo) 
            {
                vicini.insert(arco.from());
            }
        }
        return vicini;
    }
    //add_edge
    void add_edge(const arco_non_direzionato<G>& arco) {
        grafo.insert(arco);
    }
    //all_edges
    std::vector<arco_non_direzionato<G>> all_edges() const {
        std::vector<arco_non_direzionato<G>> tutti_gli_archi;
        for (auto itor = grafo.begin(); itor != grafo.end(); itor++) {
            arco_non_direzionato<G> val = *itor;
            tutti_gli_archi.insert(tutti_gli_archi.end(), val);
        }
        return tutti_gli_archi;
    }
    //all_nodes
    std::set<G> all_nodes() const {
        std::set<G> nodi;
        for (const auto& arco : grafo) {
            nodi.insert(arco.from());
            nodi.insert(arco.to());
        }
        return nodi;
    }
    //edge_number
    int edge_number(const arco_non_direzionato<G>& arco) const {
        int pos = 0;
        for (const arco_non_direzionato<G>& attuale : grafo) {
            if (attuale == arco) {
                return pos;
            }
            pos=pos+1;
        }
        return 0;
    }
    //edge_at
    arco_non_direzionato<G> edge_at(int n) const {
        int pos = 0;
        for (auto itor = grafo.begin(); itor != grafo.end(); itor++) 
        {
            if (pos == n) {
                return *itor;
            }
            pos = pos+1;
        }
    }
    //operatore meno
    grafo_non_direzionato operator-(const grafo_non_direzionato& altro) const {
        grafo_non_direzionato diff;
        for (auto itor = grafo.begin(); itor != grafo.end(); itor++) 
        {
            const arco_non_direzionato<G>& arco = *itor;
            if (altro.grafo.find(arco) == altro.grafo.end()) 
            {
                diff.add_edge(arco);
            }
        }
        return diff;
    }
};