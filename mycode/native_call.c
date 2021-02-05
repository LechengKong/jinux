#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <asm/unistd.h>

int main (void)
{
    int uid = syscall(__NR_getuid);
    printf("The uid is: %d\n",uid);
    int return_val = syscall(__NR_setuid);
    if( return_val != 0 ) 
        printf("Error: setuid failed! Reason: %s\n", strerror(errno));
    uid = syscall(__NR_getuid);
    printf("The uid is: %d\n",uid);
    return 0;
}
