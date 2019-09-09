#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
__int128 exgcd(__int128 a, __int128 b, __int128 &x, __int128 &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    __int128 g, t;
    g = exgcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return g;
}
ll CRT(ll *m, ll *r, int n)
{
    __int128 p = m[0],res = r[0], x, y, g;
    for (int i = 1; i < n; i++)
    {
        g = exgcd(p, (__int128)m[i], x, y);
        if ((r[i] - res) % g)
            return -1;
        x = (r[i] - res) / g * x % (m[i] / g);
        res += x * p;
        p = p / g * m[i];
        res %= p;
    }
    if (res <= 0)
        res += p;
    return res;
}
ll m[150], r[150];
int n;

ll f[150];
unordered_map<ll,int>mp;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    f[0]=0;mp[0]=1;
    f[1]=1;mp[1]=1;
    for(int i=2;i<=100;i++){
        f[i]=f[i-1]+f[i-2];
        //assert(f[i]<=1e15);
        mp[f[i]]=1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &m[i], &r[i]);
    }
    ll ans = CRT(m, r, n);
    //cout<<ans<<endl;
    if(ans==-1){
        puts("Tankernb!");
    }
    else{
        if(mp[ans]){
            puts("Lbnb!");
        }
        else {
            puts("Zgxnb!");
        }
    }
    return 0;
}