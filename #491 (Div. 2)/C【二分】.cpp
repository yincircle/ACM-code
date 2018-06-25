//http://codeforces.com/contest/991/problem/C
//二分
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll check(ll k){
    ll cnt=0,all=n;
    while(all>0){
        ll x=min(k,all);
        cnt+=x;
        all-=x;
        ll y=all/10;
        all-=y;
    }
    return cnt;
}
int main(){
    cin>>n;
    ll l=0,r=n;
    while(l+1<r){
        ll mid=l+(r-l)/2;
        if(2*check(mid)>=n)r=mid;
        else l=mid;
    }
    cout<<r;
    return 0;
}

