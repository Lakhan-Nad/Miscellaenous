def print_rangoli(size):
    for i in range(0,2*size-1):
        if(i<size):
            j=i
        else:
            j=2*size-1-i-1
        print("-"*(2*(size-1-j)),end='')
        string=''
        string2=''
        for k in range(0,j):
            string=string + chr(96+size-k) + '-'
        string2=string + chr(96+size-j) + string[::-1]
        print(string2,end='')
        print("-"*(2*(size-1-j)),end='')
        print()
def main():
    size=int(input("enter the integer between 1 to 26 :"))
    if (size<=26 and size>=1):
        print_rangoli(size)
    else:
        print("invalid input")
    n=input()
main()
