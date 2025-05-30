#include "givenA3 (1).h"


int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]) {
    FILE *fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        printf("Failed to open file\n");
        return -1;
    }
    
    srand(time(NULL));
    int songCount = 0;
    char readLine [500];
    
//    if (*headLL == NULL) {
//        deletePlayList(headLL);
//    }
    
    while (fgets(readLine, sizeof(readLine), fptr)) {
        
        A3Song *newSong = malloc(sizeof (A3Song));
        if (newSong == NULL) {
            printf("Failed to allocate memory for new song\n");
            fclose(fptr);
            return songCount;
        }
        
        for (int i = 0; i < MAX_LENGTH; i++) {
            newSong->songNotes[i][0] = '\0';
        }
        
        char *token = strtok(readLine, ",");
        if (token == NULL) {
            free(newSong);
        } else {
            strncpy(newSong->songName, token, MAX_LENGTH - 1);
            newSong->songName[MAX_LENGTH - 1] = '\0';
            
            long int lengthName = strlen(newSong->songName);
            int randomInt = (rand() % 1000) + 1;
            newSong->songId = (int)(lengthName + randomInt);
            
            int notePos = 0;
            while((token = strtok(NULL, ",")) != NULL && notePos < 21) {
                strncpy(newSong->songNotes[notePos],token,NOTE_LENGTH - 1);
                newSong->songNotes[notePos][NOTE_LENGTH - 1] = '\0';
                notePos++;
            }
        }
        
        newSong->nextSong = NULL;
        if (*headLL == NULL) {
            *headLL = newSong;
        } else {
            A3Song *currentSong = *headLL;
            while(currentSong->nextSong !=NULL) {
                currentSong = currentSong->nextSong;
            }
            currentSong->nextSong = newSong;
        }
        
        songCount++;
        
    }
    
    fclose(fptr); 
    return songCount;
}
