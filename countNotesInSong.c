#include "givenA3 (1).h"

int countNotesInASong(A3Song *headLL, int givenSongId, char whichNote[4]) {
    
    if (headLL == NULL) {
        printf("playlist empty\n");
        return -1;
    }
    
    A3Song *song = headLL;
    
    while (song!=NULL) {
        if (givenSongId == song->songId) {
            int count = 0;
            for (int i = 0; i < 21; i++) {
                if (strcmp(song->songNotes[i], whichNote)) {
                    count++;
                }
            }
            printf("Number of times the note appears: %d", count);
            return count;
        }
        
        song = song->nextSong;
    }
    
    printf("Song not found!!\n");
    return -1;
}
