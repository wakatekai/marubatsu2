#define EMPTY       0
#define FIRST_TURN  1
#define SECOND_TURN 2

#define ERROR         -1
#define RESULT_DRAW    0
#define RESULT_FIRST   1
#define RESULT_SECOND  2

#define LENGTH  3

int game_main();
int player_set(int turn);
int game_judge(int turn);
