t = int(input())
for test in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    l = 0
    r = n - 1
    suml = a[0]
    sumr = a[n-1]
    ans = 0
    while l < r:
        if suml == sumr:
            ans = max(ans, l + 1 + n - r)

        if suml <= sumr:
            l+=1
            suml+=a[l]

        elif sumr < suml:
            r-=1
            sumr+=a[r]
            
    print(ans)