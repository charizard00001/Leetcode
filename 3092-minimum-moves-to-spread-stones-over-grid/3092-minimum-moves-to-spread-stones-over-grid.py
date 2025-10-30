# class Solution:
#     def minimumMoves(self, g: List[List[int]]) -> int:
#         z = [(i,j) for i,j in product(*[range(3)]*2) if g[i][j]==0]
#         q = [(i,j) for i,j in product(*[range(3)]*2) for _ in range(1,g[i][j])]
#         return min(sum(abs(i-k)+abs(j-l) for (i,j),(k,l) in zip(z,p)) for p in {*permutations(q)})

from itertools import product, permutations
from typing import List

class Solution:
    def minimumMoves(self, g: List[List[int]]) -> int:
        # Collect all zero positions
        zero_positions = [
            (i, j)
            for i, j in product(range(3), range(3))
            if g[i][j] == 0
        ]

        # Collect all extra balls' positions (cells with value >1 contribute multiple times)
        ball_positions = [
            (i, j)
            for i, j in product(range(3), range(3))
            for _ in range(1, g[i][j])
        ]

        # Try all permutations of assigning extra balls to zero positions
        min_moves = min(
            sum(abs(i - x) + abs(j - y) for (i, j), (x, y) in zip(zero_positions, perm))
            for perm in set(permutations(ball_positions))
        )

        return min_moves
