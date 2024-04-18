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
    vector<int> marked;
  public:
      SegmentTree(int sz) {
          n=sz;
          marked.resize(n);
          fill(marked.begin(),marked.end(), 0);
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
          marked.resize(n);
          fill(marked.begin(),marked.end(), 0);
          fill(t.begin(), t.end(), 0);
          build(a, 1, 0, n-1);
      }
      void push(int v) {
            if (marked[v]) {
                t[v*2] = t[v*2+1] = t[v];
                marked[v*2] = marked[v*2+1] = true;
                marked[v] = false;
            }
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
    void update_helper(int v, int tl, int tr, int l, int r, int new_val) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v] = new_val;
            marked[v] = true;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update_helper(v*2, tl, tm, l, min(r, tm), new_val);
            update_helper(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        }
    }

    
    void update(int l, int r, int add) {
        update_helper(1, 0, n-1, l, r, add);
    }
    
    int get_helper(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm) 
            return get_helper(v*2, tl, tm, pos);
        else
            return get_helper(v*2+1, tm+1, tr, pos);
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
