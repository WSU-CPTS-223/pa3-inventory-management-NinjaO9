#include "../HeaderFiles/REPL.hpp"
#include <exception>

// Custom exception for coolness
class FileNotFound : public exception
{
    public:

    FileNotFound(const string& msg) : message(msg){};

    const char* what() const noexcept override {return message.c_str();}

    private:

    const string message;
};


void print_help()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool valid_command(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void eval_command(string line, HashTable<string, ProductData>& product_table, HashTable<string, LinkedList<ProductData>*>& category_table)
{
    istringstream iss(line);
    string command, argument;
    
    if (line == ":help")
    {
        print_help();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        iss >> command >> argument;
        auto prod =  product_table[argument];
        if (prod.get_uniqid() == "N/A")
            cout << "Product \"" << argument << "\" was not found" << endl;
        else
            cout << "Categories: " << prod.get_categories() << endl;
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        iss >> command;
        argument = line.substr(command.length(), line.size());
        argument.erase(remove_if(argument.begin(), argument.end(), ::isspace), argument.end()); // Remove whitespace - Reminder to myself to do this for user input too

        auto prod = category_table[argument];
        if (prod == nullptr)
            cout << "Category \"" << argument << "\" was not found" << endl;
        else
        {
            auto it = prod->begin();
            cout << prod->get_size() << endl;
            while (it != prod->end())
            {
                if ((*it).get_productname() == "Heroes Wanted: Breaking News Expansion")
                {
                    cout << "PAUSE" << endl;
                }
                cout << "Product: " << (*it).get_productname() << endl;
                ++it;
            }
        }
    }
}

void bootstrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";

    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}

void process_csv(HashTable<string, ProductData>& product_table, HashTable<string, LinkedList<ProductData>*>& category_table)
{
    ifstream infile = ifstream("ResourceFiles/marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");
    //ifstream infile = ifstream("ResourceFiles/sample.csv");

    if (!infile.is_open()) throw FileNotFound("File was not found. Check the path?");

    ProductData prod_data = ProductData();
    string line;
    string attributes_list[28];
    getline(infile, line); // get rid of discriptor line


    while (!infile.eof())
    {
        getline(infile, line);
        prod_data = parse_line(line);
        //cout << prod_data.get_uniqid() << endl;
        place_into_categories(prod_data, category_table);
        product_table.insert(prod_data.get_uniqid(), prod_data);
    }
}

// Modified code from the previous PA
ProductData parse_line(string line)
{
    string::size_type cindex1 = 0, cindex2 = 0, tempindex = 0;
    unsigned int index = UNIQ_ID;
    string fields[28] = {};
    string sub;

    while (index != LAST)
    {
        // next item is in quotes
        if (line[cindex1] == '\"')
        {
            tempindex = cindex1;
            while (line[cindex2 + 1] != ',') // incase we get baited with another double quote inside of double quotes, we will search for the quote which has a comma next to it
            {
                cindex2 = line.find("\"", tempindex + 1);
                tempindex = cindex2;
            }
            if (cindex2 == string::npos) cindex2 = line.length() - 1;
            sub = line.substr(cindex1 + 1, (cindex2 - 1) - cindex1);
            cindex1 = cindex2 + 2;

        }
        else // We can parse normally
        {
            cindex2 = line.find(",", cindex1);
            if (cindex2 == string::npos) cindex2 = line.length() - 1;
            sub = line.substr(cindex1, cindex2 - cindex1);
            cindex1 = cindex2 + 1;
        }
        if (sub == "") sub = "N/A";
        fields[index] = sub;
        index++;
    }
    return ProductData(fields);

}

void place_into_categories(const ProductData data, HashTable<string, LinkedList<ProductData>*>& category_table)
{
    if (data.get_categories() == "N/A") return;
    LinkedList<string> categories = LinkedList<string>();
    string::size_type cindex1 = 0, cindex2 = 0;
    string line = data.get_categories();
    string sub = "";

    while (cindex2 < line.length())
    {
        cindex2 = line.find("|", cindex1);
        if (cindex2 == string::npos)
            cindex2 = line.length() + 1;
        sub = line.substr(cindex1, (cindex2 - 1) - cindex1);
        sub.erase(remove_if(sub.begin(), sub.end(), ::isspace), sub.end()); // Remove whitespace - Reminder to myself to do this for user input too
        categories.push_back(sub);
        cindex1 = cindex2 + 1;
    }

    for (auto it = categories.begin(); it != categories.end(); ++it)
    {
        if (category_table.find(*it))
        {
            category_table[*it]->push_back(data);
        }
        else
        {
            category_table.insert(*it, new LinkedList<ProductData>(data));
        }
    }
}
