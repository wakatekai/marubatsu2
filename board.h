#define BOARD_ROW (3)
#define BOARD_COL (3)

#define STATUS_INIT (0)
#define STATUS_OK (1)
#define STATUS_ERROR (-1)

void clear_Board(int row, int col);
int set_Board(int row, int col, int num);
int get_Board(int row, int col);
int show_Board(int row, int col);