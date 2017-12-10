def all_perms(n, a, state=()):
    for i in range(a[n-1]):
        if (n == 1):
            yield (i,)
        else:
            for result in all_perms(n-1, a, state+(i,)):
                yield result + (i,)

print list(all_perms(3,[2,1,3]))
