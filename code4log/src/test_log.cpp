
#include <iostream>
#define LOGURU_WITH_STREAMS 1
#include "loguru/loguru.cpp"
int testloguru()
{
    char ch = 'a';
    char str[10] = "AC";
    float float_val = 10.10;
    int num = 88;
    double double_val = 10.123456;
    char log_path[1024];
    loguru::suggest_log_path("./logurufile/", log_path, sizeof(log_path));       //获取日志文件路径
    loguru::add_file(log_path, loguru::FileMode::Append, loguru::Verbosity_MAX); //设置日志文件路径

    LOG_F(INFO, "字符为 %c \n", ch);
    LOG_F(WARNING, "字符串为 %s \n", str);
    LOG_F(ERROR, "浮点数为 %f \n", float_val);
    LOG_S(INFO) << "整数为" << num;
    LOG_S(ERROR) << "双精度值为" << double_val;
    return 0;
}

#include "spdlog/spdlog.h"
int testspd()
{
    char ch = 'a';
    char str[10] = "AC";
    float float_val = 10.10;
    int num = 88;
    double double_val = 10.123456;
    spdlog::info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
    spdlog::warn("字符为 {} \n", ch);
    spdlog::error("字符串为 {} \n", str);
    spdlog::info("浮点数为 {} \n", float_val);
    spdlog::info("整数为 {} \n", num);
    spdlog::info("双精度值为 {} \n", double_val);
    return 0;
}

int main()
{
    testloguru();
    testspd();
    return 0;
}