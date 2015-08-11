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

void inc (int & a) {
  a++;
  a = a % pts.size();
}

pt vectorize (pt a, pt b) {
  pt c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  return c;
}

bool foo (pt a, pt b) {
  return (a.angle <= b.angle);
}

bool foo2 (pt a, pt b) {
  return (a.idx <= b.idx);
}

int cross (pt u, pt v, int d) {
  return (u.x * v.y - u.y * v.x);
}

void remove_negatives () {
  int i = 0;
  while (i < pts.size()) {
    if (pts[i].idx == -1) {
      pts.erase(pts.begin() + i);
    } else {
      i++;
    }
  }
}

void doit (int cas) {
  cout << "Case #" << cas << ":" << endl;
  cin >> N;
  pts.clear();
  pts = vector<pt> (N);

  for (int i = 0; i < N; i++) {
    cin >> pts[i].x;
    cin >> pts[i].y;
    pts[i].best = 3001;
    pts[i].idx = i;
  }

  if (N <= 4) {
    for (int i = 0; i < N; i++)
      cout << 0 << endl;
    return;
  }


  for (int p = 0; p < pts.size(); p++) {
    for (int q = 0; q < pts.size(); q++) {
      if (p != q) {

        pt pt_p = pts[p];
        pt pt_q = pts[q];

        pts[p].idx = -1;
        pts[q].idx = -1;
        remove_negatives();

        for(int i = 0; i < pts.size(); i++)
          pts[i].angle = atan2l(pts[i].y - pt_p.y, pts[i].x - pt_p.x);

        pt phead, ptail;
        int h, t;



      }
    }
  }

  sort(pts.begin(), pts.end(), foo2);
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

