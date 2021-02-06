class Solution:
    def simplifyPath(self, path: str) -> str:
        words = path.split("/")
        final = []
        for x in words:
            if x == ' ' or x == '':
                continue
            elif x == ".":
                continue
            elif x == ".." :
                if(len(final) > 0):
                    final.pop(len(final)-1)
            else:
                final.append(x)
        
        ans ="/"+ "/".join(final)
        
        print(ans)
        return ans