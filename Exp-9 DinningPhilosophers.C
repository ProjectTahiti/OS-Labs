#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define LEFT (i+4)%5
#define RIGHT (i+1)%5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
int state[5];
void put_forks(int);
void test(int);
void take_forks(int);
void philosopher(int i)
{
    if(state[i]==0)
    {
        take_forks(i);
        if(state[i]==EATING)
        {
            printf("\n Eating in progress..");
            put_forks(i);
        }
    }
}
void take_forks(int i)
{
    state[i]=HUNGRY;
    test(i);
}
void put_forks(int i)
{
    state[i]=THINKING;
    printf("\nphilosopher %d has completed its work",i);
    test(LEFT);
    test(RIGHT);
}
void test(int i)
{
    if(state[i]==HUNGRY&&state[LEFT]!=EATING&&state[RIGHT]!=EATING)
    {
        printf("\nphilosopher %d can eat",i);
        state[i]=EATING;
    }
}
void main()
{
    int i;
    for(i=1;i<=5;i++)
    state[i]=0;
    printf("\n\n\t\t\t DINNING PHILOSOPHERS PROBLEM");
    printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n ALL THE PHILOSOPHERS ARE THINKING !!....\n",i);
    for(i=1;i<=5;i++)
    {
        printf("\n\n the philosopher %d falls hungry\n",i);
        philosopher(i);
        getch();
    }
}
