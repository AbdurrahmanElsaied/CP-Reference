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
struct node{
    int sum , lazy ;
    bool isLazy = 0;
    node(){
        sum = 0 ;
        lazy = 0 ;
    }
    void assign(int val,int l,int r){
        sum = val ;
        lazy = val;
        isLazy=1;
    }
};

struct Lazysegtree{
    int sz = 1;
    vector<node> sg;
    Lazysegtree(int n){
        while(sz < n )sz *= 2;
        sg.resize(2 * sz,node());
    }
    node merge(node &lf,node &ri){
        node ans = node();
        ans.sum = lf.sum + ri.sum;
        return ans;
    }
    void propagate(int n,int l,int r){
        if(r-l == 1 || !sg[n].isLazy)return ;
        int mid = (r+l)/2;
        sg[2*n+1].assign(sg[n].lazy,l,mid);
        sg[2*n+2].assign(sg[n].lazy,mid,r);
        sg[n].isLazy=sg[n].lazy=0;
    }
    void set(int curl , int curr , int l ,int r ,int n,int val){
        if(curl >= r || curr <= l){
            return ;
        }
        if(curl >= l && curr <= r){
            sg[n].assign(val,curl,curr);
            return ; 
        }
        propagate(n,curl,curr);
        int mid = (curl + curr)/2;
        set(curl,mid,l,r,2*n+1,val);
        set(mid,curr,l,r,2*n+2,val);
        sg[n] = merge(sg[2*n+1],sg[2*n+2]);
    }
    void set(int l,int r,int val){
        set(0,sz,l,r,0,val);    
    }
    node get(int curl , int curr , int l ,int r ,int n){
        if(curl >= r || curr <= l){
            return node();
        }
        if(curl >= l && curr <= r){
            return sg[n]; 
        }
        propagate(n,curl,curr);
        int mid = (curl + curr)/2;
        node lf = get(curl,mid,l,r,2*n+1);
        node ri = get(mid,curr,l,r,2*n+2);
        return merge(lf,ri);
    }
    int get(int l,int r){
       return get(0,sz,l,r,0).sum;    
    }
};
signed main()
{
    Fast();
    int n,q;cin >> n >> q;
    Lazysegtree sg(n+1);
    while(q--){
        int op;cin >> op;
        if(op == 1){
            int l,r,val;cin >> l >> r >> val;
            sg.set(l,r,val);
        }
        else{
            int idx;cin >> idx;
            cout << sg.get(idx,idx+1) << '\n';
        }
    }
    return 0;
}
