#define _POSIX_SOURCE 
#include <sys/types.h> 
#include <pwd.h>
#include <grp.h> 
#include <stdio.h> 
#include <unistd.h> 


int main(int argc, char *argv[])
{
  setuid(0); // attempts to set the current uid of this process to 0 (root) if allowed
  setgid(0); //attemps to set the current gid of this process to 0 (root) if allowed 
  struct passwd *p; // define an empty struct for the getpwuid() function  
  struct group *g; // same but for the getgrgid() function 
  gid_t gid; // groupID var  
  uid_t uid; // userID var 
  // checks if the program can get the needed user info or not 
  if ((p = getpwuid(uid = getuid())) == NULL || (g = getgrgid(gid = getgid())) == NULL)  
    perror("Failed to get user info");
  else {
    puts("Infomation of current user who is executing this program:"); 
    // prints the user, group and the UserID and the GroupID from the returned structs 
    printf("  User: %s\n", p->pw_name);
    printf("  UserID: %d\n", p->pw_uid);
    printf("  Group: %s\n", g->gr_name);
    printf("  GroupID: %d\n", g->gr_gid);
  }
  return 0;
}
