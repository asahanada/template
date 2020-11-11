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
//const ll big=998244353LL;
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
ll expm(ll x,ll y,ll mod){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (expm(x,y-1,mod)*x)%mod;
    ll t=expm(x,y/2,mod);
    return (t*t)%mod;
}
ll exp(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||y==0)return x;
    if(y%2==1)return exp(x,y-1)*x;
    ll t=exp(x,y/2);
    return t*t;
}
int m;
struct mint{
    ll x;
    mint(const ll _):x(_%m){
        if(x<0)x+=m;
    }
    friend mint operator+(const mint &a,const mint &b){
        return mint(a.x+b.x);
    }
    friend mint operator*(const mint &a,const mint &b){
        return mint(a.x*b.x);
    }
};

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/

    int n,k;
    cin >> n >> k >> m;
    if(n-1>2*k-1){
        cout << expm(k,n,m) << endl;
    }
    /*
    最初の値がk通り
    これは全探索しても高々10通り
    そこから先が問題で,どうしよう.
    差分の数列をとるともしも同じ値が現れたらだめ
    差分として現れうるのが2*k-1(<=19)通り.
    これまでにiが出てきたかどうかを確認していると,時間が,ぎりぎり？
    状態が
    (もうやばい) or (まだ平気)
        1            2^19
    */
    /*
    dp[i][S]:=i番めまで見て,これまでに出た差分の状態がS.
    */
}
