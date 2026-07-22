#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

int main() 
{
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<pair<int, int>> q;
    vector<int> parent(n + 1, 0);

    q.push({1, 0});
    vis[1] = 1;

    int ans = -1;

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (node == n) {
            ans = dist;
            break;
        }

        for (int it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                parent[it] = node;
                q.push({it, dist + 1});
            }
        }
    }

    if (ans != -1) {
        cout << ans + 1 << '\n';

        vector<int> path;
        int node = n;
        while (node != 0) {
            path.push_back(node);
            node = parent[node];
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < (int)path.size(); i++) {
            cout << path[i] << (i + 1 == (int)path.size() ? '\n' : ' ');
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}