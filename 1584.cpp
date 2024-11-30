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
        
        pq.push({0, 0});
        menor_distancia[0] = 0;

        int soma = 0;

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            
            if (visitado[u]) {
                continue;
            }

            visitado[u] = true;

            soma += w;

            for (int i = 0; i < n; i++) {
                if (!visitado[i]) {
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