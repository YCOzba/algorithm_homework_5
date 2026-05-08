#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "graph.h"
#include "memory_tracker.h"

int main() {
    printf("J.A.R.V.I.S. Lojistik Agi Yonetim Protokolu Baslatildi.\n");
    printf("Sistem Ayarlari: Tip B Hash, Zincirleme (Chaining), DFS Gezinme.\n\n");

    // 1. Hash Tablosunu Baslat ve 5 Veri Gir
    Package* hash_table[TABLE_SIZE];
    init_hash_table(hash_table);

    printf("--- Paket Veri Girisleri (Hash Tablosu) ---\n");
    insert_package(hash_table, 101, "Istanbul");
    insert_package(hash_table, 205, "Ankara");
    insert_package(hash_table, 312, "Izmir");
    insert_package(hash_table, 427, "Bursa"); // Olasi cakisma testi
    insert_package(hash_table, 555, "Antalya");

    // 2. Graf Yapisini Baslat ve Rota Ekle
    printf("\n--- Lojistik Rotalari Olusturuluyor (Graf) ---\n");
    Graph* city_graph = create_graph(5); // 5 Sehirli sistem
    add_edge(city_graph, 0, 1); // Istanbul -> Ankara
    add_edge(city_graph, 0, 2); // Istanbul -> Izmir
    add_edge(city_graph, 1, 3); // Ankara -> Bursa
    add_edge(city_graph, 2, 4); // Izmir -> Antalya

    // 3. Bellek Izleme Raporunu Cikar (Istenen Teknik Tablo Icin)
    generate_memory_report(hash_table, city_graph);

    // 4. DFS ile Rota Taramasi
    printf("--- Derinlemesine Rota Taramasi (DFS) ---\n");
    reset_visited(city_graph);
    DFS(city_graph, 0); // 0 numarali sehirden (Istanbul) basla

    printf("\n");
    return 0;
}


//Derleme kodu: gcc main.c hash_table.c graph.c memory_tracker.c -o LojistikSistemi

//Çalıştırma kodu: ./LojistikSistemi