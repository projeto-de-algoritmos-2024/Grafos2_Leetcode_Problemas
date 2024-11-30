#include <vector>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
    vector<long long> dijkstra(int n, vector<vector<pii>>& grafo, int src) {
        // Inicializa as distâncias com infinito, menos a origem
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto topo = pq.top();
            long long d = topo.first;
            int u = topo.second;
            pq.pop();
            
            if (d > dist[u]) 
                continue;
            
            // Verifica os vizinhos e ajusta suas distâncias se necessário
            for (auto& vizinho : grafo[u]) {
                int v = vizinho.first;
                int peso = vizinho.second;
                
                // Atualiza a distância se encontrar um caminho mais curto
                if (dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        // Criação do grafo e do grafo reverso (lista de adjacências).
        // O grafo reverso será utilizado para calcular as distâncias dos outros nós para o nó de destino.
        vector<vector<pii>> grafo(n), grafoReverso(n);
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            grafo[u].push_back({v, w});
            grafoReverso[v].push_back({u, w});
        }
        
        // Encontra os caminhos mínimos partindo de cada um dos três nós principais
        // De src1 para todos os outros nós
        vector<long long> dist1 = dijkstra(n, grafo, src1);

        // De src2 para todos os outros nós
        vector<long long> dist2 = dijkstra(n, grafo, src2);

        // Usando grafo reverso para obter as distâncias até o destino
        vector<long long> distDest = dijkstra(n, grafoReverso, dest);
    }
};