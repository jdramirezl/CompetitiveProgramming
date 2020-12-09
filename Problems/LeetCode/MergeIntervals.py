# https://leetcode.com/problems/merge-intervals/
# O(n)

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        
        if len(intervals) == 1:
            return intervals

        result = list()
        indextocheck = 1
        x = 0 
        merged = False
        while x < len(intervals)-1:
            if not merged:
                now = intervals[x]
            
            merged = False  
            
            indextocheck = x + 1
            nextxd = intervals[indextocheck]
            
            
            if now[1] == nextxd[0]:
                now[1] = nextxd[1]
                merged = True
            elif now[1] >= nextxd[1]:
                merged = True
            elif now[1] > nextxd[0]:
                now[1] = nextxd[1]
                merged = True
            else:
                merged = False
                result.append(now)
            
            x += 1
            
        if not merged:
            result.append(intervals[x])
        else:
            result.append(now)
            
        return result