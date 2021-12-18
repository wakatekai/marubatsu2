#include <stdio.h>
#define BOARD_ROW (3)
#define BOARD_COL (3)
#define BOARD_SET_INIT (0)
#define BOARD_SET_OK (1)
#define BOARD_SET_NG (-1)

int board[3][3];

void clear_Board(int row, int col) {
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            board[i][j] = 0;
        }
    }
    return;
}

int set_Board(int row, int col, int num) {
    int status = BOARD_SET_INIT;

    if (row > BOARD_ROW || col > BOARD_COL) {
        status = BOARD_SET_NG;
    } else {
        status = BOARD_SET_OK;
        board[row][col] = num;
    }

    return status;
}

int get_Board(int row, int col) {
    int status = BOARD_SET_INIT;
    int return_val = 0;

    if (row > BOARD_ROW || col > BOARD_COL) {
        return_val = BOARD_SET_NG;
    } else {
        return_val = board[row][col];
    }

    return board[row][col];
}

void show_Board(int row, int col) {
    int i = 0;
    int j = 0;

    printf(" ");
    for (j = 0; j < col; j++) {
        printf(" %d", j);
    }
    printf("\n");
    for (i = 0; i < row; i++) {
        printf("%c", i + 65);
        for (j = 0; j < col; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }

    return;
}

/* Debug */
int main(void) {
    int set_status;
    int get_status;

    clear_Board(BOARD_ROW, BOARD_COL);
    set_status = set_Board(3, 2, 1);
    printf("set_Boardのreturn %d\n", set_status);
    get_status = get_Board(3, 2);
    show_Board(BOARD_ROW, BOARD_COL);

    return;
}
