//http://codeforces.com/contest/991/problem/B
#include<bits/stdc++.h>
using namespace std;
int n,sum,ans;
int A[105];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
        sum+=A[i];
    }
    sort(A,A+n);
    int goal=n*4.5+1;
    for(int i=0;i<n;i++){
        if(sum>=goal)break;
        if(A[i]!=5){
            ans++;
            sum+=5-A[i];
        }
    }
    cout<<ans;
    return 0;
}

