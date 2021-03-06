/* 盤面操作処理ファイル */
#include <stdio.h>
#include "board.h"

/* #define DEBUG_BOARD_C */

static int board[BOARD_ROW][BOARD_COL];

/* 盤面初期化関数 */
void clear_Board(int row, int col) {
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            board[i][j] = BOARD_EMPTY;
        }
    }
    return;
}

/* 盤面設定関数 */
int set_Board(int row, int col, int num) {
    int status = STATUS_INIT;
    /* 盤面の大きさを超えた入力は異常と判定 */
    if (row >= BOARD_ROW || col >= BOARD_COL) {
        status = STATUS_ERROR;
    } else {
        /* 盤面が空いている時のみ設定できる */
        if(board[row][col] == BOARD_EMPTY){
            board[row][col] = num;
            status = STATUS_OK;
        }else{
            status = STATUS_CONTINUE;
        }
    }

    return status;
}

/* 盤面取得関数 */
int get_Board(int row, int col) {
    int return_val = STATUS_INIT;
    /* 盤面の大きさを超えた入力は異常と判定 */
    if (row > BOARD_ROW || col > BOARD_COL) {
        return_val = STATUS_ERROR;
    } else {
        return_val = board[row][col];
    }

    return return_val;
}

/* 盤面表示関数 */
int show_Board(int row, int col) {
    int i = 0;
    int j = 0;
    char ch = 0;
    int status = STATUS_INIT;

    printf(" ");
    /* 横軸の数字表示 */
    for (j = 0; j < col; j++) {
        printf(" %d", j);
    }
    printf("\n");

    for (i = 0; i < row; i++) {
        /* 縦軸の数字表示 */
        printf("%d", i);
        for (j = 0; j < col; j++) {
            ch = board[i][j];
            switch (ch) {
                case 0:
                    printf(" -");
                    status = STATUS_OK;
                    break;
                case 1:
                    printf(" ■");
                    status = STATUS_OK;
                    break;
                case 2:
                    printf(" □");
                    status = STATUS_OK;
                    break;
                default:
                    /*  */
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
