/*
 * pass arguments to qemu binary
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
 char *newargv[argc + 3];

 newargv[0] = argv[0];
 newargv[1] = "-cpu";
 newargv[2] = "cortex-a53";

 memcpy(&newargv[3], &argv[1], sizeof(*argv) * (argc -1));
 newargv[argc + 2] = NULL;
 return execve("/usr/bin/qemu-aarch64-real", newargv, envp);
}
