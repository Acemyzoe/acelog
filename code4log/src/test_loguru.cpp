
#include <iostream>
#define LOGURU_WITH_STREAMS 1 //使用流进行日志记录
#include "loguru/loguru.cpp"
int testloguru(int argc, char **argv)
{
    loguru::init(argc, argv);
    char ch = 'a';
    char str[10] = "AC";
    float float_val = 10.10;
    int num = 88;
    double double_val = 10.123456;

    char log_path[1024];
    loguru::suggest_log_path("./logurufile/", log_path, sizeof(log_path)); //获取日志文件夹路径
    loguru::add_file(log_path, loguru::FileMode::Append, loguru::Verbosity_MAX);

    loguru::add_file("latest_readable.log", loguru::Append, loguru::Verbosity_INFO);

    LOG_SCOPE_FUNCTION(INFO); //缩进日志记录以使其更具可读性
    LOG_F(INFO, "字符为 %c ", ch);
    LOG_F(WARNING, "字符串为 %s ", str);
    LOG_F(ERROR, "浮点数为 %f ", float_val);

    LOG_S(INFO) << "整数为" << num;
    LOG_S(ERROR) << "双精度值为" << double_val;
    return 0;
}

int main(int argc, char **argv)
{
    testloguru(argc, argv);
    return 0;
}