#include "givenA3 (1).h"


int playSongGivenName(A3Song *headLL, char givenSongName[MAX_LENGTH]) {
    
    if (headLL == NULL) {
        printf("playlist is empty\n");
        return -1;
    }
    
    A3Song *song = headLL;
    
    while (song != NULL) {
        if (strcmp(song->songName, givenSongName) == 0) {
            printf("Song ID: %d\n", song->songId);
            printf("Song Name: %s\n", song->songName);
            printf("Song Notes: ");
            for (int i = 0; i < 21; i ++) {
                printf("%s ", song->songNotes[i]);
                
                if (i < 21) {
                    printf("."); 
                }
            }
            printf("\n");
            return 1;
        }
        
        song = song->nextSong; 
    }
    
    
    printf("No song found ! !\n");
    return -1;
}

    


