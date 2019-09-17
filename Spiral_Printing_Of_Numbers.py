n=int(input("enter number : "))
l=[0]*n
for i in range(n):
    l[i]=[0]*n
z=1
for j in range(0,(n-1)//2+1):
    for k in range(j,n-j):
        l[j][k]=z
        z=z+1
    for k in range(j+1,n-j):
        l[k][n-j-1]=z
        z=z+1
    for k in range(j,n-j-1):
        l[n-1-j][n-2-k]=z
        z=z+1
    for k in range(j+1,n-j-1):
        l[n-1-k][j]=z
        z=z+1
maxval=n**2
size=len(str(maxval))
for i in range(n):
    for j in range(n):
        s=str(l[i][j])
        s=s+' '*(size-len(s))
        print(s,end='  ')
    print()
input()
