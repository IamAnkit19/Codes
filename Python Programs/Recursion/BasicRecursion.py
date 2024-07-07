def printnumber(n):
    if(n==0):
        return
    print(n)
    printnumber(n-1)

printnumber(10)