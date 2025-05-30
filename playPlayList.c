#include "givenA3 (1).h"


void playPlayList(A3Song *headLL) {
    
    A3Song *temp = headLL;
    
    if (temp == NULL) {
        printf("Playlist is empty\n");
    }
    
    while(temp != NULL) {
        
        printf("Song ID: %d\n", temp->songId);
        printf("Song Name: %s\n", temp->songName);
        
        printf("Song Notes: ");
        for (int i = 0; i < 21; i++) {
            printf("%s", temp->songNotes[i]);
            
            if (i < 21) {
                printf(".");
            }
        }
        printf("\n\n");

        temp = temp->nextSong;
    }
    
}
