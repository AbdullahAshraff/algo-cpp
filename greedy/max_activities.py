# Activity selection problem


def print_max_activities(start, finish):
    n = len(finish)
    print("Following activities are selected")

    i = 0
    print(i, end=" ")

    for j in range(1, n):
        if start[j] >= finish[i]:
            print(j, end=" ")
            i = j


# Driver code
if __name__ == "__main__":

    start = [1, 3, 0, 5, 8, 5]
    finish = [2, 4, 6, 7, 9, 9]

    # Function call
    print_max_activities(start, finish)
