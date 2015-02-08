// C++
#include <iostream>
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

char a[5000][4];
int s;
string ans;


bool check (char c) {
  bool flag;
  for (int i = s; i < s+4; i++) {
    flag = true;
    for (int j = 0; j < 4; j++) {
      if (a[i][j] != c && a[i][j] != 'T') {
        flag = false;
        break;
      }
    }
    if (flag) return flag;
  }

  for (int i = 0; i < 4; i++) {
    flag = true;
    for (int j = s; j < s+4; j++) {
      if (a[j][i] != c && a[j][i] != 'T') {
        flag = false;
        break;
      }
    }
    if (flag) return flag;
  }

  flag = true;
  for (int i = 0; i < 4; i++) {
    if (a[s+i][i] != c && a[s+i][i] != 'T') {
      flag = false;
      break;
    }
  }
  if (flag) return flag;

  flag = true;
  for (int i = 0; i < 4; i++) {
    if (a[s+i][3-i] != c && a[s+i][3-i] != 'T') {
      flag = false;
      break;
    }
  }
  if (flag) return flag;

  return false;
}

bool isDraw () {
  for (int i = s; i < s+4; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][j] == '.') return false;
    }
  }
  return true;
}

void solve (int t) {
  //cout << "START" << endl;
  s = (t-1)*4;
  bool O, X;
  O = check('O');
  X = check('X');
  if (O && !X) ans = "O won";
  if (!O && X) ans = "X won";
  if (!O && !X) {
    if (isDraw()) ans = "Draw";
    else ans = "Game has not completed";
  }
  //if (O && X) cout << "Wow..." << endl;

  //cout << "Here is the maze: " << endl;
  //for (int i = s; i < s+4; i++) {
    //for (int j = 0; j < 4; j++) {
      //cout << a[i][j];
    //}
    //cout << endl;
  //}

  cout << "Case #" << t << ": " << ans << endl;
}

int main () {
  int T; cin >> T;
  for (int t = 0; t < T*5; t++) {
    for (int u = 0; u < 4; u++) {
      cin >> a[t][u];
    }
  }
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
