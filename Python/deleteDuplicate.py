#Sorted array
lst = [1, 1, 2, 3, 3, 3, 4, 5, 5]
n = len(lst)
i = 0
while i < n :
    if i < n-1 and lst[i] == lst[i+1]:
        lst.pop(i)
        n -= 1
        i -= 1  # Adjust index after removal
    i += 1
print(lst)

#Unsorted array
lst1 = [1, 8, 4, 1, 4, 1, 2, 2, 8, 1]
