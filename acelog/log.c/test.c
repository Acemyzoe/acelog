#include <stdio.h>
#include <sys/time.h>
#include "log.h"

int main(void)
{
    char ch = 'a';
    char str[10] = "ZhengN";
    float float_val = 10.10;
    int num = 88;
    double double_val = 10.123456;
    log_trace("字符为 %c \n", ch);
    log_debug("字符串为 %s \n", str);
    log_info("浮点数为 %f \n", float_val);
    log_warn("整数为 %d\n", num);
    log_error("双精度值为 %lf \n", double_val);
    log_fatal("八进制值为 %o \n", num);
    log_fatal("十六进制值为 %x \n", num);
    return 0;
}