#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;  // Test set counter
    while (true) {
        vector<vector<int>> g(21);  // 1..20
        int x;

        // Read first connection line
        if (!(cin >> x)) return 0;   // EOF reached

        // Read lines 1 to 19
        for (int i = 1; i <= 19; i++) {
            if (i != 1) cin >> x;   // For i==1 we already read x above
            for (int j = 0; j < x; j++) {
                int v;
                cin >> v;
                g[i].push_back(v);
                g[v].push_back(i);
            }
        }

        // Read number of queries
        int N;
        cin >> N;

        cout << "Test Set #" << T++ << "\n";

        while (N--) {
            int A, B;
            cin >> A >> B;

            // BFS
            queue<int> q;
            vector<int> dist(21, -1);
            dist[A] = 0;
            q.push(A);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            cout << setw(2) << A << " to "
                 << setw(2) << B << ": "
                 << dist[B] << "\n";
        }

        cout << "\n";  // Blank line between test sets
    }

    return 0;
}
