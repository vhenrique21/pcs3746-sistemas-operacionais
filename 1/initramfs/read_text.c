#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

   int fd = open("text.txt", O_RDONLY);

   if (fd == -1)
   {
      printf("Fail!!!");
      return 1;
   }

   char lineBuf[256];
   while (1)
   {
      unsigned long nbytes = read(fd, lineBuf, sizeof(lineBuf));
      write(1, lineBuf, nbytes);
      if (nbytes <= 0)
         break;
   };

   // printf("\n OK! \n\n\n");
   close(fd);

   return 0;
}
