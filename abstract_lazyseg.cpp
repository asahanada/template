#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)

int ceil_two(int n){
    int res=1;
    while(res<n)res*=2;
    return res;
}

template<typename S,
         S (*op)(S,S),
         S (*e)(),
         typename F,
         S (*mapping)(F,S),
         F (*composition)(F,F),
         F (*id)()>
struct lazyseg{
    int n;
    int sz;
    vector<T> a;
    vector<F> lz;
    lazyseg(const int n_) : lazyseg(vector<T>(n_,e())){}
    lazyseg(const vector<T> &v) : n(v.size()){
        int sz=ceil_two(n);
    }
    void change(int s,const T x){

    }
};
