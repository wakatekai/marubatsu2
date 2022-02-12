#define BOARD_ROW (3)
#define BOARD_COL (3)

enum en_status {
    STATUS_INIT = 0,
    STATUS_OK,
    STATUS_CONTINUE,
    STATUS_ERROR = -1
};

void clear_Board(int row, int col);
int set_Board(int row, int col, int num);
int get_Board(int row, int col);
int show_Board(int row, int col);