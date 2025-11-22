#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int u, v;
};

int cube(int x) {
    return x * x * x;
}

int main() {
    int setCount = 1;
    int n;
    while (cin >> n) {
        vector<int> busyness(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> busyness[i];

        int r;
        cin >> r;
        vector<Edge> edges(r);
        for (int i = 0; i < r; ++i)
            cin >> edges[i].u >> edges[i].v;

        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; ++i)
            cin >> queries[i];

        // Bellman-Ford
        vector<int> dist(n + 1, INF);
        dist[1] = 0;
        for (int i = 1; i < n; ++i) {
            for (const auto& e : edges) {
                int u = e.u, v = e.v;
                int cost = cube(busyness[v] - busyness[u]);
                if (dist[u] != INF && dist[u] + cost < dist[v])
                    dist[v] = dist[u] + cost;
            }
        }

        // Output after input
        cout << "Set #" << setCount++ << "\n";
        for (int target : queries) {
            if (target < 1 || target > n || dist[target] == INF || dist[target] < 3)
                cout << "?\n";
            else
                cout << dist[target] << "\n";
        }
    }
    return 0;
}
