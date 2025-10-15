def display(lst, n, m):
    for i in range(n):
        for j in range(m):
            print(lst[i][j], end=" ")
        print()

str1 = "axabhihsllhabhirupfnlndlaepi"
str2 = "aabhdnjabhirupbagarpiabhiacchhaya"

n = len(str1)
m = len(str2)

length = 0
end = 0

dp = [[0] * (m+1) for _ in range(n+1)]
# display(dp, n+1, m+1)

for i in range(1, n+1):
    for j in range(1, m+1):
        if str1[i-1] == str2[j-1]:
            dp[i][j] = dp[i-1][j-1]+1
            if dp[i][j] > length:
                length = dp[i][j]
                end = i
        else:
            dp[i][j] = 0
  
print("Longest common substring:", str1[end - length : end : ])
# display(dp, n+1, m+1)
# print("Length of longest common substring:", length)