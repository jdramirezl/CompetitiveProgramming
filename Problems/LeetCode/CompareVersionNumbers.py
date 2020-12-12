#https://leetcode.com/problems/compare-version-numbers/submissions/


class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = list(map(int, version1.split(".")))
        v2 = list(map(int, version2.split(".")))
        
        print(v1)
        
        mini = min(len(v1), len(v2))
        mismotam = len(v1) == len(v2)
        
        for i in range(mini):
            if v1[i] == v2[i]: continue
            elif v1[i] > v2[i]: return 1
            else: return -1
        
        if mismotam: return 0
        
        zeros = False
        if len(v1) > mini:
            for i in range(mini, len(v1)):
                if v1[i] != 0: return 1
            
            return 0
        
        else:
            for i in range(mini, len(v2)):
                if v2[i] != 0: return -1
            
            return 0
        