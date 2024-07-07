def calculate(n):
    if(n==0):
        return 0
    else:
        return n+calculate(n-1)

n=int(input("Enter n: "))
ans=calculate(n)
print("Sum is:",ans)