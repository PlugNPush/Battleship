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
                case 5:
                    printf("💥");
                    break;
                case 10:
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
                    case 5:
                        printf("💥");
                        break;
                    case 10:
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
                    case 5:
                        printf("💥");
                        break;
                    case 10:
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
                    case 5:
                        printf("💥");
                        break;
                    case 10:
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
        scanf("%d", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d", &posy);
        printf("Please enter the direction (0 = vertical upwards, 1 = horizontal to the left): ");
        scanf("%d", &dir);
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
        scanf("%d", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d", &posy);
        printf("Please enter the direction (0 = vertical upwards, 1 = horizontal to the left): ");
        scanf("%d", &dir);
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
        scanf("%d", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d", &posy);
        printf("Please enter the direction (0 = vertical upwards, 1 = horizontal to the left): ");
        scanf("%d", &dir);
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
        scanf("%d", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d", &posy);
        printf("Please enter the direction (0 = vertical downwards, 1 = horizontal to the left): ");
        scanf("%d", &dir);
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
        scanf("%d", &posx);
        printf("Please enter start position y (column) [0-9]: ");
        scanf("%d", &posy);
        printf("Please enter the direction (0 = vertical upwards, 1 = horizontal to the left): ");
        scanf("%d", &dir);
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

int gameStarted(){
    // This is the core center for the game and it will retrun the winner
    
    return 0;
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
    playerPlaceBoats();
    
    int result = gameStarted();
    if (result == 0){
        printf("\n🎉 Congratulations! You won the game!");
    } else if (result == 1){
        printf("😕 Oh no... The computer won the game this time... You'll do better next time!");
    } else {
        printf("An internal error occured. We are sorry to say that there is no clear winner because something wrong happened.");
    }
    
    
    return;
}

void mainmenu(){
    
    // Create a main menu
    
    game();
    return;
}




int main(int argc, const char * argv[]) {
    
    // insert code here...
    mainmenu();
    
    
    return 0;
    
    
}



