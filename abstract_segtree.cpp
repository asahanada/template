#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep2(i,s,n) for(int i=s;i<(int)n;i++)
typedef long long ll;

int ceil_two(int n){
    int res=1;
    while(res<n)res*=2;
    return res;
}

template<class T,
         T (*op)(T,T),
         T (*e)()>
struct segtree{
    int n;
    int sz;
    vector<T> a;
    segtree(const int n_) : segtree(vector<T>(n_,e())) {}
    segtree(const vector<T> &v) : n((int)v.size()) {
        sz=ceil_two(n);//2冪だけ用意
        a.resize(sz*2,e());
        rep(i,n)change(i,v[i]);
    }
    //内部実装は1_indexed
    //iの親:i/2
    //iの子供:2*i,2*i+1
    void change(int s,T x){//親に行く
        s+=sz;
        a[s]=x;
        for(int i=s/2;i>0;i/=2){
            a[i]=op(a[2*i] , a[2*i+1]);
        }
        return;
    }
    T get(int l,int r){//[l,r)での総積
        l++;r++;
        return getsub(l,r,1,sz+1,1);
    }//T(0)
    T getsub(int l,int r,int ll,int rr,int k){//区間[l,r)を得るのが目標(1_indexed) [ll,rr)を今見ていて、そのindexはk
        if(l<=ll && rr<=r)return a[k];
        if(rr<=l || r<=ll)return e();
        else return op(getsub(l,r,ll,(ll+rr)/2,2*k) , getsub(l,r,(ll+rr)/2,rr,2*k+1));
    }
};
