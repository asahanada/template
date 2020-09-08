#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

struct unionfind{
    vector<int> par;
    vector<int> high;
    vector<int> size;
    int num;
    unionfind(int n):num(n), par(n,-1), high(n,1), size(n,1){}
    int find(const int x){
        if(par[x]==-1)return x;
        return par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return;
        if(high[x]>high[y])swap(x,y);
        if(high[x]==high[y])high[y]++;
        par[x]=y;
        size[y]+=size[x];
        num--;
        return;
    }
    int getsize(const int i){
        return size[find(i)];
    }
    void get(const int m){
        rep(i,m){
            int a,b;cin >> a >> b;
            unite(a-1,b-1);
        }
        return;
    }
};

int main(){
    int n,m,ans=0;cin >> n >> m;
    unionfind uf(n);
    uf.get(m);
    rep(i,n)ans=max(ans,uf.getsize(i));
    cout << ans << endl;
}