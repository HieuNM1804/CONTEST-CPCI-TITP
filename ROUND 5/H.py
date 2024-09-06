F = [[0 for _ in range(105)] for _ in range(105)]
G = [[0 for _ in range(105)] for _ in range(105)]
F[0][0] = F[2][1] = 1
G[0][0] = 1
for i in range(1, 101):
    G[2][i] = G[0][i] = 1
for i in range(4, 101, 2):
    for j in range(1, 101):
        if j * 2 <= i:
            for k in range(2, i + 1, 2):
                F[i][j] += F[k - 2][j - 1] * G[i - k][j]
                F[i][j] += G[k - 2][j - 2] * F[i - k][j]
        G[i][j] = G[i][j - 1] + F[i][j]
for _ in range(int(input())):
    n, k = map(int, input().split())
    print(F[n][k])
    # ans = str(F[n][k])
    # if(len(ans) <= 10): print(ans)
    # else : 
    #     print(ans[:5], ans[-5:], sep = '...')