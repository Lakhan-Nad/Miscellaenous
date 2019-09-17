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

def checkvalid(d,m,y):
    if (m in range(1,13) and y>=1 and d in range(1,return_days(m,y)+1)):
        return 1
    else:
        return 0

def calc(d1,m1,y1,d2,m2,y2):
    no_days=0
    for i in range(y1,y2):
        no_days=no_days+365+checkleap(i)
    for i in range(1,m2):
        no_days=no_days+return_days(i,y2)
    for i in range(1,m1):
        no_days=no_days-return_days(i,y1)
    no_days=no_days+d2-d1
    return no_days

def main():
    d1,m1,y1=(int(x)for x in input("enter date of previous day (d.m.y) :").split('.'))
    d2,m2,y2=(int(x)for x in input("enter date of next day (d.m.y) :").split('.'))
    if (checkvalid(d1,m1,y1) and checkvalid(d2,m2,y2))==1:
        if ((y2<y1) or (y2==y1 and m2<m1) or (y2==y1 and m2==m1 and d2<d1)):
            print("YOUR DATES ORDER IS WRONG")
        else:
            y=calc(d1,m1,y1,d2,m2,y2)
            print("NO OF DAYS IN BETWEEN IS",y)
    else:
        print("INVALID INPUT")

main()
input()
