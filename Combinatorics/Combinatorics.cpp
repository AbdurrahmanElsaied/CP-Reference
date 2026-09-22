#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void Fast(){    ios::sync_with_stdio(false);  cin.tie(0);cout.tie(0);}
const int MOD = 998244353;
const int N=1e6+5;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
struct Combinatorics {
    vector<int> fact, invFact;
    Combinatorics(int N){
        fact.resize(N);
        invFact.resize(N);

        fact[0] = 1;

        for (int i = 1; i < N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[N - 1] = fastpow(fact[N - 1], MOD - 2);

        for (int i = N - 2; i >= 0; i--) {
            invFact[i] = (i + 1) * invFact[i + 1] % MOD;
        }
    }
    int fastpow(int a, int b) {
        int ret = 1;
        while (b) {
            if (b & 1)
                ret = ret * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }
        return ret;
    }

    int ncr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
     int npr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[n - r] % MOD;
    }
};

signed main() {
    Fast();
    int t=1;
   // cin >> t;
    Combinatorics C(N);
    while (t--){
    }
    
    return 0;
}

