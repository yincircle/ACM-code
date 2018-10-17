
ll phi(ll x){
    ll ret=x;
    for(ll i=2;i*i<=n;i++){
        if(x%i==0){
            ret=ret/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)ret=ret/x*(x-1);
    return ret;
}
