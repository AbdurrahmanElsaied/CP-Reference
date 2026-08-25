struct SparseTable{
    vector<vector<int>> sp;
    SparseTable(int n){
        sp = vector<vector<int>> (__lg(n)+1 , vector<int>(n,0));
        sp[0] = a;
        for(int msk = 1;(1<<msk) <= n; ++msk){
            int sz = (1 << msk);
            for(int i=0;i+sz-1< n ;++i){
                sp[msk][i] = min(sp[msk-1][i],sp[msk-1][i+(sz/2)]);
            }
        }
    }
    //  if overlapping matter
    int get(int l, int r){
        int range = (r  - l + 1);
        int res = 1e9;
        for(int i=0;l<=r;i++){
            if((range >> i) & 1){
                res = min(res , sp[i][l]);
                l+=(1<<i);
            }
        }   
        return res;
    }
 
    int get2(int l , int r){
        int msk = __lg(r-l+1);
        return min(sp[msk][l] , sp[msk][r-(1<<msk)+1]);
    }
};
