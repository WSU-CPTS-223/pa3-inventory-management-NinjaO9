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
        Nearly done, I just need to figure out some issues where inputs in the csv are inconsistent (Sometimes there will be double quotes)
        To fix this, I will probably just duplicate the line I used to get rid of whitespace, but instead search for quotes.

        Then, I also need to get the commands working, but the datastructures and algorithms (title drop) that I am using are generally complete, unless I need so come back and do some small modifications (which I will probably do)

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
