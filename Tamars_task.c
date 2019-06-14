#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Song 
{
  char* name;
  char* artist;
  struct Song* next;
} Song;



Song* createSong(char* name, char* artist);
void printSong(Song* song);
void addSongToEnd(Song* head, Song* songToAdd);
void printPlaylist(Song* head);
void freeSong(Song* song);
void freePlaylist(Song* head);
void removeSong(Song* head, Song* songToRemove);
void deleteSpecificSongs(Song* head, char* artist);
void searchByName(Song* head, char* name);
void addSongAtSpecificLocation(Song* head, int location, Song* songToAdd);
void reverseOrder(Song* head);
//void subList(Song* head, char* artist);


void main()
{
  Song* head = createSong("first song", "me");
  Song* sn1 = createSong("like", "me");
  addSongToEnd(head, sn1);
  addSongToEnd(head, createSong("hi", "man"));
  addSongAtSpecificLocation(head, 1, createSong("hola", "lola"));
  printPlaylist(head);
  reverseOrder(head);
  deleteSpecificSongs(head, "me");
  searchByName(head, "hola");
  //removeSong(head, sn1);
  printPlaylist(head);
  freePlaylist(head);

  getchar();
}
Song* createSong(char* name, char* artist)
{
  Song* newSong = malloc(sizeof(Song));
  if (newSong) {
    newSong->name = name;
    newSong->artist = artist;
    newSong->next = NULL;
    printf("Song created: \n");
    printSong(newSong);
  }
  else
  {
    printf("allocation failed\n");
    exit(1);
  }
  return newSong;
}

void printSong(Song* song) 
{
  printf("the song:%s preformed by %s\n", song->name, song->artist);
}

void addSongToEnd(Song* head, Song* songToAdd) 
{
  Song* current = head;
  while (current != NULL && current->next != NULL) 
  {
    current = current->next;
  }
  current->next = songToAdd;
  songToAdd->next = NULL;
  printf("The song is added successfully\n");
}

void printPlaylist(Song* head) {
  Song* current = head;
  int count = 1;
  printf("The playlist: \n------------------\n");
  while (current) {
    printf("%d - ", count);
    printSong(current);
    current = current->next;
    count++;
  }
  printf("------------------\n");

}

void freeSong(Song* song) {
  printf("Freeing song: ");
  printSong(song);
  free(song);
}

void freePlaylist(Song* head) {
  Song* current = head;
  Song* tempSong = NULL;

  printf("Freeing playlist.............\n");
  while (current) {
    tempSong = current->next;
    freeSong(current);
    current = tempSong;
  }
  printf("Done freeing playlist.............\n");
}

void removeSong(Song* head, Song* songToRemove) {
  Song* current = head;
  while (current->next != songToRemove) {
    current = current->next;
  }
  current->next = songToRemove->next;
  freeSong(songToRemove);
}

void addSongAtSpecificLocation(Song* head, int location, Song* songToAdd) 
{
  Song* current = head;
  int i = 0;
  for (i = 0; i < location&&current->next != NULL; i++, current = current->next) {
  }
  if (i == location) {
    songToAdd->next = current->next;
    current->next = songToAdd;
    printf("song added at %d", location);
  }
  else
    printf("location is not found");

}

void reverseOrder(Song* head)
{
  printf("Printed reversed list:\n");
  Song* current, *prev, *next;
  current = head;
  prev = NULL;
  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  printPlaylist(head);

}

void deleteSpecificSongs(Song* current, char* artist)// current = head at first iteration
{
  //Song* current = head;
  if (current != NULL)
  {
    while (current->next != NULL)
    {
      if (current->artist == artist)
        removeSong(head, current);
    }
    printf("songs deleted\n");
  }
  
}

void searchByName(Song* head, char* name)
{
  printf("Searching song......\n");
  Song* current = head;
  int counter = 0;
  while (current != NULL)
  {
    counter++;
    if (current->name == name)
      printf("Song is at %d place", counter);
  }
  printf("Song not found!");
}

 void subList(Song *head, char* artist)
{
  Song* current = head;
  while (current != NULL)
  {
    if (current->artist == artist)
    {

    }

  }
}
