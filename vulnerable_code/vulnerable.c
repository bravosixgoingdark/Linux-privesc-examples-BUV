#include <unistd.h>
#include <stdio.h> 




void vuln() {
  char buf[100]; 
  read(0, buf, 200);
  printf("%s\n", buf);
}


int main(int argc, char *argv[])
{
  setvbuf(stdout, 0LL, 2, 0LL);
  setvbuf(stdin, 0LL, 1, 0LL);
  puts("enter your input here, do you worst.");
  vuln(); 
}


