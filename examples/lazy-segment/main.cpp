#include <stdio.h>
#include <vector>

using namespace std;

struct data {
   int sum;
   int delta;
   data() {
     sum = 0;
     delta = 0;
   }
} invalid;


int left(int p) {
    return p<<1;
}

int right(int p) {
    return p<<1+1;
}

void build(p,int L, int R,vector<data> &st) {
   data default;
   
   st[p] = default;
   if (L==R) return;

   build(left(p) , L        , (L+R)/2, st);
   build(right(p), (L+R)/2+1, R      , st);
}

int query(p,int L, int R, int qL, int qR, vector<data> &st) {
   int size = R-L;
   int p1,p2;
 
   // out of range
   if (R < qL || L > qR) return -1;

   if (L >= qL &&  R <= qR) // complete overlap
      return st[p].sum + st[p].delta * size;

   // Otherwise, split range and check.  Propagate delta
   // downward first.

   st[left(p)].delta += st[p].delta;
   st[right(p)].delta += st[p].delta;
   st[p].delta = 0;

   p1 = query(left(p) , L        , (L+R)/2, i, j, st);
   p2 = query(right(p), (L+R)/2+1, R      , i, j, st);
   
   if (p1 == -1) return p2;
   if (p2 == -1) return p1;

   return p1 + p2;
}

int update(p,int L, int R, int qL, int qR, int delta, vector<data> &st) {
   int size = R-L;
   int p1,p2;
 
   // out of range
   if (R < qL || L > qR) return 0;

   if (L == R) {
      st[p].sum += st[p].delta + delta;
      st[p].delta = 0;
      return st[p].sum;
   }

   if (L >= qL &&  R <= qR)  { // complete overlap
      st[p].delta += delta;
      return st[p].sum + st[p].delta * size;
   }

   // Otherwise, split range and propagate.  Propagate current delta first. 

   st[left(p)].delta += st[p].delta;
   st[right(p)].delta += st[p].delta;

   p1 = update(left(p) , L        , (L+R)/2, i, j, delta, st);
   p2 = update(right(p), (L+R)/2+1, R      , i, j, delta, st);
   
   st[p].sum = p1 + p2;
   st[p].delta = 0;

   return st[p].sum;
}

int main() {
    int r,nu,nq; // range, num updates, num queries
    int i,j;

    vector<data> st(400000); // For ranges 1..100000
    invalid.sum = -1;

    scanf("%d %d %r",&r,&nu,&nq);
    build(1,1,r,st);

    // etc

}

