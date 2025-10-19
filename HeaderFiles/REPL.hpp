#include "libs.h"
#include "../HeaderFiles/linkedlist.hpp"
#include "../HeaderFiles/hashtable.hpp"
#include "../HeaderFiles/productdata.hpp"


void print_help();

bool valid_command(string line);

void eval_command(string line, HashTable<string, ProductData>& product_table, HashTable<string, LinkedList<ProductData>*>& category_table);

void bootstrap();

void process_csv(HashTable<string, ProductData>& product_table, HashTable<string, LinkedList<ProductData>*>& category_table);

ProductData parse_line(string line);

void place_into_categories(const ProductData data, HashTable<string, LinkedList<ProductData>*>& category_table);