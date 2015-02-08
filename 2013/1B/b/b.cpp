// C++
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <utility> // pair
// C
#include <stdlib.h> // atoi, qsort
#include <math.h>
#include <assert.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()
string tokenize (string &target, string delimiter);

#define xmax 20000
#define ymax 10000

int N, xx, yy;
double grid[xmax+1][ymax+1];

void set (int x, int y, double val) {
  grid[x+10000][y]= val;
}

double get (int x, int y) {
  return grid[x+10000][y];
}

void clear () {
  for (int i = 0; i < xmax+1; i++) for (int j = 0; j < ymax+1; j++) grid[i][j] = 0.0;
}

int binomial (int n, int k) {
  if (k < 0 || k > n) return 0;
  if (k == 0 || k == n) return 1;
  return binomial(n-1,k-1)+binomial(n-1,k);
}

int getlevel () {
  return (int)((sqrt(8*N+1)+1)/4);
}

void doit (int l,int fcount) {
  int amount = 2*l-1;
  int xstart = (amount/2)*3;
  int ystart = 0;

  int xs, ys;
  while (amount >= 0) {
    xs = xstart;
    ys = ystart;

    for (int i = 0; i < amount; i++) {
      set(xs,ys,1.0);
      xs= xs- 2;
    }
    xstart--;
    ystart++;
    amount--;
  }

  if (fcount == 0) return;
  amount = 2*l-1;
  





  int xpos = (amount/2)*2+2;
  int y =0;

  int max_slots = 1+(4*l-1-1)/2;
  int mini = 0;
  double denom = 0.0;

  if (max_slots >= fcount) denom = pow(2,fcount);
  else {
    mini = fcount - max_slots;
    for (int i = mini; i <= max_slots; i++) denom += binomial(fcount, i);
  }
  assert(denom > 0.0);

  int start = 1;
  if (mini != 0) {
    for (int i = 0; i < mini; i++) {
      set(xpos, y, 1.0);
      set(-1*xpos, y, 1.0);
      xpos--;
      y++;
    }
    start = mini+1;
  }

  if (fcount < max_slots) {
    max_slots = fcount;
    assert(mini == 0);
  }

  double numer;
  for (int i = start; i <= max_slots; i++) {
    numer = 0.0;
    for (int j = i; j <= max_slots; j++) {
      numer += binomial(fcount,j);
    }
    assert(numer > 0.0);
    set(xpos,y,numer/denom);
    set(-1*xpos,y,numer/denom);
    xpos--;
    y++;
  }




//  double denom = pow(2,fcount);
//  assert(denom > 0.0);
//
//  for (int i = 1; i <= fcount; i++) {
//    set(xpos,y,(double)(binomial(i,fcount)/denom));
//    set(-1*xpos,y,(double)(binomial(i,fcount)/denom));
//    xpos--;
//    y++;
//  }

}

void solve (int t) {
  clear();
  cin >> N >> xx >> yy;

  int level = getlevel();
  int fcount = N-level*(2*level-1);
  assert(fcount >= 0);
  assert(level >= 1);

  doit(level,fcount);

  cout << std::fixed;
  cout << "Case #" << t << ": " << std::setprecision(9) << get(xx,yy) << endl;

}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++)
    solve(t);
  return 0;
}







































































































string tokenize (string &target, string delimiter) {
  if (target == "")
    return target;

    string ret = "";
    size_t found = target.find(delimiter);
    if (found == std::string::npos && target != "") {
      ret = target;
      target = "";
    } else {
      ret = target.substr(0, found);
      target = target.substr(found+1,target.length());
    }
    return ret;
}
