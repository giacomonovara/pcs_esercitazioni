#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>
using namespace std;
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
    grafo_non_direzionato(const grafo_non_direzionato& other) 
    = default;
        // {};
    
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

//LIFO(stack)
template <typename S>
class lifo {
public:
    std::stack<S> stack;
    bool empty() const
    {
        return stack.empty();
    }
    S get()
    {
        S oggetto = stack.top();
        stack.pop();
        return oggetto;
    }
    void put(const S& oggetto)
    {
        stack.push(oggetto);
    }
};

//FIFO(queue)
template <typename C>
class fifo {
public:
    std::queue<C> coda;
    bool empty() const {
        return coda.empty();
    };
    C get() {
        C oggetto = coda.front();
        coda.pop();
        return oggetto;
    };
    void put(const C& oggetto) {
        coda.push(oggetto);
        return;
    };
};

template <typename T, typename G>
grafo_non_direzionato<G> graph_visit(const grafo_non_direzionato<G>& grafo, const int nodo_sorgente, T& lifo_fifo) {
    grafo_non_direzionato<G> albero_visita;
    auto numero_nodi = grafo.all_nodes().size();
    int n = numero_nodi;
    std::vector<int> pred(n);
    std::vector<bool> reached(n);
    for (int i=0; i<n; i++) {
        reached[i] = false;
    }
    reached[nodo_sorgente] = true;
    lifo_fifo.put(nodo_sorgente);
    while (!lifo_fifo.empty()) {
        auto u = lifo_fifo.get();
        auto vicini = grafo.neighbours(u);
        for (const auto& w : vicini) {
            if (!reached[w]) {
                reached[w] = true;
                pred[w] = u;
                lifo_fifo.put(w);
                albero_visita.add_edge(arco_non_direzionato<G>(u, w));
            }
        }
    }
    return albero_visita;
}

template <typename G>    //questa funziona :)
grafo_non_direzionato<G> recursive_dfs(const grafo_non_direzionato<G>& grafo, const int nodo_sorgente) {
    grafo_non_direzionato<G> albero;
    auto set_nodi = grafo.all_nodes();
    auto numero_nodi = set_nodi.size();
    int n = numero_nodi;
    static std::vector<bool> reached(n, false);
    reached[nodo_sorgente] = true;
    auto vicini = grafo.neighbours(nodo_sorgente);
    for (const auto& w : vicini){
        if (!reached[w]) {
            albero.add_edge(arco_non_direzionato<G>(nodo_sorgente, w));
            auto sub = recursive_dfs(grafo, w); //sotto albero
            for (const auto& edge : sub.all_edges()) {
                albero.add_edge(edge);
            }
        }
    }
    return albero;
}

template <typename G>
grafo_non_direzionato<G> dijkstra(const grafo_non_direzionato<G>& grafo, const int s) {
    // const int n = 10; 
    auto numero_nodi = grafo.all_nodes().size();
    int n = numero_nodi+1;
    std::vector<int> pred(n);
    std::vector<int> dist(n);
    for (int i = 0; i<n; i++) {
        pred[i] = -1;
        dist[i] = 1e8;
    }
    dist[s] = 0;
    pred[s] = s;
    fifo<int> PQ;
    PQ.put(s);
    while (!PQ.empty()) {
        auto u = PQ.get();
        auto vicini = grafo.neighbours(u);
        for (const auto& w : vicini) {
            const int peso_uw = 1;
            if (dist[u] != 1e8 && dist[w] > dist[u] + peso_uw) {
                dist[w] = dist[u] + peso_uw;
                pred[w] = u;
                PQ.put(w);
            }
        }
    }
    grafo_non_direzionato<G> dij;
    for (int i = 0; i < n; i++) {
        if (pred[i] !=i && pred[i] !=-1) {
            dij.add_edge(arco_non_direzionato<G>(pred[i], i));
        }
    }
    return dij;
}