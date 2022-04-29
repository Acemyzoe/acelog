#include <iostream>

// #include "loguru_example.hpp"
#define LOGURU_WITH_STREAMS 1
#define LOGURU_DEBUG_LOGGING 0
#include "../loguru.cpp"

int main(int argc, char *argv[])
{
    loguru::init(argc, argv);
    // loguru::add_file("./latest_readable.log", loguru::Truncate, loguru::Verbosity_INFO);

    char log_path[PATH_MAX];
    loguru::suggest_log_path("./loguru/", log_path, sizeof(log_path));
    loguru::add_file(log_path, loguru::FileMode::Append, loguru::Verbosity_MAX);

    // LOG_F(INFO, "Hello from main.cpp!");
    // // complex_calculation();
    // LOG_F(INFO, "main function about to end!");
    LOG_F(INFO, "This is an INFO message!");
    LOG_F(WARNING, "This is a WARNING message!");
    LOG_F(ERROR, "This is an ERROR message!");

    LOG_F(1, "This may be important, but probably not");
    LOG_F(9, "Nobody will ever care about this.");

    loguru::Verbosity verbosity = 5; // Higher = less likely to be printed
    VLOG_F(verbosity, "...");

    verbosity = loguru::Verbosity_WARNING;
    VLOG_F(verbosity, "...");

    RAW_LOG_F(INFO, "This will show up in raw log file only!");

    DLOG_F(INFO, "This will show up in the main log file and raw log file!");

    LOG_S(INFO) << "Hello,streams!";
}
