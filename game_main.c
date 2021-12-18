#include <stdio.h>
#include <string.h>

# include "main.c"
# include "board.c"
# include "game_main.h"

int GAME_MAIN() {

while(1){
	static	int turn = 0;		/* 0:先行 、 1:後攻  */
			int set = 0;		/* 0:初期値、1:先行の値 、 2:後攻の値 */
			int i = 0;			/* 盤面の行 0～2 */
			int j = 0;			/* 盤面の列 0～2 */
			int error_flg;		/* エラー判定 */
			int game_end_flg;	/* ゲーム継続判定判定 0:継続、-1:終了*/

			/* プレイヤー操作 */
			if (turn == 0) {
				printf("先行の番です。\n");
				printf("行の値を入力してください\n");
				scanf("%d",&i);
				printf("列の値を入力してください\n");
				scanf("%d",&j);
			}
			else
			{
				printf("後攻の番です。\n");
				printf("行の値を入力してください\n");
				scanf("%d", &i);
				printf("列の値を入力してください\n");
				scanf("%d", &j);
			}

			/* ゲーム継続の判定　*/
			game_end_flg　 = show_Board(int i, int j);
			if (game_end_flg == ERROR) {
				return = ERROR;				/* ゲームの終了 */
			}


			/* セット値の判定　*/
			if ((i < 3) || (j < 3) 
				&& (i < 3) || (j < 3))
				&& (get_Board(int i, int j, int turn) == 0)
			{
				set_Board(int i, int j, int turn);
			}
//			else{
//				return -1;
//			}

			/*　勝敗の判定 */
			for



		}


}


int main()
{
	int GAME_MAIN();
}