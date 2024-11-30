#include "ft_printf.h"

int main()
{
    char *p = "achaq";
    ft_printf("%s\n","sadsadasdsa");
    ft_printf("%c\n",'g');
    ft_printf("%+d\n",343434);
    ft_printf("%-i\n",3424343);
    ft_printf("%p\n",&p);
    ft_printf("%#x\n",435543);
    ft_printf("%#X\n",345435345);
    ft_printf("%u\n",-3455);
    ft_printf("%%","sadsadasdsa");
}