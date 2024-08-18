#include <iostream>
#include <logger.hpp>

int main() {
    volt::logger::info("This is an info message.");
    volt::logger::warning("This is a warning message.");
    volt::logger::error("This is an error message.");
    volt::logger::debug("This is a debug message.");

    return 0;
}
