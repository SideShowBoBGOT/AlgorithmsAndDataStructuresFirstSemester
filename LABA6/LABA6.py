def calc(n):
    sum = 0
    count = 0
    if len(n) == 1:
        count = 1
        sum = int(n)
    else:
        c, s = calc(n[1:])
        sum = sum + int(n[0]) + s
        count = count + c + 1
    return count, sum


count, sum = calc(input('Enter integer > 0: '))
print(f'Count: {count}\tSum: {sum}')