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

struct chest {
  int type;
  int kcount;
  vector<int> keys;
};

#define num 201
int K; // No. of keys
int N; // No. of chests you need to open
int keys[num];
int keys2[num];
chest chests[num];
bool taken[num];
bool taken2[num];
vector<int> ans;

//bool match () {
//  for (int i = 0; i < num; i++) {
//    keys2[i] = keys[i];
//  }
//  for (int i = 1; i <= N; i++) {
//    if (!taken[i]) { // ith chest is not taken
//      for (int j = 0; j < chests[i].kcount; j++) {
//        keys2[chests[i].keys[j]]++;
//      }
//    }
//  }
//}

bool allopen (bool* tt) {
  for (int i = 1; i <= N; i++) {
    if (!tt[i]) return false;
  }
  return true;
}

bool reachable () {
  for (int i = 0; i < num; i++) {
    keys2[i] = keys[i];
    taken2[i] = taken[i];
  }

  bool opened_a_chest;

  while (true) {
    if (allopen(taken2)) return true;
    opened_a_chest = false;

    for (int idx = 1; idx <= N; idx++) {
      if (keys2[chests[idx].type] > 0 && !taken2[idx]) {
        taken2[idx] = true;
        opened_a_chest = true;
        for (int j = 0; j < chests[idx].kcount; j++) {
          keys2[chests[idx].keys[j]]++;
        }
      }
    }
    if (!opened_a_chest && !allopen(taken2)) return false;
  }
}

void doit (bool& done) {
  if (ans.size() == N) done = true;
  if (done) return;
  if (!reachable()) return;

  for (int n = 1; n <= N; n++) {
    if (!taken[n] && keys[chests[n].type] > 0) {


      for (int j = 0; j < chests[n].kcount; j++) {
        keys[chests[n].keys[j]]++;
      }
      keys[chests[n].type]--;
      taken[n] = true;
      ans.push_back(n);
      doit(done);
      if (done) return;
      ans.pop_back();
      keys[chests[n].type]++;
      taken[n] = false;
      for (int j = 0; j < chests[n].kcount; j++) {
        keys[chests[n].keys[j]]--;
      }




    }
  }



}

void solve (int t) {
  for (int i = 0; i < num; i++) {
    keys[i] = 0;
    keys2[i] = 0;
  }
  cin >> K >> N;
  int k;
  for (int i = 1; i <= K; i++) {
    cin >> k;
    keys[k]++;
    keys2[k]++;
  }
  for (int i = 1; i <= N; i++) {
    cin >> chests[i].type;
    cin >> chests[i].kcount;
    chests[i].keys.clear();
    for (int j = 1; j <= chests[i].kcount; j++) {
      cin >> k;
      chests[i].keys.push_back(k);
      keys2[k]++;
    }
  }

  for (int i = 1; i <= N; i++) {
    keys2[chests[i].type]--;
  }
  for (int i = 0; i < num; i++) {
    if (keys2[i] < 0) {
      cout << "Case #" << t << ": IMPOSSIBLE" << endl;
      return;
    }
  }

  for (int i = 0; i < num; i++) taken[i] = false;
  bool done = false;
  ans.clear();
  doit(done);

  if (ans.empty()) {
    cout << "Case #" << t << ": IMPOSSIBLE" << endl;
    return;
  }

  cout << "Case #" << t << ": ";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size()-1) cout << endl;
    else cout << " ";
  }






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
