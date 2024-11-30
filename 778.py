class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        #Para o inicio do problema, precisamos saber o tamanho
        n = len(grid)
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        heap = [(grid[0][0], 0, 0)]

        visited = [[-1] * n for _ in range(n)]
        visited[0][0] = 0

        while heap:
            el, x, y = heapq.heappop(heap)

            if x==n-1 and y==n-1:
                return el
            
            for dx, dy in directions:
                newx, newy = x+dx, y+dy

                if 0<=newx<n and 0<=newy<n and visited[newx][newy]==-1:
                    visited[newx][newy]=0
                    newel = max(el, grid[newx][newy])
                    heapq.heappush(heap, (newel, newx, newy))
        return -1