#include "board.h"

#include <stdio.h>

/* #define DEBUG_BOARD_C */
#define BOARD_ROW (3)
#define BOARD_COL (3)

int board[BOARD_ROW][BOARD_COL];

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
    int status = STATUS_INIT;

    if (row >= BOARD_ROW || col >= BOARD_COL) {
        status = STATUS_ERROR;
    } else {
        status = STATUS_OK;
        board[row][col] = num;
    }

    return status;
}

int get_Board(int row, int col) {
    int status = STATUS_INIT;
    int return_val = 0;

    if (row > BOARD_ROW || col > BOARD_COL) {
        return_val = STATUS_ERROR;
    } else {
        return_val = board[row][col];
    }

    return return_val;
}

int show_Board(int row, int col) {
    int i = 0;
    int j = 0;
    char ch = 0;
    int status = STATUS_INIT;

    printf(" ");
    for (j = 0; j < col; j++) {
        printf(" %d", j);
    }
    printf("\n");
    for (i = 0; i < row; i++) {
        printf("%c", i + 65);
        for (j = 0; j < col; j++) {
            ch = board[i][j];
            switch (ch) {
                case 0:
                    printf(" -");
                    break;
                case 1:
                    printf(" ¡");
                    break;
                case 2:
                    printf("  ");
                    break;
                default:
                    status = STATUS_ERROR;
                    break;
            }
        }
        printf("\n");
    }

    return status;
}

/* Debug */
#ifdef DEBUG_BOARD_C
int main(void) {
    int set_status;
    int get_status;
    int show_status;

    clear_Board(BOARD_ROW, BOARD_COL);
    set_status = set_Board(2, 2, 1);
    get_status = get_Board(3, 2);
    show_status = show_Board(BOARD_ROW, BOARD_COL);

    return;
}
#endif
