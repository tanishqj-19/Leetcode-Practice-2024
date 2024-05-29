class Solution:
    def numSteps(self, s: str) -> int:
        n = int(s, 2)
        
        moves = 0
        while n != 1:
            if n % 2 == 0:
                n = n // 2
            else:
                n += 1
            moves += 1
        return moves
