#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<string> notignore;
vector<string> ignore;
vector<vector<string> > text;

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

string caps (string a) {
  for (ll i = 0; i < a.size(); i++) {
    a[i] = toupper(a[i]);
  }
  return a;
}

string lower (string a) {
  for (ll i = 0; i < a.size(); i++) {
    a[i] = tolower(a[i]);
  }
  return a;
}

bool notin (string a) {
  for (ll i = 0; i < ignore.size(); i++) {
    if (ignore[i] == a) {
      return false;
    }
  }
  return true;
}

int main () {
  string line;

  while (true) {
    getline(cin, line);
    if (line == "::") {
      break;
    }
    ignore.push_back(line);
  }

  vector<string> vec;
  while (getline(cin, line)) {
    vec.clear();
    while (line != "") {
      vec.push_back(lower(tokenize(line, " ")));
    }
    text.push_back(vec);
  }

  for (ll i = 0; i < text.size(); i++) {
    for (ll j = 0; j < text[i].size(); j++) {
      if (notin(text[i][j])) {
        notignore.push_back(text[i][j]);
      }
    }
  }

  sort(notignore.begin(), notignore.end());
  notignore.erase(unique(notignore.begin(), notignore.end()), notignore.end());

  for (ll i = 0; i < notignore.size(); i++) {
    for (ll j = 0; j < text.size(); j++) {
      for (ll k = 0; k < text[j].size(); k++) {
        if (notignore[i] == text[j][k]) {
          for (ll l = 0; l < text[j].size(); l++) {
            if (l == k) {
              cout << caps(text[j][l]);
            } else {
              cout << text[j][l];
            }
            if (l == text[j].size() - 1) {
              cout << endl;
            } else {
              cout << " ";
            }
          }
        }
      }
    }
  }

  return 0;
}

