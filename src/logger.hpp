#pragma once

#include <iostream>
#include <string_view>
#include <sstream>
#include <string>

namespace Logger {

    enum class Level {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };
    
    constexpr std::string_view get_prefix(Level level) {
        switch (level) {
            case Level::INFO:    return "[INFO]";
            case Level::WARNING: return "[WARNING]";
            case Level::ERROR:   return "[ERROR]";
            case Level::DEBUG:   return "[DEBUG]";
            default:             return "[LOG]";
        }
    }

    constexpr std::string_view get_color(Level level) {
        switch (level) {
            case Level::INFO:    return "\033[32m";
            case Level::WARNING: return "\033[33m";
            case Level::ERROR:   return "\033[31m";
            case Level::DEBUG:   return "\033[34m";
            default:             return "\033[0m";
        }
    }

    template<typename... Args>
    std::string format(std::string_view format_str, Args&&... args) {
        std::ostringstream oss;
        ((oss << args << " "), ...);
        return oss.str();
    }

    template<typename... Args>
    void log(Level level, std::string_view format_str, Args&&... args) {
        std::string message = format(format_str, std::forward<Args>(args)...);
        std::cout << get_color(level) 
                  << get_prefix(level) 
                  << ": " << message << "\033[0m\n";
    }

    inline void info(std::string_view message) {
        log(Level::INFO, message);
    }

    inline void warning(std::string_view message) {
        log(Level::WARNING, message);
    }

    inline void error(std::string_view message) {
        log(Level::ERROR, message);
    }

    inline void debug(std::string_view message) {
        log(Level::DEBUG, message);
    }

} // namespace Logger
