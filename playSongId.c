#include "givenA3 (1).h"
#include <stdio.h>
#include <stdlib.h>

int playSongGivenId(A3Song *headLL, int givenSongId) {
    
    if (headLL == NULL) {
        printf("Playlist is empty\n");
        return -1;
    }
    
    A3Song *song = headLL;
    
    while (song!=NULL) {
        
        if (givenSongId == song->songId) {
            printf("Song id matches\n");
            
            printf("Song ID: %d\n", song->songId);
            
            printf("Song Name: %s\n", song->songName);
            
            printf("Song Notes: ");
            for (int i = 0; i < 21; i++) {
                printf("%s ", song->songNotes[i]);
                
                if (i < 20) {
                    printf(".");
                }
            }
            printf("\n");
            
            return 1;
            
        }
        
        song = song->nextSong;
    }
        printf("No song found! !\n");
        return -1;
}


