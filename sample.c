#include <stdio.h>
#include <string.h>

#define MAXBUFSIZE 256

void test(int a, int b)
{
    printf("ans = %d, ans2 = %d\n", a, b);

}

int add(int a, int b)
{

    return a + b;
}

int main()
{
    int answer;
    int ans2;
    int condition = 0;
    char string[MAXBUFSIZE];
   // printf("○×ゲーム\n");
   // printf("スタートしますか？ yes or no\n");

    
    answer = add(1, 3);
    ans2 = add(5, 4);

    test(answer, ans2);

    fgets(string, MAXBUFSIZE, stdin);

    

    if (strcmp(string, "yes\n") == 0)
    {
        printf("Yesと入力しました。");
    }
    else
    {
        printf("input = %s test\n", string);
    }

    while (condition < 10) 
    {
        printf("繰り返してます… %d\n", condition);
        condition = condition + 1;
    }

    return 0;
}