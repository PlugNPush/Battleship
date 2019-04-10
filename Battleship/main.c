//
//  main.c
//  Battleship
//
//  Created by PlugN on 14/03/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Our global variables used in the entire code, way easier to manage than a main declaration + pointers
int playfield[500][500], playfield2[500][500], sizex, sizey, winningEntity;



int placeBoats(int pf, int posx, int posy, int dir, int type){
    if ((pf > 1 || pf < 0) || (dir > 1 || dir < 0) || (type > 50 || type < 20) || (posx > sizex || posx < 0) || (posy > sizey || posy < 0)){
        // Unrealistic error
        return 1;
    }
    
    // dir = 0 -> vertical | dir = 1 -> horizontal
    
    if (pf == 0){
        // Le joueur
            int a;
            int isPossible = 1;
        
        int i,s;
        
        for (i = 0; i < sizex; i++){
            for (s = 0; s < sizey; s++){
                if(playfield[i][s] == type){
                    return 3;
                }
            }
        }
        
        if (dir == 0){
            if (type / 10 % 10 + posx >= sizex){
                return 2;
            }
        } else {
            if (type / 10 % 10 + posy >= sizey){
                return 2;
            }
        }
        
            for (a = 0; a < type / 10 % 10; a++){
                if (dir == 0){
                    if (playfield[posx+a][posy] != 0) {
                        isPossible = 0;
                    }
                } else if (dir == 1){
                    if (playfield[posx][posy+a] != 0) {
                        isPossible = 0;
                    }
                }
        }
        
        if (isPossible == 0){
            return 2;
        }
        
        for (a = 0; a < type / 10 % 10; a++){
            if (dir == 0){
                playfield[posx+a][posy] = type;
                } else if (dir == 1){
                playfield[posx][posy+a] = type;
            }
        }
        return 0;
        // playfield[posx][posy] = type;
    } else if (pf == 1){
        
        int a;
        int isPossible = 1;
        int i,s;
        
        for (i = 0; i < sizex; i++){
            for (s = 0; s < sizey; s++){
                if(playfield[i][s] == type){
                    return 3;
                }
            }
        }
        
        if (dir == 0){
            if (type / 10 % 10 + posx >= sizex){
                return 4;
            }
        } else {
            if (type / 10 % 10 + posy >= sizey){
                return 4;
            }
        }
        
        for (a = 0; a < type / 10 % 10; a++){
            if (dir == 0){
                if (playfield2[posx+a][posy] != 0) {
                    isPossible = 0;
                }
            } else if (dir == 1){
                if (playfield2[posx][posy+a] != 0) {
                    isPossible = 0;
                }
            }
        }
        
        if (isPossible == 0){
            return 2;
        }
        
        for (a = 0; a < type / 10 % 10; a++){
            if (dir == 0){
                playfield2[posx+a][posy] = type;
            } else if (dir == 1){
                playfield2[posx][posy+a] = type;
            }
        }
        return 0;
    }
    
    return 0;
}

void playingShowBoards(){
    
    // We show the two boards but without the details of the enemy
    
    int i,s;
    printf("\t\t\t  YOU\t\t\t\t\t\t\t   ENEMY\n");
    for (i = 0; i < sizex; i++) {
        for (s = 0; s < sizey; s++) {
            switch (playfield[i][s]) {
                case 0:
                    printf("🌊");
                    break;
                case 20:
                    printf("🚣🏼‍♀️");
                    break;
                case 30:
                    printf("🚤");
                    break;
                case 35:
                    printf("🚤");
                    break;
                case 40:
                    printf("⛵️");
                    break;
                case 50:
                    printf("🚢");
                    break;
                case 1:
                    printf("💦");
                    break;
                case 520:
                    printf("💥");
                    break;
                case 530:
                    printf("💥");
                    break;
                case 535:
                    printf("💥");
                    break;
                case 540:
                    printf("💥");
                    break;
                case 550:
                    printf("💥");
                    break;
                case 920:
                    printf("☠️");
                    break;
                case 930:
                    printf("☠️");
                    break;
                case 935:
                    printf("☠️");
                    break;
                case 940:
                    printf("☠️");
                    break;
                case 950:
                    printf("☠️");
                    break;
                    
                default:
                    printf("🌊");
                    break;
            }
            printf(" ");
        }
        printf(" |  ");
        for (s = 0; s < sizey; s++){
                switch (playfield2[i][s]) {
                    case 0:
                        printf("🌊");
                        break;
                    case 1:
                        printf("💦");
                        break;
                    case 520:
                        printf("💥");
                        break;
                    case 530:
                        printf("💥");
                        break;
                    case 535:
                        printf("💥");
                        break;
                    case 540:
                        printf("💥");
                        break;
                    case 550:
                        printf("💥");
                        break;
                    case 920:
                        printf("☠️");
                        break;
                    case 930:
                        printf("☠️");
                        break;
                    case 935:
                        printf("☠️");
                        break;
                    case 940:
                        printf("☠️");
                        break;
                    case 950:
                        printf("☠️");
                        break;
                        
                    default:
                        printf("🌊");
                        break;
                }
            printf(" ");
            }
        printf("\n");
        }
        
    
            
    }

void finalShowBoards(){
    
    // We show the 2 boards with every details
    
    int i,s;
    printf("\t\t\t  YOU\t\t\t\t\t\t\t   ENEMY\n");
    for (i = 0; i < sizex; i++) {
        for (s = 0; s < sizey; s++) {
            switch (playfield[i][s]) {
                case 0:
                    printf("🌊");
                    break;
                case 20:
                    printf("🚣🏼‍♀️");
                    break;
                case 30:
                    printf("🚤");
                    break;
                case 35:
                    printf("🚤");
                    break;
                case 40:
                    printf("⛵️");
                    break;
                case 50:
                    printf("🚢");
                    break;
                case 1:
                    printf("💦");
                    break;
                case 520:
                    printf("💥");
                    break;
                case 530:
                    printf("💥");
                    break;
                case 535:
                    printf("💥");
                    break;
                case 540:
                    printf("💥");
                    break;
                case 550:
                    printf("💥");
                    break;
                case 920:
                    printf("☠️");
                    break;
                case 930:
                    printf("☠️");
                    break;
                case 935:
                    printf("☠️");
                    break;
                case 940:
                    printf("☠️");
                    break;
                case 950:
                    printf("☠️");
                    break;
                    
                default:
                    printf("🌊");
                    break;
            }
            printf(" ");
        }
        printf(" |  ");
        for (s = 0; s < sizey; s++){
            switch (playfield2[i][s]) {
                case 0:
                    printf("🌊");
                    break;
                case 20:
                    printf("🚣🏼‍♀️");
                    break;
                case 30:
                    printf("🚤");
                    break;
                case 35:
                    printf("🚤");
                    break;
                case 40:
                    printf("⛵️");
                    break;
                case 50:
                    printf("🚢");
                    break;
                case 1:
                    printf("💦");
                    break;
                case 520:
                    printf("💥");
                    break;
                case 530:
                    printf("💥");
                    break;
                case 535:
                    printf("💥");
                    break;
                case 540:
                    printf("💥");
                    break;
                case 550:
                    printf("💥");
                    break;
                case 920:
                    printf("☠️");
                    break;
                case 930:
                    printf("☠️");
                    break;
                case 935:
                    printf("☠️");
                    break;
                case 940:
                    printf("☠️");
                    break;
                case 950:
                    printf("☠️");
                    break;
                    
                default:
                    printf("🌊");
                    break;
            }
            printf(" ");
        }
        printf("\n");
    }
    
    
    
}




void showBoard(int pf){
    
    // Shows a board individually. You can see how the boats ID are structured.
    
    if (pf == 0){
        int i;
        int s;
        for (i = 0; i < sizex; i++) {
            for (s = 0; s < sizey; s++) {
                switch (playfield[i][s]) {
                    case 0:
                        printf("🌊");
                        break;
                    case 20:
                        printf("🚣🏼‍♀️");
                        break;
                    case 30:
                        printf("🚤");
                        break;
                    case 35:
                        printf("🚤");
                        break;
                    case 40:
                        printf("⛵️");
                        break;
                    case 50:
                        printf("🚢");
                        break;
                    case 1:
                        printf("💦");
                        break;
                    case 520:
                        printf("💥");
                        break;
                    case 530:
                        printf("💥");
                        break;
                    case 535:
                        printf("💥");
                        break;
                    case 540:
                        printf("💥");
                        break;
                    case 550:
                        printf("💥");
                        break;
                    case 920:
                        printf("☠️");
                        break;
                    case 930:
                        printf("☠️");
                        break;
                    case 935:
                        printf("☠️");
                        break;
                    case 940:
                        printf("☠️");
                        break;
                    case 950:
                        printf("☠️");
                        break;

                    default:
                        printf("🌊");
                        break;
                }
                printf(" ");
            }
            printf("\n");
        }
    } else if (pf == 1) {
        int i;
        int s;
        for (i = 0; i < sizex; i++) {
            for (s = 0; s < sizey; s++) {
                switch (playfield2[i][s]) {
                    case 0:
                        printf("🌊");
                        break;
                    case 20:
                        printf("🚣🏼‍♀️");
                        break;
                    case 30:
                        printf("🚤");
                        break;
                    case 35:
                        printf("🚤");
                        break;
                    case 40:
                        printf("⛵️");
                        break;
                    case 50:
                        printf("🚢");
                        break;
                    case 1:
                        printf("💦");
                        break;
                    case 520:
                        printf("💥");
                        break;
                    case 530:
                        printf("💥");
                        break;
                    case 535:
                        printf("💥");
                        break;
                    case 540:
                        printf("💥");
                        break;
                    case 550:
                        printf("💥");
                        break;
                    case 920:
                        printf("☠️");
                        break;
                    case 930:
                        printf("☠️");
                        break;
                    case 935:
                        printf("☠️");
                        break;
                    case 940:
                        printf("☠️");
                        break;
                    case 950:
                        printf("☠️");
                        break;
                        
                    default:
                        printf("🌊");
                        break;
                }
                printf(" ");
            }
            printf("\n");
        }
    }
    
    return;
    
}


void computerPlaceBoats(){
    
    // The computer places each boats randomly
    
    srand((unsigned int)time(NULL));
    int posx;
    int posy;
    int dir;
    
    do {
        posx = rand() % sizex;
        posy= rand() % sizey;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 20) != 0);
    
    do {
        posx = rand() % sizex;
        posy= rand() % sizey;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 30) != 0);
   
    do {
        posx = rand() % sizex;
        posy= rand() % sizey;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 35) != 0);
    
    do {
        posx = rand() % sizex;
        posy= rand() % sizey;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 40) != 0);
    
    do {
        posx = rand() % sizex;
        posy= rand() % sizey;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 50) != 0);
    
}




void playerPlaceBoats(){
    
    // In this function, we call the placeBoats function for each boats the player wants to place, with the support of the error return codes
    
    printf("Welcome! The computer is ready. It is time for you to place your boats! Here is your playing field:\n");
    showBoard(0);
    printf("\n");
    int posx, posy, dir, result;
    
    printf("You are about to place a canoe : 🚣🏼‍♀️🚣🏼‍♀️\n");
    do {
        printf("Please enter start position x (line) [0-%d]: ", sizex-1);
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-%d]: ", sizey-1);
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 20);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to %dx%d)\n", sizex, sizey);
                break;
            case 2:
                printf("Impossible to proceed. There is already a boat on your boat's path.\n");
                break;
            case 3:
                printf("Unexpected error: a boat of same type is already placed on the playing field. Skipping.\n");
                break;
            case 4:
                printf("Impossible to proceed. Your boat path is outbound the playing field!\n");
                break;
                
            default:
                printf("Unknown error.\n");
                break;
        }
        if (result == 3){
            break;
        }
    } while (result != 0);
    
    showBoard(0);
    printf("\n");
    printf("You are about to place an outboard : 🚤 🚤 🚤\n");
    do {
        printf("Please enter start position x (line) [0-%d]: ", sizex-1);
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-%d]: ", sizey-1);
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 30);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to %dx%d)\n", sizex, sizey);
                break;
            case 2:
                printf("Impossible to proceed. There is already a boat on your boat's path.\n");
                break;
            case 3:
                printf("Unexpected error: a boat of same type is already placed on the playing field. Skipping.\n");
                break;
            case 4:
                printf("Impossible to proceed. Your boat path is outbound the playing field!\n");
                break;
                
            default:
                printf("Unknown error.\n");
                break;
        }
        if (result == 3){
            break;
        }
    } while (result != 0);
    
    showBoard(0);
    printf("\n");
    printf("You are about to place another outboard : 🚤 🚤 🚤\n");
    do {
        printf("Please enter start position x (line) [0-%d]: ", sizex-1);
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-%d]: ", sizey-1);
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 35);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to %dx%d)\n", sizex, sizey);
                break;
            case 2:
                printf("Impossible to proceed. There is already a boat on your boat's path.\n");
                break;
            case 3:
                printf("Unexpected error: a boat of same type is already placed on the playing field. Skipping.\n");
                break;
            case 4:
                printf("Impossible to proceed. Your boat path is outbound the playing field!\n");
                break;
                
            default:
                printf("Unknown error.\n");
                break;
        }
        if (result == 3){
            break;
        }
    } while (result != 0);
    
    showBoard(0);
    printf("\n");
    
    printf("You are about to place a sailing ship : ⛵️\n");
    do {
        printf("Please enter start position x (line) [0-%d]: ", sizex-1);
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-%d]: ", sizey-1);
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 40);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to %dx%d)\n", sizex, sizey);
                break;
            case 2:
                printf("Impossible to proceed. There is already a boat on your boat's path.\n");
                break;
            case 3:
                printf("Unexpected error: a boat of same type is already placed on the playing field. Skipping.\n");
                break;
            case 4:
                printf("Impossible to proceed. Your boat path is outbound the playing field!\n");
                break;
                
            default:
                printf("Unknown error.\n");
                break;
        }
        if (result == 3){
            break;
        }
    } while (result != 0);
    
    showBoard(0);
    printf("\n");
    
    printf("You are about to place a cargo : 🚢\n");
    do {
        printf("Please enter start position x (line) [0-%d]: ", sizex-1);
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-%d]: ", sizey-1);
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 50);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to %dx%d)\n", sizex, sizey);
                break;
            case 2:
                printf("Impossible to proceed. There is already a boat on your boat's path.\n");
                break;
            case 3:
                printf("Unexpected error: a boat of same type is already placed on the playing field. Skipping.\n");
                break;
            case 4:
                printf("Impossible to proceed. Your boat path is outbound the playing field!\n");
                break;
                
            default:
                printf("Unknown error.\n");
                break;
        }
        if (result == 3){
            break;
        }
    } while (result != 0);
    
    
}

void backup(int whosturn){
    
    // We backup everything, with the turn as argument
    
    FILE *fieldx = fopen("/Users/plugn/Desktop/Battleship/fieldx.data", "w");
    fprintf(fieldx, "%d", sizex);
    fclose(fieldx);
    
    FILE *fieldy = fopen("/Users/plugn/Desktop/Battleship/fieldy.data", "w");
    fprintf(fieldy, "%d", sizey);
    fclose(fieldy);
    
    FILE *f = fopen("/Users/plugn/Desktop/Battleship/playfield2.data", "w");
    
    int m,n;
    for (m = 0; m < sizex; m++) {
        for (n = 0; n < sizey; n++) {
            fprintf(f, "%d\n", playfield2[m][n]);
        }
    }
    fclose(f);
    
    FILE *g = fopen("/Users/plugn/Desktop/Battleship/playfield.data", "w");
    
    for (m = 0; m < sizex; m++) {
        for (n = 0; n < sizey; n++) {
            fprintf(g, "%d\n", playfield[m][n]);
        }
    }
    fclose(g);
    
    FILE *restore = fopen("/Users/plugn/Desktop/Battleship/restore.data", "w");
    fprintf(restore, "1");
    fclose(restore);
    
        // argument needed !!!
    FILE *turn = fopen("/Users/plugn/Desktop/Battleship/turn.data", "w");
    fprintf(turn, "%d", whosturn);
    fclose(turn);
    
    return;
}

void deleteBackup(){
    
    FILE *restore = fopen("/Users/plugn/Desktop/Battleship/restore.data", "w");
    fprintf(restore, "0");
    fclose(restore);
 
    return;
}

int isDead(int pf){
    
    // We check if all the boats ID are 9ID, which means all are dead so the game is over
    
    if (pf == 0){
        int deadBoat1 = 0;
        int deadBoat2 = 0;
        int deadBoat3 = 0;
        int deadBoat4 = 0;
        int deadBoat5 = 0;
        int i,s;
        
        for (i = 0; i < sizex; i++){
            for (s = 0; s < sizey; s++){
                if(playfield[i][s] == 920){
                    deadBoat1 = 1;
                }
                else if(playfield[i][s] == 930){
                    deadBoat2 = 1;
                }
                else if(playfield[i][s] == 935){
                    deadBoat3 = 1;
                }
                else if(playfield[i][s] == 940){
                    deadBoat4 = 1;
                }
                else if(playfield[i][s] == 950){
                    deadBoat5 = 1;
                }
            }
        }
        
        if (deadBoat1 == 1 && deadBoat2 == 1 && deadBoat3 == 1 && deadBoat4 == 1 && deadBoat5 == 1){
            return 1;
        } else {
            return 0;
        }
        
    } else {
        int deadBoat1 = 0;
        int deadBoat2 = 0;
        int deadBoat3 = 0;
        int deadBoat4 = 0;
        int deadBoat5 = 0;
        int i,s;
        
        for (i = 0; i < sizex; i++){
            for (s = 0; s < sizey; s++){
                if(playfield2[i][s] == 920){
                    deadBoat1 = 1;
                }
                else if(playfield2[i][s] == 930){
                    deadBoat2 = 1;
                }
                else if(playfield2[i][s] == 935){
                    deadBoat3 = 1;
                }
                else if(playfield2[i][s] == 940){
                    deadBoat4 = 1;
                }
                else if(playfield2[i][s] == 950){
                    deadBoat5 = 1;
                }
            }
        }
        
        if (deadBoat1 == 1 && deadBoat2 == 1 && deadBoat3 == 1 && deadBoat4 == 1 && deadBoat5 == 1){
            return 1;
        } else {
            return 0;
        }
        
    }
}

void convertToDeath(int pf){
    
    // We convert all the 5ID to 9ID when there is no ID left using an ID counter (cf. Boat ID structure)
    
    if (pf == 0){
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int count4 = 0;
        int count5 = 0;
        
        int i,s;
        for (i = 0; i < sizex; i++){
            for (s = 0; s < sizey; s++){
                if (playfield[i][s] == 520){
                    count1++;
                }
                if (playfield[i][s] == 530){
                    count2++;
                }
                if (playfield[i][s] == 535){
                    count3++;
                }
                if (playfield[i][s] == 540){
                    count4++;
                }
                if (playfield[i][s] == 550){
                    count5++;
                }
            }
        }
        
        if (count1 == 2){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield[i][s] == 520){
                        playfield[i][s] = 920;
                    }
                }
            }
        }
        
        if (count2 == 3){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield[i][s] == 530){
                        playfield[i][s] = 930;
                    }
                }
            }
        }
        
        if (count3 == 3){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield[i][s] == 535){
                        playfield[i][s] = 935;
                    }
                }
            }
        }
        
        if (count4 == 4){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield[i][s] == 540){
                        playfield[i][s] = 940;
                    }
                }
            }
        }
        
        if (count5 == 5){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield[i][s] == 550){
                        playfield[i][s] = 950;
                    }
                }
            }
        }
        
    } else {
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int count4 = 0;
        int count5 = 0;
        
        int i,s;
        for (i = 0; i < sizex; i++){
            for (s = 0; s < sizey; s++){
                if (playfield2[i][s] == 520){
                    count1++;
                }
                if (playfield2[i][s] == 530){
                    count2++;
                }
                if (playfield2[i][s] == 535){
                    count3++;
                }
                if (playfield2[i][s] == 540){
                    count4++;
                }
                if (playfield2[i][s] == 550){
                    count5++;
                }
            }
        }
        
        if (count1 == 2){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield2[i][s] == 520){
                        playfield2[i][s] = 920;
                    }
                }
            }
        }
        
        if (count2 == 3){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield2[i][s] == 530){
                        playfield2[i][s] = 930;
                    }
                }
            }
        }
        
        if (count3 == 3){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield2[i][s] == 535){
                        playfield2[i][s] = 935;
                    }
                }
            }
        }
        
        if (count4 == 4){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield2[i][s] == 540){
                        playfield2[i][s] = 940;
                    }
                }
            }
        }
        
        if (count5 == 5){
            for (i = 0; i < sizex; i++){
                for (s = 0; s < sizey; s++){
                    if (playfield2[i][s] == 550){
                        playfield2[i][s] = 950;
                    }
                }
            }
        }
        
    }
}

int shoot(int pf, int posx, int posy){
    
    // We convert the ID to 5ID to inform it is hit, or to 1 if it is the sea.
    
    if (pf == 0){
        if (playfield[posx][posy] == 20) {
            playfield[posx][posy] = 520;
            return 1;
        }
        else if (playfield[posx][posy] == 30) {
            playfield[posx][posy] = 530;
            return 1;
        }
        else if (playfield[posx][posy] == 35) {
            playfield[posx][posy] = 535;
            return 1;
        }
        else if (playfield[posx][posy] == 40) {
            playfield[posx][posy] = 540;
            return 1;
        }
        else if (playfield[posx][posy] == 50) {
            playfield[posx][posy] = 550;
            return 1;
        } else {
            playfield[posx][posy] = 1;
            return 0;
        }
    } else {
        if (playfield2[posx][posy] == 20) {
            playfield2[posx][posy] = 520;
            return 1;
        }
        else if (playfield2[posx][posy] == 30) {
            playfield2[posx][posy] = 530;
            return 1;
        }
        else if (playfield2[posx][posy] == 35) {
            playfield2[posx][posy] = 535;
            return 1;
        }
        else if (playfield2[posx][posy] == 40) {
            playfield2[posx][posy] = 540;
            return 1;
        }
        else if (playfield2[posx][posy] == 50) {
            playfield2[posx][posy] = 550;
            return 1;
        } else {
            playfield2[posx][posy] = 1;
            return 0;
        }
    }
    
    return 5;
}

int gameStarted(int turn){
        // This is the core center for the game and it will retrun the winner
    
    printf("\n");
    playingShowBoards();
    
    int posx, posy;
    
    if (turn == 0){
        int won;
        printf("It is your turn to fire!\n");
        printf("Please enter position x (line) [0-%d]: ", sizex-1);
        scanf("%d.1s", &posx);
        printf("Please enter position y (column) [0-%d]: ", sizey-1);
        scanf("%d.1s", &posy);
        
        while (posx < 0 || posx >= sizex || posy < 0 || posy >= sizey) {
            printf("Please enter reasonable values!\n");
            printf("Please enter position x (line) [0-%d]: ", sizex-1);
            scanf("%d.1s", &posx);
            printf("Please enter position y (column) [0-%d]: ", sizey-1);
            scanf("%d.1s", &posy);
        }
        
        if (playfield2[posx][posy] == 1 || playfield2[posx][posy] == 520 || playfield2[posx][posy] == 530 || playfield2[posx][posy] == 535 || playfield2[posx][posy] == 540 || playfield2[posx][posy] == 550 || playfield2[posx][posy] == 920 || playfield2[posx][posy] == 930 || playfield2[posx][posy] == 935 || playfield2[posx][posy] == 940 || playfield2[posx][posy] == 950){
            printf("You already shoot there!\n");
            gameStarted(turn);
        }
        int result = shoot(1, posx, posy);
        if (result == 1){
            // Hit
            printf("You hit a boat!\n");
            
            // There is a process to convert the shot boats to dead boats (5ID -> 9ID)
            convertToDeath(1);
            // We check if all the boats are dead
            won = isDead(1);
            if (won == 1){
                winningEntity = turn;
                return turn;
            }
            
            // We backup the state of the game and recall the same function with the same turn if a boat is hit
            backup(turn);
            gameStarted(turn);
        }
        
        // And we do the same if the boat was not hit, just in case of a malfunction, and we recall the function with the computers turn
        convertToDeath(1);
        won = isDead(1);
        if (won == 1){
            winningEntity = turn;
            return turn;
        }
        backup(turn);
        gameStarted(1);
        
    } else {
        printf("\n The computer has played!\n");
        int won;
        srand((unsigned int)time(NULL));
        posx = rand() % sizex;
        posy = rand() % sizey;
        if (playfield[posx][posy] == 1 || playfield[posx][posy] == 520 || playfield[posx][posy] == 530 || playfield[posx][posy] == 535 || playfield2[posx][posy] == 540 || playfield2[posx][posy] == 550 || playfield2[posx][posy] == 920 || playfield2[posx][posy] == 930 || playfield[posx][posy] == 935 || playfield[posx][posy] == 940 || playfield[posx][posy] == 950){
            gameStarted(turn);
        }
        int result = shoot(0, posx, posy);
        if (result == 1){
            convertToDeath(1);
            won = isDead(1);
            if (won == 1){
                return turn;
            }
            
            backup(turn);
            gameStarted(turn);
        }
        
        convertToDeath(0);
        won = isDead(0);
        if (won == 1){
            return turn;
        }
        backup(turn);
        gameStarted(0);
    }
    
    // This is the last step of the function. As it is recalled multiple times, we decided to use a global variable that will save the winning entity to safely return the winner
    return winningEntity;
}

void winner(int turn){
    int result;
    // This is the longest step of the program, the gameStarted function returns the winner.
    result = gameStarted(turn);
    
    // At this point, the game is over, we backup everything and then unsign it
    backup(result);
    deleteBackup();
    printf("\n\n");
    
    // Show the final boards and announce the winner:
    finalShowBoards();
    if (result == 0){
        printf("\n🎉 Congratulations! You won the game!\n");
    } else if (result == 1){
        printf("😕 Oh no... The computer won the game this time... You'll do better next time!\n");
    } else {
        printf("An internal error occured. We are sorry to say that there is no clear winner because something wrong happened.\n");
    }
}

void game(){
    
    // Game configuration process
    
    // Set the size first
    
    printf("Select the number of lines (x-axis) [LIMITED TO 500]: ");
    scanf("%d", &sizex);
    printf("Select the number of columns (y-axis) [LIMITED TO 500]: ");
    scanf("%d", &sizey);
    
    while (sizex > 500 || sizex < 0 || sizey > 500 || sizey < 0) {
        printf("Please enter reasonable values.\n");
        printf("Select the number of lines (x-axis) [LIMITED TO 500]: ");
        scanf("%d", &sizex);
        printf("Select the number of columns (y-axis) [LIMITED TO 500]: ");
        scanf("%d", &sizey);
    }
    
        // Initiate the playfields
    int i, s;
    
        // Playfield for the player
    for (i = 0; i < sizex; i++){
        for (s = 0; s < sizey; s++){
            playfield[i][s] = 0;
        }
    }
    
        // Playfield for the computer
    for (i = 0; i < sizex; i++){
        for (s = 0; s < sizey; s++){
            playfield2[i][s] = 0;
        }
    }
    
        // Place the boats
    computerPlaceBoats();
    
    // DEV MODE -- REMOVE FOR THE PRODUCTION VERSION
    showBoard(1);
    
    printf("\n\n");
    
    playerPlaceBoats();
    
    
    // Who is going to fire first?
    srand((unsigned int)time(NULL));
    int turn;
    turn = rand() % 2;
    
    // Now that the game is set, we backup everything so it can be restored at this point
    backup(turn);
    
    // The game starts
    winner(turn);
    return;
}

void restore(){
    
        // If restore.data = 1 then do this, otherwise, return the random funciton
    
    FILE *r = fopen("/Users/plugn/Desktop/Battleship/restore.data", "r");
    int restore;
    fscanf(r, "%d", &restore);
    
    // This file is crucial because it tells if the backup is valid
    
    if (restore == 0){
        // No valid backup
        // Run the game configuration process
        game();
        return;
    } else {
        printf("Backup found, do you want to restore it? (0 = no, [1 = yes]): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 0){
            // The backup is marked as non-valid, in order to not confuse the user if he restarts the program with the same backup
            deleteBackup();
            game();
            return;
        }
    }
    
    // We restore everything back in the variables, starting with the size of the field
    // We could use a single file for everything, but in order to avoid confusion, we decided to split the files
    
    FILE *fieldx = fopen("/Users/plugn/Desktop/Battleship/fieldx.data", "r");
    fscanf(fieldx, "%d", &sizex);
    fclose(fieldx);
    
    FILE *fieldy = fopen("/Users/plugn/Desktop/Battleship/fieldy.data", "r");
    fscanf(fieldy, "%d", &sizey);
    fclose(fieldy);
    
    FILE *g = fopen("/Users/plugn/Desktop/Battleship/playfield.data", "r");
    int x,y;
    for (x = 0; x < sizex; x++) {
        for (y = 0; y < sizey; y++) {
            fscanf(g, "%d", &playfield[x][y]);
        }
    }
    
    fclose(g);
    
    FILE *f = fopen("/Users/plugn/Desktop/Battleship/playfield2.data", "r");
    for (x = 0; x < sizex; x++) {
        for (y = 0; y < sizey; y++) {
            fscanf(f, "%d", &playfield2[x][y]);
        }
    }
    
    fclose(f);
    
    FILE *h = fopen("/Users/plugn/Desktop/Battleship/turn.data", "r");
    int turn;
    fscanf(h, "%d", &turn);
    
    fclose(h);
    
    // This function starts officially the game
    winner(turn);
}


void mainmenu(){
    
        // Create a main menu
    
    // The function restore will check if a backup is still valid to be restored
    restore();
    return;
}









int main(int argc, const char * argv[]) {
    
    // Calling the main menu
    mainmenu();
    
    
    return 0;
    
    
}



