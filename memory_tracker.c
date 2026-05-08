#include <stdio.h>
#include "memory_tracker.h"

void generate_memory_report(Package* table[], Graph* graph) {
    printf("\n======================================================\n");
    printf("              BELLEK IZLEME RAPORU (RAM)              \n");
    printf("======================================================\n");
    
    printf("\n--- HASH TABLOSU (Zincirleme Baglanti Adresleri) ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index [%d] Ana Adres: %p\n", i, (void*)&table[i]);
        Package* temp = table[i];
        while (temp != NULL) {
            printf("    -> Paket ID: %d [Kendi Adresi: %p | Sonraki Pointer: %p]\n", 
                   temp->package_id, (void*)temp, (void*)temp->next);
            temp = temp->next;
        }
    }

    printf("\n--- GRAF YAPISI (Dugum Adresleri) ---\n");
    printf("Graf Ana Yapi Adresi: %p\n", (void*)graph);
    for (int i = 0; i < graph->num_vertices; i++) {
        if(graph->adjacency_list[i] != NULL) {
            printf("Sehir %d Komsuluk Listesi Basi -> Adres: %p\n", i, (void*)graph->adjacency_list[i]);
        }
    }
    printf("======================================================\n\n");
}