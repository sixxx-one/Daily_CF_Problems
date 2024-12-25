#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 1e6+10;

int t[N];
int n,k;

void add(int i,int x)
{
    while(i<N)
    {
        t[i]+=x;
        i+=i&-i;
    }
}

int ask(int i)
{
    int res = 0;
    while(i)
    {
        res+=t[i];
        i-=i&-i;
    }
    return res;
}

int ask(int l,int r)
{
    if(l>r)
    {
        swap(l,r);
        return ask(n)-ask(r)+ask(l-1);
    }
    r--,l++;
    return ask(r)-ask(l-1);
}

void solve()
{
    cin >> n >> k ;
    int m = n,i = 1;
    int ans = 1;
    while(m--)
    {
        int j = (i+k)%n;
        if(j==0)j=n;
        if(2*k<n)ans+=ask(i,j)+1;
        else ans += ask(j,i)+1;
        add(i,1);
        add(j,1);
        i = j;
        cout << ans << ' ';
    }
    // add(1,1),add(4,2),add(7,1);
    // cout << ask(7,10) << endl;
}

signed main()
{
    IOS
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}
