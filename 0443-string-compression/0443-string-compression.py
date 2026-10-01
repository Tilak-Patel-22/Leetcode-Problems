class Solution:
    def compress(self, chars: list[str]) -> int:
        result  =[]
        i = 0
        while i<len(chars):
            ch = chars[i]
            count = 0
            while i<len(chars) and chars[i] == ch:
                count+=1
                i+=1

            result.append(ch)
            if count>1:
                result.extend(str(count))
        for i in range(len(result)):
            chars[i] = result[i]
        return len(result)