n=int(input())
alphabets="abcdefghijklmnopqrstuvwxyz"
from collections import defaultdict
ans={}
from collections import Counter
for i in range(n):
  s=input()
  c=Counter(s)
  for i,j in c.items():
    if not j in ans:
      ans[i]=j
    else:
      ans[i]=min(j,ans[i])
    print(ans)
for i,a in enumerate(ans):
  if ans[a]!=0:
    print(a*i,end="")