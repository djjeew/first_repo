#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Song{char* name;struct Song* next;}Song;
Song* createSong(char* name);
void printSong(Song* song);
void addSongToEnd(Song* head, Song* songToAdd);
void freeSong(Song* song);
void freePlaylist(Song* head);
void removeSong(Song* head, Song* songToRemove);
void deleteSpecificSongs(Song* head);
void searchByName(Song* head, char* name);
void addSongAtSpecificIndex(Song* head,Song *index, Song* songToAdd); 
void reverseOrder(Song* head);
void freeSong(Song* song){printf("Freeing song: ");printSong(song);free(song);}
void freePlaylist(Song* current) 
{
  Song* tempSong = NULL;

  printf("Freeing playlist.............\n");
  if(current != NULL)
  {
    while (current->next != NULL) 
    {
      tempSong = current->next;
      freeSong(current);
      current = tempSong;
      current = current->next;
    }
    puts("Playlist is empty.............");
  }

  else
    puts("Palylist isn't initialized");
}
void printSong(Song* song){printf("Song %s \n", song->name);}
void printPlaylist(Song* head){
  Song* current = head;
  int count = 1;
  printf("The playlist: \n------------------\n");
  while (current) 
  {
    printf("%d - ", count);
    printSong(current);
    current = current->next;
    count++;
  }
  printf("------------------\n");}
Song* createSong(char* name)
{
  Song* newSong = malloc(sizeof(Song));
  if (newSong != NULL) 
  {
    newSong->name = name;
    newSong->next = NULL;
    printf("Song %s created successfully\n",newSong->name);
  }
  
  else
  {
    printf("allocation failed,database is full\n");
    exit(1);
  }
  return newSong;
}


void addSongToEnd(Song* head, Song* songToAdd) 
{
  Song* current = head;
  if (current != NULL)
  {

    while (current->next != NULL) 
    {
      current = current->next;
    }

    current->next = songToAdd;
    songToAdd->next = NULL;
    printf("The song is added successfully\n");
  }
  
  else
  {
    puts("List is empty");
  }
}

void main()
{
  Song* song1 = createSong("First song");
  Song* song2 = createSong("Second song");
  Song* song3= createSong("Third song");
  addSongToEnd(song1,song2);
  addSongToEnd(song1,song3);
  addSongAtSpecificIndex(song1, song1, song3);
}

void addSongAtSpecificIndex(Song* head, Song *searchedIndex, Song* songToAdd) 
{
  Song* currentIndex = head , *prevIndex = NULL;

  
  #define NAME_CMPR (strcmp(songToAdd->name,currentIndex->name))//name comparision

  if ((searchedIndex == songToAdd) || (head->next == NULL))
  {
    puts("List consists of one song only,add more songs before prociding to this operation");
    puts("Or you choosed to advance song to the same position that it was before,i.e nothing changed");
    exit(EXIT_FAILURE);
  }
  else if (head->next != NULL && searchedIndex != songToAdd )//list is consists of two songs at least
  {
      while (currentIndex != searchedIndex && currentIndex->next != NULL &&  NAME_CMPR != 0 )
      {
        prevIndex = currentIndex;
        currentIndex = currentIndex->next;
      }
      
      if(NAME_CMPR == 0 )//you found copie of the song and you didn't reach the last position of playlist
      {
        printf("Song %s already exist at playlist \n",songToAdd->name);
      }

      else if (NAME_CMPR != 0 )//There isn't copies of the song in your playlist
      {
          if ( prevIndex != NULL  && songToAdd->next != NULL)//searched place isn't at first position ,songToAdd isn't at last postion of list 
          { 
            if(currentIndex == searchedIndex && currentIndex->next != NULL )
            { 
              searchedIndex->next = songToAdd->next;
              songToAdd->next = searchedIndex;
              head->next = songToAdd;
              
              printf("%s ----> %s ----> %s ----> %s points to",head,songToAdd ,currentIndex,songToAdd->next);
            } 
          }

        else if (prevIndex == NULL && currentIndex == head && songToAdd->next == NULL)//choosed to place songToAdd at the head of the list ,songToAdd is at last index of list
          {
            head = songToAdd ;
            searchedIndex =searchedIndex->next;
            currentIndex->next = head->next;
            head->next = searchedIndex;//head and currentIndex in this case are the same
            searchedIndex->next = currentIndex;        
          }
      }
    }
}