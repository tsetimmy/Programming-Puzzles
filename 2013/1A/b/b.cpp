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

ll E; // max amount of energy you can have.
ll R; // amount of energy you regain after each activity.
ll N; // number of activities planned for the day.
ll V[10000+1];
//ll hash[10000][10000];

ll maxg;

ll maximum (ll l, ll r) {
  if (l > r) return l; return r;
}

ll doit (ll n, ll c_E) {
  if (n > N) {
    return 0;
  }
//  if (c_E < 10000 && hash[n][c_E] != -1) {
//    return hash[n][c_E];
//  }


  ll n_E;
  ll n_g;
  ll bestg = -1;
  for (int e = 0; e <= c_E; e++) {
    n_g = e*V[n];
    n_E = c_E - e;
    n_E += R;

    if (n_E > E) n_E = E;
    n_g += doit(n+1, n_E);

    bestg = maximum(n_g, bestg);


  }
//  if (c_E < 10000) {
//    hash[n][c_E] = bestg;
//  }
  return bestg;
}

void solve (int t) {
  cin >> E >> R >> N;
  for (ll n = 1; n <= N; n++) {
    cin >> V[n];
  }

//  maxg = -1;
//  for (int i = 0; i < 10000; i++) {
//    for (int j = 0; j < 10000; j++) {
//      hash[i][j] = -1;
//    }
//  }
  maxg = doit(1,E);
  cout << "Case #" << t << ": " << maxg << endl;
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
