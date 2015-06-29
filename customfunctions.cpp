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
void binomial_coefficient (int N, int K) {
  for (int k = 1; k <= K; k++) {
    binomial[0][k] = 0;
  }
  for (int n = 0; n <= N; n++) {
    binomial[n][0] = 1;
  }
  for (int n = 1; n <= N; n++) {
    for (int k = 1; k <= K; k++) {
      binomial[n][k] = binomial[n-1][k-1] + binomial[n-1][k];
    }
  }
}

int to_int (string s) {
  istringstream buffer(s);
  int value;
  buffer >> value;
  return value
}
