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
 struct dsu
       {
           int parent[N], sz[N];
           stack<array<int,4>> st;
           int comp ;
           dsu(int n)
           {    
                comp = n-1;
               for(int i = 0; i < n; i++)
               {
                   parent[i] = i;
                   sz[i] = 1;
               }
           }
       
           int find(int i)
           {
               return parent[i] == i ? i : find(parent[i]);
           }
       
           bool samegroup(int x, int y)
           {
               return find(x) == find(y);
           }
       
           void merge(int x, int y)
           {
               int root1 = find(x);
               int root2 = find(y);
       
               array<int,4> ins = {-1, -1, -1,-1};
               st.push(ins);
       
               if(root1 == root2) return;
       
               st.pop();
       
               if(sz[root1] > sz[root2])
                   swap(root1, root2);
       
               ins[0] = root1;
               ins[1] = root2;
               ins[2] = sz[root2];
               ins[3] = comp;
               st.push(ins);
               comp--;
               parent[root1] = root2;
               sz[root2] += sz[root1];
           }
       
           void rollback()
           {
               array<int,4> last = st.top();
               st.pop();
               if(last[0] == -1) return;

               parent[last[0]] = last[0];
               sz[last[1]] = last[2];
               comp = last[3];
           }
       
           int getsize(int x)
           {
               return sz[find(x)];
           }
       };
int main() {
    Fast();
    int t=1;
    //cin >> t;
    while (t--){
      int n,m;cin >> n >> m;
      int cnt = 0;
      dsu d(n+1);
      stack<int> stk;
      while(m--){
        string str;cin >> str;
        if(str == "persist"){
            stk.push(cnt);
            cnt = 0;
        }
        else if(str == "union"){
            cnt++;
            int u,v;cin >> u >> v;
            d.merge(u,v);
            cout << d.comp << '\n';
        }
        else{
            while(cnt--)d.rollback();
            cnt = stk.top();
            stk.pop();
            cout << d.comp << '\n';
        }
      }
    }
    
    return 0;
}

