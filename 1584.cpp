#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:

    int manhattanDistance(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

    }
};