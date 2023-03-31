n = int(input())
field = []
for i in range(n):
    row = input().strip()
    field.append(row)

visited = [[False for _ in range(n)] for _ in range(n)]

def dfs(x, y):
    visited[x][y] = True
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        if nx >= 0 and nx < n and ny >= 0 and ny < n and not visited[nx][ny] and field[nx][ny] == 'T':
            dfs(nx, ny)

count = 0
for i in range(n):
    for j in range(n):
        if field[i][j] == 'T' and not visited[i][j]:
            count += 1
            dfs(i, j)

print(count)
