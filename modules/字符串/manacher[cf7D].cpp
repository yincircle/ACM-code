#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6 + 50;

int ma[maxn*2];
void manacher(char s[])
{
    int n = strlen(s);
    int id=0, ub=0;
    for(int i=0; i<2*n-1; i++) {
        int p=i/2, q=(i+1)/2;
        int l = q<ub?min(ub-q, ma[id-i]):0;
        while(p-l>=0 && q+l<n && s[p-l]==s[q+l]) l++;
        if(ub < q+l) {
            ub = q+l;
            id = i*2;
        }
        ma[i] = l;
    }
    for(int i=0; i<2*n-1; i++)
        ma[i] = ma[i]*2-(!(i&1));
}

char s[maxn];
int dp[maxn*2];
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%s",s);
    int n=strlen(s);
    manacher(s);
    ll ans=0;
    for(int i=0;i<n;i++){
        if(ma[i]==i+1){
            dp[i]++;
            if(i%2==1&&ma[i-(i+1)/2]<=ma[i+(i+1)/2]){
                dp[i]=dp[i-(i+1)/2]+1;
            }
            else if(i%2==0&&ma[i/2-1]<=ma[i/2*3+1]){
                dp[i]=dp[i/2-1]+1;
            }
        }
        ans+=dp[i];
        //cout<<i<<" "<<ma[i]<<" "<<dp[i]<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}