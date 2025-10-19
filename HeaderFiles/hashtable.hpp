#include "libs.h"
#include "linkedlist.hpp"
#ifndef HASHTABLE_H
#define HASHTABLE_H

#define MIN_SIZE 101
#define MAX_LOAD 0.5

/*
    This is the first time I am implementing a hashmap, so I might get a little fancy with this one, we will see lmao
    Temalate takes 3 params (1 optional). This lets us customize the hash we will use for the hashtable 
    Unordered map showcases something about buckets. This could be helpful for separating a populated, empty, and deleted parts of the table (https://en.cppreference.com/w/cpp/container/unordered_map.html)

*/
int primes[6] = {101, 211, 401, 809, 1601, 3299};

template <typename Key, typename T, typename Hash = hash<Key>>
class HashTable
{
    public:

    HashTable();

    HashTable(HashTable& other);

    ~HashTable() = default;

    void insert(const Key key, const T& value);

    T find(const Key& key);

    void erase(const Key& key);

    T operator[](const Key& key);

    protected:

    // This enum will help act as a flag for if the index of the table is populated, deleted, or empty (as shown in the names)
    enum BucketState
    {
        POPULATED,
        DELETED,
        EMPTY
    };

    // The table will be an array of buckets that contain these three factors.
    struct Bucket
    {
        Key key; // Saving a copy of the key lets me easily do comparisons
        T data;
        enum HashTable<Key,T,Hash>::BucketState state;

    };

    private:

    void rehash();

    
    int size = MIN_SIZE;
    int count = 0;
    const int attempts = 3;

    struct Bucket table[MIN_SIZE];

};

template <typename Key, typename T, typename Hash>
HashTable<Key, T, Hash>::HashTable()
{
    for (auto& bucket : table)
    {
        bucket.data = T();
        bucket.state = EMPTY;
    }
}

template <typename Key, typename T, typename Hash>
void HashTable<Key, T, Hash>::insert(const Key key, const T& value)
{
    int attempt = 0;
    size_t index = 0;

    for (; attempt < attempts; attempt++)
    {
        index = (Hash{}(key) + (int)pow(attempt, 2)) % size;
        //cout << table[index].state << endl;
        // If we have duplicate keys, then we will act like we are 'updating' the data
        if (table[index].state != POPULATED && table[index].key != key)
        {
            table[index].key = key;
            table[index].data = value;
            table[index].state = POPULATED;
            //cout << "Inserted!" << endl;
            rehash();
            return;
        }
    }
    //cout << "Not inserted" << endl;
    
}

template <typename Key, typename T, typename Hash>
T HashTable<Key, T, Hash>::find(const Key &key)
{
    int attempt = 0;
    size_t index = 0;

    for (; attempt < attempts; attempt++)
    {
        index = (Hash{}(key) + (int)pow(attempt, 2)) % size;
        if (table[index].state == POPULATED && table[index].key == key)
        {
            //cout << "Found!" << endl;
            return table[index].data;
        }
        if (table[index].state == EMPTY) return T();
    }
    //cout << "Not found" << endl;
    return T();
}

template <typename Key, typename T, typename Hash>
T HashTable<Key, T, Hash>::operator[](const Key &key)
{
    return find(key);
}

template <typename Key, typename T, typename Hash>
void HashTable<Key, T, Hash>::rehash()
{
    double loadfactor = (double)count/(double)size;
    cout << "Load factor: " << loadfactor << endl;
    if (loadfactor < MAX_LOAD) return;

    int newsize = size;
    for (int prime : primes)
    {
        if (prime > newsize)
        {
            newsize = prime;
            break;
        }
    }
    /*
    struct Bucket newtable = new Bucket[newsize];
    struct Bucket temp = table;
    table = newtable;
    for (struct Bucket bucket : temp)
    {
        if (bucket.state == POPULATED)
        {
            insert(bucket.key, bucket.data);
        }
    }
    delete[] temp;
    */

}

#endif