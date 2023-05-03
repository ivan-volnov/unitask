#include "special_id.hpp"
#include <iostream>

auto main(int argc, char *argv[]) -> int
{
    uni::SpecialId id;
    std::mutex mutex;

    std::cout << "Usage:\n\n"
                 "Enter empty string to increment\n"
                 "Enter value to assign\n"
                 "Enter 'q', quit or Ctrl+C to quit\n"
              << std::endl;

    std::string cmd;
    while (true) {
        {
            // Let's assume we use our id from multiple threads
            std::lock_guard lock(mutex);
            std::cout << id.to_string() << "\n❯ " << std::flush;
        }

        // Wait for user command
        std::getline(std::cin, cmd);
        if (cmd == "q" || cmd == "quit") {
            break;
        }

        try {
            std::lock_guard lock(mutex);
            if (cmd.empty()) {
                ++id;
                continue;
            }
            id = cmd;
        }
        catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    }
}
