n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
cnt=0
a_idx=[]
for i in range(n):
  if a[i]==b[0]:
    a_idx.append(i)
if len(a_idx)<2:
  print("No")
  exit()
else:
  cnt=0
  b_idx=1
  for i in range(a_idx[0]+1,n):
    if a[i]==b[b_idx]:
      b_idx+=1
      if b_idx==m:
        cnt+=1
        break
  b_idx=1
  for i in range(a_idx[1]+1,n):
    if a[i]==b[b_idx]:
      b_idx+=1
      if b_idx==m:
        cnt+=1
        break
if cnt==2:
  print("Yes")
else:
  print("No")