#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/sink.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

void multi_sink_example2()
{
    spdlog::init_thread_pool(8192, 1);
    auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/mylog.txt", 1024 * 1024 * 10, 3);
    std::vector<spdlog::sink_ptr> sinks{stdout_sink, rotating_sink};
    auto logger = std::make_shared<spdlog::async_logger>("loggername", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
    auto logger2 = std::make_shared<spdlog::async_logger>("loggername2", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
    spdlog::register_logger(logger);
    spdlog::register_logger(logger2);
    spdlog::set_pattern("[%Y-%m-%d %H:%M][%a] [%n] [%g][pro %p thr %t] [%l] %v");
    SPDLOG_INFO("Hello world!");
    logger->info("Hello world!");
    logger2->info("Hello world!");
}
int main()
{
    auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.log");
    spdlog::set_default_logger(logger);
    spdlog::set_pattern("[%Y-%m-%d %H:%M][%a] [%n] [%g][pro %p thr %t] [%l] %v");
    SPDLOG_INFO("Hello world!");
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");
    multi_sink_example2();
    return 0;
}