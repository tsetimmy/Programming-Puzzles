#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct term {
  string tok;
  ll sgn;
  ll coe;
  ll x;
  ll y;
};

vector<term> vs, vt, vr;
string top, bottom;

bool foo (term left, term right) {
  if (left.x > right.x) return true;
  if (left.x < right.x) return false;;
  if (left.y < right.y) return true;
  return false;
}

void multiply () {
  vr.clear();
  term t;

  for (ll i = 0; i < vs.size(); i++) {
    for (ll j = 0; j < vt.size(); j++) {
      t.sgn = vs[i].sgn * vt[j].sgn;
      t.coe = vs[i].coe * vt[j].coe * t.sgn;
      t.x = vs[i].x + vt[j].x;
      t.y = vs[i].y + vt[j].y;
      vr.push_back(t);
    }
  }
}

void simplify () {
  ll i, j;
  i = 0;
  j = 0;

  while (i < vr.size()) {
    j = i + 1;
    while (j < vr.size()) {
      if (vr[i].x == vr[j].x && vr[i].y == vr[j].y) {
        vr[i].coe += vr[j].coe;
        vr.erase(vr.begin() + j);
        continue;
      }
      j++;
    }
    i++;
  }

  sort(vr.begin(), vr.end(), foo);

}

void blank (string& s, ll len) {
  for (ll i = 0; i < len; i++) {
    s.push_back(' ');
  }
}

string tostring (ll val) {
  stringstream ss;
  ss << val;
  return ss.str();
}

void pretty () {
  top = "";
  bottom = "";
  string s;

  for (ll i = 0; i < vr.size(); i++) {
    if (vr[i].coe == 0) continue;
    if (i != 0) {
      top += "   ";
      if (vr[i].coe < 0) bottom += " - ";
      else bottom += " + ";
    }
    if (abs(vr[i].coe) != 1 || (vr[i].x == 0 && vr[i].y == 0)) {
      s = tostring(abs(vr[i].coe));
      bottom += s;
      blank(top, s.size());
    }
    if (vr[i].x != 0) {
      bottom.push_back('x');
      top.push_back(' ');
      if (vr[i].x != 1) {
        s = tostring(vr[i].x);
        blank(bottom, s.size());
        top += s;
      }
    }
    if (vr[i].y != 0) {
      bottom.push_back('y');
      top.push_back(' ');
      if (vr[i].y != 1) {
        s = tostring(vr[i].y);
        blank(bottom, s.size());
        top += s;
      }
    }
  }
  if (vr[0].coe < 0) {
    top = " " + top;
    bottom = "-" + bottom;
  }

}

ll parse (string target, char c) {
  ll idx;
  string s;
  for (ll i = 0; i < target.size(); i++) {
    if (target[i] == c) {
      idx = i + 1;
      if (idx == target.size() || !(target[idx] >= '0' && target[idx] <= '9')) return 1;
      s = "";
      while (idx < target.size() && target[idx] >= '0' && target[idx] <= '9') {
        s.push_back(target[idx]);
        idx++;
      }
      return atoi(s.c_str());
    }
  }
  return 0;
}

void populate (string s, vector<term> &vec) {
  vec.clear();
  ll len = 0;
  term t;
  t.coe = 1;
  t.x = 0;
  t.y = 0;

  ll idx = 0;
  string seg;
  while (idx < s.size()) {
    seg = "";
    if (s[idx] == '+' || s[idx] == '-') {
      seg.push_back(s[idx]);
      idx++;
      while (s[idx] != '+' && s[idx] != '-' && idx < s.size()) {
        seg.push_back(s[idx]);
        idx++;
      }
      t.tok = seg;
      vec.push_back(t);
    }
  }

  for (ll i = 0; i < vec.size(); i++) {
    vec[i].sgn = vec[i].tok[0] == '+' ? 1 : -1;
    vec[i].coe = parse(vec[i].tok, vec[i].tok[0]);
    vec[i].x = parse(vec[i].tok, 'x');
    vec[i].y = parse(vec[i].tok, 'y');
  }

}

void doit (string s, string t) {
  assert(s.size() >= 1);
  assert(t.size() >= 1);
  if (s[0] != '-') {
    s = "+" + s;
  }
  if (t[0] != '-') {
    t = "+" + t;
  }
  populate(s,vs);
  populate(t,vt);
  multiply();
  simplify();
  pretty();
}


int main () {
  string s, t;
  while (true) {
    cin >> s;
    if (s == "#") break;
    cin >> t;

    doit(s,t);
    if (top == "" && bottom == "")
      cout << 0 << endl;
    else {
      cout << top << endl;
      cout << bottom << endl;
    }

//    cout << "Here it is: " << endl;
//    for (ll i = 0; i < vr.size(); i++) {
//      cout << vr[i].tok << endl;
//      cout << "Here is coe: " << vr[i].coe << endl;
//      cout << "Here is x power: " << vr[i].x << endl;
//      cout << "Here is y power: " << vr[i].y << endl;
//    }
//    cout << "Done." << endl;

  }
  return 0;
}
