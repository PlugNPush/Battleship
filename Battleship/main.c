//
//  main.c
//  Battleship
//
//  Created by PlugN on 14/03/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//

#include <stdio.h>

int playfield[10][10], playfield2[10][10];

int placeBoats(int pf, int posx, int posy, int dir, int type){
    if ((pf > 1 || pf < 0) || (dir > 1 || dir < 0) || (type > 50 || type < 20) || (posx > 10 || posx < 0) || (posy > 10 || posy < 0)){
        // Unrealistic error
        return 1;
    }
    
    // dir = 0 -> horizontal | dir = 1 -> vertical
    
    if (pf == 0){
        // Le joueur
            int a;
            int isPossible = 1;
        
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
        
        // playfield[posx][posy] = type;
    } else if (pf == 1){
        int a;
        int isPossible = 1;
        
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
        
    }
    
    
    
    
    
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
    
    
    
    return;
}

void mainmenu(){
    
    return;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    mainmenu();
    
    return 0;
    
    
}



