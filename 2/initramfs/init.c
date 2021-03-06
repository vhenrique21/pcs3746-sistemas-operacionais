#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/sched.h>

#define len(_arr) ((int)((&_arr)[1] - _arr))
#define __NR_hello_cfs 404


static const char * const programs[] = { "/io_bound", "/cpu_bound", "/io_bound", "/cpu_bound", "/cpu_bound" };

void panic(const char *msg)
{
	fprintf(stderr, "%s: %s (errno = %d)\n", msg, strerror(errno), errno);
	exit(-1);
}

void mount_fs()
{
	printf("Mounting filesystems\n");
	// If /sys is not created, make it read-only (mode = 444)
	if (mkdir("/sys", 0x124) && errno != EEXIST)
		panic("mkdir");
	if (mount("none", "/sys", "sysfs", 0, ""))
		panic("mount");
}

int main()
{
	printf("Custom initramfs - Read Text:\n");
	mount_fs();

	printf("Forking to run %d programs\n", len(programs));

	for (int i = 0; i < len(programs); i++) {
		const char *path = programs[i];
		pid_t pid = fork();
		if (pid == -1) {
			panic("fork");
		} else if (pid) {
			printf("Starting %s (pid = %d)\n\n", path, pid);
		} else {
			execl(path, path, (char *)NULL);
			panic("execl");
		}
	}

	while(1) {
		syscall(__NR_hello_cfs);
		printf("\n\n");
		sleep(2);
	}

	

	// int program_count = len(programs);
	// while (program_count) {
	// 	int wstatus;
	// 	pid_t pid = wait(&wstatus);
	// 	if (WIFEXITED(wstatus))
	// 		printf("pid %d exited with %d\n", pid, WEXITSTATUS(wstatus));
	// 	else if (WIFSIGNALED(wstatus))
	// 		printf("pid %d killed by signal %d\n", pid, WTERMSIG(wstatus));
	// 	else
	// 		continue;
	// 	program_count--;
	// }

	printf("init finished\n");

	// for (;;)
	// 	sleep(1000);

	// sleep(1);

	return 0;
}
