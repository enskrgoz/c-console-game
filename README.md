# Konsol Hayatta Kalma Oyunu

> **C dili** ile yazılmış, terminal tabanlı gerçek zamanlı bir hayatta kalma oyunu. Algoritmalar & Programlama dersi final projesi olarak geliştirilmiştir.

---

 Hakkında

**Oyun**, Duvarlardan rastgele düşman çıkar ve sen bu düşmalardan kaçdıkça puan kazanırsın. Eğer düşman seni yakalarsa canın bir azalır ve başlangıç konumumna dönersin. Can sayın bittiğinde oyun da biter. Oyunda 3 tane bonus vardır bu bonusların ustune geldıgınde bonusları kullanmış olursun. Düşmanlar ve Bonuslar rastgele doğmaktadırlar. Düşmanlar tek yönlü ilerleme sağlarken bonuslar sabit kalırlar.

---

Nasıl Oynanır

Sen **`@`** karakterisin. Duvarlardan rastgele doğan **`X`** düşmanlarından kaç, bonus topla, puanını artır. Tüm canların bitene kadar oyun devam eder.

### Kontroller

| Tuş | Hareket |
|-----|---------|
| `W` | Yukarı |
| `S` | Aşağı |
| `A` | Sola |
| `D` | Sağa |
| `ESC` | Oyundan Çık |

---

## Özellikler

- **Gerçek zamanlı hareket** — 80ms oyun döngüsü ile akıcı WASD kontrolleri
- **Dinamik zorluk** — 10 seviye; puan arttıkça düşmanlar hızlanır ve daha sık doğar
- **Dokunulmazlık süresi** — Hasar aldıktan sonra kısa süreli koruma
- **Görsel efektler** — Hasar alınca ekran kırmızı, bonus alınca yeşil yanıp söner
- **Puan sistemi** — Zaman geçtikçe, düşman öldürünce ve bonus toplayınca puan kazanırsın
- **Canlı HUD** — Puan, can, kill sayısı ve seviye ekranda sürekli görünür

---

## Bonuslar

Bonuslar oyun alanında rastgele belirir ve belirli süre içinde toplanmazsa kaybolur.

| Sembol | Ad | Efekt |
|--------|----|-------|
| `K` | Kill Bonusu | Ekrandaki **tüm düşmanları** anında yok eder |
| `P` | Puan Bonusu | **+100 puan** kazandırır |
| `C` | Can Bonusu | **+1 ekstra can** kazandırır |

---

## Puan Sistemi

| Kaynak | Puan |
|--------|------|
| Hayatta kalma süresi | Her 2 tick'te +1 |
| Düşman öldürme | +3 puan |
| Puan bonusu (`P`) | +100 puan |

---

## Zorluk Skalası

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


## 🎓 Akademik Bağlam

Bu proje, **Algoritmalar & Programlama** dersinin final ödevi olarak hazırlanmıştır.  
Diziler, oyun döngüsü, çarpışma mantığı, dinamik zorluk skalası ve C dilinde gerçek zamanlı G/Ç konularını uygulamalı olarak kapsamaktadır. Word dosyasında kodun detaylı açıklamaları parçalar halinde yapılmıştır.(Dosya en altta eklenmiştir.)

---

## 👤 Geliştirici

> *ENES KARAGÖZ (AlGORİTMA VE PROGRAMLAYA GİRİŞ FİNAL PROJESİ)*

---
## 👤 OYUNDAN GÖRÜNTÜLER:

<img width="550" height="582" alt="Ekran görüntüsü 2025-12-20 133441" src="https://github.com/user-attachments/assets/f6221df4-7602-41d7-9852-95e2632fc1e2" />


<img width="567" height="592" alt="Ekran görüntüsü 2025-12-20 133422" src="https://github.com/user-attachments/assets/833c4cf0-ff71-47d6-8e04-8de31acce970" />


<img width="606" height="587" alt="Ekran görüntüsü 2025-12-20 133344" src="https://github.com/user-attachments/assets/14eab012-458d-499e-ab65-b4707f1ee1bc" />


<img width="570" height="252" alt="Ekran görüntüsü 2025-12-20 133555" src="https://github.com/user-attachments/assets/d1091fa8-ab72-4931-a00b-f02f7838504b" />




## Word dosyası : [Algo_Oyun_C.docx](https://github.com/user-attachments/files/26252519/Algo_Oyun_C.docx)

