n=int(input())
abc=[list(map(int,input().split())) for _ in range(n)]
a=[float('inf')]*n
b=[float('inf')]*n
c=[float('inf')]*n
a[0],b[0],c[0]=abc[0]
for i in range(1,n):
  a[i]=max(b[i-1],c[i-1])+abc[i][0]
  b[i]=max(a[i-1],c[i-1])+abc[i][1]
  c[i]=max(a[i-1],b[i-1])+abc[i][2]
print(max(a[n-1],b[n-1],c[n-1]))