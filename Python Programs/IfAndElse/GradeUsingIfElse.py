marks=int(input("Enter your marks: "))

if(marks>=85):
    grade='A+'
elif(marks>=75 and marks<85):
    grade='A'
elif(marks>=60 and marks<75):
    grade='B'
elif(marks>=45 and marks<60):
    grade='C'
elif(marks>=33 and marks<45):
    grade='D'
else:
    grade='Fail'
print("Your grade is:",grade)