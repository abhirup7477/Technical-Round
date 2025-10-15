# def atoiRecursive(num, index, n):
#     if index >= len(num):
#         return n
#     if num[index].isdigit():
#         print(f"1. n = {n}")
#         return atoiRecursive(num, index+1, n*10+int(num[index]))
#     else:
#         print(f"2. n = {n}")
#         return n

# def atoi(num):
#     index = 0
#     sign = 1
#     while(num[index] == " "):
#         index += 1
#     if num[index] == "-" or num[index] == "+":
#         if num[index] == "-":
#             sign = -1
#         index += 1
#     return sign * atoiRecursive(num, index, 0)

# or
def recursiveAtoi(num, n):
    if not num:
        return n
    elif not num[0].isdigit():
        return n
    else:
        return recursiveAtoi(num[1:], n*10 + int(num[0]))

def atoi(num):
    sign = 1
    num = num.lstrip()
    if num[0] == "-" :
        sign = -1
        num = num[1:]
    elif num[0] == "+" :
        num = num[1:]
    num = num.lstrip("0")
    return sign * recursiveAtoi(num, 0)

num = "    -0001234.45 word"
num1 = "    00012340"
print(atoi(num))
print(atoi(num1))