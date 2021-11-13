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

        printf("ゲームを終了？ or もう一回やりますか？ もう一回やるときはyes 終了するときはno を入力\n");

    }

    return 0;
}