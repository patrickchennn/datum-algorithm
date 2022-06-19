import pprint # for print pretty dict

def gridTraveler(n,m,memo):
    key = str(n) + ',' + str(m)
    # print(f"key = {key}")

    if(key in memo):
        print(f"{key} is in memo!")
        return memo[key]
    if(n==0 or m==0): return 0
    if(n==1 and m==1): return 1

    memo[key] = gridTraveler(n-1,m,memo)+gridTraveler(n,m-1,memo)
    pprint.pprint(memo,width=1)
    print()
    return memo[key]

def main():
    memo = {}
    # print(gridTraveler(1,1,memo)) # 1
    print(gridTraveler(2,3,memo)) # 3
    # print(gridTraveler(3,2,memo)) # 3
    # print(gridTraveler(3,3,memo)) # 6
    # print(gridTraveler(18,18,memo)) # 2333606220

if __name__ == "__main__":
	main()
'''
note: try to think about your recursive functions in terms of tree. I.E. try to VISUALIZE it
'''