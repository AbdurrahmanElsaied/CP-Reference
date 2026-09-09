#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fix(x, m) (((x) % (m) + (m)) % (m))
void Fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
/*
counts the number of integers between 1 and  n inclusive, which are coprime to  n.

Q(N) = Q(P1 ^ A1) * Q(P2 ^ A2) * .... 
= Q(P1^A1 - P1^(A1-1)) *    Q(P2^A2 - P2^(A2-1))
=  P1 AND P2 COMMON FACTOR P1(1-(1/P1))
= n * (1-(1/p1)) * (1-(1/p2));
*/
int phi(int n) {
    int result = n; 
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
signed main()
{
    Fast();
    
    return 0;
}
