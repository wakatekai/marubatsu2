#include <stdio.h>
#include <string.h>

#include "board.h"
#include "game_main.h"

int game_main() {
	int turn = FIRST_TURN;				/* 1:先行 、 2:後攻  */
	int draw_count = 0;					/* 0:初期値、9:ゲーム終了（引き分け）*/
	int return_value = 0;
	clear_Board(LENGTH, LENGTH);
	
	while(1){
//				int game_end_flg = 0;		/* ゲーム継続判定判定 0:継続、-1:終了*/
		
		/* 盤面へのセット */
		if(player_set(turn) == ERROR){
			return_value = ERROR;
			break;
		}

		/* 盤面の判定 */
		if(game_judge(turn) == FIRST_TURN){
			return_value = FIRST_TURN;
			break;
		}
		else if(game_judge(turn) == SECOND_TURN){
			return_value = SECOND_TURN;
			break;
		}
		
		/* プレイヤーの交代 */
		if (turn == FIRST_TURN) {
			turn = SECOND_TURN;
		}
		else{
			turn = FIRST_TURN;
		}
		
		/* 盤面の表示 */
		if(show_Board(LENGTH, LENGTH) == STATUS_ERROR){	/* 正しくセットできなかった時？ */
			return_value = (ERROR);
			break;
		}

		/* 操作数のカウント */
		draw_count++;
	}
	return return_value;
}

int player_set(int turn){
	
	int i = 0;					/* 盤面の行(セット用) 0～2 */
	int j = 0;					/* 盤面の列(セット用) 0～2 */

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
	if((i < 0 || LENGTH - 1 < i)
	||	(j < 0 || LENGTH - 1 < j)){
		return  (ERROR);
	}
	else{
		if(set_Board(i, j, turn) == STATUS_ERROR){	/* 正しくセットできなかった時？ */
			return  (ERROR);
		}
	}
	return 0;
}

int game_judge(int turn){

	int row = 0;				/* 行（判定用） */
	int col = 0;				/* 列（判定用） */
	int target_cell =0;
	int cell_count =0;

	/* 勝敗の判定 */
	/* 横の判定 */
	for(row = 0;row < LENGTH;row++){
		target_cell = get_Board(row,0);
		cell_count = 0;
		for(col = 1;col < LENGTH;col++){
			if((get_Board(row,col) == target_cell)		/* セルの値が一致 */
			&& (target_cell != 0)){						/* セルの値が0(初期値)以外 */
				cell_count++;
				if(cell_count == LENGTH - 1){			/* 3マス一致した時 */
					if(turn == FIRST_TURN){
						return FIRST_TURN;				/* 先行の勝利 */
					}
					else{
						return SECOND_TURN;				/* 後攻の勝利 */
					}						
				}
			}
		}
	}

	/* 縦の判定 */
	for(col = 0;col < LENGTH;col++){
		target_cell = get_Board(0,col);
		cell_count = 0;
		for(row = 1;row < LENGTH;row++){
			if((get_Board(row,col) == target_cell)		/* セルの値が一致 */
			&& (target_cell != 0)){						/* セルの値が0(初期値)以外 */
				cell_count++;
				if(cell_count == LENGTH - 1){			/* 3マス一致した時 */
					if(turn == FIRST_TURN){
						return FIRST_TURN;				/* 先行の勝利 */
					}
					else{
						return SECOND_TURN;				/* 後攻の勝利 */
					}						
				}
			}
		}
	}
		
	/* 斜め（右下がり）の判定 */
	target_cell = get_Board(0,0);
	cell_count = 0;
	col = 1;
	for(row = 1;row < LENGTH;row++){
		if((get_Board(row,col) == target_cell)		/* セルの値が一致 */
		&& (target_cell != 0)){						/* セルの値が0(初期値)以外 */
			cell_count++;
			if(cell_count == LENGTH - 1){			/* 3マス一致した時 */
				if(turn == FIRST_TURN){
					return FIRST_TURN;				/* 先行の勝利 */
				}
				else{
					return SECOND_TURN;				/* 後攻の勝利 */
				}						
			}
		}
		col++;
	}

	/* 斜め（左下がり）の判定 */
	target_cell = get_Board(LENGTH - 1,LENGTH - 1);
	cell_count = 0;
	col = LENGTH - 2;
	for(row = LENGTH - 2;row > -1;row--){
		if((get_Board(row,col) == target_cell)		/* セルの値が一致 */
		&& (target_cell != 0)){						/* セルの値が0(初期値)以外 */
			cell_count++;
			if(cell_count == LENGTH - 1){			/* 3マス一致した時 */
				if(turn == FIRST_TURN){
					return FIRST_TURN;				/* 先行の勝利 */
				}
				else{
					return SECOND_TURN;				/* 後攻の勝利 */
				}						
			}
		}
		col--;
	}
	return 0;
}



