p=int(input("Enter principle amount: "))
r=float(input("Enter rate of interest: "))
t=float(input("Enter time period: "))
CI=p*pow((1+(r/100)),t)-p
print("Compound interest is:",CI)