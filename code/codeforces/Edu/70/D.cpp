#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
 
ll A[maxn+50];
 
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    for(int i=1;i<=maxn;i++)
        A[i]=1ll*(i-1)*i/2;
    int T;
    scanf("%d",&T);
    int cnt[maxn+10];
    while(T--){
        memset(cnt,0,sizeof(cnt));
        ll n;
        scanf("%lld",&n);
        int f=0,len=0;
        int tmp=maxn;
        while(n){
            if(n>=A[tmp]){
                if(!f)len=tmp;
                f=1;
                n-=A[tmp];
                cnt[tmp]++;
            }
            else{
                tmp--;
            }
        }
        /*cout<<len<<endl;
        for(int i=0;i<=len;i++){
            cout<<i<<" "<<cnt[i]<<endl;
        }*/
        printf("13");
        for(int i=2;i<=len;i++){
            printf("3");
            while(cnt[i]){
                printf("7");
                cnt[i]--;
            }
        }
        puts("");
    }
    return 0;
}