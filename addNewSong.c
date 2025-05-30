#include "givenA3 (1).h"

bool addNewSong(A3Song **headLL, int beginOrEnd) {
    
    A3Song *newSong = malloc(sizeof(A3Song));

    printf("Song Name: ");
    getchar();
    fgets(newSong->songName, sizeof(newSong->songName), stdin);
    newSong->songName[strcspn(newSong->songName, "\n")] = '\0';
    
    srand(time(NULL));
    long int lengthName = strlen(newSong->songName);
    int randomInt = (rand() % 1000 + 1);
    newSong->songId = (int)(lengthName + randomInt);
    
    char randomNotes[7][4] = {"do", "re", "mi", "fa", "sol", "la", "ti"};
    for (int i = 0; i < 21; i++) {
        int randomI = rand() % 7;
        strcpy(newSong->songNotes[i], randomNotes[randomI]);
    }
    

    
    printf("Song ID: %d\n", newSong->songId);
    
    printf("Song name: %s\n", newSong->songName);
    
    
    printf("Notes: ");
    for (int i = 0; i < 21; i ++) {
        printf("%s ", newSong->songNotes[i]);
    }
    printf("\n");
    
    if (beginOrEnd == 1) {
        A3Song *newSong = malloc(sizeof(A3Song));
        newSong->nextSong = *headLL;
        *headLL = newSong;
        printf("Song added at the beginning!\n");
        return true;
        
    } else if (beginOrEnd == 2) {
        newSong->nextSong = NULL;
        
        if(*headLL == NULL) {  //If the linked list is empty
            *headLL = newSong;
        } else {
            A3Song *tempSong = *headLL;
            while (tempSong->nextSong != NULL) {
                tempSong = tempSong->nextSong;
            }
            tempSong->nextSong = newSong;
        }
        
        printf("Song added at the end!\n");
        return true;
        
    } else {
        free(newSong);
        return false;
    }
}
