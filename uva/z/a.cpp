#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long ll;

struct coor {
  double x;
  double y;
};

struct v {
  double x;
  double y;
  double a;
  double b;
};

coor coors [3];
vector<double> allin;
v v1, v2;

void perp (v& vec) {
  double t;
  t = vec.a;
  vec.a = vec.b;
  vec.b = t;
  vec.a *= -1.0;
}

void doit () {
  v1.x = coors[0].x;
  v1.y = coors[0].y;
  v1.a = coors[0].x - coors[1].x;
  v1.b = coors[0].y - coors[1].y;

  v2.x = coors[1].x;
  v2.y = coors[1].y;
  v2.a = coors[1].x - coors[2].x;
  v2.b = coors[1].y - coors[2].y;

  perp(v1);
  perp(v2);




}

int main () {
  cout << std::fixed;
  cout << std::setprecision(3);
  double in;
  allin.clear();

  while (cin >> in) {
    allin.push_back(in);
  }

  ll idx;
  for (ll i = 0; i < allin.size(); i += 6) {
    idx = 0;
    for (ll j = i; j < i + 6; j += 2) {
      coors[idx].x = allin[j];
      coors[idx].y = allin[j + 1];
      idx++;
    }
    doit();
  }


  return 0;
}
