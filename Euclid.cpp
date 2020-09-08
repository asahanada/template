#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> Euclid(ll a,ll b){
    if(b==0){
        return pair<ll,ll>(1,0);
    }
    pair<ll,ll> ans = Euclid(b,a%b);
    pair<ll,ll> t=pair<ll,ll>(ans.second,ans.first-a/b*ans.second);
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/

    
}