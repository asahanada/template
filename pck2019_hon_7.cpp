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
        cout << expm(k,n,m) << endl;return 0;
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
    dp[S][j]:=これまでに出た差分の状態がSで,最後に出たのがj+1.
    ダメになった時点でansに加える,適当になにかのべき乗をかけるパートが存在するので頑張る
    */

    vector<vector<mint>> dp(1<<(2*k-1),vector<mint>(k,mint(0)));
    rep(i,k){
        dp[0][i]=1;
    }
    /*
    差分は最小で1-k.
    これを0に持ってきたいのだから,Sにおいてはk-1を加えた桁の所に持つ.
    dp[S][i]→dp[S|(1<<(j-i+k-1))][j]みたいな感じになるかな...
    */

    vector<pair<int,int>> bits;
    rep(S,1<<(2*k-1)){
        int cnt=bitset<20>(S).count();
        bits.push_back({cnt,S});
    }
    sort(all(bits));
    mint ans=0;
    for(auto now:bits){
        int S=now.second;
        int cnt=now.first+1;
        if(cnt>=n)break;
        rep(j,k)rep(i,k){//dp[S][j]からdp[S|(i-j+k-1番めのbit)][i]への遷移
            if((S>>(i-j+k-1))&1){
                cout << (bitset<3>(S)) << ' ' << j << ' ' << i << endl;
                cout << expm(k,n-cnt-1,m) << endl;
                cout << k  << ' ' << n-cnt-1 << endl;
                ans=ans+mint(expm(k,n-cnt-1,m));continue;
            }
            dp[S+(1<<(i-j+k-1))][i]=dp[S+(1<<(i-j+k-1))][i]+dp[S][j];
        }
    }
    cout << ans.x << endl;
}
