# Works for both small and large inputs.
import sys

def doit(string):
    ret = string[0]
    for i in range(1, len(string)):
        if string[i] >= ret[0]:
            ret = string[i] + ret
        else:
            ret = ret + string[i]
    sys.stdout.write(" " + ret + "\n")

if __name__ == "__main__":
    tcases = int(raw_input())
    for cas in range(tcases):
        sys.stdout.write("Case #" + str(cas + 1) + ":")
        line = raw_input().split(" ")
        doit(line[0])
