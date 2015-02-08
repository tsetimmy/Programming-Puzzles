#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;
#define maxn 30
#define dim 26
ll trans (char in) { return (ll) in - 'A'; }
ll toint (char in) { return (ll) (in - 'A'); }
char tochar (ll in) { return (char) (in + 'A'); }
void clear();
string tokenize(string&, string);


ll grid[maxn][maxn];
string s;

string best;
ll bestc;

bool in (char t) {
  for (ll i = 0; i < s.size(); i++) {
    if (s[i] == t) {
      return true;
    }
  }
  return false;
}



void populate (char source, char dest) {
  grid[toint(source)][toint(dest)] = 1;
  grid[toint(dest)][toint(source)] = 1;
  if (!in(source)) s.push_back(source);
  if (!in(dest)) s.push_back(dest);
}

void swap (ll i, ll j) {
  char t = s[i];
  s[i] = s[j];
  s[j] = t;
}

ll getdist (char first, char second, string ss) {
  ll i1, i2;
  for (ll i = 0; i < ss.size(); i++) {
    if (ss[i] == first) i1 = i;
    if (ss[i] == second) i2 = i;
  }
  return abs(i1 - i2);
}

ll bandwidth (string ban) {
  ll m = -1;
  for (ll i = 0; i < ban.size(); i++) {
    for (ll j = 0; j < dim; j++) {
      if (grid[toint(ban[i])][j]) {
        m = max(m, getdist(ban[i], tochar(j), ban));
      }
    }
  }


  return m;
}

void recurse (ll idx) {
  if (idx == s.size()) {
    ll b = bandwidth(s);
    if (bestc == -1 || b < bestc || (bestc == b && s < best)) {
      bestc = b;
      best = s;
    }
    return;
  }

  for (ll i = idx; i < s.size(); i++) {
    swap(idx, i);
    recurse(idx + 1);
    swap(idx, i);
  }

}

void process (string line) {
  string gchunk, source, dest;
  while (line != "") {
    gchunk = tokenize(line, ";");
    source = tokenize(gchunk, ":");
    assert(source.size() == 1);
    dest = tokenize(gchunk, ":");
    for (ll i = 0; i < dest.size(); i++) {
      populate(source[0], dest[i]);
    }
  }

  recurse(0);

}

void print () {
  for (ll i = 0; i < best.size(); i++) {
    cout << best[i];
    if (i != best.size() - 1) cout << " ";
  }
  cout << " -> " << bestc << endl;
}



int main () {
  string line;
  while (true) {
    getline(cin, line);
    if (line == "#")  break;
    clear();
    process(line);
    print();
    //doit();
  }

  return 0;
}

void clear () {
  s = "";
  best = "";
  bestc = -1;
  for (ll i = 0; i < maxn; i++)
    for (ll j = 0; j < maxn; j++)
      grid[i][j] = 0;
}





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
