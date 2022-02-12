/* 盤面の大きさ */
#define BOARD_ROW   (3)  /* 縦 */
#define BOARD_COL   (3)  /* 横 */

#define BOARD_EMPTY (0)  /* 空き */

enum en_status {
    STATUS_INIT = 0,     /* ステータス：初期値 */
    STATUS_OK,           /* ステータス：正常 */
    STATUS_CONTINUE,     /* ステータス：継続 */
    STATUS_ERROR = -1    /* ステータス：異常 */
};

/* プロトタイプ宣言 */
void clear_Board(int row, int col);
int set_Board(int row, int col, int num);
int get_Board(int row, int col);
int show_Board(int row, int col);