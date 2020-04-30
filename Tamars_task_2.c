#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Prototypes*/
typedef struct Song{char* name;char* artist;struct Song* next;struct Song *previous;}Song;
Song* createSong(char* name, char* artist);
void printSong(Song* song);
void addSongToEnd(Song* head, Song* songToAdd);
void printPlaylist(Song* head);
void freeSong(Song* song);
void freePlaylist(Song* head);
void removeSong(Song* head, Song* songToRemove);
void deleteSpecificSongs(Song* head, char* artist);
void searchByName(Song* head, char* name);
void addSongAtSpecificIndex(Song* head,Song *index, Song* songToAdd); 
void reverseOrder(Song* head);
//void subList(Song* head, char* artist);
/*Prototypes*/

///////////////////////////////////////////////////////////////////
                    /*Memory Handling Functions*/
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
//////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
                        /*OutPut FUNCTIONS*/
void printSong(Song* song){printf("%s performed by %s\n", song->name, song->artist);}

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

///////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////
                    /*Additional Functions*/
Song* createSong(char* name, char* artist)
{
  Song* newSong = malloc(sizeof(Song));
  if (newSong != NULL) 
  {
    newSong->name = name;
    newSong->artist = artist;
    newSong->next = NULL;
    printf("%s performed by %s created successfully\n",newSong->name,newSong->artist);
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


void searchByName(Song* current, char* SearchedName)
{
  int counter = 1; 

  printf("Searching for the following title: %s\n ......",SearchedName);
  
  if (current != NULL)// Playlist isn't empty
  {
    for(;current->name != SearchedName && current->next != NULL;++counter,current=current->next)
      {;} //iterate through the loop until song found or reached end of the list
    if (current->name == SearchedName)
      printf("%s is at %d positon\n",SearchedName, counter);
    else if (current == NULL)
      printf("%s not found!\n",SearchedName);        
  }
  else
  {
    puts("Playlist is empty");
  }
}

void removeSong(Song* head, Song* songToRemove) 
{
  Song *currentTrack = head, *previousTrack = NULL;

  if (currentTrack !=NULL) //Playlist isn't empty
  {
      while(currentTrack != searchedSong && currentTrack->next != NULL )
      {
          previousTrack = currentTrack;
          currentTrack= currentTrack->next ;
      }
        
      if (currentTrack == NULL )//song isn't located in the list
      {
        printf("Couldn't locate %s \n", songToRemove->name);
      }  

      else if (previousTrack == NULL && currentTrack == songToRemove)
      {
        printf("%s located at first position of playlist",songToRemove->name);
        head = head->next;
        freeSong(songToRemove);
      }

      else// song located between second and last index
      {
        previousTrack->next= trackToRemove->next;
        freeSong(trackToRemove);
      } 
  }

  else  
  {
    puts("Playlist is empty");
  }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void main()
{
  Song* head = createSong("Head of Playlist", "Eminem");
  Song* song1 = createSong("First song", "Marvin Gaye");
  Song* song2 = createSong("Second song", "Bob Marley");
  Song* song3= createSong("Third song", "Bob Marley");

  addSongToEnd(head, song1);
  addSongToEnd(head,song2);
  addSongToEnd(head,song3);

  searchByName(head, song1->name);


  addSongAtSpecificIndex(head, song1, song2);
  printPlaylist(head);
  //reverseOrder(head);
  //deleteSpecificSongs(head, "Marvin Gaye");
  //removeSong(head, song1);
  printPlaylist(head);
  //freePlaylist(head);

  getchar();
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                      NOT FINISHED !!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void addSongAtSpecificIndex(Song* head, Song *searchedIndex, Song* songToAdd) 
{
  Song* currentIndex = head , *prevIndex = NULL;
  #define NAME_CMPR (strcmp(songToAdd->name,currentIndex->name)//name comparision

  if ((searchedIndex == songToAdd) || (head != NULL && head->next == NULL)) 
  {
    puts("List consists of one song only,add more songs before prociding to this operation");
    puts("Or you choosed to advance song to the same position that it was before,i.e nothing changed");
  }
//(searchedIndex != head && searchedIndex != head->next) 
  else if (head->next != NULL && searchedIndex != songToAdd )//list is consists of two songs at least
  {
      while (currentIndex != searchedIndex && currentIndex->next != NULL &&  NAME_CMPR != 0 )
      {
        prevIndex = currentIndex;
        currentIndex = currentIndex->next;
      }
      
      if(NAME_CMPR == 0 )//you found identical song and you didn't reach the last position of playlist
        puts("Song already exist");
      else if (NAME_CMPR != 0 )//The name of the song is unique,there isn't copies of the song in your playlist
      {
        if ( prevIndex != NULL  && songToAdd->next != NULL)
        { 
          if(currentIndex == searchedIndex && currentIndex->next != NULL )
          {
            currentIndex->next = songToAdd->next;
            songToAdd->next = currentIndex; 
            head->next = songToAdd;  
            printf("%s ----> %s ----> %s ----> %s points to",head,songToAdd ,current,songToAdd->next);
          } 
          else if (prevIndex == NULL && currentIndex == head && songToAdd->next == NULL)
            {
              currentIndex->next = songToAdd->next;
              songToAdd->next = head;//currentIndex in this case , it is the same 
            }               
        }

        
  
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*
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
      current = current->next;
    }
    printf("Songs deleted\n");
  }
  else
  {

  }
  
}
*/

/* void subList(Song *head, char* artist)
{
  Song* current = head;
  while (current != NULL)
  {
    if (current->artist == artist)
    {

    }

  }
}
*/