#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef long long ll;
#define ULLMAX std::numeric_limits<long long>::max()

struct point {
  ll x;
  ll y;
  ll z;
};

vector<point> points;
ll distances[10];

ll dist (point p1, point p2) {
  ll x, y, z;
  x = p1.x - p2.x;
  y = p1.y - p2.y;
  z = p1.z - p2.z;
  return x*x + y*y + z*z;
}

void incr (ll val) {
  for (ll i = 0; i < 10; i++) {
    if (val >= i*i && val < (i + 1)*(i + 1)) {
      distances[i]++;
      break;
    }
  }
}

void doit () {
  for (ll i = 0; i < 10; i++) {
    distances[i] = 0;
  }

  ll mini;
  for (ll i = 0; i < points.size(); i++) {
    mini = ULLMAX;
    for (ll j = 0; j < points.size(); j++) {
      if (i != j) {
        mini = min(mini, dist(points[i], points[j]));
      }
    }
    incr(mini);
  }
}

void printjust(ll val) {
  ll t = val;
  ll count = 0;
  while (t != 0) {
    count++;
    t /= 10;
  }
  for (ll i = 0; i < 4 - count; i++) {
    cout << " ";
  }
  cout << val;
}

void print () {
  for (ll i = 0; i < 10; i++) {
    printjust(distances[i]);
  }
  cout << endl;
}

int main () {
  point p;
  points.clear();

  while (true) {
    cin >> p.x >> p.y >> p.z;
    if (p.x == 0 && p.y == 0 && p.z == 0) break;
    points.push_back(p);
  }
  doit();
  print();
}
