/*
code by harsha_76

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

#define all(x) x.begin(), x.end()
#define rep(i, start, end) for(int i=start;i<end;i++)

void swapf(int a[], int f, int s, int d)
{
    for(int i=0;i<d;i++)
    {
        int temp=a[f+i];
        a[f+i]=a[s+i];
        a[s+i]=temp;
    }
}

void rotate(int a[], int d, int n)
{
    if(d==0||d==n)
    return;
   if(d>n)
   d=d%n;
    
    if(d==n-d)
    {
        swapf(a, 0, n-d, d);
        return;
    }
    else if(d<n-d)
    {
        swapf(a, 0, n-d, d);
        rotate(a, d, n-d);
    }
    else
    {
        swapf(a, 0, d, n-d);
        rotate(a+n-d, 2*d-n, d);
    }
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a[]={1, 2, 3, 4, 5, 6, 7};
    rotate(a, 6, 7);
    for(int e:a)
    {
        cout<<e<<' ';
    }
    cout<<'\n';
    
   
    
    return 0;
}