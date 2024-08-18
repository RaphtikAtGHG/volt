#pragma once

#include <iostream>
#include <string_view>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <ctime>

namespace volt::logger {

    enum class Level {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    inline constexpr std::string_view get_prefix(Level level) {
        switch (level) {
            case Level::INFO:    return "[INFO]";
            case Level::WARNING: return "[WARNING]";
            case Level::ERROR:   return "[ERROR]";
            case Level::DEBUG:   return "[DEBUG]";
            default:             return "[LOG]";
        }
    }

    inline constexpr std::string_view get_color(Level level) {
        switch (level) {
            case Level::INFO:    return "\033[32m";
            case Level::WARNING: return "\033[33m";
            case Level::ERROR:   return "\033[31m";
            case Level::DEBUG:   return "\033[34m";
            default:             return "\033[0m";
        }
    }

    inline constexpr std::string_view get_bold() {
        return "\033[1m";
    }

    inline constexpr std::string_view get_reset() {
        return "\033[0m";
    }

    inline std::string get_current_time() {
        using namespace std::chrono;
        auto now = system_clock::now();
        auto time_t_now = system_clock::to_time_t(now);
        auto local_time = *std::localtime(&time_t_now);

        std::ostringstream oss;
        oss << std::put_time(&local_time, "%H:%M:%S");
        
        auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;
        oss << '.' << std::setw(3) << std::setfill('0') << ms.count();

        return oss.str();
    }

    inline void log(Level level, const std::string_view& message) {
        std::cout << get_color(level)
                  << get_bold()
                  << get_current_time()
                  << ' ' << get_prefix(level)
                  << get_reset()
                  << ": " << message;
        std::cout << '\n';
    }

    inline void info(const std::string_view& message) {
        log(Level::INFO, message);
    }

    inline void warning(const std::string_view& message) {
        log(Level::WARNING, message);
    }

    inline void error(const std::string_view& message) {
        log(Level::ERROR, message);
    }

    inline void debug(const std::string_view& message) {
        log(Level::DEBUG, message);
    }

} // namespace volt::logger
