// https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#define N 8


bool isValid(int i, int j, int sol[N][N]){
    return (i>=0 && j>=0 && i<N && j<N && sol[i][j]==-1);
}

int solveKTUtil(int x, int y, int val, int sol[][], int xMove[], int yMove[]){
    if(val==N*N){
        return 1;
    }


    int next_x, next_y;
    for(int i=0;i<8;i++){
        next_x = x + xMove[i];
        next_y = y + yMove[i];
        if(isValid(next_x, next_y, sol)){
            sol[next_x][next_y]=val;
            if(solveKTUtil(next_x, next_y, val+1, sol, xMove, yMove)==1){
                return 1;
            }else{
                sol[next_x][next_y]=-1;
            }
        }
    }
    return 0;
}

void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

int solveKnightTour(int sol[][]){
    // initially none is visited
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sol[i][j]=-1;
        }
    }

    // knight starts from 0,0
    sol[0][0]=1;


    int xMove[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int yMove[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    if(solveKTUtil(0, 0, 1, sol, xMove, yMove)==0){
        return false;
    }else{
        printSolution(sol);
    }
}


int knightTour(){
    int sol[N][N];
    solveKnightTour(sol);
    return sol;
}