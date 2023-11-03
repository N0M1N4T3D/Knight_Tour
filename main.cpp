#include <iostream>
#define N 10

int main() {
    int chessboard[N][N], allsteps[8], horsesteps[8][2];
    int x0, y0, count = 1, secondcount = 0;
    bool attention = 1;
    std::cout << "Enter x0 and y0 separated by space: ";
    std::cin >> x0 >> y0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            chessboard[i][j] = 0;
        }
    }
    chessboard[x0][y0] = 1;
    horsesteps[0][0] = -1; horsesteps[0][1] = 2;
    horsesteps[1][0] = 1;  horsesteps[1][1] = 2;
    horsesteps[2][0] = 2;  horsesteps[2][1] = 1;
    horsesteps[3][0] = -2; horsesteps[3][1] = 1;
    horsesteps[4][0] = 2;  horsesteps[4][1] = -1;
    horsesteps[5][0] = -2; horsesteps[5][1] = -1;
    horsesteps[6][0] = 1;  horsesteps[6][1] = -2;
    horsesteps[7][0] = -1; horsesteps[7][1] = -2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            chessboard[i][j] = 0;
        }
    }
    chessboard[x0][y0] = count;
    while (true) {
        for (int i = 0; i < 8; i++) {
            if (x0 + horsesteps[i][0] < 0 || x0 + horsesteps[i][0] >= N || y0 + horsesteps[i][1] < 0 ||
                y0 + horsesteps[i][1] >= N || chessboard[x0 + horsesteps[i][0]][y0 + horsesteps[i][1]] != 0) {
                allsteps[i] = -1;
            } else {
                for (int j = 0; j < 8; j++) {
                    int xn = x0 + horsesteps[i][0] + horsesteps[j][0];
                    int yn = y0 + horsesteps[i][1] + horsesteps[j][1];
                    if (xn >= 0 && xn < N && yn >= 0 && yn < N && chessboard[xn][yn] == 0) {
                        secondcount++;
                    }
                }
                allsteps[i] = secondcount;
                secondcount = 0;
            }
        }
        int savecoef = 0;
        for (int i = 0; i < 8; i++) {
            if (allsteps[i] > 0 && attention == 1) {
                attention = 0;
                savecoef = i;
            }
            if (allsteps[i] < allsteps[savecoef] && allsteps[i] > 0 && attention != 1) {
                savecoef = i;
            }
        }
        if (attention == 1) {
            for (int i = 0; i < 8; i++) {
                if (allsteps[i] == 0) {
                    chessboard[x0 + horsesteps[i][0]][y0 + horsesteps[i][1]] = ++count;
                }
            }
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    std::cout << chessboard[i][j] << "\t";
                }
                std::cout << "\n";
            }
            return 0;
        } else {
            x0 += horsesteps[savecoef][0];
            y0 += horsesteps[savecoef][1];
            chessboard[x0][y0] = ++count;
            attention = 1;
        }
    }
}