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


  for (int i = 0; i < pts.size(); i++) {

    for (int j = 0; j < pts.size(); j++) {
      if (i != j) {
        pts[j].angle = atan2l(pts[j].y - pts[i].y, pts[j].x - pts[i].x);
      }
    }
    pts[i].angle = inf;

    sort(pts.begin(), pts.end(), foo);



    int h, tail;
    bool flag = false;
    for (int q = 0; q < pts.size(); q++) {
      if (q == i)
        continue;



      for (int k = 0; k < pts.size(); k++) {
        cout << pts[k].x << " " << pts[k].y << " " << pts[k].angle << endl;
      }
      cout << "p: " << i << endl;
      cout << "q: " << q << endl;
      return;

      pt pq = vectorize(pts[q], pts[i]);
      h = q;
      pt ph = pq;
      while (cross(pq, ph, 0) >= 0) {
        inc(h);
        while (h == i) {
          inc(h);
        }
        ph = vectorize(pts[h], pts[i]);
        cout << "1" << endl;
      }


      if (!flag) {
        flag = true;
        tail = h;
      }
      pt ptail = vectorize(pts[tail], pts[i]);
      while (cross(pq, ptail, 1) <= 0) {
        inc(tail);
        while (tail == i)
          inc(tail);
        ptail = vectorize(pts[tail], pts[i]);
        cout << "2" << endl;
      }

      pts[i].best = min(pts[i].best, abs(tail - h));
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

