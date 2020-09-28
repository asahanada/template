#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define vec vector
typedef long long ll;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

template<typename T>
struct edge{
    int to;
    T cap,rev;//capは容量限界 waterは今流れてる流量 revは逆辺
};

template<typename T>
struct maxflow{
    vector<vector<edge<T>>> g;
    vector<bool> seen;
    maxflow(int n):g(n),seen(n,false){}

    void add_edge(int from,int to,T cap){
        //fromからtoへの容量capの辺と逆辺を張る revは(今の辺を追加する前の)辺が向かう先のサイズ...?なぜこれでいいかはわからないがとりあえず。
        g[from].push_back((edge<T>){to,cap,T(1)*((int)g[to].size())});
        g[to].push_back((edge<T>){from,0,T(1)*((int)g[from].size()-1)});
    }
    
    //vからの増加パスをdfsにより探す 増加パスが存在すればそこのcapを直接減らすような形で水を流す fは最大でどれだけ流せるか？の量,即ちcapのmin
    T dfs(int v,int t,T f){
        if(v==t)return f;
        seen[v]=true;
        for(edge &e:g[v]){
            if((!seen[e.to]) && e.cap>0){
                int d=dfs(e.to , t , min(f,e.cap));
                if(d>0){
                    e.cap-=d;
                    g[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return T(0);//これ以上いけないなら0を返す
    }

    T flow(int s,int t){
        T flow=0;
        while(1){
            memset(seen,false,sizeof(seen));
            T f=dfs(s,t,numeric_limits::max(T));
            if(f==T(0))return flow;
            flow+=f;
        }
        return T(0);
    }    
};


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/

    int n,m;cin >> n >> m;
    maxflow<int> g(n*n+2);
    vector<vector<char>> s(n,vector<char>(n));
    rep(i,n)rep(j,n)cin >> s[i][j];
    rep(i,n)rep(j,n){
        if(s[i][j]=='#')continue;
        if((i+j)%2==0){
            g.add_edge(0,n*i+j+1,1);
        }else{
            g.add_edge(n*i+j+1,n*n+1,1);
        }
    }
    rep(i,n)rep(j,n){
        rep(k,4){
            int ni=i+dx[k],nj=j+dy[k];
        }
    }
}
