#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef long long ll;
string tokenize(string&, string);
int gcdr(int, int);
int gcd_iter(int, int);
ll stringtoint (string in);
string inttostring (ll in);
void printdebug();

struct person {
  vector<string> friends;
  ll fcount;
  string name;
  ll spend;
};

struct ppl {
  string name;
  ll net;
};

vector<person> v;
vector<ppl> final;

ll getidx (string name) {
  for (ll i = 0; i < final.size(); i++) {
    if (name == final[i].name) {
      return i;
    }
  }
  assert(false);
}

void print () {
  for (ll i = 0; i < final.size(); i++) {
    cout << final[i].name << " " << final[i].net << endl;
  }
}

void doit () {
  ll gainer, loser;
  for (ll i = 0; i < v.size(); i++) {
    if (v[i].spend != 0) {
      loser = getidx(v[i].name);
      for (ll j = 0; j < v[i].friends.size(); j++) {
        gainer = getidx(v[i].friends[j]);
        final[loser].net -= v[i].spend/v[i].friends.size();
        final[gainer].net += v[i].spend/v[i].friends.size();
      }
    }
  }
}

void process (string line) {
//  person empty;
//  empty.spend = 0;
//  empty.net = 0;
//  empty.singlespend = 0;
//  string tok;
//  while (line != "") {
//    v.push_back(empty);
//    tok = tokenize(line, " ");
//    v.back().name = tok;
//  }

  ppl empty;
  empty.net = 0;
  while (line != "") {
    empty.name = tokenize(line, " ");
    final.push_back(empty);
  }
}

void processagain (string line) {
  string name;
  ll idx, fc;
  person t;

  t.name = tokenize(line, " ");
  t.spend = stringtoint(tokenize(line, " "));
  t.fcount = stringtoint(tokenize(line, " "));
  t.friends.clear();
  while (line != "") {
    t.friends.push_back(tokenize(line, " "));
  }
  v.push_back(t);
  assert(t.fcount == t.friends.size());


//  v[idx].spend += stringtoint(tokenize(line, " "));
//  fc = stringtoint(tokenize(line, " "));
//  if (fc != 0) {
//    while (line != "") {
//      v[idx].friends.push_back(tokenize(line, " "));
//    }
//  }
//  if (v[idx].friends.size() != 0) {
//    v[idx].spend /= v[idx].friends.size();
//    v[idx].singlespend = v[idx].spend;
//    v[idx].spend *= v[idx].friends.size();
//  }
}


int main () {
  string line;

  ll c = 0;
  ll ppl_c;
  while (cin >> ppl_c) {
    if (c != 0) cout << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    v.clear();
    final.clear();
    getline(cin, line);
    process(line);
    for (ll i = 0; i < ppl_c; i++) {
      getline(cin, line);
      processagain(line);
    }
    doit();
    print();
    c++;
    //printdebug();
  }


  return 0;
}











void printdebug () {
  cout << v.size() << endl;
  cout << "anmes" << endl;
  for (ll i = 0; i < v.size(); i++) {
    cout << v[i].name << endl;
  }
  for (ll i = 0; i < v.size(); i++) {
    cout << v[i].spend << endl;
  }
  cout << "ok" << endl;
  for (ll i = 0; i < v.size(); i++) {
    cout << v[i].name << " ";
    cout << v[i].spend << " ";
//    for (ll j = 0; j < v[i].friends.size(); j++) {
//      cout << v[i].friends[j] << " ";
//    }
    cout << endl;
  }
  cout << "DONE" << endl;
}

ll stringtoint (string in) {
  return atoi(in.c_str());
}

string inttostring (ll in) {
  stringstream ss;
  ss << in;
  return ss.str();
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

// This function calculates the greatest common divisor (GCD) between two numbers.
int gcdr (int a, int b) {
  if (a == 0) {
    return b;
  } else {
    return gcdr(b%a, a);
  }
}

int gcd_iter (int u, int v) {
  int t;
  while (v) {
    t = u;
    u = v;
    v = t % v;
  }
  return u < 0 ? -u : u;
}


// This function fills in a binomial coefficient array of size N by K.
//void binomial_coefficient (int N, int K) {
//  for (int k = 1; k <= K; k++) {
//    binomial[0][k] = 0;
//  }
//  for (int n = 0; n <= N; n++) {
//    binomial[n][0] = 1;
//  }
//  for (int n = 1; n <= N; n++) {
//    for (int k = 1; k <= K; k++) {
//      binomial[n][k] = binomial[n-1][k-1] + binomial[n-1][k];
//    }
//  }
//}
