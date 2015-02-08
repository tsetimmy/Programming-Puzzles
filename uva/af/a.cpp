#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;

struct character {
  vector<character*> proceeders;
  ll total;
  ll count;
  bool used;
  string name;
};

string tokenize(string&, string);
ll stringtoint (string in);
string inttostring (ll in);

vector<character> vec;
vector<string> ans;
vector<string> final;

void doit () {
  if (ans.size() == vec.size()) {
    string s = "";
    for (ll i = 0; i < ans.size(); i++) {
      s += ans[i];
    }
    final.push_back(s);
    return;
  }

  for (ll i = 0; i < vec.size(); i++) {
    if (vec[i].used == false && vec[i].count == vec[i].total) {
      ans.push_back(vec[i].name);
      for (ll j = 0; j < vec[i].proceeders.size(); j++) {
        vec[i].proceeders[j]->count++;
      }
      vec[i].used = true;
      doit();
      ans.pop_back();
      for (ll j = 0; j < vec[i].proceeders.size(); j++) {
        vec[i].proceeders[j]->count--;
      }
      vec[i].used = false;
    }
  }
}

void process1 (string line) {
  character t;
  t.total = 0;
  t.count = 0;
  t.used = false;
  while (line != "") {
    t.name = tokenize(line, " ");
    vec.push_back(t);
  }
}

void fill (string precede, string proceed) {
  character* ptr = NULL;
  ll precedeidx, proceedidx;
  for (ll i = 0; i < vec.size(); i++) {
    if (vec[i].name == precede) {
      precedeidx = i;
    }
    if (vec[i].name == proceed) {
      proceedidx = i;
    }
  }

  ptr = &vec[proceedidx];
  ptr->total++;
  vec[precedeidx].proceeders.push_back(ptr);
}

void process2 (string line) {
  character* ptr = NULL;
  string precede, proceed;
  while (line != "") {
    precede = tokenize(line, " ");
    proceed = tokenize(line, " ");
    fill(precede, proceed);
  }
}

void print () {
  sort(final.begin(), final.end());
  for (ll i = 0; i < final.size(); i++) {
    cout << final[i] << endl;
  }
}




int main () {
  ll count = 0;
  string line1, line2;
  while (getline(cin, line1)) {
    if (count != 0) cout << endl;
    vec.clear();
    process1(line1);
    getline(cin, line2);
    process2(line2);
    ans.clear();
    final.clear();
    doit();
    print();
    count++;
  }
  return 0;
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

ll stringtoint (string in) {
  return atoi(in.c_str());
}

string inttostring (ll in) {
  stringstream ss;
  ss << in;
  return ss.str();
}
