n,m=map(int,input().split())
wv=[list(map(int,input().split())) for _ in range(n)]
w=[i[0] for i in wv]
v=[i[1] for i in wv]
dp=[[0]*(m+1) for _ in range(n+1)]
#dp[i][j]:i番目までの品物から重さjを選んだ場合の最大価値
for i in range(1,n+1):
  for j in range(1,m+1):
    if j<w[i-1]:
      dp[i][j]=dp[i-1][j]
    else:
      dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1])
print(dp[n][m])