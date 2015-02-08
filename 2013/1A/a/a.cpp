// C++
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
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

ll r, vol, k, counter;
void solve (int t) {



  cin >> r >> vol;
  k = 1;
  counter = 0;
  ll amount;


  while (true) {
    //amount = (r+2*k-1)*(r+2*k-1)-(r+2*k-2)*(r+2*k-2);
    amount = 4*k+2*r-3;
    if (vol-amount >= 0) {
      vol = vol - amount;
      k++;
      counter++;

    } else {
      break;
    }

  }
  cout << "Case #" << t << ": " << counter << endl;

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
