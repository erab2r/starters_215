#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int N, e;
        cin >> N >> e;
        string ss;
        cin >> ss;
        int res = 0;
        for (char c : ss) {
            if (c == '0') 
                res++;
        }

        long long res1 = 0;
        int odd_val = 0;
        for (int i = 0; i < e;i++) {
            if (i >= N) 
                break;
            int idx = N - 1;
            int length = (idx - i) / e + 1; 

            res1 += (length + 1) / 2;
            if (length % 2 == 1) 
                odd_val++;
        }

        long long mn = res1- odd_val;
        long long mx = res1;

        if (res >= mn && res <= mx) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
