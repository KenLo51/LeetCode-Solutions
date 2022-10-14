class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while(len(stones)>1):
            stones.sort()
            val = stones.pop() - stones.pop()
            if(val > 0):
                stones.append(val)
        return stones[0] if (len(stones)==1) else 0