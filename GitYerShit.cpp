#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

int main() {
    std::string local_directory;
    std::string github_username;

    std::cout << "Enter local directory path: ";
    std::getline(std::cin, local_directory);

    std::cout << "Enter github username or org: ";
    std::getline(std::cin, github_username);

    if (!fs::is_directory(local_directory)) {
        std::cerr << "Error: " << local_directory << " is not a directory." << std::endl;
        return 1;
    }

    for (const auto& entry : fs::directory_iterator(local_directory)) {
        if (!fs::is_directory(entry)) {
            continue; // Skip non-directory entries
        }

        const auto& dir = entry.path();

        if (fs::exists(dir / ".git")) {
            std::cout << "Updating " << dir.filename().string() << "..." << std::endl;
            std::system(("git -C " + dir.string() + " pull").c_str());
            std::cout << std::endl;
            std::cout << "Already up to date." << std::endl;
        }
        else {
            std::cout << "Cloning " << dir.filename().string() << "..." << std::endl;
            std::system(("git clone https://github.com/" + github_username + "/" + dir.filename().string() + ".git " + dir.string()).c_str());
            std::cout << std::endl;
            std::cout << "Updated." << std::endl;
        }
    }

    std::string check_package;
    std::cout << "Do you want to check for package.json and build (only works for ox resources)? (y/n): ";
    std::getline(std::cin, check_package);

    if (check_package == "y" || check_package == "Y") {
        for (const auto& entry : fs::directory_iterator(local_directory)) {
            if (!fs::is_directory(entry)) {
                continue; // Skip non-directory entries
            }

            const auto& dir = entry.path();

            if (fs::exists(dir / "web/package.json")) {
                std::cout << "Running pnpm in " << dir.filename().string() << "/web..." << std::endl;
                std::system(("cd " + dir.string() + "/web && pnpm i && pnpm build").c_str());
            }
        }
    }

    std::string check_another;
    std::cout << "Do you want to check another GitHub username/org? (y/n): ";
    std::getline(std::cin, check_another);

    if (check_another == "y" || check_another == "Y") {
        std::system("cls"); // Clear console
        main(); // Execute main() function again
    }

    return 0;
}
