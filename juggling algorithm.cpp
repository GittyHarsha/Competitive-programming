/*
code by harsha_76

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

#define all(x) x.begin(), x.end()
#define rep(i, start, end) for(int i=start;i<end;i++)

void juggle(vector<int>& a, int n, int d)
{
    d=d%n;
    int g=__gcd(n, d);
    for(int i=0;i<g;i++)
    {
        int temp=a[i];
        int k=i+d;
        int j=i;
        while(k!=i)
        {
            a[j]=a[k];
            j=k;
            k=(k+d)%n;
        }
        a[j]=temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; printf("n = "); scanf("%d",&n);
    int d; printf("d = "); scanf("%d",&d);
    vi a(n);
    printf("elements : \n");
    for(int i=0;i<n;i++) cin>>a[i];
    juggle(a, n, d);
    cout<<"rotated array\n";
    for(int e:a)
    {
        cout<<e<<' ';
    }
    cout<<'\n';
    
    return 0;
}