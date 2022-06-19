import re
from typing import Dict, List

# m = len(target)
# n = len(wordBank)

def canConstruct(target: str, wordBank: List) -> bool:
    # base case
    if(target==""):
        return True

    for word in wordBank:
        # we only care prefix word
        if(target.find(word)==0):
            newTarget = target[len(word):] # TC: O(m). SC: O(m)
            print(f"{word} in {target}")
            print(f"newTarget = {newTarget}\n")

            if(canConstruct(newTarget,wordBank)==True):
                return True
        else:
            print(f"{word} not in {target}")
    ''' total
    TC: O(n^m * m)
    SC: O(m^2)
    '''

    return False

def canMemo(target: str, wordBank: List, memo: Dict) -> bool:
    # memo
    if(target in memo):
        return True

    # base case
    if(target==""):
        return True

    for word in wordBank:
        # we only care prefix word
        if(target.find(word)==0):
            newTarget = target[len(word):] # TC: O(m). SC: O(m)
            print(f"{word} in {target}")
            print(f"newTarget = {newTarget}\n")

            if(canConstruct(newTarget,wordBank,memo)==True):
                memo[target] = True
                return True
        else:
            print(f"{word} not in {target}")
    ''' total
    TC: O(n*m^2)
    SC: O(m^2)
    '''

    memo[target] = False
    return False
def main():
    print()
    # print(canConstruct("abcdef",["ab","abc","cd","def","abcd"])) # true
    # print(canConstruct("skateboard",["bo","rd","ate","t","ska","sk","boar"])) # false
    # print(canConstruct("enterapotentpot",["a","p","ent","enter","ot","o","t"])) # true
    print(canConstruct("purple",["purp","p","ur","le","purpl"]))


if __name__ == "__main__":
	main()


'''
Write a function 'canConstruct(target, wordBank)' that accepts a target string and an array of strings

The function should return a boolean indicating whether or not the 'target' can be constructed by concatenanting elements of the 'wordBank' array.

You mau reuse elements of 'wordBank' as many times as needed

approach:
1.we are going to match our target string with each wordBank
2.note that we only care about prefix case, for ex: 
"abcd" "ab" this allowed
"abcd" "bc" this is not allowed

3.we are going to slice our targeted string with each our wordBank untill zero string
target word
"abcd" "ab" = "cd"

4.zero string it means we already found the targeted string, return true
"cd" "cd" = ""
return True

'''