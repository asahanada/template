#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI=acos(-1);

vector<complex<double>> fft(vector<complex<double>> a,bool inv = false){//aはsizeが2冪になるようにしておく
    int n=a.size();
    int h=0;//h=log(n)
    for(int i=0;1<<i < n;i++)h++;
    rep(i,n){
        int j=0;
        rep(k,h)j |= (i>>k & 1)<<(h-k-1);//ひっくり返す k番目のフラグをh-k-1番目に持っていく
        if(i<j)swap(a[i],a[j]);
    }
    
    //バタフライ演算する
    for(int b=1;b<n;b*=2){//ブロックサイズb*2のところでの演算をする
        rep(j,b){//各ブロック内j段目から送るやつ
            complex<double> w = polar(1.0 , (2*PI)/(2*b) * j * (inv ? 1 : -1));
            for(int k=0;k<n;k+=2*b){
                complex<double> s=a[j+k] , t=a[j+k+b]*w;
                a[j+k]=s+t;
                a[j+k+b]=s-t;
            }
        }
    }
    if(inv)rep(i,n)a[i]/=n;
    return a;
}
 
vector<complex<double>> fft(vector<double> a,bool inv = false){
    vector<complex<double>> a_(a.size());
    rep(i,a.size())a_[i]=complex<double>(a[i],0);
    return fft(a_,inv);
}
 
vector<double> convolve(vector<double> a,vector<double> b){
    int s=a.size()+b.size()-1;
    int t=1;
    while(t<s)t*=2;
    a.resize(t),b.resize(t);
    vector<complex<double>> A=fft(a) , B=fft(b);
    rep(i,t)A[i]*=B[i];
    A=fft(A,true);
    a.resize(s);
    rep(i,s)a[i]=A[i].real();
    return a;
}
