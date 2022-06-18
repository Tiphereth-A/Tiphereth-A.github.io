def f(n, p, q):
    return n * n * (n + 1)**2 * (2 * n * n + 2 * n - 1)//12 * q - p * n


def get_root(val, p, q):
    l, r = 1, 114514 * 19 ** 19 + 810
    ans = r
    while l <= r:
        mid = (l + r)//2
        res = f(mid, p, q)
        if res == val:
            ans = mid
            break
        elif res > val:
            ans, r = mid, mid - 1
        else:
            l = mid + 1
    return ans


p, q = map(int, input().split())
r0, r1 = get_root(0, p, q), get_root(10 ** 99, p, q)
if r0 > 1:
    print(p + max([-f(i, p, q)for i in range(1, r0)]))
else:
    print(p)
print(r1)
