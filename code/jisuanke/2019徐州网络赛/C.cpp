#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin>>n;
    if(n==2){
        cout<<"NO"<<endl;
        return 0;
    }
    if(n%2==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}