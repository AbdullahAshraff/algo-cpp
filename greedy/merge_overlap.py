# Merge Overlapping Intervals by Checking all Possible Overlaps


def mergeOverlap(intervals: list):
    # Sort intervals based on start values
    intervals.sort()

    res = []
    res.append(intervals[0])

    for i in range(1, len(intervals)):
        last_added = res[-1]
        current = intervals[i]

        # If current interval overlaps with the last merged interval, merge them
        if current[0] <= last_added[1]:
            last_added[1] = max(last_added[1], current[1])
        else:
            res.append(current)

    return res


if __name__ == "__main__":

    intervals = [[7, 8], [1, 5], [2, 4], [4, 6]]
    res = mergeOverlap(intervals)

    for interval in res:
        print(interval[0], interval[1])
