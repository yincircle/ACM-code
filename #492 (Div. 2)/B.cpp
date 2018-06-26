//http://codeforces.com/contest/996/problem/B
#include<bits/stdc++.h>
using namespace std;
int A[100005];
int n,temp,ans;
int main(){
    scanf("%d",&n);
    temp=2e9,ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        A[i]=A[i]-i+1;
        int now=(A[i]+n-1)/n+1;
        if(now<temp)temp=now,ans=i;
    }
    printf("%d\n",ans);
    return 0;
}
