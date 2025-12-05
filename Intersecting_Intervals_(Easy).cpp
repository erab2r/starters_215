 #include <bits/stdc++.h>
using namespace std;

long long bestInclude(const vector<long long>& e) {
    int N = e.size();
    vector<long long> l(N), r(N);
    l[0] = e[0];
    for (int i = 1;i<N;i++)
        l[i] = max(e[i], l[i - 1] + e[i]);
    r[N - 1] = e[N - 1];
    for (int i = N - 2; i >= 0; i--)
        r[i] = max(e[i], r[i + 1] + e[i]);
    long long ress = LLONG_MIN;
    for (int i = 0; i < N; i++) {
        long long rslt = l[i] + r[i]-e[i];
        ress = max(ress, rslt);
    }
    return ress; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int N;
        cin >> N;

        vector<long long> A(N), B(N);
        for (auto &p : A) 
            cin >> p;
        for (auto &p : B) 
            cin >> p;
        vector<long long> lA(N), rA(N), lB(N), rB(N);
        lA[0] = A[0];
        for (int i = 1; i < N; i++) 
            lA[i] = max(A[i], lA[i-1] + A[i]);
        rA[N-1] = A[N-1];
        for (int i = N-2; i >= 0; i--) 
            rA[i] = max(A[i], rA[i+1] + A[i]);
        lB[0] = B[0];
        for (int i = 1; i < N; i++) 
            lB[i] = max(B[i], lB[i-1] + B[i]);
        rB[N-1] = B[N-1];
        for (int i = N-2; i >= 0; i--) 
            rB[i] = max(B[i], rB[i+1] + B[i]);

        long long resultss = LLONG_MIN;

        for (int i = 0; i < N; i++) {
            long long ss = lA[i] +rA[i]-A[i];
            long long hh = lB[i] +rB[i]-B[i];
            resultss = max(resultss, ss + hh);
        }

        cout << resultss << "\n";
    }
    return 0;
}