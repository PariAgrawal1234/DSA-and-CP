#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n;
        cin >> n;
        
        long long sum_L_minus_1 = 0;
        long long count_ones = 0;
        vector<long long> comm_suf;
        
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            
            if (x == 1) {
                count_ones++;
            }
            
            vector<long long> path;
            while (x != 1) {
                path.push_back(x);
                if (x % 2 == 0) {
                    x /= 2;
                } else {
                    x += 1;
                }
            }
            path.push_back(1);
            
            sum_L_minus_1 += path.size() - 1;
            
            if (i == 0) {
                comm_suf = path;
            } else {
                int p1 = comm_suf.size() - 1;
                int p2 = path.size() - 1;
                int match = 0;
                
                while (p1 >= 0 && p2 >= 0 && comm_suf[p1] == path[p2]) {
                    match++;
                    p1--;
                    p2--;
                }
                
                if (match < comm_suf.size()) {
                    comm_suf.erase(comm_suf.begin(), comm_suf.end() - match);
                }
            }
        }
        
        long long min_ops = -1;
        
        for (int i = 0; i < comm_suf.size(); ++i) {
            long long dist_to_1 = comm_suf.size() - 1 - i;
            long long ops = sum_L_minus_1 - n * dist_to_1;
            
            if (min_ops == -1 || ops < min_ops) {
                min_ops = ops;
            }
        }
        
        long long ops_v2 = sum_L_minus_1 - n + 2 * count_ones;
        if (min_ops == -1 || ops_v2 < min_ops) {
            min_ops = ops_v2;
        }
        
        cout << min_ops << "\n";
    }
    
    return 0;
}