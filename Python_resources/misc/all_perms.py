def all_perms(n, state=()):
    for i in range(n):
        if i not in state:
            if (len(state) == (n-1)):
                yield (i,)
            else:
                for result in all_perms(n, state+(i,)):
                    yield result + (i,)

print list(all_perms(4))
