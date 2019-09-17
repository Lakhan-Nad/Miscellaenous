/* This is a basic visualization of Towe Of Hanoi game with best possible moves
   Although algorithm used is general best will be to keep disc size less than 9
   Because each step is visualized and you can move to next step by clicking*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
struct stack
{
    int top;
    int arr[max];
}source,medium,last;
void push(struct stack *s,int x)
{
    if(s->top==max-1)
    {
        return;
    }
    s->top=s->top+1;
    s->arr[s->top]=x;
}
int pop(struct stack *s)
{
    if(s->top==-1)
    {
        return 0;
    }
    int x=s->arr[s->top];
    s->top=s->top-1;
    return x;
}
void initialize(int n)
{
    for(int i=0;i<n;i++)
        push(&source,n-i);
}
int number=-1;
void display(int n,struct stack s,struct stack i,struct stack d)
{
    system("CLS");
    printf("\n\n");
    number++;
    int x=s.top;
    int y=i.top;
    int z=d.top;
    for(int c=n-1;c>=0;c--)
    {
        if(c<=x)
            printf("%d      ",pop(&s));
        else
            printf(".      ");
        if(c<=y)
            printf("%d      ",pop(&i));
        else
            printf(".      ");
        if(c<=z)
            printf("%d      ",pop(&d));
        else
            printf(".      ");
        printf("\n");
    }
    printf("NO OF MOVES:%d\n",number);
    printf("Enter to see next move\n");;
    printf("\n");
}
void toh(int total,int n,struct stack *s,struct stack *i,struct stack *d)
{
    if(n>0)
    {
        toh(total,n-1,s,d,i);
        push(d,pop(s));
        display(total,source,medium,last);
        getch();
        toh(total,n-1,i,s,d);
    }
}
void main()
{
    source.top=-1;
    medium.top=-1;
    last.top=-1;
    int n;
    printf("Enter No. Of Discs: ");
    scanf("%d",&n);
    initialize(n);
    display(n,source,medium,last);
    getch();
    toh(n,n,&source,&medium,&last);
    getch();
}

