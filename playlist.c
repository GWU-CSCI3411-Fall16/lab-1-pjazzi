#include <stdio.h>

char* titles [] = {"Freebird", "YMCA", "Sandstorm"};
char* artists [] = {"Lynard Skynard", "Village People", "Darude"};

struct song_t
{
    char* title;
    char* artist;
};//used _t so that we know it's a type

struct node_t
{
    struct song_t* song;
    struct node_t* next;
};

struct playlist_t
{
    char* name;
    struct node_t* head;
};

void print(struct playlist_t* pl)
{    
    struct node_t* ptr;
    ptr = pl->head;//whatever the first node of the list is, it makes it the head
    while(ptr->next != NULL)
    {
        printf("%s by %s\n", ptr->song->tilte, ptr->song->artist);
	ptr = ptr->next;
    }
}//we make it a playlist * so that it doesn't make a copy, which takes time


int main(int arg, char* argv[])
{
    struct song_t freebird, ymca, sandstorm;
    struct playlist_t pl1, pl2;
    struct node_t pl1_s1, pl1_s2, pl1_s3;
    struct node_t pl2_s1, pl2_s2, pl2_s3;
    
    freebird.title = titles[0];
    freebird.artist = artists[0];
    ymca.title = title[1];
    ymca.artist = artists[1];
    sandstorm.title = title[2];
    sandstorm.artist = artists[2];
    
    pl1.name = "70's";
    pl1_s1.song = &ymca;//you can't send a pointer to another pointer, so you should send the location of the pointer you want to send to the other pointer
    pl1_s1.next = &pl1_s2;
    pl1_s2.song = &freebird;
    pl1_s2.next = NULL;

    print(&pl1_s1);
/*
    song.title = titles[0];
    song.artist = artists[0];//these are not copies, they're pointers. If you change here, it changes there.
*/
    return 0;
}
