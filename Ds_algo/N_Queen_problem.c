#include <stdio.h>


int solveNQueen(int q_array[4][4], int col , int max_col);
int possible_solution(int q_array[4][4], int r, int col);

void print(int q_array[4][4], int r, int c) {

    printf("array values for row:%d column:%d \n", r, c);

     // Print solution.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", q_array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("N Queen problem.!! \n");
    int q_array[4][4] = {0};

    solveNQueen(q_array, 0/*column first index*/, 4 /*max coulmn*/);
   
    print(q_array, 0, 0);
    return 0;
}

int solveNQueen(int q_array[4][4], int row , int max)
{
    int c;

    if(row >= max)
        return 1;

    for (c = 0; c < max; c++)
    {
        if(possible_solution(q_array, row, c))
        {
            q_array[row][c] = 1;
           
            if (solveNQueen(q_array, row+1 /*check for next queen position*/, max))
                return 1;

            // clear previous value.
            q_array[row][c] = 0;
        }
    }
    return 0;
}

int possible_solution(int q_array[4][4], int r, int col)
{
    // check across fix row and variable column.
    for(int c = 0; c < 4; c++)
    {
        if(q_array[r][c])
            return 0;
    }

    // check across variable row and fix column.
    for(int ro=0; ro <4; ro++)
    {
        if(q_array[ro][col])
            return 0;
    }

    //check across left diagonal downward
    for(int ro =r, c=col; ro < 4 && c >= 0; ro++, c--)
    {
        if(q_array[ro][c])
            return 0;
    }

    // check across left diagonal upward
    for(int ro =r, c=col; ro >=0 && c >= 0; ro--, c--)
    {
        if(q_array[ro][c])
            return 0;
    }

    //check across right diagonal upward
    for(int ro =r, c=col; ro > 4 && c < 4; ro--, c++)
    {
        if(q_array[ro][c])
            return 0;
    }

    //check across right diagonal downward
    for(int ro =r, c=col; ro < 4 && c < 4; ro++, c++)
    {
        if(q_array[ro][c])
            return 0;
    }

    return 1;
}