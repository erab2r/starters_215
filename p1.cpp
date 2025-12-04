#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int N;
        long long e;
        cin >> N >> e;

        vector<long long> vecc(N);
        for (int i = 0;i<N;i++) {
            cin >> vecc[i];
        }
        string S;
        cin >> S;

        long long sm = 0;   
        long long tl = 0;  

        for (int i = 0; i < N;i++) {
            tl += vecc[i];
            if (S[i] == '0') {
                sm+= vecc[i];
            }
        }

        long long reslt = sm; 
        if (sm >= e) {
            reslt = max(reslt, tl-e);
        }

        cout << reslt << "\n";
    }

    return 0;
}
