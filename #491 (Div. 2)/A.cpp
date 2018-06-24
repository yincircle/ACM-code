//http://codeforces.com/contest/991/problem/A

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    int num=a+b-c;
    if(n-num<=1)cout<<"-1";
    else cout<<n-num;
    return 0;
}

