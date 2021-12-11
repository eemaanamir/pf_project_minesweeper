#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
#include <time.h>



void print_array(char arr[][10], int rows, int select_i, int select_j);
int plant_bombs(char arr[][10], int rows);
bool bomb_status(char arr[][10], int i, int j);
void number_tiles(char arr[][10], int rows);
void initial_look(char arr[][10], int rows);
void print_menu();
void mv_up(int &i, int &j);
void mv_down(int &i, int &j, int type);
void mv_left(int &i, int &j);
void mv_right(int &i, int &j, int type);
bool is_valid(int i, int j, int type);
bool open(char f[][10],char b[][10], int i, int j);

void print_array2(char arr[][20], int rows, int select_i, int select_j);
int plant_bombs2(char arr[][20], int rows);
bool bomb_status2(char arr[][20], int i, int j);
void number_tiles2(char arr[][20], int rows);
void initial_look2(char arr[][20], int rows);
bool open2(char f[][20],char b[][20], int i, int j);


int main()
{
    int f=0;
    int flags=0;
    char input;
    int select_ii=0;
    int select_jj=0;
    char front_grid[10][10]; //front grid the one shown to user
    char back_grid[10][10]; //back grid containing all info
    char front_grid2[20][20]; //for 20x20
    char back_grid2[20][20];
    int type;
    cout<<"CHOOSE YOUR GRID SIZE BY ENTERING OPTION NUMBER\n1. 10x10\n2. 20x20\n\n";
    cin>>type;
    if(type==1)
    {
        int bombs = plant_bombs(back_grid, 10);
        number_tiles(back_grid, 10);
        initial_look(front_grid, 10);
        cout << "\nbombs:" << bombs - flags << endl << endl;
        print_array(front_grid, 10, select_ii, select_jj);
        print_menu();


        while (flags<bombs && f != 1) {
            cin >> input;
            if (input == 'f')
            {
                if (front_grid[select_ii][select_jj] != 'F')
                {
                    front_grid[select_ii][select_jj] = 'F';
                    flags++;
                }
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array(front_grid, 10, select_ii, select_jj);
                print_menu();
                if (back_grid[select_ii][select_jj] != 'B')
                    f = 2;
            }
            if (input == 'w')
            {
                mv_up(select_ii, select_jj);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array(front_grid, 10, select_ii, select_jj);
                print_menu();
            }
            if (input == 's')
            {
                mv_down(select_ii, select_jj, type);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array(front_grid, 10, select_ii, select_jj);
                print_menu();
            }
            if (input == 'a')
            {
                mv_left(select_ii, select_jj);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array(front_grid, 10, select_ii, select_jj);
                print_menu();
            }
            if (input == 'd')
            {
                mv_right(select_ii, select_jj, type);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array(front_grid, 10, select_ii, select_jj);
                print_menu();
            }
            if (input == 'o') {
                f = open(front_grid, back_grid, select_ii, select_jj);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array(front_grid, 10, select_ii, select_jj);
                print_menu();
            }
        }
        if (f == 1 || f == 2) {
            cout << "\nbombs:" << bombs - flags << endl << endl;
            print_array(back_grid, 10, select_ii, select_jj);
            cout << "\n\nGAME OVER YOU LOST!\n";
        } else if (f == 0) {
            cout << "\n\nYOU WIN!!!\n";
        }
    }
    else if(type==2)
    {
        int bombs = plant_bombs2(back_grid2, 20);
        number_tiles2(back_grid2, 20);
        initial_look2(front_grid2, 20);
        cout << "\nbombs:" << bombs - flags << endl << endl;
        print_array2(front_grid2, 20, select_ii, select_jj);
        print_menu();


        while (flags<bombs && f != 1) {
            cin >> input;
            if (input == 'f')
            {
                if (front_grid2[select_ii][select_jj] != 'F')
                {
                    front_grid2[select_ii][select_jj] = 'F';
                    flags++;
                }
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array2(front_grid2, 20, select_ii, select_jj);
                print_menu();
                if (back_grid2[select_ii][select_jj] != 'B')
                    f = 2;
            }
            if (input == 'w')
            {
                mv_up(select_ii, select_jj);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array2(front_grid2, 20, select_ii, select_jj);
                print_menu();
            }
            if (input == 's')
            {
                mv_down(select_ii, select_jj, type);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array2(front_grid2, 20, select_ii, select_jj);
                print_menu();
            }
            if (input == 'a')
            {
                mv_left(select_ii, select_jj);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array2(front_grid2, 20, select_ii, select_jj);
                print_menu();
            }
            if (input == 'd')
            {
                mv_right(select_ii, select_jj, type);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array2(front_grid2, 20, select_ii, select_jj);
                print_menu();
            }
            if (input == 'o')
            {
                f = open2(front_grid2, back_grid2, select_ii, select_jj);
                cout << "\nbombs:" << bombs - flags << endl << endl;
                print_array2(front_grid2, 20, select_ii, select_jj);
                print_menu();
            }
        }
        if (f == 1 || f == 2)
        {
            cout << "\nbombs:" << bombs - flags << endl << endl;
            print_array2(back_grid2, 20, select_ii, select_jj);
            cout << "\n\nGAME OVER YOU LOST!\n";
        }
        else if (f == 0)
        {
            cout << "\n\nYOU WIN!!!\n";
        }

    }

   return 0;
}






bool is_valid(int i, int j, int type)
{
    if(type==1)
    {
        if (i > -1 && i < 10 && j < 10 && j > -1)
            return true;
    }
    else if(type==2)
    {
        if (i > -1 && i < 20 && j < 20 && j > -1)
            return true;
    }
    return false;
}
void mv_right(int &i, int &j, int type)
{
    if(type==1)
        j=min(j+1,9);
    else if(type==2)
        j=min(j+1,19);
}
void mv_left(int &i, int &j)
{
    j=max(j-1,0);
}
void mv_down(int &i, int &j,int type)
{
    if(type==1)
        i=min(i+1,9);
    else if(type==2)
        i=min(i+1,19);
}
void mv_up(int &i, int &j)
{
    i=max(i-1,0);
}
void print_menu()
{
    cout<<"\nUse W to move up\nPress S to move down\nPress A to move left\nPress D to move right\nPress letter O to open\nPress letter F to plant a flag\n";
}
void initial_look(char arr[][10], int rows)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<10; j++)
        {
            arr[i][j]='*';
        }
    }
}
bool bomb_status(char arr[][10], int i, int j)
{
    if(i<10 && i>-1 && j<10 && j>-1 && arr[i][j]=='B')
        return true;
    else
        return false;
}
void number_tiles(char arr[][10], int rows)
{
    char count;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<10; j++)
        {
            count=48;
            if(arr[i][j]!= 'B')
            {
                count=count+bomb_status(arr,i-1,j-1);
                count=count+bomb_status(arr,i-1,j);
                count=count+bomb_status(arr,i-1,j+1);
                count=count+bomb_status(arr,i,j-1);
                count=count+bomb_status(arr,i,j+1);
                count=count+bomb_status(arr,i+1,j-1);
                count=count+bomb_status(arr,i+1,j);
                count=count+bomb_status(arr,i+1,j+1);
                arr[i][j]=count;
            }

        }
    }
}
int plant_bombs(char arr[][10], int rows)
{
    srand(time(0));
    int i;
    int j;
    int bomb_no=rand()%11+10;
    int planted=0;
    while(planted<bomb_no)
    {
        i=rand()%10;
        j=rand()%rows;
        if(arr[i][j]!='B')
        {
            arr[i][j] = 'B';
            planted++;
        }
    }
    return bomb_no;
}
void print_array(char arr[][10], int rows, int select_i, int select_j)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(i==select_i && j==select_j)
                cout<<"|"<<arr[i][j]<<"|"<<" ";
            else if(j==select_j)
                cout<<" "<<arr[i][j]<<"  ";
            else
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool open(char f[][10],char b[][10], int i, int j)
{
    int is[100]={i};
    int js[100]={j};
    int reps=1;
    for(int k=0; k<reps; k++)
    {
        i=is[k];
        j=js[k];
        if (b[i][j] == 'B' && k==0)
        {
            f[i][j] = b[i][j];
            return true;
        }
        else if (b[i][j] != 48 && k==0)
        {

            f[i][j] = b[i][j];
            return false;
        }
        else if (b[i][j]==48)
        {
            f[i][j] = b[i][j];
            if (is_valid(i-1, j-1,1) && f[i - 1][j - 1] == '*')
            {
                f[i - 1][j - 1] = b[i - 1][j - 1];
                if(b[i-1][j-1]==48)
                {
                    is[reps]=i-1;
                    js[reps]=j-1;
                    reps++;
                }
            }
            if (is_valid(i-1, j,1) && f[i - 1][j] == '*')
            {
                f[i - 1][j] = b[i - 1][j];
                if(b[i-1][j]==48)
                {
                    is[reps]=i-1;
                    js[reps]=j;
                    reps++;
                }
            }
            if (is_valid(i-1, j+1,1) && f[i - 1][j + 1] == '*')
            {
                f[i - 1][j + 1] = b[i - 1][j + 1];
                if(b[i-1][j+1]==48)
                {
                    is[reps]=i-1;
                    js[reps]=j+1;
                    reps++;
                }
            }
            if (is_valid(i, j-1,1) && f[i][j - 1] == '*')
            {
                f[i][j - 1] = b[i][j - 1];
                if(b[i][j-1]==48)
                {
                    is[reps]=i;
                    js[reps]=j-1;
                    reps++;
                }
            }
            if (is_valid(i, j+1,1) && f[i][j + 1] == '*')
            {
                f[i][j + 1] = b[i][j + 1];
                if(b[i][j+1]==48)
                {
                    is[reps]=i;
                    js[reps]=j+1;
                    reps++;
                }
            }
            if (is_valid(i+1, j-1,1) && f[i + 1][j - 1] == '*') {
                f[i + 1][j - 1] = b[i + 1][j - 1];
                if(b[i+1][j-1]==48)
                {
                    is[reps]=i+1;
                    js[reps]=j-1;
                    reps++;
                }
            }
            if (is_valid(i+1, j,1) && f[i + 1][j] == '*')
            {
                f[i + 1][j] = b[i + 1][j];
                if(b[i+1][j]==48)
                {
                    is[reps]=i+1;
                    js[reps]=j;
                    reps++;
                }
            }
            if (is_valid(i+1, j+1,1) && f[i + 1][j + 1] == '*')
            {
                f[i + 1][j + 1] = b[i + 1][j + 1];
                if(b[i+1][j+1]==48)
                {
                    is[reps]=i+1;
                    js[reps]=j+1;
                    reps++;
                }
            }
        }
    }
    return false;
}



void initial_look2(char arr[][20], int rows)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<20; j++)
        {
            arr[i][j]='*';
        }
    }
}
bool bomb_status2(char arr[][20], int i, int j)
{
    if(i<10 && i>-1 && j<10 && j>-1 && arr[i][j]=='B')
        return true;
    else
        return false;
}
void number_tiles2(char arr[][20], int rows)
{
    char count;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<20; j++)
        {
            count=48;
            if(arr[i][j]!= 'B')
            {
                count=count+bomb_status2(arr,i-1,j-1);
                count=count+bomb_status2(arr,i-1,j);
                count=count+bomb_status2(arr,i-1,j+1);
                count=count+bomb_status2(arr,i,j-1);
                count=count+bomb_status2(arr,i,j+1);
                count=count+bomb_status2(arr,i+1,j-1);
                count=count+bomb_status2(arr,i+1,j);
                count=count+bomb_status2(arr,i+1,j+1);
                arr[i][j]=count;
            }

        }
    }
}
int plant_bombs2(char arr[][20], int rows)
{
    srand(time(0));
    int i;
    int j;
    int bomb_no=rand()%11+20;
    int planted=0;
    while(planted<bomb_no)
    {
        i=rand()%20;
        j=rand()%rows;
        if(arr[i][j]!='B')
        {
            arr[i][j] = 'B';
            planted++;
        }
    }
    return bomb_no;
}
void print_array2(char arr[][20], int rows, int select_i, int select_j)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(i==select_i && j==select_j)
                cout<<"|"<<arr[i][j]<<"|"<<" ";
            else if(j==select_j)
                cout<<" "<<arr[i][j]<<"  ";
            else
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool open2(char f[][20],char b[][20], int i, int j)
{
    int is[100]={i};
    int js[100]={j};
    int reps=1;
    for(int k=0; k<reps; k++)
    {
        i=is[k];
        j=js[k];
        if (b[i][j] == 'B' && k==0)
        {
            f[i][j] = b[i][j];
            return true;
        }
        else if (b[i][j] != 48 && k==0)
        {

            f[i][j] = b[i][j];
            return false;
        }
        else if (b[i][j]==48)
        {
            f[i][j] = b[i][j];
            if (is_valid(i-1, j-1,2) && f[i - 1][j - 1] == '*')
            {
                f[i - 1][j - 1] = b[i - 1][j - 1];
                if(b[i-1][j-1]==48)
                {
                    is[reps]=i-1;
                    js[reps]=j-1;
                    reps++;
                }
            }
            if (is_valid(i-1, j,2) && f[i - 1][j] == '*')
            {
                f[i - 1][j] = b[i - 1][j];
                if(b[i-1][j]==48)
                {
                    is[reps]=i-1;
                    js[reps]=j;
                    reps++;
                }
            }
            if (is_valid(i-1, j+1,2) && f[i - 1][j + 1] == '*')
            {
                f[i - 1][j + 1] = b[i - 1][j + 1];
                if(b[i-1][j+1]==48)
                {
                    is[reps]=i-1;
                    js[reps]=j+1;
                    reps++;
                }
            }
            if (is_valid(i, j-1,2) && f[i][j - 1] == '*')
            {
                f[i][j - 1] = b[i][j - 1];
                if(b[i][j-1]==48)
                {
                    is[reps]=i;
                    js[reps]=j-1;
                    reps++;
                }
            }
            if (is_valid(i, j+1,2) && f[i][j + 1] == '*')
            {
                f[i][j + 1] = b[i][j + 1];
                if(b[i][j+1]==48)
                {
                    is[reps]=i;
                    js[reps]=j+1;
                    reps++;
                }
            }
            if (is_valid(i+1, j-1,2) && f[i + 1][j - 1] == '*') {
                f[i + 1][j - 1] = b[i + 1][j - 1];
                if(b[i+1][j-1]==48)
                {
                    is[reps]=i+1;
                    js[reps]=j-1;
                    reps++;
                }
            }
            if (is_valid(i+1, j,2) && f[i + 1][j] == '*')
            {
                f[i + 1][j] = b[i + 1][j];
                if(b[i+1][j]==48)
                {
                    is[reps]=i+1;
                    js[reps]=j;
                    reps++;
                }
            }
            if (is_valid(i+1, j+1,2) && f[i + 1][j + 1] == '*')
            {
                f[i + 1][j + 1] = b[i + 1][j + 1];
                if(b[i+1][j+1]==48)
                {
                    is[reps]=i+1;
                    js[reps]=j+1;
                    reps++;
                }
            }
        }
    }
    return false;
}