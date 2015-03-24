# Works for both small and large inputs.
import math

def doit (cas):
  line = input().split()
  C = float(line[0])
  F = float(line[1])
  X = float(line[2])

  i = -1
  while True:
    i += 1
    lag = X/(2 + i*F)
    lead = C/(2 + i*F) + X/(2 + (i + 1)*F)
    if lag <= lead:
      break;

  s = 0.0
  for j in range(i):
    s += C/(2 + j*F)
  s += X/(2 + i*F)

  print ("Case #" + str(cas) + ": " + str(s))

tcases = input()
tcases = int(tcases)

for i in range(tcases):
  doit(i + 1)
