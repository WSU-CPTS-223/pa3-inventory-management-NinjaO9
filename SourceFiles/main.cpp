#include "../HeaderFiles/REPL.hpp"
#include "../HeaderFiles/linkedlist.hpp"

int main(int argc, char const *argv[])
{
    /*
    string line;
    bootstrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (valid_command(line))
        {
            eval_command(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
        */

    LinkedList<int> test;

    test.push_back(5);
    test.push_back(4);
    test.push_back(3);
    test.push_back(2);
    test.push_back(1);

    auto it = test.begin();

    while (it != test.end())
    {
        cout << *it << endl;
        ++it;
    }

    
    return 0;
}
