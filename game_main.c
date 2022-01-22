#include <stdio.h>
#include <string.h>


# include "board.h"
# include "game_main.h"


int game_main() {

	while(1){
		static	int turn = FIRST_TURN;		/* 1:先行 、 2:後攻  */
				int set = 0;				/* 0:初期値、1:先行の値 、 2:後攻の値 */
				int i = 0;					/* 盤面の行(セット用) 0～2 */
				int j = 0;					/* 盤面の列(セット用) 0～2 */
				int error_flg = 0;			/* エラー判定 */
				int game_end_flg = 0;		/* ゲーム継続判定判定 0:継続、-1:終了*/
				int board[3][3]	= 0;		/* 盤面情報　0:空白、1:先行、2:後攻*/	
				int row = 0;				/* 行 */
				int col = 0;				/* 列 */
				int draw_count = 0;			/* 0:初期値、9:ゲーム終了（引き分け）*/
				
		if(draw_count == 9){
			return RESULT_DRAW;
		}

		/* プレイヤー操作 */
		if (turn == FIRST_TURN) {
			printf("先行の番です。\n");
			printf("行の値を入力してください\n");
			scanf("%d",&i);
			printf("列の値を入力してください\n");
			scanf("%d",&j);
		}
		else{
			printf("後攻の番です。\n");
			printf("行の値を入力してください\n");
			scanf("%d", &i);
			printf("列の値を入力してください\n");
			scanf("%d", &j);
		}

		/* 入力値の判定 */
		if((i < 0 || 2 < i)
		||	(j < 0 || 2 < j)){
			return  (ERROR);
		}

		/* ゲーム継続（エラー）の判定 */
		game_end_flg = show_Board(i, j);
		if (game_end_flg == ERROR) {
			return (ERROR);				/* ゲームの終了 */
		}


		/* セット */
		set_Board(i, j, turn);

		/* 勝敗の判定(値のセット) */
		for(row = 0;row <= 2;row++){
			for(col = 0;col <= 2;col++){
				board[row][col]	= get_Board(row, col);	/* 現在のマス目情報取得*/
			}	
		}

		/*　勝敗の判定(8パターンから判定) */
		if(board[0][0] != 0){
			if(((board[0][0] == board[0][1]) && (board[0][0] == board[0][2]))		/* 一行目（横）がそろっているか？ */
			|| ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))		/* 右下がり（斜め）がそろっているか？ */
			|| ((board[0][0] == board[1][0]) && (board[0][0] == board[2][0])))	/* 一列目（縦）がそろっているか？ */
			{	
				game_end_flg = 1;
			}
		}

		if(board[0][1] != 0){
			if((board[0][1] == board[1][1]) && (board[0][1] == board[2][1]))		/* 二列目（縦）がそろっているか？ */
			{	
				game_end_flg = 1;
			}
		}

		if(board[0][2] != 0){
			if((board[0][2] == board[1][1]) && (board[0][0] == board[2][0]))		/* 左下がり（斜め）がそろっているか？ */
			||((board[0][2] == board[1][2]) && (board[0][2] == board[2][2])))	/* 三列目（縦）がそろっているか？ */
			{	
				game_end_flg = 1;
			}
		}

		if(board[1][0] != 0){
			if((board[1][0] == board[1][1]) && (board[1][0] == board[1][2]))		/* 二行目（横）がそろっているか？ */
			{
				game_end_flg = 1;
			}
		}

		if(board[2][0] != 0){
			if((board[2][0] == board[2][1]) && (board[2][0] == board[2][2]))		/* 三行目（横）がそろっているか？ */
			{
				game_end_flg = 1;
			}
		}

		/* 勝者が決まる時 */
		if(game_end_flg == 1){
			if(turn == FIRST_TURN){
				return FIRST_TURN;
			}
			else{
				return SECOND_TURN;
			}
		}

		/* プレイヤーの交代 */
		if (turn == FIRST_TURN) {
			turn == SECOND_TURN;
		}
		else{
			turn == FIRST_TURN;
		}

		/* 操作数のカウント */
		draw_count++;
	}
}