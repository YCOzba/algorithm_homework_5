#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

// Tip B Hash Fonksiyonu: Tek numaralar için modüler aritmetik
int hash_function_B(int package_id) {
    return (package_id * 31) % TABLE_SIZE;
}

void init_hash_table(Package* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

// Zincirleme (Chaining) yöntemi ile çakışma çözümü
void insert_package(Package* table[], int id, const char* city) {
    int index = hash_function_B(id);
    
    Package* new_package = (Package*)malloc(sizeof(Package));
    new_package->package_id = id;
    strcpy(new_package->destination_city, city);
    new_package->next = NULL;

    // Listenin başına ekleme (O(1) karmaşıklığı)
    if (table[index] == NULL) {
        table[index] = new_package;
    } else {
        new_package->next = table[index];
        table[index] = new_package;
    }
    printf("Sistem Log: Paket ID %d, '%s' sehrine %d indeksine eklendi.\n", id, city, index);
}

Package* search_package(Package* table[], int id) {
    int index = hash_function_B(id);
    Package* temp = table[index];
    
    while (temp != NULL) {
        if (temp->package_id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}