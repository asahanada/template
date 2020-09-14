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
typedef pair<ll,ll> P;
//const ll big=998244353;
const ll big=1000000007LL;
const ll INF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
if(x<y)return x;
else return y;
}
ll expm(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (expm(x,y-1)*x)%big;
    ll t=expm(x,y/2);
    return (t*t)%big;
}
ll exp(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||y==0)return x;
    if(y%2==1)return exp(x,y-1)*x;
    ll t=exp(x,y/2);
    return t*t;
}


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/

    
}
