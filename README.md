# Lojistik Ağı Yönetim ve Paket İndeksleme Sistemi

Bu proje, bir lojistik firmasının şehirler arası bağlantılarını ve paket bilgilerini yönetmek amacıyla geliştirilmiş hibrit bir veri yapısı sistemidir. C programlama dili ile mantıksal katmanlara ayrılarak (multi-file) tasarlanmıştır.

## 🚀 Proje Mimarisi
Sistem, istenen algoritmik gereksinimler doğrultusunda şu teknikleri kullanmaktadır:
* **Hash Fonksiyonu:** Tip B (Modüler Aritmetik tabanlı)
* **Çakışma (Collision) Çözümü:** Zincirleme (Chaining / Linked List)
* **Graf Gezinme Algoritması:** DFS (Depth-First Search)

## 📂 Dosya Yapısı
* `main.c`: Sistem kontrol merkezi ve entegrasyon noktası.
* `hash_table.c` / `.h`: Paketlerin indekslenmesi ve zincirleme çakışma çözümü.
* `graph.c` / `.h`: Şehirler arası lojistik rotalarının Graf (Adjacency List) ile yönetimi.
* `memory_tracker.c` / `.h`: RAM üzerindeki bellek adreslerinin (`0x...`) ve pointer ilişkilerinin dinamik haritalanması.

## 🛠️ Kurulum ve Çalıştırma
Projeyi derlemek için terminal veya komut satırında tüm `.c` dosyalarını dahil etmelisiniz:
```bash
gcc main.c hash_table.c graph.c memory_tracker.c -o LojistikSistemi
./LojistikSistemi
