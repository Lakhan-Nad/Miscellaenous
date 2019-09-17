/* A program to print permutation of string in lexographic order. 
Algorithm is to print smallest first and then use it to generate 
and print next in order and then next until all permutations 
are prinrted*/

#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 100

char* up_p(char s[100])
{
    int inv_p=0;
    int i=0,j;
    for(i=0;s[i]!='\0';i++);
    for(j=0;j<i-1;j++)
    {
        if(s[i-j-2]>=s[i-j-1])
            continue;
        else
        {
            inv_p=i-j-2;
            break;
        }
    }
    if(j==i-1)
    {
        return "\0";
    }
    int k=0;
    while(s[i-k-1]<=s[inv_p])
        k++;
    char temp=s[i-k-1];
    s[i-k-1]=s[inv_p];
    s[inv_p]=temp;
    for(k=0;k<(i-inv_p-1)/2;k++)
    {
        temp=s[inv_p+1+k];
        s[inv_p+1+k]=s[i-1-k];
        s[i-1-k]=temp;
    }
    printf("%s\n",s);
    return s;
}

int main()
{
    char s[MAX_SIZE];
    scanf("%s",s);
    int i=0,j,k;
    for(i=0;s[i]!='\0';i++);
    for(j=0;j<i;j++)
    {
        for(k=0;k<i-j-1;k++)
        {
            if(s[k]>s[k+1])
            {
                char temp=s[k];
                s[k]=s[k+1];
                s[k+1]=temp;
            }
        }
    }
    printf("%s\n",s);
    char *n=up_p(s);
    while(n[0]!='\0')
    {
        n=up_p(n);
    }
    getch();
    return 0;
}

