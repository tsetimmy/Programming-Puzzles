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

vector<int> s;

void doit (bool& done) {
  if (done) return;
  if (s.size() == N) {
    done = true;
    return;
  }

  for (int n = 1; n <= N; n++) {
    if (!taken[n] && keys[chests[n].type] > 0) { // I can unlock this chest.
      keys[chests[n].type]--;
      for (int i = 0; i < chests[n].kcount; i++) {
        keys[chests[n].keys[i]]++;
      }

      s.push_back(n);
      taken[n] = true;
      doit(done);
      taken[n] = false;
      if (done) return;
      s.pop_back();

      keys[chests[n].type]++;
      for (int i = 0; i < chests[n].kcount; i++) {
        keys[chests[n].keys[i]]--;
      }
    }
  }




}
void solve (int t) {
//  for (int i = 0; i < 201; i++) keys[i] = 0;
//  cin >> K >> N;
//  int k;
//  for (int i = 1; i <= K; i++) {
//    cin >> k;
//    keys[k]++;
//  }
//  for (int i = 1; i <= N; i++) {
//    cin >> chests[i].type;
//    cin >> chests[i].kcount;
//    chests[i].keys.clear();
//    for (int j = 1; j <= chests[i].kcount; j++) {
//      cin >> k;
//      chests[i].keys.push_back(k);
//    }
//  }
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







  for (int i = 0; i < 201; i++) taken[i] = false;

  bool done = false;
  s.clear();
  doit(done);

  cout << "Case #" << t << ": ";

  if (s.empty()) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    for (int i = 0; i < s.size(); i++) {
      cout << s[i];
      if (i != s.size()-1) cout << " ";
      else cout << endl;
    }
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
