def HowSum(targetSum,numbers):
    if(targetSum == 0):
        print(f"YAHOO WE FIND THIS SHIT")
        return [] # this is our targeted sum

    if(targetSum < 0):
        print("OUR TARGETSUM IS NEGATIVE! {}".format(targetSum))
        return None

    for num in numbers:
        # a + b = targetSum where a,b ∈ numbers
        # a = targetSum - b
        remainder = targetSum - num # this shit is gonna be our new targetSum and keep changing if we do a recursive call
        print(f"r = {targetSum}-{num} --> r = {remainder}")

        remainderResult = HowSum(remainder,numbers)
        print(f"remainderResult ~≟ None {remainderResult}")
        # check if at least one of them is true, then that parent should return true
        if(remainderResult != None):
            print(f"RETTTTT NUM={num}")
            print(f"RETTTTT TRUEEE={remainder}")
            return [*remainderResult,num]
        else:
            print("nah\n")
    print("RETRUN False False False False False")
    return None

def HowSumMemo(targetSum,numbers,memo):
    if(targetSum in memo): return memo[targetSum]

    if(targetSum == 0):
        return [] # this is our targeted sum

    if(targetSum < 0):
        return None

    for num in numbers:
        remainder = targetSum - num # this shit is gonna be our new targetSum and keep changing if we do a recursive call

        remainderResult = HowSumMemo(remainder,numbers,memo)
        if(remainderResult != None):
            return [*remainderResult,num]
    memo[targetSum] = None
    return None

def main():
    # execute this first because we already have visualized recursive
    # print(HowSum(7,[2,3]))
    print(HowSum(7,[5,3,4,7]))
    # print(HowSum(7,[2,4]))
    # print(HowSum(8,[2,3,5]))



    memo = {}
    # memoized
    # print(HowSumMemo(300,[7,14],memo))
    # l=list(HowSumMemo(1222,[7,14,12,123,2131,123,12,12],memo))
    # print(l,sum(l))


if __name__ == "__main__":
    main()

'''
Write a function "howSum(targetSum, numbers)" that takes in a targetSum and an array of numbers as arguments

The function should return an array containing any combination of elements that add up to exactly the targetSum. If there is no combination that adds up to the targeSum, then return null.

If there are multiple combinations possible, you may return any single one

howSum(7,[5,3,4,7])
possible ans:
[7]
[3,4]

howSum(8,[2,3,5])
possible ans: 
[2,2,2,2]
[5,3]

howSum(7,[2,4])
possible ans:
null

howSum(0,[1,2,3])
possible ans:
[]
'''