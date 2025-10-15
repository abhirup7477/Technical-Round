def save(n, vaccines, patients):
    for i in range(n):
        if vaccines[i] < patients[i]:
            return False
    return True

lines = ["1", "5", "123 100 345 200 645", "100 140 700 400 450"]
n = int(lines[1])
vaccines = list(map(int, lines[2].split()))
patients = list(map(int, lines[3].split()))

print(n)
print(vaccines)
print(patients)

vaccines.sort()
patients.sort()
print(vaccines)
print(patients)

if save(n ,vaccines, patients):
    print("Yes")
else:
    print("No")
