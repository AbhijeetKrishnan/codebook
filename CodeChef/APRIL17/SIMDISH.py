t = int(input())

for test in range(t):
    dish1 = input().split()
    dish1.sort()
    dish2 = input().split()
    dish2.sort()
    similar_ingredient_count = 0
    i, j = 0, 0
    while i != len(dish1) and j != len(dish2):
        if dish1[i] == dish2[j]:
            similar_ingredient_count += 1
            i += 1
            j += 1
        elif dish1[i] < dish2[j]:
            i += 1
        else:
            j += 1
    if similar_ingredient_count >= 2:
        print('similar')
    else:
        print('dissimilar')