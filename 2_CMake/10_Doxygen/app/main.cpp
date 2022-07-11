#include <iostream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <fmt/format.h>
#include <cxxopts.hpp>
#include "my_lib.h"
#include "config.hpp"

int main(int argc, char** argv)
{
    auto welcome_message = fmt::format("Welcome to {} v{}\n", project_name, project_version);
    spdlog::info(welcome_message);

    auto json_message = fmt::format("Using JSON lib v{}.{}.{}\n",
                                    NLOHMANN_JSON_VERSION_MAJOR,
                                    NLOHMANN_JSON_VERSION_MINOR,
                                    NLOHMANN_JSON_VERSION_PATCH);
    spdlog::info(json_message);

    cxxopts::Options options(project_name.data());
    options.add_options("arguments")("h,help", "Print usage");
    auto result = options.parse(argc, argv);
    if (result.count("help")) {
        std::cout << options.help() << std::endl;
    }

    std::cout << project_name << "\n";
    std::cout << project_version << "\n";

    print_hello_world();

    return 0;
}
