list=[1,2,3,2,1]
copylist=list.copy()
copylist.reverse()
if(list==copylist):
    print("List is Palindrome")
else:
    print("List is not Palindrome")