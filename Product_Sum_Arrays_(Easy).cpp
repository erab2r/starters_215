#include <bits/stdc++.h>
using namespace std;
int cunt;
void dfs(long long e, long long h) {
    if (cunt >= 3) 
        return; 
    if (e >=h) {
        ++cunt;                
        if (cunt >= 3) return;  
    }
    for (long long i =h; i * i <= e && cunt < 3;i++) {
        if (e % i == 0) {
            dfs(e/i,i);  
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        long long N;
        cin >> N;

        if (N == 1) {
            cout << 1 << "\n"; 
            continue;
        }
        cunt = 0;
        dfs(N, 2);
        if (cunt > 3) 
            cunt = 3; 
        cout << cunt << "\n";
    }

    return 0;
}