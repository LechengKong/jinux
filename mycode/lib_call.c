#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main (void)
{
    int uid = getuid();
    printf("The uid is: %d\n",uid);
    int return_val = setuid(0);
    if( return_val != 0 ) 
        printf("Error: setuid failed! Reason: %s\n", strerror(errno));
    uid = getuid();
    printf("The uid is: %d\n",uid);
    return 0;
}
