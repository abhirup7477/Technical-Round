def fibonacciRecursive(n, dp):
    if dp[n-1] != -1:
        return dp[n-1]
    elif n == 1:
        dp[n-1] = 0
    elif n == 2:
        dp[n-1] = 1
    else:
        dp[n-1] = fibonacciRecursive(n-1, dp) + fibonacciRecursive(n-2, dp)
    return dp[n-1]

def printFibonacci(terms):
    if(terms < 1):
        print("Invalid number of terms!")
        return
    print(f"First {terms} terms of fibonacci series are : ", end = " ")
    dp = [-1] * terms
    for i in range(1, terms+1):
        print(fibonacciRecursive(i, dp), end = " ")
    print()
    print(dp)

def fibonacci(terms):
    if terms < 1:
        print("Invalid number if terms!")
        return
    print("First {0} terms of fibonacci series are : ".format(terms), end = " ")
    if terms == 1:
        print("0")
    elif terms == 2:
        print("0 1")
    else:
        a = 0
        b = 1
        print("0 1 ", end = "")
        for i in range(3, terms+1):
            c = a + b
            print(c, end = " ")
            a = b
            b = c
        print()

terms = int(input("Enter the number of terms : "))
printFibonacci(terms)
fibonacci(terms)