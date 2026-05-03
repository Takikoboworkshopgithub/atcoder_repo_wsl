N=int(input())
S=[list(input().strip())for _ in range(N)]
l=[set()for i in range(N*2)]


for i in range(N):
  for j in range(N):
    if not S[i][j] == "?":
      S[i][j]=int(S[i][j])
      l[i+j].add(S[i][j])
if not all(len(l[i])<=1 for i in range(N*2)):
  print("-1")
else:
  ans=[[0]*N for _ in range(N)]
  for i in range(N):
    for j in range(N):
      if len(l[i+j]) == 0:
        ans[i][j] = 0
      elif len(l[i+j]) == 1:
        ans[i][j] = list(l[i+j])[0]
  for i in ans:
    print("".join(i))