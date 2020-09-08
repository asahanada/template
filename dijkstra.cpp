#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep2(i,s,n) reo(int i=s;i<(int)n;i++)
typedef long long ll;
typedef pair<ll,ll> P;
#define vec vector
const ll INF=100000000000000000LL;//1e17

struct edge{
    ll to,cost;
    constexpr bool operator<(const edge &a)const noexcept{
        if((*this).cost<a.cost)return true;
        else return false;
    }
    constexpr bool operator>(const edge &a)const noexcept{
        if((*this).cost>a.cost)return true;
        else return false;
    }
};

struct graph{
    ll v;
    vec<vec<edge>> g;
    vec<ll> d;

    graph(ll n) : v(n),g(n),d(n,INF){}

    void addedge(const ll s,const ll t,const ll cost){
        edge e;
        e.to=t;
        e.cost=cost;
        g[s].emplace_back(e);
    }
    //E+VlogV
    void dijkstra(ll s){//sからstartのdijkstra
        /*一度dijkstraをした時同じグラフでdijkstraしたいならこれも入れる
        rep(i,v)d[i]=INF;
        */
        d[s]=0;
        priority_queue<P,vec<P>,greater<P>> que;
        que.push(P(0,s));
        while(!que.empty()){
            P pa=que.top();que.pop();
            ll k=pa.second;
            if(d[k]<pa.first)continue;
            for(auto e:g[k]){
                if(d[e.to]>d[k]+e.cost){
                    d[e.to]=d[k]+e.cost;
                    que.push(P(d[e.to],e.to));
                }
            }
        }
    }
};

int main(){

}