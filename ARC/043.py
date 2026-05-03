a=[]
s=input()
for i in s:
  if i=="0":
    a.append(0)
  elif i=="1":
    a.append(1)
  elif i=="B":
    if len(a)>0:
      a.pop()
print(*a,sep="")