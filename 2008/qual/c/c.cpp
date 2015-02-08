#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <assert.h>
using namespace std;

#define EPSILON 0.00001
double f, R, t, r, g;
double innerR;
double area;

//vector<pair<double, double> > squares;

double get_intersect (double input) {
  return sqrt(innerR*innerR-input*input);
}

double get_sector_area (pair<double, double> intersect1, pair<double, double> intersect2) {
  double chord_length, rise, run, height;
  rise = fabs(intersect1.first-intersect2.first);
  run = fabs(intersect1.second-intersect2.second);
  chord_length = sqrt(rise*rise+run*run);
  assert(chord_length >= 0.0);
  height = innerR-sqrt(innerR*innerR-(chord_length/2)*(chord_length/2));
  assert(height >= 0.0);
  double sectorarea = innerR*innerR*acos((innerR-height)/innerR)-(innerR-height)*sqrt(2*innerR*height-height*height);
  //assert(sectorarea >= 0.0);
  return sectorarea;

}

double get_area (double x, double y, bool &out) {
  //assert(x >= 0.0);assert(y >= 0.0);assert(g >= 0.0);
  double lower_left = sqrt(x*x+y*y);
  double lower_right = sqrt((x+g)*(x+g)+y*y);
  double upper_left = sqrt(x*x+(y+g)*(y+g));
  double upper_right = sqrt((x+g)*(x+g)+(y+g)*(y+g));

  if (lower_left > innerR) {
    out = true;
    return 0.0;
  }
  if (innerR >= upper_right) {
    return g*g;
  }

  double A = 0.0;
  pair<double, double> intersect1;
  pair<double, double> intersect2;

  if (upper_left > innerR && lower_right > innerR) {
    intersect1.first = x;
    intersect1.second = get_intersect(x);

    intersect2.first = get_intersect(y);
    intersect2.second = y;

    A += get_sector_area(intersect1, intersect2);
    A += (fabs(intersect1.second-y)*fabs(intersect2.first-x))/2;

    return A;
  } else if (upper_right > innerR && upper_left > innerR) {
    intersect1.first = x;
    intersect1.second = get_intersect(x);

    intersect2.first = x+g;
    intersect2.second = get_intersect(x+g);

    A += get_sector_area(intersect1, intersect2);

    double longer, shorter;
    longer = max(intersect1.second, intersect2.second)-y;
    shorter = min(intersect1.second, intersect2.second)-y;
    assert(longer >= 0);assert(shorter >= 0);

    A += fabs(longer-shorter)*g/2.0 + g*shorter;

    return A;
  } else if (upper_right > innerR && lower_right > innerR) {
    intersect1.first = get_intersect(y);
    intersect1.second = y;

    intersect2.first = get_intersect(y+g);
    intersect2.second = y+g;

    A += get_sector_area(intersect1, intersect2);

    double longer, shorter;
    longer = max(intersect1.first, intersect2.first)-x;
    shorter = min(intersect1.first, intersect2.first)-x;
    assert(longer >= 0);assert(shorter >= 0);

    A += fabs(longer-shorter)*g/2.0 + g*shorter;

    return A;
  } else if (upper_right > innerR) {
    intersect1.first = get_intersect(y+g);
    intersect1.second = y+g;

    intersect2.first = x+g;
    intersect2.second = get_intersect(x+g);

    A += g*g + get_sector_area(intersect1, intersect2);

    double tri_area = ((x+g-intersect1.first)*(y+g-intersect2.second))/2.0;
    assert(tri_area >= 0);
    A -= tri_area;

    return A;
  }

  assert(false);
}

void solve (int tcase) {
  //squares.clear();
  area = 0.0;
  cin >> f >> R >> t >> r >> g;
  r += f;
  t += f;
  g -= 2*f;
  if (g < 0.0) {
    g = 0.0;
  }
  //assert(g >= 0.0);
  innerR = R-t;

  double x, y;
  bool out;
  bool done;
  for (int i = 0; true; i++) {
    done = false;
    for (int j = 0; true; j++) {
      x = r+(double)j*(g+2.0*r);
      y = r+(double)i*(g+2.0*r);
      out = false;
      area += get_area(x, y, out);
      if (out && j == 0) {
        done = true;
      }
      if (out) {
        break;
      }
    }
    if (done) {
      break;
    }
  }

  area *= 4.0;
  area = 1.0-area/(M_PI*R*R);
  assert(area <= 1.0);

  cout << "Case #" << tcase << ": " << std::setprecision(9) << area << endl;

}

int main () {
  cout << std::fixed;
  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    solve(tt);
  }
  return 0;
}
