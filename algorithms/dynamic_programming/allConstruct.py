from typing import Dict, List

def allConstruct(target: str, wordBank: List) -> List[List]:
    if(target == ""):
        return [[]]

    res = []
    for word in wordBank:
        if(target.find(word)==0):
            newTarget = target[len(word):]
            arr = allConstruct(newTarget,wordBank)
            arrWays = [word]
            print(arr)
            # print(arrWays)
            res.append(arrWays)
    
    return res


def main():
    # print(allConstruct("abcdef",["ab","abc","cd","def","abcd"]))
    print(allConstruct("purple",["purp","p","ur","le","purpl"]))



if __name__ == "__main__":
	main()