/*
统计字串出现次数
计算字符串中子串出现的次数。
输入：输入以空格相隔的两个字符串（字符数不大于20个），敲回车。
输出：统计第一个字符串中第二个字符串出现的次数。
样例输入
sdsdsdsd sd
样例输出
4
*/

#include <stdio.h>
#include <string.h>

// 生成NEXT数组
void FindNext(char *substr, int *next)
{
    int prefix_len = 0;
    for (int i = 0; i < strlen(substr);)
    {
        if (substr[prefix_len] == substr[i])
        {
            prefix_len++;
            next[i] = prefix_len;
            i++;
        }
        else
        {
            if (prefix_len == 0)
            {
                next[i] = 0;
                i++;
            }
            else
            {
                prefix_len = next[prefix_len - 1];
                /*note:这里的巧妙之处在于，没有i++，使得程序中i不动，不断循环求出这里的next[i]*/
            }
        }
    }
}

int FindCount(char *str, char *substr, int *next)
{
    int p = 0;
    int count = 0;
    for (int i = 0; i < strlen(str);)
    {
        if (str[i] == substr[p])
        {
            p++;
            i++;
        }
        else if (p > 0)
        {
            p = next[p - 1];
        }
        else
        {
            i++;
        }

        if (p == strlen(substr))
        {
            p = 0;
            count++;
        }
    }
    return count;
}

int main()
{
    int count;
    int next[5000];
    char str[5000], substr[5000];
    while (scanf("%s %s", str, substr) != EOF)
    {
        FindNext(substr, next);
        count = FindCount(str, substr, next);
        printf("%d\n", count);
    }
}