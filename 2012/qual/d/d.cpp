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

char mirror[120][120];
char map[30][30];
int H, W, D;

int x, y;
vector<pair<int,int> > slope;

bool okay (int i, int j) {

  int rise = abs(i-x);
  int run = abs(j-y);

  if (rise*rise + run*run > 2*D*D) {
    return false;
  }
  if (slope.empty()) {
    slope.push_back(make_pair(rise,run));
    return true;
  }
  for (int c = 0; c < slope.size(); c++) {
    if (slope[c].first*run == rise*slope[c].second) {
      return false;
    }
  }

  slope.push_back(make_pair(rise,run));
  return true;

}

void clear () {
  for (int i = 0; i < 120; i++) {
    for (int j = 0; j < 120; j++) {
      mirror[i][j] = '*';
    }
  }
}

void solve (int t) {
  clear();
  cin >> H >> W >> D;
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      cin >> map[h][w];
    }
  }

  // initial writing
  for (int h = 1; h <= H-2; h++) {
    for (int w = 1; w <= W-2; w++) {
      mirror[59-(H-2)+h][59-(W-2)+w] = map[h][w];
    }
  }



  for (int i = 0; i < 120; i++) {
    for (int j = 0; j < 120; j++) {
      if (mirror[i][j] == 'X') {
        x = i;
        y = j;
      }
    }
  }

  // left
  for (int h = 1; h <= H-2; h++) {
    for (int w = 1; w <= W-2; w++) {
      mirror[59-(H-2)+h][59-(W-2)+1-w] = mirror[59-(H-2)+h][59-(W-2)+w];
    }
  }

  // up
  for (int h = 1; h <= H-2; h++) {
    for (int w = 0; w <= 120; w++) {
      mirror[59-(H-2)+1-h][w] = mirror[59-(H-2)+h][w];
    }
  }

  // right
  for (int w = 60; w < 120; w++) {
    for (int h = 0; h < 120; h++) {
      mirror[h][w] = mirror[h][120-1-w];
    }
  }

  // down
  for (int h = 60; h < 120; h++) {
    for (int w = 0; w < 120; w++) {
      mirror[h][w] = mirror[120-1-h][w];
    }
  }

  slope.clear();
  int ans = 0;
  for (int h = 0; h < 120; h++) {
    for (int w = 0; w < 120; w++) {
      if (mirror[h][w] == 'X' && !(h == x && w == y)) {
        if (okay(h,w)) {
          ans++;
        }
      }
    }
  }

  cout << "Case #" << t << ": " << ans << endl;


















//  // left
//  for (int h = 1; h <= H-2; h++) {
//    for (int w = 1; w <= W-2; w++) {
//      mirror[59+h][59-(W-2)-w+1] = mirror[59+h][59-(W-2)+w];
//    }
//  }
//
//  // up
//  for (int h = 60; h < 120; h++) {
//    for (int w = 0; w < 120; w++) {
//      mirror[120-1-h][w] = mirror[h][w];
//    }
//  }
//
//  // right
//  for (int h = 0; h < 120; h++) {
//    for (int w = 0; w < 60; w++) {
//      mirror[h][120-1-w] = mirror[h][w];
//    }
//  }





  for (int i = 0; i < 120; i++) {
    for (int j = 0; j < 120; j++) {
      cout << mirror[i][j];
    }
    cout << endl;
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
