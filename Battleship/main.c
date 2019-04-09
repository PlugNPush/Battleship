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

int playfield[10][10], playfield2[10][10];

int placeBoats(int pf, int posx, int posy, int dir, int type){
    if ((pf > 1 || pf < 0) || (dir > 1 || dir < 0) || (type > 50 || type < 20) || (posx > 10 || posx < 0) || (posy > 10 || posy < 0)){
        // Unrealistic error
        return 1;
    }
    
    // dir = 0 -> vertical | dir = 1 -> horizontal
    
    if (pf == 0){
        // Le joueur
            int a;
            int isPossible = 1;
        
        int i,s;
        
        for (i = 0; i < 10; i++){
            for (s = 0; s < 10; s++){
                if(playfield[i][s] == type){
                    return 3;
                }
            }
        }
        
        if (dir == 0){
            if (type / 10 % 10 + posx >= 10){
                return 2;
            }
        } else {
            if (type / 10 % 10 + posy >= 10){
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
        
        for (i = 0; i < 10; i++){
            for (s = 0; s < 10; s++){
                if(playfield[i][s] == type){
                    return 3;
                }
            }
        }
        
        if (dir == 0){
            if (type / 10 % 10 + posx >= 10){
                return 4;
            }
        } else {
            if (type / 10 % 10 + posy >= 10){
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
    int i,s;
    printf("\t\t\t  YOU\t\t\t\t\t\t\t   ENEMY\n");
    for (i = 0; i < 10; i++) {
        for (s = 0; s < 10; s++) {
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
                case (500 / 100 % 100):
                        // On va changer ça et mettre 520, 530, 535, 540 et 550 pour savoir si le bateau est coulé en interne
                        // On mettra pour le display case 500 / 100 % 100
                    printf("💥");
                    break;
                case (900 / 100 % 100):
                    printf("☠️");
                    break;
                    
                default:
                    printf("🌊");
                    break;
            }
            printf(" ");
        }
        printf(" |  ");
        for (s = 0; s < 10; s++){
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
                    case (500 / 100 % 100):
                            // On va changer ça et mettre 520, 530, 535, 540 et 550 pour savoir si le bateau est coulé en interne
                            // On mettra pour le display case 500 / 100 % 100
                        printf("💥");
                        break;
                    case (900 / 100 % 100):
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
    if (pf == 0){
        int i;
        int s;
        for (i = 0; i < 10; i++) {
            for (s = 0; s < 10; s++) {
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
                    case (500 / 100 % 100):
                        // On va changer ça et mettre 520, 530, 535, 540 et 550 pour savoir si le bateau est coulé en interne
                        // On mettra pour le display case 500 / 100 % 100
                        printf("💥");
                        break;
                    case (900 / 100 % 100):
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
        for (i = 0; i < 10; i++) {
            for (s = 0; s < 10; s++) {
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
                    case (500 / 100 % 100):
                            // On va changer ça et mettre 520, 530, 535, 540 et 550 pour savoir si le bateau est coulé en interne
                            // On mettra pour le display case 500 / 100 % 100
                        printf("💥");
                        break;
                    case (900 / 100 % 100):
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
    
    srand((unsigned int)time(NULL));
    int posx;
    int posy;
    int dir;
    
    do {
        posx = rand() % 10;
        posy = rand() % 10;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 20) != 0);
    
    do {
        posx = rand() % 10;
        posy = rand() % 10;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 30) != 0);
   
    do {
        posx = rand() % 10;
        posy = rand() % 10;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 35) != 0);
    
    do {
        posx = rand() % 10;
        posy = rand() % 10;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 40) != 0);
    
    do {
        posx = rand() % 10;
        posy = rand() % 10;
        dir = rand() % 2;
    } while (placeBoats(1, posx, posy, dir, 50) != 0);
    
}




void playerPlaceBoats(){
    printf("Welcome! The computer is ready. It is time for you to place your boats! Here is your playing field:\n");
    showBoard(0);
    printf("\n");
    int posx, posy, dir, result;
    
    printf("You are about to place a canoe : 🚣🏼‍♀️🚣🏼‍♀️\n");
    do {
        printf("Please enter start position x (line) [0-9]: ");
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 20);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to 10x10)\n");
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
        printf("Please enter start position x (line) [0-9]: ");
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 30);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to 10x10)\n");
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
        printf("Please enter start position x (line) [0-9]: ");
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 35);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to 10x10)\n");
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
        printf("Please enter start position x (line) [0-9]: ");
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 40);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to 10x10)\n");
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
        printf("Please enter start position x (line) [0-9]: ");
        scanf("%d.1s", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d.1s", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the right): ");
        scanf("%d.1s", &dir);
        result = placeBoats(0, posx, posy, dir, 50);
        switch (result) {
            case 0:
                printf("Your boat is on track!\n");
                break;
            case 1:
                printf("Unrealistic request. Make sure you privided meaningful values (keep in mind that the playing field is limited to 10x10)\n");
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
    FILE *f = fopen("/Users/plugn/Desktop/Battleship/playfield2.data", "w");
    
    int m,n;
    for (m = 0; m < 10; m++) {
        for (n = 0; n < 10; n++) {
            fprintf(f, "%d\n", playfield2[m][n]);
        }
    }
    fclose(f);
    
    FILE *g = fopen("/Users/plugn/Desktop/Battleship/playfield.data", "w");
    
    for (m = 0; m < 10; m++) {
        for (n = 0; n < 10; n++) {
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

int isDead(int pf){
    if (pf == 0){
        int deadBoat1 = 0;
        int deadBoat2 = 0;
        int deadBoat3 = 0;
        int deadBoat4 = 0;
        int deadBoat5 = 0;
        int i,s;
        
        for (i = 0; i < 10; i++){
            for (s = 0; s < 10; s++){
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
        
        if (deadBoat1 == deadBoat2 == deadBoat3 == deadBoat4 == deadBoat5 == 1){
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
        
        for (i = 0; i < 10; i++){
            for (s = 0; s < 10; s++){
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
        
        if (deadBoat1 == deadBoat2 == deadBoat3 == deadBoat4 == deadBoat5 == 1){
            return 1;
        } else {
            return 0;
        }
        
    }
}

void convertToDeath(int pf){
    if (pf == 0){
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int count4 = 0;
        int count5 = 0;
        
        int i,s;
        for (i = 0; i < 10; i++){
            for (s = 0; s < 10; s++){
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
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
                    if (playfield[i][s] == 520){
                        playfield[i][s] = 920;
                    }
                }
            }
        }
        
        if (count2 == 3){
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
                    if (playfield[i][s] == 530){
                        playfield[i][s] = 930;
                    }
                }
            }
        }
        
        if (count3 == 3){
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
                    if (playfield[i][s] == 535){
                        playfield[i][s] = 935;
                    }
                }
            }
        }
        
        if (count4 == 4){
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
                    if (playfield[i][s] == 540){
                        playfield[i][s] = 940;
                    }
                }
            }
        }
        
        if (count5 == 5){
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
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
        for (i = 0; i < 10; i++){
            for (s = 0; s < 10; s++){
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
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
                    if (playfield2[i][s] == 520){
                        playfield2[i][s] = 920;
                    }
                }
            }
        }
        
        if (count2 == 3){
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
                    if (playfield2[i][s] == 530){
                        playfield2[i][s] = 930;
                    }
                }
            }
        }
        
        if (count3 == 3){
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
                    if (playfield2[i][s] == 535){
                        playfield2[i][s] = 935;
                    }
                }
            }
        }
        
        if (count4 == 4){
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
                    if (playfield2[i][s] == 540){
                        playfield2[i][s] = 940;
                    }
                }
            }
        }
        
        if (count5 == 5){
            for (i = 0; i < 10; i++){
                for (s = 0; s < 10; s++){
                    if (playfield2[i][s] == 550){
                        playfield2[i][s] = 950;
                    }
                }
            }
        }
        
    }
}

int shoot(int pf, int posx, int posy){
    
    
    
    return 1;
}

int gameStarted(int turn){
        // This is the core center for the game and it will retrun the winner
    
    playingShowBoards();
    
    int posx, posy;
    
    if (turn == 0){
        printf("It is your turn to fire!\n");
        printf("Please enter position x (line) [0-9]: ");
        scanf("%d.1s", &posx);
        printf("Please enter position y (column) [0-9]: ");
        scanf("%d.1s", &posy);
        if (playfield2[posx][posy] == 1 || playfield2[posx][posy] == 500 / 100 % 100 || playfield2[posx][posy] == 900 / 100 % 100){
            printf("You already shoot there!\n");
            gameStarted(turn);
        }
        int result = shoot(1, posx, posy);
        if (result == 1){
            // Hit
            printf("You hit a boat!\n");
            gameStarted(turn);
        }
        
        convertToDeath(1);
        
        if (isDead(1) == 1){
            return turn;
        }
        gameStarted(1);
        
    } else {
        srand((unsigned int)time(NULL));
        posx = rand() % 10;
        posy = rand() % 10;
        if (playfield[posx][posy] == 1 || playfield[posx][posy] == 500 / 100 % 100 || playfield[posx][posy] == 900 / 100 % 100){
            gameStarted(turn);
        }
        int result = shoot(0, posx, posy);
        if (result == 1){
            gameStarted(turn);
        }
        
        convertToDeath(0);
        
        if (isDead(0) == 1){
            return turn;
        }
        gameStarted(0);
    }
    
    return 953;
}

void winner(int turn){
    int result = gameStarted(turn);
    if (result == 0){
        printf("\n🎉 Congratulations! You won the game!\n");
    } else if (result == 1){
        printf("😕 Oh no... The computer won the game this time... You'll do better next time!\n");
    } else {
        printf("An internal error occured. We are sorry to say that there is no clear winner because something wrong happened.\n");
    }
}

void game(){
    
        // Initiate the playfields
    int i, s;
    
        // Playfield for the players #PS4
    for (i = 0; i < 10; i++){
        for (s = 0; s < 10; s++){
            playfield[i][s] = 0;
        }
    }
    
        // Playfield for the computer
    for (i = 0; i < 10; i++){
        for (s = 0; s < 10; s++){
            playfield2[i][s] = 0;
        }
    }
    
        // Place the boats
    computerPlaceBoats();
    
    
    showBoard(1);
    printf("\n\n");
    
    playerPlaceBoats();
    
    backup(0);
    
    srand((unsigned int)time(NULL));
    int turn;
    turn = rand() % 2;
    winner(turn);
    return;
}

void restore(){
    
        // If restore.data = 1 then do this, otherwise, return the random funciton
    
    FILE *r = fopen("/Users/plugn/Desktop/Battleship/restore.data", "r");
    int restore;
    fscanf(r, "%d", &restore);
    
    if (restore == 0){
        game();
        return;
    } else {
        printf("Backup found, do you want to restore it? (0 = no, [1 = yes]): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 0){
            game();
            return;
        }
    }
    
    FILE *g = fopen("/Users/plugn/Desktop/Battleship/playfield.data", "r");
    int x,y;
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            fscanf(g, "%d", &playfield[x][y]);
        }
    }
    
    fclose(g);
    
    FILE *f = fopen("/Users/plugn/Desktop/Battleship/playfield2.data", "r");
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            fscanf(f, "%d", &playfield2[x][y]);
        }
    }
    
    fclose(f);
    
    FILE *h = fopen("/Users/plugn/Desktop/Battleship/turn.data", "r");
    int turn;
    fscanf(h, "%d", &turn);
    
    fclose(h);
    
    winner(turn);
}


void mainmenu(){
    
        // Create a main menu
    
    restore();
    return;
}









int main(int argc, const char * argv[]) {
    
    
    mainmenu();
    
    
    return 0;
    
    
}



