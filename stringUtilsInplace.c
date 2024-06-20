// 原位修改字符串
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 删除字符串中的某字符
void remove_character(char * str, char c)
{
    int i, j;
    for (i = j = 0; str[i] != '\0'; i ++)
    {
        if (str[i] != c)
        {
            str[j] = str[i];
            j ++;
        }
    }
    str[j] = '\0';
} 

// 替换字符串[begin, end)位置的内容为content（不要求content长度为end-begin）
// 返回一个指针，指向替换后的字符串中原来end处的字符
char * replace(char * begin, char * end, char * content)
{
    int end_len = (int) strlen(end);
    char * end_temp = (char *) malloc((unsigned)(end_len + 1) * sizeof(char));
    strcpy(end_temp, end);
    for (; *content != '\0'; begin ++, content ++)
    {
        *begin = *content;
    }
    char * ret = begin;
    for (int i = 0; i < end_len; i ++)
    {
        *begin = end_temp[i];
        begin ++;
    }
    *begin = '\0';
    free(end_temp);
    return ret;
}

// 颠倒字符串内容
void reverse(char * s)
{
    char temp = 0;
    for (int i = 0, j = (int)strlen(s) - 1; i < j; i ++, j --)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// 将整数的字符串表示存储到s中（支持正数、负数、0）
void itoa(int a, char * s)
{
    int i = 0;
    int sign = a;
    if (a < 0)
    {
        a = -a;
    }
    if (a == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return;
    }
    while (a > 0)
    {
        s[i] = (char)(a % 10) + '0';
        a /= 10;
        i ++;
    }
    if (sign > 0)
    {
        s[i] = '\0';
    }
    else
    {
        s[i] = '-';
        s[i + 1] = '\0';
    }
    
    reverse(s);
}
// 将整数的字符串表示（16进制）存储到s中（支持正数、0）
void itoh(unsigned n,char s[])
{
    int h,i=0;
    do{
        h=n%16;
        s[i++]=(h<=9)?h+'0':h+'A'-10;
    } while((n/=16)!=0);
    s[i] = '\0';
    reverse(s);
}
// 在s中查找t，返回t第一个字符的下标
int getIndex(char s[],char t[])
{
    int i,j,k;
    for(i=0;s[i]!='\0';i++)
    {
        for(j=i,k=0;s[j] != '\0'&&s[j]==t[k];j++,k++)
            ;
        if(t[k] == '\0')
            return i;
    }
    return -1;
}

// 逆序打印字符串(递归)
void inverp(char *a)
{
    if ( *a == '\0' )
        return;
    inverp(a+1);
    printf("%c", *a );
}