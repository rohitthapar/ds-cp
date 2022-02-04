t=int(input())
for i in range(t):
    a,b,c,p,q,r = map(int,input().split(''))
    s=(p+q+r)/2
    if (a+b+c)>s:
        print("YES")
    else:
        if(p+b+c)>s:
            print("YES")
        elif(q+a+c)>s:
            print("YES")
        elif(b+a+r)>s:
            print("YES")
        else:
            print("NO")

