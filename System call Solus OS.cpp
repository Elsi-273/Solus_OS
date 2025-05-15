#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Mock kernel services
class Kernel {
public:
    void boot() {
        cout << "[Kernel] Booting system..." << endl;
        loadDrivers();
        launchShell();
    }

private:
    void loadDrivers() {
        cout << "[Kernel] Loading device drivers..." << endl;
        cout << "[Kernel] Network driver loaded." << endl;
        cout << "[Kernel] Disk driver loaded." << endl;
    }

    void launchShell() {
        cout << "[Kernel] Launching shell..." << endl;
        Shell shell;
        shell.run();
    }
};

// Mock shell interface
class Shell {
public:
    void run() {
        string command;
        cout << "[Shell] Welcome to SolusShell v1.0" << endl;
        while (true) {
            cout << "user@solus:~$ ";
            getline(cin, command);

            if (command == "exit") {
                cout << "Exiting shell..." << endl;
                break;
            } else if (command == "help") {
                showHelp();
            } else if (command == "info") {
                showInfo();
            } else {
                cout << "Command not found: " << command << endl;
            }
        }
    }

private:
    void showHelp() {
        cout << "Available commands: help, info, exit" << endl;
    }

    void showInfo() {
        cout << "SolusShell - Mock OS Interface v1.0" << endl;
    }
};

// Entry point
int main() {
    Kernel solusKernel;
    solusKernel.boot();
    return 0;
}