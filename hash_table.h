#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 10

// Zincirleme (Chaining) için bağlı liste yapısı
typedef struct Package {
    int package_id;
    char destination_city[50];
    struct Package* next; 
} Package;

// Fonksiyon prototipleri
int hash_function_B(int package_id);
void init_hash_table(Package* table[]);
void insert_package(Package* table[], int id, const char* city);
Package* search_package(Package* table[], int id);

#endif