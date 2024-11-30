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
                long long peso = vizinho.second;
                
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
        
    }
};