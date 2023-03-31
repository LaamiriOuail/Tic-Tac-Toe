#include <iostream>
using namespace std;
int A[9];
int indexT=0;
static int n=0;
char T[9]= {'1','2','3','4','5','6','7','8','9'};
int ctoi(char c)
{
    int i=(c=='0')?0:(c=='1')?1:(c=='2')?2:(c=='3')?3:(c=='4')?4:(c=='5')?5:(c=='6')?6:(c=='7')?7:(c=='8')?8:(c=='9')?9:0;
    return i;
}
void drawtictactoo(char T[9])
{
    cout<<"Player 1: X "<<endl;
    cout<<"Player 2: Y "<<endl;
    cout<<endl;
    cout<<"       "<<T[0]<<" | "<<T[1]<<" | "<<T[2]<<endl;
    cout<<"      __________"<<endl;
    cout<<"       "<<T[3]<<" | "<<T[4]<<" | "<<T[5]<<endl;
    cout<<"      __________"<<endl;
    cout<<"       "<<T[6]<<" | "<<T[7]<<" | "<<T[8]<<endl;
}
int isExiste(int j)
{
    int i=0;
    for(int k=0; k<=indexT; k++)
        if(A[k]==j) i=1;
    return i;
}
void Empilement()
{
    int i=0,j,k;
    char c,n;
    while(i<9)
    {
        if(i%2==0)
        {
            j=1;
            c='X';
        }
        else
        {
            j=2;
            c='O';
        }
        do
        {
            system("cls");
            drawtictactoo(T);
            cout<<"Player "<<j<<" : "<<endl;
            cout<<"Entrer place : ";
            cin>>n;
            k=ctoi(n);
        }
        while(k<0 || k>9 || isExiste(k)==1);
        T[k-1]=c;
        A[indexT]=k;
        indexT++;
        i++;
        n++;
        do
        {
            system("cls");
            if(T[0]==T[1] && T[1]==T[2] || T[3]==T[5] && T[5]==T[4] || T[7]==T[8] && T[8]==T[6] ||T[4]==T[1] && T[1]==T[7] ||T[5]==T[8] && T[5]==T[2] || T[3]==T[6] && T[6]==T[0] || T[0]==T[4] && T[4]==T[8] || T[4]==T[2] && T[6]==T[2])
            {
                drawtictactoo(T);
                cout<<"\n Winner "<<endl;
                char a='1';
                for(int j=0; j<9; j++)
                {
                    T[j]=a;
                    a++;
                }
                cout<<"Enter * pour repeter : ";
                cin>>c;
                break;
            }
            else if(n==9)
            {
                cout<<"Draw "<<endl;
                char a='1';
                for(int j=0; j<9; j++)
                {
                    T[j]=a;
                    a++;
                }
                cout<<"Enter * pour repeter : ";
                cin>>c;
            }
        }
        while(c=='*');
        if(c=='*')
        {
            int m=0;
            for(int t=100; t<109; t++)
            {
                A[m]=t;
                m++;
            }
            Empilement();
        }
    }
}
int main()
{
    Empilement();
    return 0;
}
