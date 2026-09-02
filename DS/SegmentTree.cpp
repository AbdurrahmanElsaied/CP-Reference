#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fix(x, m) (((x) % (m) + (m)) % (m))
void Fast(){    ios::sync_with_stdio(false);  cin.tie(0);cout.tie(0);}
const int MOD = 1e9+7;
const int N=1e6+5;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
struct node{
    int sum;
    node(){
        sum =0;
    }
    void change(int val){
        sum += val;
    }
};
struct segtree{
    int sz ;
    vector<node> sg;
    segtree(int n){
        sz = 1;
        while(sz < n )sz*=2;
        sg.assign(2 * sz,node());
    }
    node merge(node &l , node&r){
        node ans= node();
        ans.sum = l.sum + r.sum;
        return ans;
    }
    void init(vector<int> &arr,int l,int r ,int n){
        if(r - l == 1){
            if(l < arr.size()){
                sg[n].change(arr[l]);
            }
            return ;
        }
        int mid = (l+r)/2;
        init(arr , l , mid , 2* n + 1);
        init(arr, mid ,r, 2 * n + 2);
        sg[n] = merge(sg[2*n+1], sg[2*n+2]);
    }
    void set(int idx ,int val, int l,int r,int n){
        if(r - l == 1){
            sg[n].change(val);
            return ;
        }
        int mid = (l + r )/2;
        if(idx < mid){
            set ( idx  ,val, l , mid , 2 * n + 1);
        }
        else{
            set ( idx , val,mid , r , 2 * n + 2);
        }
        sg[n] = merge(sg[2*n+1],sg[2*n+2]);
    }
   void set(int idx,int val){
    set(idx,val, 0, sz, 0);
    }
    void init(vector<int> &arr){
        init(arr,0,sz,0);
    }
    node get(int l,int r,int curl ,int curr ,int n){
        if(curl >= r || curr<=l){
            return node();
        }
        if(curl >= l && curr<= r){
            return sg[n];
        }
        int mid = (curl + curr)/2;
        node lf= get(l,r,curl,mid, 2 * n + 1);
        node ri = get(l,r,mid,curr, 2 * n + 2);
        return merge(lf,ri);
    }
    int get(int l,int r){
        return get(l,r,0,sz,0).sum;
    }
};

int main() {
    Fast();
    
    
    return 0;
    }
