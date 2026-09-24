#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fix(x, m) (((x) % (m) + (m)) % (m))
void Fast(){    ios::sync_with_stdio(false);  cin.tie(0);cout.tie(0);}
const int MOD = 1e9+7;
const int N=2e6+5;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

bool KnowBit(int num, int idx) {
    return ((num >> idx) & 1);
}
ll Setbit(ll n, int i) {
    return (ll) n | (1LL << i);
}
ll Reset(int n, int i) {
    return n & (~(1 << i));
}
ll flip(int n, int i) {
    return n ^ (1 << i);
}
bool poweroftwo(ll n) {
    if (n == 0) return true;
    return !(n & (n - 1));
}
ll flip1stbit(ll n) {
    return n & (n - 1);
}
ll count11(ll num) {
    int cnt = 0;
    while (num) {
        cnt++;
        num &= num - 1;
    }
    return cnt;
}
ll getvalueof1stbit(ll n) {
    ll c = n & (n - 1);
    return n - c;
    // or return n&~(n-1);
}
int No_of_bits(int x) {
    return (int) log2(x);
}

int lowbit(int x) {
    return x & (-x);
}
int main() {
    Fast();
    int t=1;
    while (t--){
     //__builtin_clzll() return number of leading zeros 
    }
    
    return 0;
}



