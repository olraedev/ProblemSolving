from collections import deque
import sys
input = sys.stdin.readline

def bfs(start):
    queue = deque([start])
    
    while queue:
        x = queue.popleft()
        
        if x == k:
            return print(visited[x])
        
        for i in (x-1, x+1, 2*x):
            if 0 <= i < MAX and not visited[i]:
                if i == 2 * x and x != 0:
                    visited[i] = visited[x]
                    queue.appendleft(i)
                else:
                    visited[i] = visited[x] + 1
                    queue.append(i)
    

MAX = 100001
n, k = map(int, input().split(' '))
visited = [0] * MAX
bfs(n)