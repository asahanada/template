#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vec vector
typedef long long ll;
typedef pair<ll,ll> P;

struct unionfind{
    vector<int> par;
    vector<int> size;
    int num;
    unionfind(int n):num(n), par(n,-1), size(n,1){}
    int find(const int x){
        if(par[x]==-1)return x;
        return par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return;
        if(size[x]>size[y])swap(x,y);
        if(size[x]==size[y])size[y]++;
        par[x]=y;
        num--;
        return;
    }
    void get(const int m){
        rep(i,m){
            int a,b;cin >> a >> b;
            a--;b--;
            unite(a,b);
        }
        return;
    }
};

struct edge{
    ll from,to,cost;
    bool operator==(const edge a)const{
        if((*this).from==a.from&&(*this).to==a.to&&(*this).cost==a.cost)
            return true;
        else return false;
    }
    bool operator!=(const edge a)const{
        return !((*this)==a);
    }
    bool operator>(const edge a)const{
        if((*this).cost>a.cost)return true;
        else return false;
    }
    bool operator<(const edge a)const{
        if((!((*this)>a))&&(!((*this)==a)))return true;
        else return false;
    }
    bool operator<=(const edge a)const{
        return !((*this)>a);
    }
    bool operator>=(const edge a)const{
        return !((*this)<a);
    }
};

//setにedgeたちを渡す nは頂点数
vec<vec<P>> kruskal(priority_queue<edge,vec<edge>,greater<edge>> &a,int n){
    unionfind uf(n);
    vec<vec<P>> ans(n);
    while(!a.empty()){
        edge k=a.top();
        a.pop();
        if(uf.find(k.from)==uf.find(k.to))continue;
        else{
            ans[k.from].emplace_back(P(k.to,k.cost));
            ans[k.to].emplace_back(P(k.from,k.cost));
            uf.unite(k.to,k.from);
        }
        rep(i,n-1){
            if(uf.find(i)!=uf.find(i+1))goto skip;
        }
        return ans;
        skip:;
    }
    return ans;
}

int main(){

}