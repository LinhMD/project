#include <stdio.h>
#include <stdlib.h>
int grid[9][9] = {  {5, 3, 0, 0, 7, 0, 0, 0, 0},
                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9} };
int grid2[9][9];
int t = 0;
int m;

void printGrid();
int isPossible(int y, int x, int n);
int solve();
int isSolve();
void copyGrid();

int main(){
    solve();
    printGrid();
//    for (int y = 0; y < 9; y++){
//        for (int x = 0; x < 9; x++){
//            printf("%4d", grid2[y][x]);
//        }
//        printf("\n");
//    }
//    return 0;
}

void printGrid(){
    for (int y = 0; y < 9; y++){
        for (int x = 0; x < 9; x++){
            printf("%4d", grid[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}
int isPossible(int y, int x, int n){
    if(n == 0)
        return 0;
    for (int i = 0; i < 9; i++) // check hang doc
        if (grid[y][i] == n)
            return 0;
    for (int i = 0; i < 9; i++) // check hang ngang
        if (grid[i][x] == n)
            return 0;
    int b = y / 3;
    int a = x / 3;
    a = a * 3;
    b = b * 3;
    for (int i = b; i < b + 3; i++) //check box
        for (int j = a; j < a + 3; j++)
            if (!(i == y && j == x))
                if (grid[i][j] == n)
                    return 0;
    return 1;
}
int solve(){
    for (int y = 0; y < 9; y++)
        for (int x = 0; x < 9; x++)
            if (grid[y][x] == 0){
                for (int n = 1; n < 10; n++)
                    if(isPossible(y, x, n)){
                        grid[y][x] = n;
//                        printf("try to solve %d:\n", t);
                        t++;
                        //printGrid();
                        if (isSolve() == 1){
                            copyGrid();
                            printGrid();
                            getchar();
                        }else{
                            solve();
                            grid[y][x] = 0;
                        }
                    }
                return 0;
            }
    return 3;
}
int isSolve(){
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j] == 0)
                return 0;
    return 1;
}
void copyGrid(){
    for (int y = 0; y < 9; y++)
        for (int x = 0; x < 9; x++)
            grid2[y][x] = grid[y][x];
}
