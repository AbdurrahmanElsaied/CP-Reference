#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define int long long
#define all(x) x.begin(), x.end()
#define int long long
#define rall(x) x.rbegin(), x.rend()
#define fix(x, m) (((x) % (m) + (m)) % (m))
void Fast(){    ios::sync_with_stdio(false);  cin.tie(0);cout.tie(0);}
const int MOD = 1e9+7;
const int N=1e6+5;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
ll mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
struct node{
    int sum , lazy ;
    bool isLazy =  0;
    node(int val =1 ){
        sum = val;
        lazy = 1;
    }
    void update(int val,int l,int r){
        sum  = mul(sum,val); 
        lazy = mul(lazy,val);
        isLazy = 1;
    }
};
struct Lazysegtree{
    int sz = 1;
    vector<node> sg;
    Lazysegtree(int n){
        while(sz < n){
            sz*=2;
        }
        sg.resize(2 * sz,node());
    }
    node merge(node lf,node ri){
        node ans = node();
        ans.sum = (lf.sum % MOD) + (ri.sum % MOD);
        ans.sum%=MOD;
        return ans;
    }
    void propagation(int n,int l,int r){    
        if(r-l == 1 || !sg[n].isLazy)return ;
        int mid = (l+r)/2;
        sg[2*n+1].update(sg[n].lazy,l,mid);
        sg[2*n+2].update(sg[n].lazy,mid,r);
        sg[n].lazy= 1LL;
        sg[n].isLazy = 0;
    }
    void build(int l, int r, int n, int size) {
    if(r-l == 1) {
        if(l < size)
            sg[n].sum = 1;
        else
            sg[n].sum = 0;

        sg[n].lazy = 1;
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*n+1, size);
    build(mid, r, 2*n+2, size);
    sg[n] = merge(sg[2*n+1], sg[2*n+2]);
    }
    void set(int val,int curl,int curr,int l,int r,int n){
        if(curl >= r || curr <= l ) return ;
        if(curl >= l && curr<=r){
            sg[n].update(val,curl,curr);
            return ;
        }
        propagation(n,curl,curr);
        int mid = (curl+curr)/2;
        set(val,curl,mid,l,r,2*n+1);
        set(val,mid,curr,l,r,2*n+2);
        sg[n] = merge(sg[2*n+1],sg[2*n+2]);
    }
    void set(int val,int l,int r){
        set(val,0,sz,l,r,0);
    }
   node get(int curl,int curr,int l,int r,int n){
        if(curl >= r || curr <= l ) return node(0) ;
        if(curl >= l && curr<=r){
            return sg[n] ;
        }
        propagation(n,curl,curr);
        int mid = (curl+curr)/2;
        node lf= get(curl,mid,l,r,2*n+1);
        node ri = get(mid,curr,l,r,2*n+2);
        return  merge(lf,ri);
    }
    int get(int l,int r){
        return get(0,sz,l,r,0).sum;
    }

};
signed main() {
    Fast();
      int n,q;cin >> n >> q;
      Lazysegtree sg(n+1);
      sg.build(0,sg.sz,0,n);
      while(q--){
        int op ;cin >> op;
        if(op == 1){
            int l,r,val;cin >> l >> r >> val;
            sg.set(val,l,r);
        }
        else{
            int l,r;cin >> l >> r;
            cout << sg.get(l,r)% MOD << '\n';
        }
      }
    
    return 0;
}

