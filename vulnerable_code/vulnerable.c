#include <unistd.h>
#include <stdio.h> 




void vuln() {
  char buf[100]; 
  read(0, buf, 200);
  printf("%s\n", buf);
}


int main(int argc, char *argv[])
{
  puts("Enter your input here, do you worst.");
  vuln(); 
}


