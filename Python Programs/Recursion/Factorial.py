def fact(n):
    if(n==0):
        return 1
    else:
        return n * fact(n-1)

n=int(input("Enter n: "))
ans=fact(n)
print("Factorial is:",ans)