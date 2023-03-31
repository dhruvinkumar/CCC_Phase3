from fractions import Fraction

def stern_brocot_tree(path):
    a, b, c, d = 0, 1, 1, 0
    for move in path:
        if move == 'L':
            a, b = a+c, b+d
        elif move == 'R':
            c, d = a+c, b+d
    return Fraction(a+c, b+d)

# Reading input
n = int(input())
paths = [input().strip() for _ in range(n)]

# Generating output
for path in paths:
    result = stern_brocot_tree(path)
    print(f"{result.denominator}/{result.numerator}")
