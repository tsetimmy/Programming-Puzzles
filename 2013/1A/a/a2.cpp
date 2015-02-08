// C++
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <utility> // pair
// C
#include <stdlib.h> // atoi, qsort
#include <math.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()
string tokenize (string &target, string delimiter);

ull r, vol, x;

ull CF (ull input) {
  return input*(2*r+2*input-1);
}

ull bin (ull l, ull r, ull target) {
  if (l == r) cout << "special" << endl;
  ull dd;

  if (l > r) dd = l-r; else dd = r-l;

  ull piv = (l+r)/2;
  if (CF(l)==target) return l;
  if (CF(r)==target) return r;





  if (dd==1 && CF(l) < target && CF(r) > target) return l;

  if (CF(piv) > target) {
    return bin(l, piv, target);

  } else if (CF(piv) < target) {
    return bin(piv, r, target);
  } else {
    return piv;
  }

}


void solve (int t) {
  cin >> r >> vol;

  ull left = 0;
  ull right = 1;

  while (!(vol <= CF(right))) {
    left = right;
    right = right*2;
  }

 
 x = bin(left,right,vol);
 cout << "Case #" << t << ": " << x << endl;





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
