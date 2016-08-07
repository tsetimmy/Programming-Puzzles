# Works for large inputs.
import sys
import time
globalJ = 0
N = 32
J = 500

def prime_checker(num):
    start_time = time.time()
    if num % 2 == 0:
        return 2
    i = 3
    while i * i <= num:
        if num % i == 0:
            return i
        i += 2
        elapsed_time = time.time() - start_time
        if elapsed_time > 1:
            print "timeout"
            return -1
    return -1

def convert_base(num, base):
    ret = 0
    exp = 0
    while num > 0:
        digit = num % 10
        num /= 10
        ret += digit * pow(base, exp);
        exp += 1
    return ret

def recurse(s):
    global globalJ
    print "globalJ:" + str(globalJ)
    if globalJ == J:
        return
    if len(s) == N:
        if s[-1] == '0':
            return
        s = int(s)
        ans = []
        for i in range(2, 11):
            p = prime_checker(convert_base(s, i))
            if p == -1:
                return
            else:
                ans.append(p)
        write = ""
        write += str(s)
        for a in ans:
            write += " " + str(a)
        print write
        target = open("./large.txt", "a+")
        target.write(write)
        target.write("\n")
        target.close()
        globalJ += 1
        return
    else:
        if len(s) == 0:
            s = "1"
            recurse(s)
        else:
            s = s + "0"
            recurse(s)
            s = s[:-1]
            s = s + "1"
            recurse(s)

def doit():
    print "Case #1:"
    s = ""
    recurse(s)

def main():
    doit()

if __name__ == "__main__":
    main()
