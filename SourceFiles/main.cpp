/*
    David Montes
    CPTS223
    PA3 - Amazon Inventory Filter (w/ REPL)
    Date Started: 10/15/25 (I think)
*/

#include "../HeaderFiles/REPL.hpp"
#include "../HeaderFiles/linkedlist.hpp"
#include "../HeaderFiles/hashtable.hpp"

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

    LinkedList<int> testList;
    HashTable<string, int> testHash;

    testHash.insert("Hello!", 6);

    cout << testHash.find("Hello!") << endl;
    cout << testHash["Hello!"] << endl;
    cout << testHash["Hello"] << endl << endl;




    testList.push_back(5);
    testList.push_back(4);
    testList.push_back(3);
    testList.push_back(2);
    testList.push_back(1);

    cout << testList;

    auto it = testList.find(3);

    if (it != testList.end()) cout << "Found: " << *it << endl;
    else cout << "Not found" << endl;

    it = testList.find(6);

    if (it != testList.end()) cout << "Found: " << *it << endl;
    else cout << "Not found" << endl;

    size_t r = hash<string>{}("Hello");

    cout << r << endl;
    
    return 0;
}
