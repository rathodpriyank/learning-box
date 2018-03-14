#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/inotify.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

/* Display information from inotify_event structure */
static void displayInotifyEvent(struct inotify_event *i)
 {
     printf("    wd =%2d; ", i->wd);
     if (i->cookie > 0)
         printf("cookie =%4d; ", i->cookie);
 
     printf("mask = ");
     if (i->mask & IN_ACCESS)        printf("IN_ACCESS ");
     if (i->mask & IN_ATTRIB)        printf("IN_ATTRIB ");
     if (i->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE ");
     if (i->mask & IN_CLOSE_WRITE)   printf("IN_CLOSE_WRITE ");
     if (i->mask & IN_CREATE)        printf("IN_CREATE ");
     if (i->mask & IN_DELETE)        printf("IN_DELETE ");
     if (i->mask & IN_DELETE_SELF)   printf("IN_DELETE_SELF ");
     if (i->mask & IN_IGNORED)       printf("IN_IGNORED ");
     if (i->mask & IN_ISDIR)         printf("IN_ISDIR ");
     if (i->mask & IN_MODIFY)        printf("IN_MODIFY ");
     if (i->mask & IN_MOVE_SELF)     printf("IN_MOVE_SELF ");
     if (i->mask & IN_MOVED_FROM)    printf("IN_MOVED_FROM ");
     if (i->mask & IN_MOVED_TO)      printf("IN_MOVED_TO ");
     if (i->mask & IN_OPEN)          printf("IN_OPEN ");
     if (i->mask & IN_Q_OVERFLOW)    printf("IN_Q_OVERFLOW ");
     if (i->mask & IN_UNMOUNT)       printf("IN_UNMOUNT ");
     printf("\n");
 
     if (i->len > 0)
         printf("        name = %s\n", i->name);
}
 
int main( )
{
  int length = 0;
  int fd;
  int wd;
  char buffer[EVENT_BUF_LEN];
  char *i;
  struct inotify_event *event;

  /*creating the INOTIFY instance*/
  fd = inotify_init();

  /*checking for error*/
  if ( fd < 0 ) {
    perror( "inotify_init" );
  }

  /*adding the “/tmp” directory into watch list. Here, the suggestion is to validate the existence of the directory before adding into monitoring list.*/
  wd = inotify_add_watch( fd, "/tmp/", IN_CLOSE_WRITE );

  /*read to determine the event change happens on “/tmp” directory. Actually this read blocks until the change event occurs*/ 

  	/*actually read return the list of change events happens. Here, read the change event one by one and process it accordingly.*/
	while (1) {
		length = read( fd, buffer, EVENT_BUF_LEN ); 

		/*checking for error*/
		if ( length < 0 ) {
			perror( "read failed" );
		}
		
		for (i = buffer; i < buffer + length; ) {
			event = ( struct inotify_event * ) i;     
			displayInotifyEvent(event);
			i += EVENT_SIZE + event->len;
		} // second while loop
		printf("Length is : %d\n", length);
	} // first while loop

	/*removing the “/tmp” directory from the watch list.*/
	inotify_rm_watch( fd, wd );

/*closing the INOTIFY instance*/
close( fd );
}
