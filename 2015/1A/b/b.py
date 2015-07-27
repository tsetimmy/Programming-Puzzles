import sys

def gcdr (a, b):
  if a == 0:
    return b;
  else:
    return gcdr(b%a, a);


def get_lcm (a, b):
  return (a * b) / gcdr(a, b)

def doit (cas):
  B, N = raw_input().split(" ")
  B = int(B)
  N = int(N)
  N = N - 1

  M = raw_input().split(" ")
  for i in range(len(M)):
    M[i] = int(M[i])

  lcm = M[0]
  for i in range(B):
    lcm = get_lcm(lcm, M[i])

  chunk = 0
  for i in range(B):
    chunk = chunk + (lcm / M[i])

  N = N % chunk
  #rate = chunk / lcm # haircuts / min
  rate = float(chunk) / float(lcm) # haircuts / min


  t = float(N) / rate
  t = int(t)
  if t > 0:
    t = t - 1

  sys.stdout.write("Case #" + str(cas) + ": ")
  L = [0] * B
  n = 0
  for i in range(B):
    n = n + t / M[i]

  for i in range(B):
    L[i] = M[i] - t % M[i]
    if L[i] == 0:
      L[i] = M[i] - 1
    if (n == N):
      print i + 1
      return
    n = n + 1

  while True:
    m = L[0]
    for i in range(B):
      m = min(m, L[i])
    for i in range(B):
      L[i] = L[i] - m
      if L[i] == 0:
        L[i] = M[i]
        if n == N:
          print i + 1
          return
        n = n + 1








tcases = int(raw_input())
for cas in range(tcases):
  doit(cas + 1)
