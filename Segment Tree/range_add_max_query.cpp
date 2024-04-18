#include <bits/stdc++.h>
using namespace std;
/* 
Range update: adding to a range 
point query
*/

class SegmentTree {
    
    int n;
    vector<int> t;
    vector<int> a;
    vector<int> lazy;

  public:
      SegmentTree(int sz) {
          n=sz;
          a.resize(n);
          t.resize(4*n+5);
          lazy.resize(4*n+5);
          fill(lazy.begin(), lazy.end(), 0);
          fill(t.begin(), t.end(), 0);
          fill(a.begin(), a.end(), 0);
          build(a, 1, 0, n-1);
      }
      SegmentTree(vector<int> arr){
          n=arr.size();
          a=arr;
          t.resize(4*n+5);
          lazy.resize(4*n+5);
          fill(lazy.begin(), lazy.end(), 0);
          fill(t.begin(), t.end(), 0);
          build(a, 1, 0, n-1);
      }
      
      void build(vector<int>a , int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2 + 1]);
        }
    }

    void push(int v) {
        t[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        t[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }

    void update_helper(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update_helper(v*2, tl, tm, l, min(r, tm), addend);
            update_helper(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    void update(int l, int r, int addend) {
        update_helper(1, 0, n-1, l, r, addend);
    }
    int query_helper(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return INT_MIN;
        if (l == tl && tr == r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return max(query_helper(v*2, tl, tm, l, min(r, tm)), 
                query_helper(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    int query(int l, int r) {
        return query_helper(1, 0, n-1, l, r);
    }
};
int main()
{
    vector<int> a={1, 2, 10, 1, 5};
    SegmentTree sg(a);
   
    cout<<sg.query(1, 3);

    return 0;
}
