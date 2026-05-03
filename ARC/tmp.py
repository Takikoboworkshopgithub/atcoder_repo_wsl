from collections import Counter
s=input()
c=Counter(s)
print(c)
for i,j in c.items():
  print(i)
  print(j)