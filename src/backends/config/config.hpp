#pragma once

#include <string>
#include <vector>
#include <backends/util/keyValue.hpp>


namespace volt::config {


class ConfigReader {

typedef struct Config {
    volt::utils::kvPair filename;
    volt::utils::kvPair compiler;
    volt::utils::kvPair linker;
    volt::utils::kvPair language;
    std::vector<volt::utils::kvPair> arguments;
    std::vector<volt::utils::kvPair> inputFiles;
    volt::utils::kvPair target;
};

public:
    ConfigReader(std::string filename);
    ~ConfigReader();

    Config readConfig();

private:
};


}