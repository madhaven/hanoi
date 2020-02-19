#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
int maxx, stack[3][50], top[3], steps=0;
COORD coord;
void gotoxy(int x, int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void displaytowers()
{
    int xx;
    system("Cls");
    cout<<"STEPS : "<<steps;
    for (int i=0; i<maxx; i++)
    {
        gotoxy(maxx+1, i+1); cout<<(char)179;
        gotoxy(3*maxx+3, i+1); cout<<(char)179;
        gotoxy(5*maxx+5, i+1); cout<<(char)179;
    }
    cout<<"\n";
    for (int i=1; i<(6*maxx+8); i++)
        cout<<(char)196;
    gotoxy(maxx+1, maxx+1); cout<<(char)193;
    gotoxy(3*maxx+3, maxx+1); cout<<(char)193;
    gotoxy(5*maxx+5, maxx+1); cout<<(char)193;
    for (int i=0; i<3; i++)
        for (int j=0; j<=top[i]; j++)
        {
            xx=(2*i+1)*maxx+(2*i+1);
            gotoxy(xx-stack[i][j], maxx-j);
            for (int k=0; k<stack[i][j]; k++)
                cout<<(char)254;
            gotoxy(xx+1, maxx-j);
            for (int k=0; k<stack[i][j]; k++)
                cout<<(char)254;
        }
    gotoxy(0,0);
}

int returntheotherone(int x, int y)
{
    if (x==0) if (y==1) return 2;
            else return 1;
    else if (x==1) if (y==2) return 0;
            else return 2;
    else if (x==2) if (y==0) return 1;
            else return 0;
}
void push(int x, int item)
{
    stack[x][++top[x]]=item;
}
int pop(int x)
{
    return stack[x][top[x]--];
}
void shift(int x, int y, int n, int time=500)
{
    int z=returntheotherone(x, y);
    if (n==1)
    {
        push(y, pop(x));
        steps++;
    }
    else
    {
        shift(x, z, n-1, time); displaytowers();_sleep(time);
        push(y, pop(x));        steps++;displaytowers();_sleep(time);
        shift(z, y, n-1, time);
    }
}
int main()
{
    cout<<"Enter no : ";
    cin>>maxx;
    top[0]=maxx-1;
    top[1]=top[2]=-1;
    for (int i=0; i<maxx; i++)
        stack[0][i]=maxx-i;
    displaytowers();
    shift(0, 2, maxx, 200);
    displaytowers();
}
