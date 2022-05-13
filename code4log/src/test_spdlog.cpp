#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/sink.h"
#include "spdlog/async.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"

// 基础用法
void test_spdlog1()
{
    auto logger1 = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.log");

    // Create a file rotating logger with 5mb size max and 3 rotated files
    auto max_size = 1048576 * 5;
    auto max_files = 3;
    auto logger2 = spdlog::rotating_logger_mt("some_logger_name", "logs/rotating.log", max_size, max_files);

    // Create a daily logger - a new file is created every day on 2:30am
    auto logger3 = spdlog::daily_logger_mt("daily_logger", "logs/daily.log", 2, 30);

    spdlog::set_default_logger(logger2);

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);

    // change log pattern
    spdlog::set_pattern("%Y-%m-%d %H:%M:%S.%f <thread %t> [%^%l%$] [%@] %v");

    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");
}

void stdout_example()
{
    // create color multi threaded logger
    auto console = spdlog::stdout_color_mt("console");
    console->info("{}", "Hello world!");
    auto err_logger = spdlog::stderr_color_mt("stderr");
    spdlog::get("stderr")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
}

#include "spdlog/stopwatch.h"
void stopwatch_example()
{
    spdlog::stopwatch sw;
    spdlog::debug("Elapsed {}", sw);
    spdlog::info("Elapsed {:.3}", sw);
}

#include "spdlog/fmt/bin_to_hex.h"
void binary_example()
{
    std::array<char, 80> buf;
    spdlog::info("Binary example: {}", spdlog::to_hex(buf));
}

// create logger with 2 targets with different log levels and formats.
// the console will show only warnings or errors, while the file will log all.
void multi_sink_example()
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::warn);
    console_sink->set_pattern("[multi_sink_example] [%^%l%$] %v");

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/multisink.txt", true);
    file_sink->set_level(spdlog::level::trace);

    spdlog::logger logger("multi_sink", {console_sink, file_sink});
    logger.set_level(spdlog::level::debug);
    logger.warn("this should appear in both console and file");
    logger.info("this message should not appear in the console, only in the file");
}

// user defined types logging by implementing operator<<
#include "spdlog/fmt/ostr.h" // must be included
struct my_type
{
    int i;
    template <typename OStream>
    friend OStream &operator<<(OStream &os, const my_type &c)
    {
        return os << "[my_type i=" << c.i << "]";
    }
};

void user_defined_example()
{
    spdlog::info("user defined type: {}", my_type{14});
}

// Log patterns can contain custom flags.
// the following example will add new flag '%*' - which will be bound to a <my_formatter_flag> instance.
#include "spdlog/pattern_formatter.h"
class my_formatter_flag : public spdlog::custom_flag_formatter
{
public:
    void format(const spdlog::details::log_msg &, const std::tm &, spdlog::memory_buf_t &dest) override
    {
        std::string some_txt = "custom-flag";
        dest.append(some_txt.data(), some_txt.data() + some_txt.size());
    }

    std::unique_ptr<custom_flag_formatter> clone() const override
    {
        return spdlog::details::make_unique<my_formatter_flag>();
    }
};

void custom_flags_example()
{
    auto formatter = std::make_unique<spdlog::pattern_formatter>();
    formatter->add_flag<my_formatter_flag>('*').set_pattern("[%n] [%*] [%^%l%$] %v");
    spdlog::set_formatter(std::move(formatter));
    spdlog::info("custom flag: {}", my_type{14});
}

int main()
{
    test_spdlog1();
    // stdout_example();
    // stopwatch_example();
    // binary_example();
    // multi_sink_example();
    // user_defined_example();
    // custom_flags_example();
    return 0;
}