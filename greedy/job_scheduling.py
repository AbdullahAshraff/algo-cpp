class Job:
    def __init__(self, id, deadline, profit):
        self.id = id
        self.deadline = deadline
        self.profit = profit

    def __str__(self):
        return self.id


def max_profit_seq(jobs: list, n: int):
    jobs.sort(key=lambda j: j.profit, reverse=True)

    result = [''] * n
    slot = [False] * n

    for i in range(n):
        if not slot[jobs[i].deadline - 1]:  # Check if slot is free
            result[i] = jobs[i].id
            slot[jobs[i].deadline - 1] = True  # Mark this slot as filled



    [print(j, end=" ") for j in result]


if __name__ == "__main__":
    jobs = [
        Job("a", 2, 100),
        Job("b", 1, 19),
        Job("c", 2, 27),
        Job("d", 1, 25),
        Job("e", 3, 15),
    ]

    n = len(jobs)
    max_profit_seq(jobs, n)
