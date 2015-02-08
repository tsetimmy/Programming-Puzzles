#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

typedef long long ll;

struct city {
  char red;
  char orange;
  char yellow;
  char green;
  char blue;
};

string tokenize(string&, string);

vector<city> cities;
vector<ll> count;

void process (string line) {
  city c;
  string tok;

  while (line != "") {
    tok = tokenize(line, ",");
    if (tok[0] == 'r') c.red = tok[2];
    else if (tok[0] == 'o') c.orange = tok[2];
    else if (tok[0] == 'y') c.yellow = tok[2];
    else if (tok[0] == 'g') c.green = tok[2];
    else if (tok[0] == 'b') c.blue = tok[2];
    else throw;
  }
  cities.push_back(c);
}

void doit () {
  ll c;
  count.clear();


  for (ll i = 0; i < cities.size(); i++) {
    c = 0;
    for (ll j = 0; j < cities.size(); j++) {
      if (i != j) {
        if (cities[i].red != cities[j].red) c++;
        if (cities[i].orange!= cities[j].orange) c++;
        if (cities[i].yellow != cities[j].yellow) c++;
        if (cities[i].green != cities[j].green) c++;
        if (cities[i].blue != cities[j].blue) c++;
      }
    }
    count.push_back(c);
  }

  assert(count.size() >= 1);

  ll idx = 0;
  for (ll i = 0; i < count.size(); i++) {
    if (count[i] < count[idx]) {
      idx = i;
    }
  }

  cout << idx + 1 << endl;
}


int main () {
  string line;
  while (true) {
    getline(cin, line);
    if (line == "#") {
      break;
    } else if (line[0] == 'e') {
      doit();
      cities.clear();
    } else {
      process(line);
    }
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
