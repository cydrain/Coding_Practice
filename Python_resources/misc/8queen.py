def conflict(nextX, state):
    nextY = len(state)
    for row in range(nextY):
        if abs(nextX-state[row]) in (0, nextY-row):
            return True
    return False

def queen(n, state=()):
    for pos in range(n):
        if not conflict(pos, state):
            if (len(state) == (n-1)):
                yield (pos,)
            else:
                for result in queen(n, state+(pos,)):
                    yield result + (pos,)

print(list(queen(8)))

