//
//  main.c
//  kral_sachovnice
//
/*
 Ze souboru sachovnice.txt načtěte popis šachovnice a určete pro ni délku nejkratší cesty králem. Výsledek vypište na standardní výstup (terminál). Šachovnice je popsána tak, že na prvních dvou řádcích jsou kladná celá čísla x a y určující počet řádků, resp. sloupců šachovnice. Následuje x řádků o y znacích. Každý znak je:

 tečka, což značí pole, na které smíme vstoupit,
 X (velké), což znační zakázané pole,
 S (taktéž velké), startovní pole,
 C (opět velké), cílové pole.
 Pokud příslušná cesta neexistuje, vypište -1.

 Příklad:
 vstup:
 4
 4
 X.XS
 .X.X
 .XXX
 ..C.
 výstup:
 6
 */
//  Created by Natálie Smolíková on 18.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

FILE* soubor;

int dejcislo()
{
    int cislo = 0, vstup;
    vstup = fgetc(soubor);
    
    while(vstup >= 48 && vstup <=57)
    {
        cislo = 10* cislo + vstup -48;
       vstup = fgetc(soubor);
    }
    return cislo;
}

int dejznak()
{
    int znak, vstup;
    vstup = fgetc(soubor);
    // . = 46==-54, C = 67 == -33, S = 83, X = 88==-12
    while ((vstup != 46) && (vstup != 67) && (vstup != 83) && (vstup != 88))
    {
        vstup = fgetc(soubor);
    }
    if ((vstup == 46) || (vstup == 67) || (vstup == 83) || (vstup == 88))
    {
        znak = vstup-100;
    }
    return znak;
}
int najdi(int *pole, int len, int co){
    for (int m = 0; m <= len; m++)
    {
        if (pole[m] == co)
            return m;
    }
    return 0;
}
int oznac_sousedy(int *pole, int col, int stred) // volat s col = y+2
//ocisluje tecky na nasledujici hodnotu, nakonec zmeni stred na H
{
    int hod = pole[stred];
    for(int p = (stred-1); p <= (stred+1); p ++)
    {
        for(int q = -1; q <= 1; q++)
        {
            if (pole[p+q*col] == -54)
                pole[p+q*col] = hod + 1;
            if (pole [p+q*col] == -33)
            {
                pole[stred] = -20; //H = -20
                return hod + 1;
            }
        }
    }
    pole[stred] = -20; //po nalezeni sousedu oznacime pole za hotove
    return 1;
}



int main() {
    int x, y;
    int s, c;
    int *board;
    int pom = 1;
    
    soubor = fopen("sachovnice.txt", "r");
    x = dejcislo();
    y = dejcislo();

    board = malloc(sizeof(int)*(x+2)*(y+2));
    int len = (x+2)*(y+2);
    
    for (int i = 0; i <= x+1; i++)
    {
        for (int j = 0; j <= y+1; j++)
        {
            if ((i==0) || ( i == x+1) || (j == 0) || (j == y+1))
                board[i * (y + 2) + j] = -12;
            else
            { board[i * (y + 2) + j] = dejznak();
            if (board[i * (y + 2) + j] == -17) //S
            {
                s =  i * (y + 2) + j;
            }
            if (board[i * (y + 2) + j] == -33) //C
            {
                c = i * (y + 2) + j;
            }
            }
        }
    }

    int now = najdi(board, len, -17), navrat;
    fclose(soubor);
    int barva = 100;
    board[now] = barva;
 
  while(pom)
    {
        pom = 0;
        while((now = najdi(board, len, barva))!= 0) //dokud jsou v poli prvky s barvou
        {
            if ((navrat = oznac_sousedy(board, y+2, now)) == 1) //hledej jejich sousedy
                pom++; //pokud ma nejaky z prvku jeste souseda, pom nebude 0
            else
                pom = 0;
        }
        barva++;
    }
    if (navrat==1) navrat = 99;
        
    printf("%d\n", navrat-100);
    
  
    return 0;
}
