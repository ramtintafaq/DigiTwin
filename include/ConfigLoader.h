#include <fstream>
#include <sstream>
#include <string>
#include <map>

std::string loadConnectionString(const std::string& filename) {
    std::ifstream file(filename);
    std::string line, connStr;
    std::map<std::string, std::string> config;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        size_t eq = line.find('=');
        if (eq != std::string::npos) {
            std::string key = line.substr(0, eq);
            std::string value = line.substr(eq + 1);
            config[key] = value;
        }
    }

    for (const auto& [key, val] : config) {
        connStr += key + "=" + val + " ";
    }

    return connStr;
}