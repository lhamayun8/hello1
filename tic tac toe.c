#include <stdio.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void printBoard() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;  // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;  // Column win
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;  // Diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;  // Diagonal win

    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;  // Game still ongoing
        }
    }

    return -1;  // Tie
}

int main() {
    int player = 1;  // Player 1 starts
    int row, col, move;

    do {
        printBoard();
        player = (player % 2) ? 1 : 2;  // Determine current player

        printf("Player %d, enter your move (row and column): ", player);
        scanf("%d", &move);

        row = move / 3;
        col = move % 3;

        // Check if the move is valid
        if (board[row][col] == ' ') {
            board[row][col] = (player == 1) ? 'X' : 'O';
            player++;
        } else {
            printf("Invalid move. Try again.\n");
        }
    } while (checkWin() == 0);

    printBoard();

    if (checkWin() == -1)
        printf("It's a tie!\n");
    else
        printf("Player %d wins!\n", (player % 2) ? 1 : 2);

    return 0;
}
