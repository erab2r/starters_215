#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 INF64 = (int64)4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    if(!(cin >> tc)) 
        return 0;
    while(tc--){
        int N, E;
        cin >> N >> E;
        vector<int64> A(N+1), B(N+1);
        for(int i=1;i<=N;i++) 
            cin >> A[i];
        for(int i=1;i<=N;i++) 
            cin >> B[i];

        while(E--){
            int CMN;
            cin >> CMN;
            if(CMN == 1){
                int P; int64 X, Y;
                cin >> P >> X >> Y;
                A[P] = X;
                B[P] = Y;
            } else if(type == 2){
                int L, R;
                cin >> L >> R;
                int len = R - L + 1;
                vector<int64> A_end(N+1, -INF64), A_start(N+1, -INF64);
                vector<int64> B_end(N+1, -INF64),B_start(N+1, -INF64);
                int64 cur = -INF64;
                for(int i=L;i<=R;i++){
                    if(i==L) cur = A[i];
                    else cur = max(A[i], cur + A[i]);
                    A_end[i] = cur;
                }
                cur = -INF64;
                for(int i=R;i>=L;i--){
                    if(i==R) cur = A[i];
                    else cur = max(A[i], cur + A[i]);
                    A_start[i] = cur;
                }
                cur = -INF64;
                for(int i=L;i<=R;i++){
                    if(i==L) cur = B[i];
                    else cur = max(B[i], cur + B[i]);
                    B_end[i] = cur;
                }
                cur = -INF64;
                for(int i=R;i>=L;i--){
                    if(i==R) cur = B[i];
                    else cur = max(B[i], cur + B[i]);
                    B_start[i] = cur;
                }

                int64 c = -INF64;
                for(int i=L;i<=R;i++){
                    int64 AA = A_end[i] + A_start[i] - A[i];
                    int64 BB = B_end[i] + B_start[i] - B[i];
                    c = max(c, AA + BB);
                }
                cout << c << '\n';
            } else {
                E--; 
            }
        }
    }
    return 0;
}
