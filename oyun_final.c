#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define DOKUNUMAZ_SURE 12
#define W 20
#define H 20
#define MAX_DUSMAN 30
#define MAX_BONUS  4
#define KILL_PUAN 3
#define BONUS_KILL 'K'
#define BONUS_PUAN 'P'
#define BONUS_CAN  'C'
#define MSJ_KILL_BONUS   "K ALINDI -> TUM DUSMANLAR SILINDI"
#define MSJ_CAN_ARTI    "+1 CAN"
#define MSJ_PUAN_ARTI   "+100 PUAN"
#define MSJ_CAN_EKSI    "-1 CAN"
#define BONUS_SURE 18
#define DOGACAK_DUSMAN_ARALIK 13 
#define MIN_DOGACAK_DUSMAN_ARALIK 3
#define HIZ_SEVIYE_2 4
#define HIZ_SEVIYE_3 8
#define MAX_HIZ_CARPANI 3
#define BONUS_IHTIMAL_BASLANGIC 2
#define BONUS_IHTIMAL_MAX 6
#define BSLK_PUAN "Puan :"
#define BSLK_CAN "Can :"
#define BSLK_KILL "Kill :"
#define BSLK_SEVIYE "Seviye :"
#define BSLK_DKNLMZ "DOKUNULMAZ !!!!!!!"
#define CAN_HAKKI 3
#define MSJ_OYUN_SONU "OYUN SONU ! "



int i, j;
int player_y, player_x;
char player = '@';
char ktus = 0;
int can;
char yatay_duvar = '=';
char dikey_duvar = '|';
char kose_duvar  = '+';
char dusman = 'X';
int zaman = 0;
int puan = 0;
int puanBonus = 0;
int kill = 0;
int seviye = 1;
int maxSeviye = 10;
int dokunulmazSure = 0;
int efekt = 0;
int efektSure = 0;
char mesaj[64];
int mesajSure = 0;
int dusman_x[MAX_DUSMAN], dusman_y[MAX_DUSMAN];
int dusman_dx[MAX_DUSMAN], dusman_dy[MAX_DUSMAN];
int dusman_aktif[MAX_DUSMAN];
int bonus_x[MAX_BONUS], bonus_y[MAX_BONUS];
char bonus_tur[MAX_BONUS];
int bonus_aktif[MAX_BONUS];
int bonus_omur[MAX_BONUS];

void renkAyarla(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void mesajYaz(char s[], int sure){
    int k = 0;
    int uzunluk = strlen(s);

    while(k < uzunluk && k < 63){
        mesaj[k] = s[k];
        k++;
    }

    mesaj[k] = '\0';
    mesajSure = sure;
}



char rastgeleBonusTuru(){
    int r = rand() % 3;

    switch(r){
        case 0:
            return BONUS_KILL;
        case 1:
            return BONUS_PUAN;
        case 2:
            return BONUS_CAN;
    }
}


void seviyeHesapla(){
    seviye = puan / 100 + 1;
    if(seviye > maxSeviye) seviye = maxSeviye;
}

int dusmanDogmaAraligi(){
    int aralik = DOGACAK_DUSMAN_ARALIK - seviye;

    if(aralik < MIN_DOGACAK_DUSMAN_ARALIK) 
        aralik = MIN_DOGACAK_DUSMAN_ARALIK;
    return aralik;
}

int dusmanHizCarpani(){
    if(seviye >= HIZ_SEVIYE_3)
        return MAX_HIZ_CARPANI;
    else if(seviye >= HIZ_SEVIYE_2)
        return 2;
    else
        return 1;
}

int bonusIhtimalModu(){
    int mod = BONUS_IHTIMAL_BASLANGIC + seviye;

    if(mod > BONUS_IHTIMAL_MAX)
        mod = BONUS_IHTIMAL_MAX;

    return mod;
}

void dusmanDogur(){
    int slot = -1;

    for(int t = 0; t < MAX_DUSMAN; t++){
        if(!dusman_aktif[t]){
            slot = t;
            break;
        }
    }
    if(slot == -1)
        return;
    int kenar = rand() % 4;
    switch(kenar){
        case 0:
            dusman_y[slot] = 0;
            dusman_x[slot] = rand() % (W - 2);
            dusman_dx[slot] = 0;
            dusman_dy[slot] = 1;
            break;
        case 1:
            dusman_y[slot] = H - 3;
            dusman_x[slot] = rand() % (W - 2);
            dusman_dx[slot] = 0;
            dusman_dy[slot] = -1;
            break;
        case 2:
            dusman_x[slot] = 0;
            dusman_y[slot] = rand() % (H - 2);
            dusman_dx[slot] = 1;
            dusman_dy[slot] = 0;
            break;
        case 3:
            dusman_x[slot] = W - 3;
            dusman_y[slot] = rand() % (H - 2);
            dusman_dx[slot] = -1;
            dusman_dy[slot] = 0;
            break;
    }
     dusman_aktif[slot] = 1;
}


void tumDusmanlariSil(){
    int silinen = 0;
    for(int t=0; t<MAX_DUSMAN; t++){
        if(dusman_aktif[t]){ dusman_aktif[t] = 0; silinen++; }
    }
    if(silinen > 0) kill += silinen;
}

void bonusDogur(){
    int slot = -1;
    for(int t=0; t<MAX_BONUS; t++){
        if(!bonus_aktif[t]){ slot = t; break; }
    }
    if(slot == -1) return;

    int mod = bonusIhtimalModu();
    if(rand() % mod != 0) return;

    int bx = rand() % (W-2);
    int by = rand() % (H-2);

    if(bx == player_x && by == player_y) return;

    for(int d=0; d<MAX_DUSMAN; d++){
        if(dusman_aktif[d] && dusman_x[d] == bx && dusman_y[d] == by) return;
    }

    for(int b=0; b<MAX_BONUS; b++){
        if(bonus_aktif[b] && bonus_x[b] == bx && bonus_y[b] == by) return;
    }

    bonus_x[slot] = bx;
    bonus_y[slot] = by;
    bonus_tur[slot] = rastgeleBonusTuru();
    bonus_aktif[slot] = 1;
    bonus_omur[slot] = 60;
}

void bonusGuncelle(){
    for(int t=0; t<MAX_BONUS; t++){
        if(!bonus_aktif[t]) continue;

        bonus_omur[t]--;
        if(bonus_omur[t] <= 0) bonus_aktif[t] = 0;
    }
}

void bonusKontrol(){
    for(int t=0; t<MAX_BONUS; t++){
        if(!bonus_aktif[t]) continue;

        if(player_x == bonus_x[t] && player_y == bonus_y[t]){

            efekt = 2;
            efektSure = 6;

            if(bonus_tur[t] == BONUS_KILL){
                tumDusmanlariSil();
                mesajYaz(MSJ_KILL_BONUS, BONUS_SURE);
            }
            else if(bonus_tur[t] == BONUS_CAN){
                can++;
                mesajYaz(MSJ_CAN_ARTI, BONUS_SURE);
            }
            else if(bonus_tur[t] == BONUS_PUAN){
                puanBonus += 100;
                mesajYaz(MSJ_PUAN_ARTI, BONUS_SURE);
            }

            bonus_aktif[t] = 0;
        }
    }
}

void dusmanGuncelle(){
    int hiz = dusmanHizCarpani();

    for(int t=0; t<MAX_DUSMAN; t++){
        if(!dusman_aktif[t]) continue;
        
        if(dusman_dy[t] != 0){
            if(zaman % 2 == 1) continue;
        }

        for(int h=0; h<hiz; h++){
            dusman_x[t] += dusman_dx[t];
            dusman_y[t] += dusman_dy[t];

            if(dusman_x[t] < 0 || dusman_x[t] > W-3 || dusman_y[t] < 0 || dusman_y[t] > H-3){
                dusman_aktif[t] = 0;
                kill++;
                break;
            }

            if(dusman_x[t] == player_x && dusman_y[t] == player_y){

                if(dokunulmazSure == 0){
                    can--;
                    dokunulmazSure = DOKUNUMAZ_SURE;

                    efekt = 1;
                    efektSure = 10;

                    mesajYaz(MSJ_CAN_EKSI, BONUS_SURE);
                }

                dusman_aktif[t] = 0;

                player_x = (W-2)/2;
                player_y = (H-2)/2;
                break;
            }
        }
    }
}

void inputAl(){
    if(_kbhit()){
        ktus = _getch();
        if(ktus=='w'||ktus=='W') player_y--;
        if(ktus=='s'||ktus=='S') player_y++;
        if(ktus=='a'||ktus=='A') player_x--;
        if(ktus=='d'||ktus=='D') player_x++;
    }
}

void sinirKoru(){
    if(player_x < 0) player_x = 0;
    if(player_x > W-3) player_x = W-3;
    if(player_y < 0) player_y = 0;
    if(player_y > H-3) player_y = H-3;
}

void ciz(){
    system("cls");

    if(efektSure > 0){
        if(efekt == 1) renkAyarla(12);
        else if(efekt == 2) renkAyarla(10);
        efektSure--;
    } else {
        renkAyarla(7);
        efekt = 0;
    }

    printf("%s%d %s%d %s%d %s%d\n", BSLK_PUAN, puan, BSLK_CAN, can, BSLK_KILL, kill, BSLK_SEVIYE, seviye);
    if(dokunulmazSure > 0) printf("%s", BSLK_DKNLMZ);
    printf("\n\n");

    
    printf("%c", kose_duvar);
    for(i=0;i<W-2;i++) printf("%c", yatay_duvar);
    printf("%c\n", kose_duvar);

   
    for(i=0;i<H-2;i++){
        printf("%c", dikey_duvar);

        for(j=0;j<W-2;j++){
            int yazildi = 0;

    
            for(int d=0; d<MAX_DUSMAN; d++){
                if(dusman_aktif[d] && dusman_x[d]==j && dusman_y[d]==i){
                    printf("%c", dusman);
                    yazildi = 1;
                    break;
                }
            }

            if(!yazildi){
                for(int b=0; b<MAX_BONUS; b++){
                    if(bonus_aktif[b] && bonus_x[b]==j && bonus_y[b]==i){
                        printf("%c", bonus_tur[b]);
                        yazildi = 1;
                        break;
                    }
                }
            }

     
            if(!yazildi){
                if(player_x==j && player_y==i) printf("%c", player);
                else printf(" ");
            }
        }

        printf("%c\n", dikey_duvar); 
    }


    printf("%c", kose_duvar);
    for(i=0;i<W-2;i++) printf("%c", yatay_duvar);
    printf("%c\n", kose_duvar);

 
    printf("--------------------------------------------------\n");
    printf("%s%d %s%d %s%d\n", BSLK_PUAN, puan, BSLK_CAN, can, BSLK_KILL, kill);

    if(mesajSure > 0){
        printf("%s\n", mesaj);
        mesajSure--;
    } else {
        printf("\n");
    }

    renkAyarla(7);
}




void main(){
    srand(time(NULL));
    mesaj[0] = '\0';

    player_x = (W-2)/2;
    player_y = (H-2)/2;
    can = CAN_HAKKI;

    for(int t=0; t<MAX_DUSMAN; t++)
        dusman_aktif[t] = 0;
    for(int t=0; t<MAX_BONUS; t++)
        bonus_aktif[t]  = 0;

    while(can){

        puan = (zaman / 2) + puanBonus + (kill * KILL_PUAN);

        seviyeHesapla();

        if(zaman % dusmanDogmaAraligi() == 0)
            dusmanDogur();
        
        if(zaman % 10 == 0)
            bonusDogur();
   
        inputAl();
        sinirKoru();

        if(dokunulmazSure > 0)
            dokunulmazSure--;

        dusmanGuncelle();
        bonusGuncelle();
        bonusKontrol();

        ciz();

        if(ktus == 27)
            break;

        Sleep(80);
        zaman++;
    }

    system("cls");
    printf("%s %s %d %s %d \n",MSJ_OYUN_SONU,BSLK_PUAN, puan,BSLK_KILL, kill);
  
}
