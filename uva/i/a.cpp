#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef long long ll;
#define maxn 20

vector<ll> best;
vector<ll> temp;
vector<string> input;
double table[maxn][maxn];
ll len;
double max_prod;

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



ll toll (string in) {
  return atoi(in.c_str());
}

double todouble (string in) {
  return atof(in.c_str());
}

void fill (ll idx, string line) {
  ll col = 0;
  string val;
  while (line != "") {
    if (table[idx][col] < 0.0) {
      col++;
    } else {
      val = tokenize(line," ");
      if (val[0] == '.') val = "0" + val;
      table[idx][col] = todouble(val);
      col++;
    }
  }
}

string trim (string in) {
  string ret = "";
  ll idx = 0;
  while (idx < in.size() && in[idx] == ' ') {
    idx++;
  }

  bool prev = false;
  while (idx < in.size()) {
    if (in[idx] != ' ') {
      ret.push_back(in[idx]);
      prev = false;
    } else if (in[idx] == ' ' && prev == false) {
      ret.push_back(in[idx]);
      prev = true;
    } else if (in[idx] == ' ' && prev == true) {
    } else {
      assert(false);
    }
    idx++;
  }
  return ret;
}

void go (ll curr, double val, ll org) {
  if (temp.size() > len) {
    return;
  } 
  if (curr == org && temp.size() != 0 && val >= 1.01) {
    if (best.size() == 0 || temp.size() < best.size()) {
      best = temp;
    }
    return;
  }

  for (ll i = 0; i < len; i++) {
    if (table[curr][i] > 0.0) {
      temp.push_back(i);
      go(i,val*table[curr][i],org);
      temp.pop_back();
    }
  }

}



int main () {
  for (ll i = 0; i < maxn; i++) {
    table[i][i] = -INFINITY;
  }
  input.clear();
  string line;

  while (getline(cin,line)) {
    input.push_back(trim(line));
  }

  ll idx = 0;
  ll i;
  ll c;
  while (idx < input.size()) {
    i = toll(input[idx]);
    len = i;
    idx++;
    i += idx;
    c = 0;
    for ( ; idx < i; idx++) {
      fill(c,input[idx]);
      c++;
    }

    best.clear();
    temp.clear();
    for (ll it = 0; it < len; it++) {
      temp.push_back(it);
      go(it,1.0,it);
      temp.pop_back();
    }

    if (best.empty()) {
      cout << "no arbitrage sequence exists" << endl;
      continue;
    }

    for (ll hi = 0; hi< best.size(); hi++) {
      cout << best[hi]+1;
      if (hi != best.size()-1) cout << " ";
      else cout << endl;
    }

//    cout << "printing out" << endl;
//    for (ll i = 0; i < len; i++) {
//      for (ll j = 0; j < len; j++) {
//        cout << table[i][j] << " ";
//      }
//      cout << endl;
//    }
//    cout << "printing out end" << endl;
//
  }

  return 0;
}
