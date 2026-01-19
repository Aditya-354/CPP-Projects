#include <iostream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

std::vector<std::string> split(std::string& cmd_line){
    std::stringstream ss(cmd_line);
    std::string word;

    std::vector<std::string> tokens;
    while(ss >> word) tokens.push_back(word);

    return tokens;
}

int main(){
    while(true){
        std::cout << "[myShell]$ " << "\n" << "->";

        std::string cmd_line_in;
        if(!std::getline(std::cin, cmd_line_in)) break;

        if(cmd_line_in == "exit") break;

        auto tokens = split(cmd_line_in);
        if(tokens.empty()) continue;

        if(tokens[0] == "cd"){
            if(tokens.size() > 1){
                if(chdir(tokens[1].c_str()) != 0) perror("cd failed!");
            }
            continue;
        }

        pid_t pid = fork();

        bool background = false;

        if(tokens.back() == "&"){
            background = true;
            tokens.pop_back();
        }

        if(pid == 0){
            // child process
            std::vector<char*> args;
            for(auto& s: tokens){
                args.push_back(const_cast<char*>(s.c_str()));
            }

            args.push_back(nullptr);
            execvp(args[0], args.data());
            perror("exec failed!");
            exit(1);
        } else {
            if(!background)
                waitpid(pid, nullptr, 0);
            else 
                std::cout << "Started in background: " << pid << "\n";
        }

        std::cout << "\n";
    }
    return 0;
}
