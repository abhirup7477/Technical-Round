time = input()
hour, min = time.split(":")
x, y = map(int, input().split())

alternate = {
    '0': '8',
    '1': '7',
    '2': None,
    '3': None,
    '4': '9',
    '5': '6',
    '7': '1',
    '8': '0',
    '9': '4'
}

def toggleMin(s):
    res = None
    if alternate[s[1]]:
        res1 = s[0] + alternate[s[1]];
    if int(res1) >=0 and int(res1) <= 60:
        diff1 = int(s) - int(res1)

    if alternate[s[0]]:
        res2 = alternate[s[0]] + s[1]
    diff2 = int(s) - int(res2)

    res = res1 if diff1 < diff2 else res2
