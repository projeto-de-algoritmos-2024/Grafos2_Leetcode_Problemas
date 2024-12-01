#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Solution {
public:

    inline int manhattanDistance(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> visitado(n, false);

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> menor_distancia(n, INT_MAX);
        
        // Inicia o algoritmo de Prim no ponto 0, com custo 0
        pq.push({0, 0});
        menor_distancia[0] = 0;

        int soma = 0;

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            
            // O ponto já está na MST
            if (visitado[u]) {
                continue;
            }

            visitado[u] = true;

            soma += w;

            for (int i = 0; i < n; i++) {
                if (!visitado[i]) {
                    // Calcula a distância de Manhattan entre os pontos u e i
                    // Se encontramos um caminho mais barato para o ponto i, atualizamos e colocamos na fila de prioridade
                    int dist = manhattanDistance(points[u], points[i]);

                    if (dist < menor_distancia[i]) {
                        menor_distancia[i] = dist;
                        pq.push({dist, i});
                    }
                }
            }
        }

        return soma;
    }
};