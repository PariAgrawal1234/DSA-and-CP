#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> adj;
vector <int> vis;

void dfs(int idx){
    vis[idx] = 1;
    for(auto &it: adj[idx]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
int main() 
{
    int n, m;
    cin >> n >> m;

    adj.assign(n+1, {});
    vis.assign(n+1, 0);

    for(int i = 0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int k = 0;
    vector <int> res;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            k++;
            res.push_back(i);
            dfs(i);
        }
    }

    cout << k-1 <<'\n';
    for(int i = 1; i < k; i++){
        cout << res[0] << " " << res[i] <<"\n";
    }
    
    return 0;
}