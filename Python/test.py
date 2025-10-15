#Experimenting with reversing and list
# lst = [1, 2, 3, 4, 5]
# lst.reverse()
# lst2 = sorted(lst, reverse=True)
# lst1 = list(reversed(lst))
# print(lst)
# print(lst1)
# print(lst2)



# # Experimenting with range and print
# # This code prints numbers from 1 to 10, but when it reaches 5,
# # it sets i to 3, which does not affect the loop.
# # The loop continues to print numbers until it reaches 10.
# n = 10
# for i in range(1, n+1):
#     print(i, end = " ")
#     if(i == 5):
#         i = 3
# print()

# #solution: use while loop insted


# str1 = "abhisgfbsbsab arpita vjsbj bag chha"
# str2 = "bdsbskbkdabhi bagarpi chhayabagdas"

# common = ""
# length = 0

# def issubstring(str1, str2):
#     n = len(str1)
#     m = len(str2)
#     for i in range(n - m):
#         for j in range(i, i + m):
#             if str1[i] != str2[j-i]:
#                 return False
#     return True

# for i in range(len(str1)):
#     for j in range(len(str1)):
#         if str1[i:j+1:] in str2:
#             if j-i+1 > length:
#                 length = j - i + 1
#                 common = str1[i:j+1]
# print("Longest common substring:", common)
# print("Length of longest common substring:", length)


#Experimenting with class in python

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def display(self, name, age):
        print(f"Name: {self.name}, Age: {self.age}")
        print(f"Name: {name}, Age: {age}")

person = Person("Abhishek", 20)
print(person.name)
print(person.age)
person.display("Arpita", 21)
Person.display(person, "Arpita", 21)
