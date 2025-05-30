#include "givenA3 (1).h"


int deleteASongGivenId(A3Song **headLL, int givenSongId) {
    
    if (headLL == NULL) {
        printf("Playlist is empty\n");
        return -1;
    }
    
    A3Song *song = *headLL;
    
    A3Song *previous = NULL;
    
    if (song->songId == givenSongId) {
            *headLL = song->nextSong;
            free(song);
            printf("Song deleted !!\n");
            return 1;
        }
    
    previous = song;
    song = song->nextSong;
    
    while (song != NULL) {
        if (song->songId == givenSongId) {
            previous->nextSong = song->nextSong;
            song = NULL; 
            free(song);
            printf("Song deleted !!\n");
            return 1;
        }
        
        previous = song;
        song = song->nextSong;
    }
    
    free(previous);
    printf("Song not found !!\n");
    return -1;
}
