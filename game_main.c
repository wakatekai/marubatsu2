#include <stdio.h>
#include <string.h>

# include "main.c"
# include "board.c"
# include "game_main.h"

int GAME_MAIN() {

while(1){
	static	int turn = 0;		/* 0:��s �A 1:��U  */
			int set = 0;		/* 0:�����l�A1:��s�̒l �A 2:��U�̒l */
			int i = 0;			/* �Ֆʂ̍s 0�`2 */
			int j = 0;			/* �Ֆʂ̗� 0�`2 */
			int error_flg;		/* �G���[���� */
			int game_end_flg;	/* �Q�[���p�����蔻�� 0:�p���A-1:�I��*/

			/* �v���C���[���� */
			if (turn == 0) {
				printf("��s�̔Ԃł��B\n");
				printf("�s�̒l����͂��Ă�������\n");
				scanf("%d",&i);
				printf("��̒l����͂��Ă�������\n");
				scanf("%d",&j);
			}
			else
			{
				printf("��U�̔Ԃł��B\n");
				printf("�s�̒l����͂��Ă�������\n");
				scanf("%d", &i);
				printf("��̒l����͂��Ă�������\n");
				scanf("%d", &j);
			}

			/* �Q�[���p���̔���@*/
			game_end_flg�@ = show_Board(int i, int j);
			if (game_end_flg == ERROR) {
				return = ERROR;				/* �Q�[���̏I�� */
			}


			/* �Z�b�g�l�̔���@*/
			if ((i < 3) || (j < 3) 
				&& (i < 3) || (j < 3))
				&& (get_Board(int i, int j, int turn) == 0)
			{
				set_Board(int i, int j, int turn);
			}
//			else{
//				return -1;
//			}

			/*�@���s�̔��� */
			for



		}


}


int main()
{
	int GAME_MAIN();
}