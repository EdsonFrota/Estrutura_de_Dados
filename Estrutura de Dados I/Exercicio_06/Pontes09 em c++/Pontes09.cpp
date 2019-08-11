#include <iostream>
#include <queue>

using namespace std;

typedef pair < int, int> No;        ///  comando typedef permite definir um novo nome para um determinado tipo.
typedef vector < vector < No > > Grafo;

void Dijkstra (Grafo G, int u, int v)     /// função do algoritmo de Dijkstra
{

    priority_queue < int > fila;
    vector < int > visitado;

    int elemento, cont, atual;

    int infinito = 999999;        /// supondo que esse seja nosso numero infinito
    visitado.resize (G.size(), infinito);

    visitado[u] = 0;
    fila.push (u);

    while ( !fila.empty() )
    {
        atual = fila.top();
        fila.pop();

        for (int i=0; i<G[atual].size(); ++i)
        {
            elemento = G[atual][i].first;
            cont = G[atual][i].second;

            if (visitado[elemento] > visitado[atual] + cont)
            {
                visitado[elemento] = visitado[atual] + cont;
                fila.push (elemento);
            }
        }
    }
    cout << visitado[v];
}

int main ()                /// função principal para receber os valores e imprir o processemanto do algoritmo
{
    int n, m, a, b, cont;
    Grafo G;

    cout <<" < Entrada >\n";
    cout << "Informe o numero de pilares do desfiladeiro:  ";
    cin >> n;

    cout << "Informe o numero de pontes: ";
    cin >> m;

    cout << " \n ";

    G.resize (n+2);

    cout << "Indique as pontes e os buracos respectivamente: \n";

    for (int i=0; i<m; ++i)
    {
        cin >> a >> b >> cont;

        G[a].push_back (make_pair (b, cont));
        G[b].push_back (make_pair (a, cont));

    }

    cout << "\nSaida: \n";
    cout << "\n Nesse caminho sera ncessario pular ";Dijkstra (G, 0, n+1);cout << " Buracos.\n";
    return (0);
}
