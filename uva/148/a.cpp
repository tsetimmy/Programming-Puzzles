#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define maxn 256+5

vector<string> dict;
vector<string> anagrams;
ll hash[maxn];

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


bool ok () {
  for (ll i = 0; i < maxn; i++) {
    if (hash[i] < 0) {
      return false;
    }
  }
  return true;
}

bool good (string s, string b) {
  for (ll i = 0; i < maxn; i++) {
    if (hash[i] != 0) {
      return false;
    }
  }

  s.erase(s.begin());
  vector<string> vs;
  vector<string> vb;

  while (s != "") {
    vs.push_back(tokenize(s, " "));
  }
  while (b != "") {
    vb.push_back(tokenize(b, " "));
  }

  if (vs.size() != vb.size()) {
    return true;
  }

  sort(vs.begin(), vs.end());
  sort(vb.begin(), vb.end());

  for (ll i = 0; i < vs.size(); i++) {
    if (vs[i] != vb[i]) {
      return true;
    }
  }

  return false;
}

void recurse (ll idx, string s, string b) {
  if (good(s,b)) {
    cout << b + " =" + s << endl;
    return;
  }
  if (idx >= dict.size()) {
    return;
  }


  //recurse(idx + 1, s);


  string attempt = dict[idx];

  for (ll i = 0; i < attempt.size(); i++) {
    hash[(ll) attempt[i]]--;
  }

  if (ok()) {
    recurse(idx + 1, s + " " + attempt, b);
  }

  for (ll i = 0; i < attempt.size(); i++) {
    hash[(ll) attempt[i]]++;
  }
  recurse(idx + 1, s, b);

}

void doit (string s) {
  for (ll i = 0; i < maxn; i++) {
    hash[i] = 0;
  }
  for (ll i = 0; i < s.size(); i++) {
    if (s[i] != ' ') {
      hash[(ll) s[i]]++;
    }
  }

  recurse(0, "", s);
}


int main () {
  string line;

  while (true) {
    getline(cin, line);
    if (line == "#") break;
    dict.push_back(line);
  }
  while (true) {
    getline(cin, line);
    if (line == "#") break;
    anagrams.push_back(line);
  }

  for (ll i = 0; i < anagrams.size(); i++) {
    doit(anagrams[i]);
  }


  return 0;
}
