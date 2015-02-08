#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cmath>
#include <limits>
#include <cstdlib>
using namespace std;
//cin.clear();
//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

typedef long long ll;

vector<pair<ll,ll> > vec;
vector<pair<ll,ll> > bases;

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

void populate () {
  vec.clear();
  ll first, second;
  ifstream infile("/cygdrive/c/Users/Tim/Desktop/hi/out.txt");
  while (infile >> first >> second) {
    vec.push_back(make_pair(first, second));
  }
}

void clear () {
  for (ll i = 0; i < bases.size(); i++) {
    bases[i].second = 0;
  }
}


int main () {
  bases.clear();
  for (ll i = 2; i <= 10; i++) {
    bases.push_back(make_pair(i, 0));
  }

  populate();

  ll T; cin >> T;
  string line;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  for (ll t = 1; t <= T; t++) {
    ll b;
    clear();

    getline(cin,line);

    while (line != "") {
      string tok = tokenize(line," ");
      b = atoi(tok.c_str());
      for (ll j = 0; j < bases.size(); j++) {
        if (bases[j].first == b) {
          bases[j].second = 1;
        }
      }
    }




    ll num = 0;
    for (ll i = 0; i < bases.size(); i++) {
      if (bases[i].second == 1) {
        num += pow(2,i);
      }
    }
    for (ll i = 0; i < vec.size(); i++) {
      if (num == vec[i].first) {
        cout << "Case #" << t << ": " << vec[i].second << endl;
        break;
      }
    }

  }
  return 0;
}

