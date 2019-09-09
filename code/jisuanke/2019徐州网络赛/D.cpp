#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 50;

int Next[maxn];

void getnext(char *b,int *Next,int len){
    int i=0,j=Next[0]=-1;
    while(i<len){
        if(j==-1||b[i]==b[j])Next[++i]=++j;
        else j=Next[j];
    }
}

int Kmp(char *a,char *b,int lena,int lenb){
    int i,j;
    //getnext(b,Next,lenb);
    i=j=0;
    while(i<lena){
        if(j==-1||a[i]==b[j]){
            i++;
            j++;
        }
        else j=Next[j];
        if(j==min(lenb,lena))return 1;
    }
    return -1;
}

char s[maxn];
char ss[maxn];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%s",s);
    int n=strlen(s);
    getnext(s,Next,n);
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%s",ss);
        int len=strlen(ss);
        int tmp=Kmp(ss,s,len,n);
        if(len<n){
            if(tmp==-1){
                puts("oh, child!");
            }
            else{
                puts("my child!");
            }
        }
        else if(len>n){
            if(tmp==-1){
                puts("senior!");
            }
            else{
                puts("my teacher!");
            }
        }
        else{
            if(tmp==-1){
                puts("friend!");
            }
            else{
                puts("jntm!");
            }
        }
    }
    return 0;
}