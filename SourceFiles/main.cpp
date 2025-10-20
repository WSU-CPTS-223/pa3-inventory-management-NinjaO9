/*
    David Montes
    CPTS223
    PA3 - Amazon Inventory Filter (w/ REPL)
    Date Started: 10/15/25 (I think)
*/

#include "../HeaderFiles/REPL.hpp"

int main(int argc, char const *argv[])
{

    /*
        Everything seems functional, but for some reason my terminal freeses up after running listInventory. Debugger shows everything is fine though...

    */

    HashTable<string, ProductData> testHash;
    HashTable<string, LinkedList<ProductData>*> testList;
    process_csv(testHash, testList);

    string line;
    bootstrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (valid_command(line))
        {
            eval_command(line, testHash, testList);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    
    return 0;
}
