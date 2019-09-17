l=[]
def main():
    n=int(input("enter the integer : "))
    b=int(input("enter the base : "))
    conv_fun(n,b)
    print("do you want to convert again,if yes then press Y:",end=' ')
    choice=input()
    if (choice=='Y' or choice=='y'):
        main()
    else:
        exit
    
def conv_fun(n,b):
    l.clear()
    x=n
    while n!=0:
        k=n%b
        l.append(k)
        n=n//b
    print("the value of ",x,"in base",b,"is : ",end='')
    for i in range(0,len(l)-1):
        print(l[len(l)-1-i],"-",sep='',end='')
    print(l[0])

main()



    
