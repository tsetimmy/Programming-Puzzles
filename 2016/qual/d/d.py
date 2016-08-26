# Works for both small and large inputs.
import sys

def get_next_index(org_length, org_index, prev_index):
    cum_index = (prev_index - 1) * org_length + org_index
    return cum_index

def doit(K, C, S):
    if K > C * S:
        sys.stdout.write(" IMPOSSIBLE\n")
        return

    length = K
    index = 1
    while length > 0:
        chunk = 0
        if length >= C:
            chunk = C
            length -= C
        else:
            chunk = length
            length = 0
        idx = index
        for i in range(chunk - 1):
            idx = get_next_index(K, index, idx)
            idx += 1
            index += 1
        index += 1
        sys.stdout.write(" " + str(idx))
    sys.stdout.write("\n")

if __name__ == "__main__":
    tcases = int(raw_input())
    for cas in range(tcases):
        sys.stdout.write("Case #" + str(cas + 1) + ":")
        line = raw_input().split(" ")
        doit(int(line[0]), int(line[1]), int(line[2]))
