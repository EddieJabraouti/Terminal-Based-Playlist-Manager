#include "givenA3 (1).h"


void deletePlayList(A3Song **headLL) {
    
    if (headLL == NULL) {
        printf("playlist empty\n");
        return;
    }
    
    A3Song *currentSong = *headLL;
    A3Song *nextSong;
    
    while(currentSong != NULL) {
        nextSong = currentSong->nextSong;
        free(currentSong);
        currentSong = nextSong;
    }
    
    *headLL = NULL;  
}
