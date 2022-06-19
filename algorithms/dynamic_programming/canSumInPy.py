def canSum(targetSum,numbers):
    if(targetSum == 0):
        print(f"YAHOO WE FIND THIS SHIT")
        return True # this is our targeted sum

    if(targetSum < 0):
        print("OUR TARGETSUM IS NEGATIVE! {}".format(targetSum))
        return False

    for num in numbers:
        # a + b = targetSum where a,b ∈ numbers
        # a = targetSum - b
        remainder = targetSum - num # this shit is gonna be our new targetSum and keep changing if we call it recursively
        print(f"r = {targetSum}-{num} --> r = {remainder}")

        child = canSum(remainder,numbers)
        print(f"child ≟ True")
        # check if at least one of them is true, then that parent should return true
        if(child==True):
            print(f"RETTTTT NUM={num}")
            print(f"RETTTTT TRUEEE={remainder}")

            return # use this return to see all recursive call/to see all trees
            # return True # use this to return True immediately to its parent call
        else:
            print("nah\n")
    print("RETRUN False False False False False")
    return False

def canSumMemo(targetSum,numbers,memo):
    if(targetSum in memo): return memo[targetSum]
    if(targetSum==0):return True

    if(targetSum < 0):
        return False

    for num in numbers:
        remainder = targetSum - num 
        child = canSumMemo(remainder,numbers,memo)
        if(child==True):
            # memo.update({remainder:True})
            return True

    # we need store our targetSum value to dict so we can check for the next execution whether "our new targetSum" is the same as "our previous targetSum".
    # note that we only need to store the false calculated sum. Why? because if we encountered "True" so it will immediately return True to the parent call
    memo.update({targetSum:False})
    return False

def main():
    memo = {}
    # execute this first because we already have visualized recursive
    # print(canSum(8,[2,3,5]))
    print(canSum(7,[5,3,4,7]))
    # print(canSum(7,[2,4]))

    # print(canSum(7,[2,1]))

    # memoized
    # print(canSumMemo(300,[7,14],memo))
    # print(canSumMemo(1222,[7,14,12,123,2131,123,12,12],memo))


if __name__ == "__main__":
    main()


'''
Write a function "canSUmMemo(targetSum,numbers)" that takes in a targetSum and an array of numbers as arguments.

The function should return a boolean indicating whether or not it is possible to generate the "targetSum" using numbers from the array.

array numbers are postive

we can reuse the numbers of the array as many times as we like

∃ (x∈numbers ^ y∈numbers ^ targetSum∈ℕ) such that x+y=targetSum
So, we will return True, if there is at least one solution which will satisfy this equation "x+y=targetSum" or "x=targetSum-y"

if this happens ~(∃ (x∈numbers ^ y∈numbers ^ targetSum∈ℕ) such that x+y=targetSum), then return False

'''