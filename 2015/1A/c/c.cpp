#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <cstdio>
using namespace std;


#define EP 1e-15
long double inf = std::numeric_limits<double>::infinity();

struct pt {
  int x;
  int y;
  long double angle;
  int best;
  int idx;
};

int N;
vector<pt> pts;

void fix (int & a, int i) {
  if (a == i) {
    a++;
    a %= pts.size() - 1;
  }
}

bool foo (pt a, pt b) {
  return (a.angle <= b.angle);
}

bool foo2 (pt a, pt b) {
  return (a.idx <= b.idx);
}

int cross (pt u, pt v) {
  cout << "in the cross" << endl;
  cout << (u.x * v.y - u.y * v.x) << endl;
  return (u.x * v.y - u.y * v.x);
}

void doit (int cas) {
  cin >> N;
  pts.clear();
  pts = vector<pt> (N);

  for (int i = 0; i < N; i++) {
    cin >> pts[i].x;
    cin >> pts[i].y;
    pts[i].best = 3001;
    pts[i].idx = i;
  }

  for (int i = 0; i < pts.size(); i++) {

    for (int j = 0; j < pts.size(); j++) {
      if (i != j) {
        pts[j].angle = atan2l(pts[j].y - pts[i].y, pts[j].x - pts[i].x);
      }
    }
    pts[i].angle = inf;

    sort(pts.begin(), pts.end(), foo);



    int h, t;
    for (int q = 0; q < pts.size() - 1; q++) {
      pt pq;
      pq.x = pts[q].x - pts[i].x;
      pq.y = pts[q].y - pts[i].y;

      h = q;
      while 

    }



    


  }
  sort(pts.begin(), pts.end(), foo2);
  cout << "Case #" << cas << ":" << endl;
  for (int i = 0; i < pts.size(); i++)
    cout << pts[i].angle << endl;







}


int main () {
  int tcases;
  cin >> tcases;
  for (int cas = 0; cas < tcases; cas++)
    doit(cas + 1);
  return 0;
}

