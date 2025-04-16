#include <iostream>

#include "gitClass.cpp"
using namespace std;

//---------------------
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define END "\033[0m"
//---------------------

#ifdef _WIN32
    const string configFileName = "config.txt"; // Windows (hidden using attrib)
#else
    const string configFileName = ".config.txt"; // Linux/macOS (hidden by name)
#endif

bool config() {
    auto path = filesystem::current_path();
    for (const auto &entry : filesystem::directory_iterator(path)) {
        if (entry.path().filename() == configFileName) {
            return true;
        }
    }
    return false;
}
int main(int argc, char *argv[])
{
    gitClass gitClassObj;
    if (argc >= 2)
    {
        string argument = string(argv[1]);
        if (argument == "config") {
    string userName = string(argv[2]);
    auto path = filesystem::current_path();
    ofstream configFile("config.txt");
    if (configFile.is_open()) {
        configFile << "UserName: " << userName << endl;
        configFile.close();

        // Rename to hidden file
        filesystem::rename("config.txt", ".config.txt");

        cout << "\033[1;32mConfiguration file created successfully!\033[0m" << endl;
    } else {
        cout << "\033[1;31mFailed to create configuration file.\033[0m" << endl;
    }
}

        else if (!config()){
            cout << "There is not config:(\n";
            cout << YEL "First config your Self \n" END;
            cout << BLU "Type this <./a.out config (User name)>\n" END;
            return 0;
        }
        
        // git init
        
        else if (argument == "init")
        {
            gitClassObj.gitInit();
            cout << GRN "git repository initialized successfully!" END << endl;
        }
        // git add
        else if (argument == "add")
        {
            if (argc == 2)
            {
                cout << RED "missing arguments!" << endl;
                cout << "Provide a third argument e.g." << endl;
                cout << "git add <'.' | 'file_name'>" END << endl;
            }
            if (argc >= 3)
            {
                if (argc == 3)
                {
                    string argumentC = string(argv[2]);
                    if (argumentC == ".")
                    {
                        gitClassObj.gitAdd();
                    }
                    else
                    {
                        string files[1] = {string(argv[2])};
                        gitClassObj.gitAdd(files, 1);
                    }
                }
                else
                {
                    string files[argc - 2];
                    for (int i = 0; i < argc - 2; i++)
                    {
                        files[i] = string(argv[i]);
                    }
                    gitClassObj.gitAdd(files, argc - 2);
                }
            }
        }
        // git commit
        else if (argument == "commit")
        {
            if (argc == 4) //[ git, commit, -m, "msg" ]
            {
                string argumentC = string(argv[2]);
                string argumentD = string(argv[3]);
                if (argumentC == "-m")
                {
                    gitClassObj.gitCommit(argumentD);
                    cout << "files commited successfully" << endl;
                }
            }
            else
            {
                cout << RED "missing arguments!" << endl;
                cout << "Provide with a message field e.g." << endl;
                cout << "git commit -m 'my commit message'" END << endl;
            }
        }
        // git revert
        else if (argument == "revert")
        {
            if (argc == 3)
            {
                string argumentC = string(argv[2]);
                if (argumentC == "HEAD")

                {
                    gitClassObj.gitRevert(argumentC);
                    cout << "The project is now at HEAD" << endl;
                }
                else
                {
                    gitClassObj.gitRevert(argumentC);
                    cout << "Reverted to <commit_id> commit" << endl;
                }
            }
            else
            {
                cout << RED "invalid arguments, should be like: " << endl;
                cout << "git revert <'HEAD'|'commit_hash'>" END << endl;
            }
        }
        // //git log
        else if (argument == "log")
        {
            gitClassObj.gitLog();
        }
        else if (argument == "--help")
        {
            cout << YEL "git is version control system made by linus Torvalds, this project is a clone of that original system with minimal features \n\n";

            cout << "Usage: " << endl;
            cout << "git init                           ->   initialize an empty git repository in the current dir" << endl;
            cout << "git add <'.'|'file_name'>          ->   add the files to staging area" << endl;
            cout << "git commit <m 'commit message'>    ->   commit your staging files" << endl;
            cout << "git revert <'HEAD'|'commit_hash'>  ->   rollback to a specific commit" END << endl;
        }
        // git status
        //  else if(argument == "status")
        //  {
        //      gitClassObj.gitStatus();
        //  }
        // wrong arguments
        else
        {
            cout << RED "Invalid arguments" END << endl;
        }
    }
    else
    {
        cout << YEL "git is version control system made by linus Torvalds, this project is a clone of that original system with minimal features \n\n";

        cout << "Usage: " << endl;
        cout << "git init                           ->   initialize an empty git repository in the current dir" << endl;
        cout << "git add <'.'|'file_name'>          ->   add the files to staging area" << endl;
        cout << "git commit <m 'commit message'>    ->   commit your staging files" << endl;
        cout << "git revert <'HEAD'|'commit_hash'>  ->   rollback to a specific commit" END << endl;
    }
}
