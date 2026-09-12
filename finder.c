#include <stdio.h>

int main(void)
{   
    FILE *file;
    file = fopen("notes.txt", "r");
    
    if (file == NULL)
    {
        printf("Could not open file");
        return 1;
    }

    return 0;
    
}