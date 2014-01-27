def largestRectArea(h):
    p = []
    i = 0
    m = 0
    h.append(0)
    while (i < len(h)):
        if (len(p) == 0 or h[p[len(p)-1]] <= h[i]):
            p.append(i)
            print "i=", i, "p=", p
            i += 1
        else:
            t = p.pop()
            if (len(p) == 0):
                m = max(m, h[t] * i)
                print "p1", h[t], i
            else:
                m = max(m, h[t] * (i-p[len(p)-1]-1))
                print "p2", h[t], (i-p[len(p)-1]-1)
            print "i=", i, "t=", t, "p=", p, "m=", m
    return m

#h = [2,1,5,6,2,3]
h = [2,2,3,4,4,2]
print largestRectArea(h)
