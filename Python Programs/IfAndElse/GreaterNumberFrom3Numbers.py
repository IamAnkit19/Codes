a=int(input("Enter first number: "))
b=int(input("Enter second number: "))
c=int(input("Enter third number: "))

if(a>b):
    if(a>c):
        print("a is greater")
    else:
        if(c>a):
            print("c is greater")
        else:
            print("a is equal to c and greater than b")
else:
    if(b>a):
        if(b>c):
            print("b is greater")
        else:
            if(c>b):
                print("c is greater")
            else:
                print("b is equal to c and greater than a")
    else:
        if(a>c):
            print("a is equal to b and greater than c")
        else:
            if(c>a):
                print("c is greater")
            else:
                print("All are equal")