//http://codeforces.com/contest/991/problem/D
//Ä£Äâ
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s0,s1;
    cin>>s0>>s1;
    int n=s0.length();
    int ans=0;
    int pre=0;
    for(int i=0;i<n;i++){
        int cur=(s0[i]=='0')+(s1[i]=='0');
        if(cur==0)pre=0;
        else if(cur==1){
            if(pre==2){
                ans++;
                pre=0;
            }
            else pre=1;
        }
        else if(cur==2){
            if(pre>0){
                ans++;
                if(pre==2)pre=1;
                else pre=0;
            }
            else pre=2;
        }
    }
    cout<<ans;
    return 0;
}
