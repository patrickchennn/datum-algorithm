def bestSum(targetSum,numbers):
    if(targetSum == 0):
        print(f"YAHOO WE FIND THIS SHIT~~~~~~~~~~~~~~~~~~~~~~~~~")
        return [] # this is our targeted sum

    if(targetSum < 0):
        print("OUR TARGETSUM IS NEGATIVE! {}".format(targetSum))
        return None

    shortestCombi = None
    for num in numbers:
        # a + b = targetSum where a,b ∈ numbers
        # a = targetSum - b
        remainder = targetSum - num # this shit is gonna be our new targetSum and keep changing if we do a recursive call
        print(f"r = {targetSum}-{num} --> r = {remainder}")

        remainderResult = bestSum(remainder,numbers)
        print(f"remainderResult ~≟ {remainderResult}")

        # check if at least one of them is true, then that parent should return true
        if(remainderResult != None):
            combi = [*remainderResult,num]
            print(f"combi = {combi}")
            if(shortestCombi==None or len(combi) < len(shortestCombi)):
                print(f"{shortestCombi==None} or {len(combi)} < {shortestCombi}")
                shortestCombi = combi
                print(f"assign!! shortestCombi = {combi}\n")

    print(f"RETRUN SHORTESTCOMBIIII {shortestCombi}\n")
    return shortestCombi

def bestSumMemo(targetSum,numbers,memo):
    if(targetSum in memo):
        return memo[targetSum]

    if(targetSum == 0):
        return [] # this is our targeted sum

    if(targetSum < 0):
        return None

    shortestCombi = None
    for num in numbers:
        remainder = targetSum - num # this shit is gonna be our new targetSum and keep changing if we do a recursive call
        remainderResult = bestSumMemo(remainder,numbers,memo)

        if(remainderResult != None):
            combi = [*remainderResult,num]
            if(shortestCombi==None or len(combi) < len(shortestCombi)):
                shortestCombi = combi

    memo[targetSum] = shortestCombi
    return memo[targetSum]

def main():
    print(bestSum(7,[5,3,4,7])) # [7]
    # print(bestSum(8,[2,3,5])) # [3,5]
    # print(bestSum(8,[1,4,5]))# [4,4]

    #memoized
    memo = {}
    # print(bestSumMemo(100,[1,2,5,25],memo)) # [25,25,25,25]

if __name__ == "__main__":
	main()


'''
Write a function `bestSum(targetSum,numbers)` that takes in a targetSum and an array of numbers as arguments.

The function should return an array containing the "shortest" combination of numbers that add up exactly the targetSum

If there is a tie for the shortest combination, you may return any one of the shortest
'''