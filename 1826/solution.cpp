#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int target;
    int weight;
};

class MessagePropagator {

public:
    int getMinTimeToReachAllNodes(int n, vector<vector<int>>& edges) {
        vector<vector<Edge>> adj(n+1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> minTime(n + 1, INT_MAX);
        minTime[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currentTime > minTime[u]) continue;

            for (const auto& edge : adj[u]) {
                if(minTime[u] + edge.weight < minTime[edge.target]) {
                    minTime[edge.target] = minTime[u] + edge.weight;
                    pq.push({minTime[edge.target], edge.target});
                }
            }
        }

        int totalTime = 0;
        for (int i = 0; i <= n; i++) {
            if (minTime[i] == INT_MAX) return -1;
            totalTime = max(totalTime, minTime[i]);
        }

        return totalTime;
    }
};

int main() {
    MessagePropagator propagator;
    int n = 5;
    vector<vector<int>> networkEdges = {
        {0, 1, 5}, {0, 2, 3}, {0, 5, 4}, {1, 3, 8}, 
        {2, 3, 1}, {3, 5, 10}, {3, 4, 5}
    };
    int result = propagator.getMinTimeToReachAllNodes(n, networkEdges);
    
    if(result != -1) {
        cout << "Total propagation time: " << result << endl;
    } else {
        cout << "Some nodes are unreachable" << endl;
    }

    return 0;
}