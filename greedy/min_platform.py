# Program to find minimum number of platforms


def findPlatform(arrive, depart, n):
    arrive.sort()
    depart.sort()

    plat_needed = 0
    max_plat = 0
    i = 0
    j = 0

    while i < n and j < n:
        if arrive[i] <= depart[j]:
            plat_needed += 1
            i += 1

        elif arrive[i] > depart[j]:
            plat_needed -= 1
            j += 1

        if plat_needed > max_plat:
            max_plat = plat_needed

    return max_plat


arrive = [100, 300, 500]
depart = [900, 400, 600]
n = len(arrive)

print(findPlatform(arrive, depart, n))
