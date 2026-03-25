# 🎮 AlgoritmaOyun — Konsol Hayatta Kalma Oyunu

> **C dili** ile yazılmış, terminal tabanlı gerçek zamanlı bir hayatta kalma oyunu. Algoritmalar & Programlama dersi final projesi olarak geliştirilmiştir.

---

## 📖 Hakkında

**Oyun**, dört duvardan içeri sızan düşmanlardan kaçarak, bonus toplayarak ve mümkün olduğunca uzun süre hayatta kalmaya çalıştığın bir konsol oyunudur. Puanın arttıkça düşmanlar hızlanır ve daha sık doğar — ne kadar dayanabilirsin?

---

## 🕹️ Nasıl Oynanır

Sen **`@`** karakterisin. Dört bir yandan gelen **`X`** düşmanlarından kaç, bonus topla, puanını artır. Tüm canların bitene kadar oyun devam eder.

### Kontroller

| Tuş | Hareket |
|-----|---------|
| `W` | Yukarı |
| `S` | Aşağı |
| `A` | Sola |
| `D` | Sağa |
| `ESC` | Oyundan Çık |

---

## ⭐ Özellikler

- **Gerçek zamanlı hareket** — 80ms oyun döngüsü ile akıcı WASD kontrolleri
- **Dinamik zorluk** — 10 seviye; puan arttıkça düşmanlar hızlanır ve daha sık doğar
- **Dokunulmazlık süresi** — Hasar aldıktan sonra kısa süreli koruma
- **Görsel efektler** — Hasar alınca ekran kırmızı, bonus alınca yeşil yanıp söner
- **Puan sistemi** — Zaman geçtikçe, düşman öldürünce ve bonus toplayınca puan kazanırsın
- **Canlı HUD** — Puan, can, kill sayısı ve seviye ekranda sürekli görünür

---

## 💎 Bonuslar

Bonuslar oyun alanında rastgele belirir ve belirli süre içinde toplanmazsa kaybolur.

| Sembol | Ad | Efekt |
|--------|----|-------|
| `K` | Kill Bonusu | Ekrandaki **tüm düşmanları** anında yok eder |
| `P` | Puan Bonusu | **+100 puan** kazandırır |
| `C` | Can Bonusu | **+1 ekstra can** kazandırır |

---

## 📊 Puan Sistemi

| Kaynak | Puan |
|--------|------|
| Hayatta kalma süresi | Her 2 tick'te +1 |
| Düşman öldürme | +3 puan |
| Puan bonusu (`P`) | +100 puan |

---

## ⚙️ Zorluk Skalası

| Seviye | Düşman Doğma Hızı | Düşman Hızı |
|--------|-------------------|-------------|
| 1–3    | Normal            | ×1 |
| 4–7    | Hızlı             | ×2 |
| 8–10   | Maksimum          | ×3 |

> Seviye, puandan otomatik hesaplanır: `seviye = puan / 100 + 1`

---

## 🛠️ Derleme ve Çalıştırma

### Gereksinimler

- Windows işletim sistemi (`windows.h`, `conio.h` kullanılıyor)
- GCC veya herhangi bir standart C derleyicisi (MinGW önerilir)

### Derleme

```bash
gcc -o oyun oyun.c
```

### Çalıştırma

```bash
oyun.exe
```

Ya da derlenmiş `.exe` dosyasına çift tıklayarak başlatabilirsin.

---

## 🧠 Teknik Detaylar

| Sabit | Değer | Açıklama |
|-------|-------|----------|
| `W` / `H` | 20 × 20 | Oyun alanı boyutları |
| `MAX_DUSMAN` | 30 | Aynı anda maksimum düşman sayısı |
| `MAX_BONUS` | 4 | Aynı anda maksimum bonus sayısı |
| `CAN_HAKKI` | 3 | Başlangıç can sayısı |
| `DOKUNUMAZ_SURE` | 12 tick | Hasar sonrası dokunulmazlık süresi |
| `BONUS_SURE` | 18 tick | Mesajların ekranda kalma süresi |

### Temel Sistemler

- **Oyun Döngüsü** — `Sleep(80)` ile 80ms tick, `_kbhit()` ile non-blocking giriş
- **Düşman Doğurma** — Düşmanlar rastgele kenardan doğar, yön vektörüyle ilerler
- **Çarpışma Tespiti** — Her tick'te oyuncu ile tüm aktif nesneler karşılaştırılır
- **Efekt Sistemi** — `SetConsoleTextAttribute` ile zamanlı ekran rengi değişimi

---

## 🎓 Akademik Bağlam

Bu proje, **Algoritmalar & Programlama** dersinin final ödevi olarak hazırlanmıştır.  
Diziler, oyun döngüsü, çarpışma mantığı, dinamik zorluk skalası ve C dilinde gerçek zamanlı G/Ç konularını uygulamalı olarak kapsamaktadır.

---

## 👤 Geliştirici

> *ENES KARAGÖZ (AlGORİTMA VE PROGRAMLAYA GİRİŞ FİNAL PROJESİ)*

---
## 👤 OYUNDAN GÖRÜNTÜLER:



<img width="570" height="252" alt="Ekran görüntüsü 2025-1
<img width="550" height="582" alt="Ekran görüntüsü 2025-12-20 133441" src="https://github.com/user-attachments/assets/a20b4928-3276-4373-b9c6-87765e0abfcd" />
2-20 133555" src="https://github.com/user-attachments/assets/fbe40875-4baf-4ccf-a740-5508256a596a" />





## Word dosyası : 
