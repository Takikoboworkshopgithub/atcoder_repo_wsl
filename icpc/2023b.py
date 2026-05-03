def amida(x,p):
  ret = p
  a=[ret]
  for i in range(len(x)):
    if x[i] == ret:
      ret +=1
    elif x[i] == ret+1:
      ret -=1
    a.append(ret)
  return ret, a
while(True):
  n,m,p,q=map(int,input().split())
  if n==0 and m==0 and p==0 and q==0:
    exit()
  x=list(map(int,input().split()))
  pos_start=[]
  pos_goal=[]
  tmp_q,pos_goal=amida(x,p)
  if q==tmp_q:
    print("OK")
    continue
  tmp_p,pos_start=amida(x.reverse(),q)
  for i in range(len(pos_start)):
    if abs(pos_start[i]-pos_goal[i])==1:
      print(i,min(pos_start[i],pos_goal[i]))
      break
  else:
    print("NO")