#include <iostream>
#include <cmath>
#include <limits>
#include <cassert>
#include <iomanip>
using namespace std;

#define EPSILON 0.001

struct hot_dog {
  int P;
  int V;
};

int C, D;
hot_dog a[200];

bool enough (double time) {
  double furthest_left = -INFINITY;
  double left_edge, right_edge;

  for (int i = 0; i < C; i++) {
    for (int j = 0; j < a[i].V; j++) {
      if (furthest_left + (double)D < (double)a[i].P) {
        if (furthest_left + (double)D > (double)a[i].P - time) {
          furthest_left += (double)D;
        } else {
          furthest_left = (double)a[i].P - time;
        }
      } else if (furthest_left + (double)D > (double)a[i].P) {
        if (furthest_left + (double)D <= (double)a[i].P + time) {
          furthest_left += (double)D;
        } else {
          return false;
        }
      } else {
        furthest_left += (double)D;
      }
    }
  }
  return true;
}

double bin () {
  double lower_limit = 0.0;
  double upper_limit = 10e13;
  double middle;

  while (abs(upper_limit-lower_limit) > 10e-8*upper_limit) {
    middle = (upper_limit+lower_limit)/2;
    if (enough(middle)) {
      upper_limit = middle;
    } else {
      lower_limit = middle;
    }
  }
  cout << 10e-8*upper_limit;
  return middle;
}


void solve (int tcase) {
  cin >> C >> D;

  for (int i = 0; i < C; i++) {
    cin >> a[i].P >> a[i].V;
  }

  double ans = bin();

  cout << "Case #" << tcase << ": " << ans << endl;
}

int main () {
  cout << std::fixed;
  cout << std::setprecision(12);
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
