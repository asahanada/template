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

template <ll mod> struct Fp{
    ll x;
    constexpr Fp(ll x=0) noexcept : x ((x%mod+mod)%mod){}
    /*-------ここから演算子-------*/
    constexpr Fp operator-() const noexcept{
        return Fp(-x);
    }
    constexpr Fp& operator+=(const Fp &a) noexcept{
        if((x+=a.x)>=mod)x-=mod;
        return *this;
    }
    constexpr Fp& operator-=(const Fp &a) noexcept{
        if((x+=mod-a.x)>=mod)x-=mod;
        return *this;
    }
    constexpr Fp& operator*=(const Fp &a) noexcept{
        (x*=a.x)%=mod;
        return *this;
    }
    constexpr Fp& operator/=(const Fp &a) noexcept{
        return (*this)*=a.inv();
    }
    constexpr Fp operator+(const Fp &a)const noexcept{
        Fp res(*this);
        return res+=a;
    }
    constexpr Fp operator-(const Fp &a)const noexcept{
        Fp res(*this);
        return res-=a;
    }
    constexpr Fp operator*(const Fp &a)const noexcept{
        Fp res(*this);
        return res*=a;
    }
    constexpr Fp operator/(const Fp &a)const noexcept{
        Fp res(*this);
        return res/=a;
    }
    
    constexpr bool operator==(const Fp &a)const noexcept{
        if((*this).x==a.x)return true;
        else return false;
    }
    constexpr bool operator!=(const Fp &a)const noexcept{
        return !((*this)==a);
    }
    constexpr bool operator<(const Fp &a)const noexcept{
        if((*this).x<a.x)return true;
        else return false;
    }
    constexpr bool operator>(const Fp &a)const noexcept{
        if((*this).x>a.x)return true;
        else return false;
    }
    constexpr bool operator<=(const Fp &a)const noexcept{
        return !((*this)>a);
    }
    constexpr bool operator>=(const Fp &a)const noexcept{
        return !((*this)<a);
    }
    /*-------ここまで演算子-------*/

    constexpr Fp pow(const ll &t)const noexcept{
        if(t==0)return (Fp)1;
        if(t%2==0){
            Fp k=pow(t/2);
            return k*k;
        }else{
            if(t>0)return (*this)*pow(t-1);
            else return pow(t+1)/(*this);
        }
    }
    constexpr Fp inv()const noexcept{
        return (Fp)forinv((*this).x,mod).first;
    }


    friend ostream& operator<<(ostream &os,const Fp &m)noexcept{
        os << m.x;
        return os;
    }
    friend istream& operator>>(istream &is,Fp &m)noexcept{
        is >> m.x;
        m.x%=mod;
        if(m.x<0)m.x=(m.x+mod)%mod;
        return is;
    }
 
private:
    //Euclidの互除法
    constexpr pair<ll,ll> forinv(ll a,ll b)const noexcept{
        if(b==0)return pair<ll,ll>(1,0);
 
        pair<ll,ll> ans = forinv(b,a%b);
        pair<ll,ll> t=pair<ll,ll>(ans.second,ans.first-a/b*ans.second);
        return t;
    }
};

using mint=Fp<big>;

/*-------comの処理関数たち-------*/
vector<mint> fac,facinv,inv;
//引数がmodに収まるときだけ使っていい
mint com(const mint &x,const mint &y)noexcept{
    if(y>x)return 0;
    mint ans=1;
    for(mint i=0;i<y;i+=1){
        ans*=(x-i)/(y-i);
    }
    return ans;
}
//引数がmodに収まらないときはこっちを使う
mint com2(const ll &x,const ll &y)noexcept{
    if(y>x||y<0||x<0)return 0;
    mint ans=1;
    rep(i,y){
        mint t=x-i,s=y-i;
        ans*=t/s;
    }
    return ans;
}
//大量のcomの処理の時
void cominit(const int &n)noexcept{
    fac.resize(n),facinv.resize(n),inv.resize(n);
    fac[0]=facinv[0]=fac[1]=facinv[1]=1;
    inv[1]=1;
    rep2(i,2,n){
        inv[i] = -inv[big%i]*(big/i);
        fac[i]=fac[i-1]*i;
        facinv[i]=facinv[i-1]*inv[i];
    }
    return;
}
mint coms(const mint &x,const mint &y)noexcept{
    if(y>x||y<0||x<0)return 0;
    return fac[x.x]*facinv[y.x]*facinv[(x-y).x];
}
/*-------comの処理終わり-------*/



int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/


}