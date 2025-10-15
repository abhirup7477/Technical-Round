def largestCommonPrefixFromList(lst):
    try:
        if not lst:
            raise ValueError("List is empty!")
        prefix = lst[0]
        for word in lst[1:]:
            while not word.startswith(prefix):
                prefix = prefix[:-1:]
                if not prefix:
                    return None
        return prefix
    except Exception as e:
        print("ERROR", e)
        return None


def largestCommonPrefix(str1, str2):
    prefix = str1
    while prefix:
        if str2.startswith(prefix):
            return prefix
        prefix = prefix[:-1:]
    return None

str1 = "abhirpbag"
str2 = "abhirup bag cse"

lst = ["Abhirup", "AbhirupBag", "Abhirup Bag", "AbhirCSEBag"]

print(largestCommonPrefix(str1, str2))
print(largestCommonPrefixFromList(lst))