#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;
ll k, dim;
//vector<pair<<vector<ll>,ll> > vec;

vector<pair<vector<ll>,ll> > vec;

vector<string> input;

ll ansc;
vector<ll> ans;

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


bool foo (pair<vector<ll>,ll> left, pair<vector<ll>,ll> right) {
  return left.first[0] < right.first[0];
}

bool valid (ll f, ll s) {
  for (ll it = 0; it < dim; it++) {
    if (vec[f].first[it] >= vec[s].first[it]) {
      return false;
    }
  }
  return true;
}

void go (ll prev, ll curr, vector<ll> &tvec, ll count) {
  if (curr >= vec.size()) {
    if (ansc < count) {
      ansc = count;
      ans = tvec;
    }
    return;
  }
  go(prev, curr+1, tvec, count);

  if (prev == -1 || valid(prev,curr)) {
    tvec.push_back(vec[curr].second);
    go(curr,curr+1,tvec,count+1);
    tvec.pop_back();
  }
}

void doit () {
//  cout << "In doit(): " << endl;
//  cout << "This is k: " << k << endl;
//  cout << "This is dim: " << dim << endl;
//
//  for (int i = 0; i < vec.size(); i++) {
//    for (int j = 0; j < vec[i].size(); j++) {
//      cout << vec[i][j] << " ";
//    }
//    cout << endl;
//  }
//  cout << "Done printing" << endl;

  for (ll i = 0; i < vec.size(); i++) {
    sort(vec[i].first.begin(), vec[i].first.end());
  }

//  for (int i = 0; i < vec.size(); i++) {
//    for (int j = 0; j < vec[i].size(); j++) {
//      cout << vec[i][j] << " ";
//    }
//    cout << endl;
//  }

  for (ll i = 0; i < vec.size(); i++) {
    vec[i].second = i+1;
  }
  sort(vec.begin(), vec.end(), foo);

  ansc = -1;
  ans.clear();
  vector<ll> tvec;
  for (ll i = 0; i < vec.size(); i++) {
    go(-1,i,tvec,0);
  }

  cout << ansc << endl;
  for (int it = 0; it < ans.size(); it++) {
    cout << ans[it];
    if (it != ans.size()) cout << " ";
    else cout << endl;
  }
  cout << endl;
}

int main () {
  string in;
  while (getline(cin,in)) {
    input.push_back(in);
  }

  ll idx = 0;
  string line;
  while (idx < input.size()) {
    line = input[idx];
    k = atoi(tokenize(line, " ").c_str());
    dim = atoi(tokenize(line, " ").c_str());
    idx++;
    vec.clear();
    for (ll t = idx + k; idx < t; idx++) {
      vector<ll> v;
      line = input[idx];
      while (line != "") {
        v.push_back(atoi(tokenize(line, " ").c_str()));
      }
      //vec.push_back(v);
      vec.push_back(make_pair(v,0));
    }
    doit();
  }
}
