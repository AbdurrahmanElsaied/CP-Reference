#include <bits/stdc++.h>
using namespace std;
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
struct MergeSortTree
{
    int sz = 1;
    vector<vector<pair<int,int>>> sg;
    MergeSortTree(int n)
    {
        while (sz < n)
            sz *= 2;
        sg.resize(2 * sz);
    }
    vector<pair<int,int>> merge_nodes(const vector<pair<int,int>> &lf, const vector<pair<int,int>> &ri)
    {
        vector<pair<int,int>> ans;
        int i={},j={};
        while( i<lf.size() && j <ri.size()){
            if(lf[i] <=ri[j] ){
                ans.push_back({lf[i].first,lf[i].first});
                if(ans.size()>1)ans.back().second += ans[ans.size()-2].second;
                i++;
            }
            else{
                ans.push_back({ri[j].first,ri[j].first});
                if(ans.size()>1)ans.back().second += ans[ans.size()-2].second;
                j++;
            }
        }
        while(i<lf.size()){
             ans.push_back({lf[i].first,lf[i].first});
                if(ans.size()>1)ans.back().second += ans[ans.size()-2].second;
                i++;
        }
        while(j<ri.size()){
            ans.push_back({ri[j].first,ri[j].first});
            if(ans.size()>1)ans.back().second += ans[ans.size()-2].second;
            j++;
        }
        return ans;
    }
    void init(vector<int> &v, int l, int r, int n)
    {
        if (r - l == 1)
        {
            if (l < v.size()) {
                sg[n].push_back({v[l],v[l]});
            }
            return ; 
        }
        int mid = (l + r) / 2;
        init(v, l, mid, 2 * n + 1);
        init(v, mid, r, 2 * n + 2);
        sg[n] = merge_nodes(sg[2 * n + 1], sg[2 * n + 2]);
    }
    void init(vector<int> &v){
        init(v,0,sz,0);
    }
    int get(int l, int r, int curl, int curr, int k, int n) {
    if (curl >= r || curr <= l) {
        return 0; 
    }
    
    if (curl <= l && r <= curr) {
        auto it = upper_bound(all(sg[n]), make_pair(k,LLONG_MAX));
        if(it==sg[n].begin())return 0;
        it--;
        return it->second;
    }
    int mid = (l+r)/ 2;
    int lf = get(l, mid, curl, curr, k, 2 * n + 1);
    int ri = get(mid, r, curl, curr, k, 2 * n + 2);
    return lf + ri;
}
int get(int l, int r, int k) {
    return get(0, sz, l, r, k, 0); 
}
};

signed main()
{
    Fast();
    int n;cin >> n;
    vector<int> v(n);
    for(auto &it:v)cin >> it;
    MergeSortTree sg(n+1);
    sg.init(v);
    int q;cin >> q;
    while(q--){
        int l,r,x;cin >> l >> r >> x;
        l--;
        cout << sg.get(l,r,x) << '\n';
    }
    return 0;
}
