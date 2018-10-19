inv[1]=1;
for(int i=2;i<=n;i++)
    inv[i]=(p-p/i)*inv[p%i]%p;

int get_inv(int n){
    if(n==1)
        return 1;
    return (p-p/n)*(get_inv(p%n))%p;
}
