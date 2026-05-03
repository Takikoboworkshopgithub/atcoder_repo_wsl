n,m=map(int,input().split())
wv=[list(map(int,input().split())) for _ in range(n)]
w=[i[0] for i in wv]
v=[i[1] for i in wv]
max_v=sum(v)+1
dp=[[0]*(max_v) for _ in range(n+1)]
for i in range(n+1):
  for j in range(max_v):dp[i][j]=float('inf')
#dp[i][j]:i番目までの品物を、価値がjになるように選んだときの最小重さ
dp[0][0]=0
for i in range(1,n+1):
  for j in range(max_v):
    if j>=v[i-1]:
      dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i-1]]+w[i-1])
    else:
      dp[i][j]=dp[i-1][j]
ans=0
for i in range(sum(v)+1):
  if dp[n][i]<=m:
    ans=i
print(ans)