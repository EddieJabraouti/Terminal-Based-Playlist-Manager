#include <stdio.h>
#include "givenA3 (1).h"

int main(int argc, const char * argv[]) {
    
    int choice = 0;
    char fileName[MAX_LENGTH] = "MusicalTunes.csv";
    A3Song *headLL = NULL;
    bool plExists = false;
    
    do {
        printMenu(choice); //Prints menu (custom helper function)
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid Type !!\n");
            while (getchar() != '\n');
        } else {
            if (choice < 1 || choice > 9 ) {
                printf("Invalid Number !!\n");
            }
            
                else if(!plExists && choice != 1 && choice != 9) {
                    printf("Create the playlist first!\n");
            }
                else {
                    printf("\n");
                    switch(choice) {
                        case 1: {
                            int songCount = createPlayList(&headLL, fileName);
                            plExists = true;
                            printf("Number of songs in the playlist: %d\n", songCount);
                            break;
                        }
                        case 2: {
                            int beginOrEnd;
                            printf("Enter the value for beginOrEnd: ");
                            scanf("%d", &beginOrEnd);
                            addNewSong(&headLL, beginOrEnd);
                            
                            break;
                        }
                        case 3: {
                            playPlayList(headLL);
                            break;
                        }
                        case 4: {
                            int id;
                            printf("Enter the id of the song you want to play: ");
                            scanf("%d", &id);
                            playSongGivenId(headLL, id);
                            break;
                        }
                        case 5: {
                            char songName[MAX_LENGTH];
                            printf("Enter the name of the song you want to play: ");
                            getchar();
                            fgets(songName, sizeof(songName), stdin);
                            songName[strcspn(songName, "\n")] = '\0';
                            playSongGivenName(headLL, songName);
                            break;
                        }
                            
                        case 6: {
                            char givenNote[4];
                            int id;
                            printf("Enter the id of the song you want to count notes in: ");
                            scanf("%d", &id);
                            printf("Enter the note of the song you want to count: ");
                            scanf("%3s", givenNote);
                            countNotesInASong(headLL, id, givenNote);
                            break;
                        }
                        case 7: {
                            int id;
                            printf("Enter the id of the song you want to delete: ");
                            scanf("%d", &id);
                            deleteASongGivenId(&headLL, id);
                            break;
                        }
                        case 8: {
                            deletePlayList(&headLL);
                            plExists = false;
                            printf("Deleting Playlist\n");
                            break;
                        }
                            
                    }
                }
        }
    } while (choice!= 9);
    
    return 0;
}
