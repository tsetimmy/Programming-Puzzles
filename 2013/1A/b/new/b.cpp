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


ull g;
ll c_E;


void solve (int t) {
  cin >> E >> R >> N;
  for (ll n = 1; n <= N; n++) {
    cin >> V[n];
  }


  g = 0;
  c_E = E;

  ll max, max_idx;
  for (ll n = 1; n <= N; n++) {
    max = V[n];
    max_idx = n;
    for (ll m = n + 1; m <= N; m++) {
      if (max < V[m]) {
        max = V[m];
        max_idx = m;
        break;
      }
    }

    if (max == V[n] || (max_idx-n)*R >= E) {
      g += V[n]*c_E;
      c_E = R;
      if (c_E > E) c_E = E;
    } else if (c_E+(max_idx-n)*R >= E) {
      ll amount = ((max_idx-n)*R+c_E)%E;
      g += amount*V[n];
      c_E -= amount;
      c_E += R;
    } else {
      c_E += R;
    }

  }

  cout << "Case #" << t << ": " << g << endl;




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
