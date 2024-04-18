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
  public:
      SegmentTree(int sz) {
          n=sz;
          a.resize(n);
          t.resize(4*n+5);
          fill(t.begin(), t.end(), 0);
          fill(a.begin(), a.end(), 0);
          build(a, 1, 0, n-1);
      }
      SegmentTree(vector<int> arr){
          n=arr.size();
          a=arr;
          t.resize(4*n+5);
          fill(t.begin(), t.end(), 0);
          build(a, 1, 0, n-1);
      }
      
      void build(vector<int> a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void update_helper(int v, int tl, int tr, int l, int r, int add) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            t[v] += add;
        } else {
            int tm = (tl + tr) / 2;
            update_helper(v*2, tl, tm, l, min(r, tm), add);
            update_helper(v*2+1, tm+1, tr, max(l, tm+1), r, add);
        }
    }
    
    void update(int l, int r, int add) {
        update_helper(1, 0, n-1, l, r, add);
    }
    
    int get_helper(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get_helper(v*2, tl, tm, pos);
        else
            return t[v] + get_helper(v*2+1, tm+1, tr, pos);
    }
    
    int get(int pos) {
        return get_helper(1, 0, n-1, pos);
    }
};
int main()
{
    vector<int> a={1, 2, 3, 4, 5};
    SegmentTree sg(a);
    sg.update(0, 3, -2);
    cout<<sg.get(0);

    return 0;
}
