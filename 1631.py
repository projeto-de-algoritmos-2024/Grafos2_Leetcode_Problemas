import heapq
from typing import List

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        # Para o início da solução do problema, precisamos saber o tamanho das linhas e das colunas, entendendo as dimensões da matriz
        rows, cols = len(heights), len(heights[0])

        # Direções declaradas, a fim de facilitar o caminho dentro da matriz
        direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        # Fila de prioridades inicializada na posição (0, 0) com esforço 0 por ser o primeiro elemento
        heap = [(0, 0, 0)] 
        
        # Matriz de esforço criada com o intuito de encontrar o menor esforço para cada célula, iniciando cada posição com -1
        effort = [[-1] * cols for _ in range(rows)]
        effort[0][0] = 0  
        
        # Entrando na fila de prioridades
        while heap:
            eff, r, c = heapq.heappop(heap)

            # Caso consiga chegar no último vértice, o esforço é retornado
            if r == rows - 1 and c == cols - 1:
                return eff
            
            # Iteração a fim de procurar nas quatro posições (baixo, cima, esquerda, direita)
            for row, col in direction:
                newr, newc = r + row, c + col
                
                # Procurar a posição que está dentro do alcance
                if 0 <= newr < rows and 0 <= newc < cols:
                    # Calcular o novo esforço para ir até a célula (newr, newc)
                    neweff = max(eff, abs(heights[r][c] - heights[newr][newc]))

                    # Se o esforço encontrado no neweff for menor, atualiza na fila de prioridades
                    if effort[newr][newc] == -1 or neweff < effort[newr][newc]:
                        effort[newr][newc] = neweff
                        heapq.heappush(heap, (neweff, newr, newc))

        # Caso o loop termine sem retornar nada, isso indica que nenhum caminho válido foi encontrado
        return -1