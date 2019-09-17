def checkvalid(m,y):
    if (m in range(1,13) and y>=1):
        return 1
    else:
        return 0

def checkleap(y):
    if (y%100!=0 and y%4==0):
        return 1
    elif (y%400==0):
        return 1
    else:
        return 0

def return_days(m,y):
    if m==0:
        return 0
    elif m==1:
        return 31
    elif m==2:
        return (28 + int(checkleap(y)))
    elif m==3:
        return 31
    elif m==4:
        return 30
    elif m==5:
        return 31
    elif m==6:
        return 30
    elif m==7:
        return 31
    elif m==8:
        return 31
    elif m==9:
        return 30
    elif m==10:
        return 31
    elif m==11:
        return 30
    elif m==12:
        return 31

def calculate(m,y):
    odd=0
    x=y-1;
    x=x%400
    z=x//100
    odd=odd+(z*5)
    x=x%100
    n=x%4
    q=x//4
    odd=odd+n+(q*5)
    for j in range(0,m):
        odd=odd+int(return_days(j,y))
    odd=odd%7
    return odd

def monthname(m):
    if m==0:
        return 0
    elif m==1:
        return "JANUARY"
    elif m==2:
        return "FEBRUARY"
    elif m==3:
        return "MARCH"
    elif m==4:
        return "APRIL"
    elif m==5:
        return "MAY"
    elif m==6:
        return "JUNE"
    elif m==7:
        return "JULY"
    elif m==8:
        return "AUGUST"
    elif m==9:
        return "SEPTEMBER"
    elif m==10:
        return "OCTOBER"
    elif m==11:
        return "NOVEMBER"
    elif m==12:
        return "DECEMBER" 

def printcal(odd,m,y):
    print("MONTH:",monthname(m),"YEAR:",y)
    print("SUN MON TUE WED THU FRI SAT")
    odd=odd+1
    t= odd + return_days(m,y)
    for i in range(1,t+1):
        if(i<=odd):
            print("    ",end='')
        else:
            p=i-odd
            print(p," "*(4-len(str(p))),sep='',end='')
        if(i%7==0):
            print()
    print()
    
def new(m,y):
    if(checkvalid(m,y)==1):
        odd=int(calculate(m,y))
        printcal(odd,m,y)
    else:
        print("ENTER A VALID MONTH OR YEAR")
    
        
def main():
    m=int(input("ENTER MONTH (1 TO 12): "))
    y=int(input("ENTER THE YEAR: "))
    new(m,y)
    input()
    
main()    
