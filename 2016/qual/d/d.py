# Works small inputs.
import sys

def doit(K, C, S):
    for k in range(1, K + 1):
        org_length = K
        org_index = k
        cum_index = k
        for c in range(1, C):
            cum_index = (cum_index - 1) * org_length + org_index
        sys.stdout.write(str(cum_index) + " ")
    sys.stdout.write("\n")

if __name__ == "__main__":
    tcases = int(raw_input())
    for cas in range(tcases):
        sys.stdout.write("Case #" + str(cas + 1) + ": ")
        line = raw_input().split(" ")
        doit(int(line[0]), int(line[1]), int(line[2]))
