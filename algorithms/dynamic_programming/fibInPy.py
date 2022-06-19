import pprint # for print pretty dict

def fibMemo(n,memo):
    # if we start count fib num from 0. 0 1 1 2 3 ...
    # if(n<=1):
    #     return n
    
    # if we start count fib num from 1. 1 1 2 3 ...
    if(n<=2): return 1

    if n in memo: # same
        print(f"{n} is in memo!")
        return memo[n] 

    memo[n] = fibMemo(n-1,memo) + fibMemo(n-2,memo)
    pprint.pprint(memo,width=1)
    print()
    return memo[n]

# naive approach
# def fib(n):

def main():
    n = 5
    memo = {}
    print(f"fib({n}) = {fibMemo(n,memo)}")
    # print(f"fib({n}) = {fib(n)}")

    # n = 50
    # memo = {}
    # print(f"fib({n}) = {fibMemo(n,memo)}")


if __name__ == "__main__":
    main()

'''
n   = 0 1 2 3
f(n)= 0 1 3 5
definition:
f0 = 0
f1 = 1
fn = fn-1 + fn-2
for n > 1

or you can start from 1
f0 = 1
f1 = 1
fn = fn-1 + fn-2
for n > 2
( f2=f1 + f0 <--> f2=1+1 ) --> f2=2

memo stands for memoization

https://www.youtube.com/watch?v=oBt53YbR9Kk&t=799s
'''