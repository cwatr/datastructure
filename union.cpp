#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> parent, rank, size;
    
    public:
    disjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUltimateParent(int n){
        if(parent[n]==n) return n;
        return parent[n] = findUltimateParent(parent[n]);
    }

    void unionByRank(int u, int v){
        int ult_u = findUltimateParent(u);
        int ult_v = findUltimateParent(v);

        if(ult_u==ult_v) return;

        int ru = rank[ult_u], rv = rank[ult_v];
        if(ru<rv){
            parent[ult_u] = ult_v;
        }
        else if(ru>rv){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
        return;
    }

    void unionBySize(int u, int v){
        int ult_u = findUltimateParent(u);
        int ult_v = findUltimateParent(v);

        if(ult_u==ult_v) return;

        if(size[ult_u]<size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
        }
        return;
    }
}
int main(){

}