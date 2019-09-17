/* Print Pascal's Triangle for a value of N less than 20 */

#include<stdio.h>
#include<conio.h>
int main()
{
    unsigned long int n,i,j;
    printf("Enter Value of N: ");
    scanf("%d",&n);
    int arr[20][41];
    for(i=0;i<2*n+1;i++)
        arr[0][i]=0;
    arr[0][n]=1;
    for(i=1;i<n+1;i++)
    {
        if(i<n)
        {
            arr[i][0]=0;
            arr[i][2*n]=0;
        }
        else
        {
            arr[i][0]=1;
            arr[i][2*n]=1;
        }
        for(j=1;j<2*n;j++)
        {
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j+1];
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=2*n-1;j++)
        {
            if(arr[i][j])
                printf("%d",arr[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
