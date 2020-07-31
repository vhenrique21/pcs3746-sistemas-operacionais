  
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd = open("/sys/kernel/show_blocked/blocked", O_RDONLY);
	char show_blocked[1024];

	if (lseek(fd, 0, SEEK_SET)) {
		perror("lseek");
	} else {
		int size = read(fd, show_blocked, 1023);
		if (size < 0) {
			perror("read");
		} else {
			show_blocked[size] = 0;
			printf("-----\n%s-----\n", show_blocked);
		}
	}

	return 0;
}



