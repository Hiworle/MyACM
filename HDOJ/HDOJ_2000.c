/*本题是HDOJ第2000题，简单比对输入的三个字符的ASCII码，交换，按顺序输出即可*/
#include<stdio.h>
void swap(char& ch1, char& ch2)
{
    char tem;
    tem = ch1;
    ch1 = ch2;
    ch2 = tem;
}
int main()
{
    char ch1, ch2, ch3;
    while (scanf("%c%c%c", &ch1, &ch2, &ch3) != EOF)
    {
        if (ch1 > ch2) swap(ch1, ch2);
        if (ch1 > ch3) swap(ch1, ch3);
        if (ch2 > ch3) swap(ch2, ch3);
        printf("%c %c %c\n", ch1, ch2, ch3);
        while (getchar() != '\n');              //吸收多余的回车以及空格
    }
    return 0;
}
