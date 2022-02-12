
#include <stdio.h>
#include <string.h>
#include "game_main.h"

#define MAXBUFSIZE 256

typedef enum  {
    false,
    true
} Bool;

#define STATE_TITLE   0 //起動時の最初のタイトル画面
#define STATE_GAME    1 //ゲーム中
#define STATE_RESULT  2 //リザルト画面
#define STATE_END     3 //終了

void init_all();  /* 全体初期化 */
Bool loop_main(); /* 全体の状態遷移 */
Bool disp_gametitle(Bool firstflg); /* ゲームタイトルの表示 */
void disp_gameresult(); /* ゲームの結果表示 */

int main()
{
    init_all();

    while (loop_main() == true);

    return 0;
}

/* 
関数名：初期化関数 
引数：無し 
内容：各種初期化
*/
void init_all()
{
    
}

/* 
関数名：メインループ
引数：無し 
内容：メインループ
*/
Bool loop_main() 
{
    Bool ret = false;
    static Bool firstflg = true;
    int result = 0;

    /* ゲームタイトル表示 */
    ret = disp_gametitle(firstflg);
    if (ret == false) return false;
    firstflg = false;

    /* ゲームの呼び出し */
    result = game_main();

    /* ゲームの結果表示 */
    disp_gameresult(result);

    printf("何かキーを押してください\n");
    fflush(stdin);
    getchar();
    
    return true;
}

/*
関数名：disp_gametitle
引数：Bool firstflg -> 初回の時のタイトルの時true
内容：ゲーム
*/
Bool disp_gametitle(Bool firstflg)
{
    char buf[MAXBUFSIZE];
    printf("\033[2J");
    printf("\033[1;0H");
    printf("# # # # ○×ゲーム # # # #\n");
    if (firstflg) {
        printf("ゲームをスタートしますか? yes no ->");
    }
    else {
        printf("もう一度やりますか？ yes no ->");
    }

    fgets(buf, MAXBUFSIZE, stdin);
    if (strcmp(buf, "yes\n") == 0)
    {
        return true;
    }

    printf("\n\n");
    return false;
}

void disp_gameresult(int result)
{
    
    printf("# # # # ゲーム終了 # # # #\n");

    switch (result) 
    {
        case ERROR:
            printf("申し訳ありません。エラーが発生しました。\n");
            break;
        case RESULT_DRAW:
            printf("お疲れ様でした。引き分けでした。\n");
            break;
        case RESULT_FIRST:
            printf("先手の勝ちです！おめでとうございます！\n");
            printf("先手有利なので、まぁよかったね。\n");
            break;
        case RESULT_SECOND:
            printf("後手の勝ちです！おめでとうございます！\n");
            printf("後手なのに勝ててすごいですね\n");
            break;
        default:
            printf("予期せぬエラーが発生しました。\n");
    }
       
}

/*
#include <stdio.h>
#include <string.h>
#define MAXBUFSIZE 256

#define TITLE   0 //起動時の最初のタイトル画面
#define GAME    1 //ゲーム中
#define RESULT  2 //リザルト画面
#define END     3 //終了

int main()
{
    int status = TITLE;

    char string[MAXBUFSIZE];
   // printf("○×ゲーム\n");
   // printf("スタートしますか？ yes or no\n");

    while ( status != END)
    {
        printf("○×ゲーム");
        printf("ゲームをスタートしますか？");

        fgets(string, MAXBUFSIZE, stdin);

        if (strcmp(string, "yes\n") == 0)
        {
            printf("ゲーム中表示");
        }
        else
        {
            printf("input = %s 終了\n", string);
        }

        if (strcmp(string, "yes\n") == 0)
        {
            printf("ゲーム中表示");
        }
        else
        {
            printf("input = %s 終了\n", string);
        }

        printf("ゲームを終了？ or もう一回やりますか？ もう一回やるときはyes
終了するときはno を入力\n");

    }

    return 0;
}
*/