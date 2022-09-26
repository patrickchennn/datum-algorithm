from typing import List

''' complexity for merge_two_sorted_lists(a,b)
TC: θ(n+m), n is the length of the first array, m is the length of the second array

'''
def merge_two_sorted_lists(a: List, b: List) -> List:
    print(a)
    print(b)
    i = j = k = 0

    m: int = len(a)
    n: int = len(b)

    # this makes our SC become O(m+n)
    sorted_list=[] 

    while(i < m and j < n):
        if(a[i] <= b[j]):
            print(f"IF a[{i}] <= b[{j}] --> {a[i]} <= {b[j]} = {a[i] <= b[j]}")

            sorted_list[k] = a[i]
            print(sorted_list,'\n')

            k+=1
            i+=1
        else:
            print(f"ELSE a[{i}] >= b[{j}] --> {a[i]} >= {b[j]} = {a[i] >= b[j]}")

            sorted_list[k] = b[j]
            print(sorted_list,'\n')

            k+=1
            j+=1
    
    print(f"i < len(a) --> {i} < {m} = {i<m}")
    print(f"j < len(b) --> {j} < {n} = {j<n}\n")

    # if either array a or b has remaining element, copy all of the element into sorted_list
    while(i<m):
        sorted_list[k] = a[i]

        k+=1
        i+=1

    while(j<n):
        sorted_list[k] = b[j]

        k+=1
        j+=1
        
    return sorted_list

def main():
    # both list are sorted
    a=[5,8,12,33] # 4
    b=[7,9,45,51] # 4
    # print(merge_two_sorted_lists(a,b))

if __name__ == "__main__":
	main()

'''

https://www.youtube.com/watch?v=6pV2IF0fgKY&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=33
2.7.1 Two Way MergeSort - Iterative method
'''
