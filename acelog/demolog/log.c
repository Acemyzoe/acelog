#include <stdio.h>
#include <stdarg.h>
#include "log.h"

static long long default_get_sys_time_ms(void)
{
    return (long long)0;
}

static get_sys_time_ms_def s_get_sys_time_ms = default_get_sys_time_ms;

void log_time_register(get_sys_time_ms_def p_get_sys_time_ms)
{
    s_get_sys_time_ms = p_get_sys_time_ms;
}

void log_print(enum log_color color, const char *file, int line, const char *func, const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE] = {0};
    long long time = s_get_sys_time_ms();

    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);

    switch (color)
    {
    case COLOR_NULL:
        printf("<%lld ms>[%s:%d %s] %s", time, file, line, func, buf);
        break;
    case RED:
        printf("\x1b[31m<%lld ms>[%s:%d %s] %s\x1b[0m", time, file, line, func, buf);
        break;
    case GREEN:
        printf("\x1b[32m<%lld ms>[%s:%d %s] %s\x1b[0m", time, file, line, func, buf);
        break;
    case YELLOW:
        printf("\x1b[33m<%lld ms>[%s:%d %s] %s\x1b[0m", time, file, line, func, buf);
        break;
    case BLUE:
        printf("\x1b[34m<%lld ms>[%s:%d %s] %s\x1b[0m", time, file, line, func, buf);
        break;
    default:
        break;
    }
}