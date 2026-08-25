#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    vector<vector<int>> sg;
    MergeSortTree(int n)
    {
        while (sz < n)
            sz *= 2;
        sg.resize(2 * sz);
    }
    vector<int> merge_nodes(const vector<int> &lf, const vector<int> &ri)
    {
        vector<int> ans;
        ans.reserve(lf.size() + ri.size());
        merge(lf.begin(), lf.end(), ri.begin(), ri.end(), back_inserter(ans));
        return ans;
    }
    void init(vector<int> &v, int l, int r, int n)
    {
        if (r - l == 1)
        {
            if (l < v.size()) {
                sg[n].push_back(v[l]);
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
        auto it = upper_bound(all(sg[n]), k)-sg[n].begin();
        return it;
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

int main()
{
    Fast();
    int n;cin >> n;
    vector<int> v(n);
    for(auto &it:v)cin >> it;
    MergeSortTree sg(n+1);
    sg.init(v);
    cout << sg.get(1,5,3) << '\n';
    return 0;
}
