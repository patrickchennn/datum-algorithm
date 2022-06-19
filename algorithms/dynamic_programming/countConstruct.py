from typing import Dict, List

# m = len(target)
# n = len(wordBank)
def canConstruct(target: str, wordBank: List) -> int:
    totalWays: int = 0
    # base case
    if(target==""):
        return 1

    for word in wordBank:
        # we only care prefix word
        if(target.find(word)==0):
            newTarget = target[len(word):] # TC: O(m). SC: O(m)
            print(f"{word} in {target}")
            print(f"newTarget = {newTarget}\n")

            ways = canConstruct(newTarget,wordBank)
            totalWays += ways
        else:
            print(f"{word} not in {target}")

    ''' total time and space
    TC: O(n^m * m)
    SC: O(m^2)
    '''

    return totalWays

def canMemo(target: str, wordBank: List, memo: Dict) -> bool:
    # memo
    if(target in memo):
        return memo[target]
    totalWays: int = 0
    # base case
    if(target==""):
        return 1

    for word in wordBank:
        # we only care prefix word
        if(target.find(word)==0):
            newTarget = target[len(word):] # TC: O(m). SC: O(m)
            print(f"{word} in {target}")
            print(f"newTarget = {newTarget}\n")

            ways = canMemo(newTarget,wordBank,memo)
            totalWays += ways
        else:
            print(f"{word} not in {target}")

    ''' total time and space
    TC: O(n^m * m)
    SC: O(m^2)
    '''
    memo[target] = totalWays
    return totalWays

def main():
    print()
    # print(canConstruct("abcdef",["ab","abc","cd","def","abcd"])) # true
    # print(canConstruct("skateboard",["bo","rd","ate","t","ska","sk","boar"])) # false
    # print(canConstruct("enterapotentpot",["a","p","ent","enter","ot","o","t"])) # true
    # print(canConstruct("purple",["purp","p","ur","le","purpl"]))
    memo = {}
    print(canMemo("purple",["purp","p","ur","le","purpl"],memo))

    

if __name__ == "__main__":
	main()


'''


'''