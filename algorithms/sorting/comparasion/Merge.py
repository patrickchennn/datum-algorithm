from typing import List

def merge_sort(arr: List) -> None:

    # basecase
    if(len(arr)<2):
        return
    
    midIdx: int = len(arr)//2

    # divide
    left: List = arr[:midIdx]
    right: List = arr[midIdx:]
    print(left,end=" | ")
    print(right)

    merge_sort(left)
    merge_sort(right)

    # conquer and combine
    print("conquer and combine part")
    merge(arr,left,right)

def merge(arr: List ,left: List, right: List) -> None:
    i = j = k = 0
    m: int = len(left)
    n: int = len(right)

    print(f"left={left} || right={right}")
    while(i < m and j < n):
        if(left[i] <= right[j]):
            arr[k] = left[i]
            i+=1
        else:
            arr[k] = right[j]
            j+=1
        k+=1

    while i < m:
        arr[k] = left[i]
        i+=1
        k+=1
        
    while j < n:
        arr[k] = right[j]
        j+=1
        k+=1
    
    print(f"sorted list = {arr}\n")

def main():
    test_cases = [
        [38,27,43,3,9,82,10]
        # [10, 3, 15, 7, 8, 23, 98, 29],
        # [],
        # [3],
        # [9,8,7,2],
        # [1,2,3,4,5]
    ]
    for arr in test_cases:
        merge_sort(arr)
        print(arr)

if __name__ == "__main__":
	main()

'''
https://www.youtube.com/watch?v=6pV2IF0fgKY&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=33
2.7.1 Two Way MergeSort - Iterative method

https://www.geeksforgeeks.org/merge-sort/
'''