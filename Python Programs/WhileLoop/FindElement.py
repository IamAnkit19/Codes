tup=(1,4,9,16,25,36,49,64,81,100)
i=0
x=int(input("Enter a number to find: "))
while i<len(tup):
    if(x==tup[i]):
        print("Element found at index no.",i)
    i+=1    