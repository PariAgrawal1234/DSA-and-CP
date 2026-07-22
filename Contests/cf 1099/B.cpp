#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long k = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            k = max(k, a[i] - a[i + 1]);
        }
    }

    if (k == 0) {
        cout << "YES\n";
        return;
    }

    long long max_so_far = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] >= max_so_far) {
            max_so_far = a[i];
        } else {
            if (a[i] + k < max_so_far) {
                cout << "NO\n";
                return;
            }
            max_so_far = a[i] + k;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}