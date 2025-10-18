/*
    David Montes
    CPTS223
    PA3 - Amazon Inventory Filter (w/ REPL)
    Date Started: 10/15/25 (I think)
*/

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

    cout << test;

    auto it = test.find(3);

    if (it != test.end()) cout << "Found: " << *it << endl;
    else cout << "Not found" << endl;

    it = test.find(6);

    if (it != test.end()) cout << "Found: " << *it << endl;
    else cout << "Not found" << endl;

    size_t r = hash<string>{}("Hello");

    cout << r << endl;
    
    return 0;
}
