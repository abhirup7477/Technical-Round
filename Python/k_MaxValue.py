# lst = list(map(int, input("Enter the nubers separated by space: ").split()))

# lst = [int(x) for x in input("Enter the numbers separated by space: ").split()]

lst = [1, 3, 4, 9, 2, 10, 44, 3, 7]
k = 4
lst.sort(reverse = True)
for i in range(k):
    print(lst[i], end = " ")
print()