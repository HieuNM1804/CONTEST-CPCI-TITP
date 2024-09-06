dp = [[0] * 60 for _ in range(60)]
dp[0][0] = 1
for i in range(1, 61):
    for j in range(1, i + 1):
        dp[i][j] = (j * dp[i - 1][j] + dp[i - 1][j - 1])
for _ in range(int(input())):
    n = int(input())
    ans = 0
    for i in range(1, n + 1):
        ans += dp[n][i]
    print(ans)