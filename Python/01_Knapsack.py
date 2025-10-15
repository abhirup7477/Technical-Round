def knapsack(val, weights, maxWeight, n, dp):
    if dp[n][maxWeight] != -1:
        return dp[n][maxWeight]
    elif n==0 or maxWeight==0 :
        dp[n][maxWeight] = 0
    elif weights[n-1] > maxWeight :
        dp[n][maxWeight] =  knapsack(val, weights, maxWeight, n-1, dp)
    else:
        dp[n][maxWeight] = max(knapsack(val, weights, maxWeight, n-1, dp), val[n-1] + knapsack(val, weights, maxWeight-weights[n-1], n-1, dp))
    return dp[n][maxWeight]

n = 3
val = [12, 9, 8]
weights = [3, 2, 1]
maxWeight = 5
dp = [[-1 for _ in range(maxWeight+1)] for _ in range(n+1)]
print(knapsack(val, weights, maxWeight, n, dp))