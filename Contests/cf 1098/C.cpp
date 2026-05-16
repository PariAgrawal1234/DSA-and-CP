#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        ull a;
        int n;
        cin >> a >> n;

        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        sort(d.begin(), d.end());

        string s_a = to_string(a);
        int len_a = s_a.length();
        ull min_diff = -1ULL;

        if (len_a > 1) {
            ull num = 0;
            for (int i = 0; i < len_a - 1; i++) {
                num = num * 10 + d.back();
            }
            min_diff = min(min_diff, (a > num) ? (a - num) : (num - a));
        }

        ull num_more = (d[0] == 0 && n > 1) ? d[1] : d[0];
        for (int i = 0; i < len_a; i++) {
            num_more = num_more * 10 + d[0];
        }
        min_diff = min(min_diff, (num_more > a) ? (num_more - a) : (a - num_more));

        ull prefix = 0;
        bool perfect = true;

        for (int i = 0; i < len_a; i++) {
            int target = s_a[i] - '0';

            int smaller = -1;
            for (int digit : d) {
                if (digit < target) smaller = max(smaller, digit);
            }
            if (smaller != -1 && !(i == 0 && smaller == 0 && len_a > 1)) {
                ull candidate = prefix * 10 + smaller;
                for (int j = i + 1; j < len_a; j++) {
                    candidate = candidate * 10 + d.back();
                }
                min_diff = min(min_diff, (a > candidate) ? (a - candidate) : (candidate - a));
            }

            int larger = 10;
            for (int digit : d) {
                if (digit > target) larger = min(larger, digit);
            }
            if (larger != 10) {
                ull candidate = prefix * 10 + larger;
                for (int j = i + 1; j < len_a; j++) {
                    candidate = candidate * 10 + d[0];
                }
                min_diff = min(min_diff, (candidate > a) ? (candidate - a) : (a - candidate));
            }

            bool exact = false;
            for (int digit : d) {
                if (digit == target) {
                    exact = true;
                    break;
                }
            }

            if (exact) {
                prefix = prefix * 10 + target;
            } else {
                perfect = false;
                break;
            }
        }

        if (perfect) {
            min_diff = min(min_diff, (a > prefix) ? (a - prefix) : (prefix - a));
        }

        cout << min_diff << "\n";
    }

    return 0;
}