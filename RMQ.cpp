#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)()
#define all(a) a.begin(),a.end()
#define vec vector
typedef long long ll;
typedef pair<ll,ll> P;
//const ll big=998244353;
const ll big=1000000007LL;
//const ll infi=1e18;
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
ll inv(ll x){
    return expm(x,big-2);
}

template <typename T>
struct RMQ{
    int n;
    vec<T> dat;
    
    T infi=numeric_limits<int>::max();
    RMQ(int m):n(m),dat(2*m-1,numeric_limits<int>::max()){}

    void update(int i,T x){//i番目をxに更新
        i+=n-1;
        dat[i]=x;
        while(i>0){
            i=(i-1)/2;
            dat[i]=min(dat[2*i+1],dat[2*i+2]);
        }
        return;
    }

    T query(int a,int b){//[a,b)のminをreturnする
        return q_sub(a,b,0,0,n);
    }
    //[a,b)の中に入ってるノードでminを求めていく
    T q_sub(int a,int b,int k,int l,int r){//kは今見ているノードのindex
        if(r<=a||b<=l)return infi;//範囲外の時
        else if(a<=l&&r<=b){//完全に範囲内
            return dat[k];
        }else{//一部かぶってるので子に任せる
            return min(q_sub(a,b,k*2+1,l,(l+r)/2),q_sub(a,b,k*2+2,(l+r)/2,r));
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/

    int n,q;cin >> n >> q;
    int k=1;
    while(k<n)k*=2;
    
    vec<int> out;
    RMQ<ll> rmq(k);

    rep(i,q){
        int com;ll x,y;cin >> com >> x >> y;
        if(com==0){
            rmq.update(x,y);
        }
        else out.emplace_back(rmq.query(x,y+1));
    }
    rep(i,out.size())cout << out[i] << endl;
}//https://algo-logic.info/segment-tree/