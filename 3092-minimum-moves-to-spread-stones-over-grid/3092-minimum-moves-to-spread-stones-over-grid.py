from itertools import product, permutations
class Solution:
    def minimumMoves(self, g: List[List[int]]) -> int:
        z = [(i,j) for i,j in product(*[range(3)]*2) if g[i][j]==0]
        q = [(i,j) for i,j in product(*[range(3)]*2) for _ in range(1,g[i][j])]
        return min(sum(abs(i-k)+abs(j-l) for (i,j),(k,l) in zip(z,p)) for p in {*permutations(q)})