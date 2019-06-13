#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000050;

int Next[maxn];

void getnext(char *b,int *Next,int len){
    int i=0,j=Next[0]=-1;
    while(i<len){
        if(j==-1||b[i]==b[j])Next[++i]=++j;
        else j=Next[j];
    }
}

char s[maxn];

int get_posmin(char *s){
    int len=strlen(s);
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len){
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0)
            k++;
        else {
            if(t>0)
                i+=k+1;
            else
                j+=k+1;
            if(i==j)j++;
            k=0;
        }
    }
    return min(i,j);
}

int get_posmax(char *s){
    int len=strlen(s);
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len){
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0)
            k++;
        else {
            if(t>0)
                j+=k+1;
            else 
                i+=k+1;
            if(i==j)j++;
            k=0;
        }
    }
    return min(i,j);
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    while(scanf("%s",s)!=EOF){
        int n=strlen(s);
        getnext(s,Next,n);
        int res=n-Next[n];
        int cnt=1;
        if(n%res==0){
            cnt=n/res;
        }
        int posmin=get_posmin(s);
        int posmax=get_posmax(s);
        printf("%d %d %d %d\n",posmin+1,cnt,posmax+1,cnt);
    }
    return 0;
}