#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <cassert>
#include <iomanip>
using namespace std;

//LLONG_MAX
typedef long long ll;

struct coor {
  ll x;
  ll y;
};

coor f;

ll cross (coor l, coor r) {
  return l.x * r.y - l.y * r.x;
}

ll dist (coor c) {
  return c.x * c.x + c.y * c.y;
}

bool foo (coor left, coor right) {
  ll ret = cross(left, right);
  if (ret == 0) {
    return dist(left) < dist(right);
  }
  return ret > 0;
}

void swap (coor& l, coor& r) {
  coor temp = l;
  l = r;
  r = temp;
}

vector<coor> GrahamScan (vector<coor> points) {
//  cout << "printing out initial vector..." << endl;
//  for (ll i = 0; i < points.size(); i++) {
//    cout << "(" << points[i].x << "," << points[i].y << ")";
//    if (i != points.size()-1) cout << " ";
//    else cout << endl;
//  }
//  cout << "printing out initial vector..." << endl;
  if (points.size() <= 3) {
    return points;
  }

  vector<coor> s;
  ll m = 0;

  for (ll i = 0; i < points.size(); i++) {
    if (points[m].y > points[i].y || (points[m].y == points[i].y && points[m].x > points[i].x)) {
      m = i;
    }
  }
  swap(points[0],points[m]);

  f = points[0];
  for (ll i = 1; i < points.size(); i++) {
    points[i].x = points[i].x - points[0].x;
    points[i].y = points[i].y - points[0].y;
  }
  sort(points.begin()+1, points.end(), foo);
  ll la, le;
  la = 1;
  le = 2;
  while (le < points.size()) {
    if (cross(points[la],points[le])==0) {
      points.erase(points.begin()+la);
    } else {
      la++;
      le++;
    }
  }
  for (ll i = 1; i < points.size(); i++) {
    points[i].x = points[i].x + points[0].x;
    points[i].y = points[i].y + points[0].y;
  }

  s.push_back(points[0]);
  s.push_back(points[1]);
  s.push_back(points[2]);
  ll lag, mid, lead, idx;
  lag = 1;
  mid = 2;
  lead = 3;

  coor front;
  coor back;

  while (lead < points.size()) {
    assert(mid == s.size()-1);
    assert(mid == lag+1);
    back.x = s[mid].x - s[lag].x;
    back.y = s[mid].y - s[lag].y;

    front.x = points[lead].x - s[mid].x;
    front.y = points[lead].y - s[mid].y;


    if (cross(back, front) > 0) {
      s.push_back(points[lead]);
      lag++;
      mid++;
      lead++;
    } else {
      s.pop_back();
      lag--;
      mid--;
    }
  }

//  cout << s.size()+1 << endl;
//  for (ll i = 0; i < s.size(); i++) {
//    cout << s[i].x << " " << s[i].y << endl;
//  }
//  cout << s[0].x << " " << s[0].y << endl;
//  if (cas != tcases-1)
//    cout << -1 << endl;

  return s;

}

double GetArea (vector<coor> poly) {
  double area = 0.0;
  for (ll i = 1; i <= poly.size()-1; i++) {
    area += (double)((poly[i-1].x * poly[i].y) - (poly[i].x * poly[i-1].y));
  }
  area += (double)((poly[poly.size()-1].x * poly[0].y) - (poly[0].x * poly[poly.size()-1].y));
  return area/2;
}

bool inside (coor p, vector<coor> poly) {
  bool first = true;
  ll sgn;
  coor v1;
  coor v2;
  for (ll i = 0; i < poly.size()-1; i++) {
    v1.x = poly[i+1].x - poly[i].x;
    v1.y = poly[i+1].y - poly[i].y;
    v2.x = p.x - poly[i].x;
    v2.y = p.y - poly[i].y;
    if (first) {
      first = false;
      sgn = cross(v1,v2);
    } else if (sgn*cross(v1,v2) < 0) {
      return false;
    }
  }
  v1.x = poly[0].x - poly[poly.size()-1].x;
  v1.y = poly[0].y - poly[poly.size()-1].y;
  v2.x = p.x - poly[poly.size()-1].x;
  v2.y = p.y - poly[poly.size()-1].y;
  if (sgn*cross(v1,v2) < 0) {
    return false;
  }
  return true;
}

bool in (vector<coor> missiles, vector<coor> poly) {
  for (ll i = 0; i < missiles.size(); i++) {
    if (inside(missiles[i], poly)) {
      return true;
    }
  }
  return false;
}

int main () {
  cout << std::fixed;
  cout << std::setprecision(2);
  ll K;
  coor c;
  vector<coor> missiles;
  vector<vector<coor> > hull;

  while (true) {
    vector<coor> t;
    cin >> K;
    if (K == -1) break;
    for (ll i = 0; i < K; i++) {
      cin >> c.x >> c.y;
      t.push_back(c);
    }
    hull.push_back(GrahamScan(t));
  }

  while (cin >> c.x >> c.y) {
    missiles.push_back(c);
  }

  double area = 0.0;
  
//  cout << "here are the missiles" << endl;
//  for (ll i = 0; i < missiles.size(); i++) {
//    cout << missiles[i].x << " " << missiles[i].y << endl;
//  }
//  cout << "here are the missiles end" << endl;
//  cout << "here are the hull" << endl;
//  for (ll i = 0; i < hull.size(); i++) {
//    cout << "Here begin" << endl;
//    for (ll j = 0; j < hull[i].size(); j++) {
//      cout << hull[i][j].x << " " << hull[i][j].y << endl;
//    }
//    cout << "Here end" << endl;
//  }
//  cout << "here are the hull end" << endl;

  for (ll i = 0; i < hull.size(); i++) {
    if (in(missiles,hull[i])) {
      area += GetArea(hull[i]);
    }
  }
  
  cout << area << endl;




  return 0;
}
