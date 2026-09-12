#include <stdio.h>
#include <string.h>

int main(void)
{   
    FILE *file;
    file = fopen("notes.txt", "r");
    
    if (file == NULL)
    {
        printf("Could not open file");
        return 1;
    }

    char line[256];
    char text[] = "File";
    while (fgets(line,256,file) != NULL)
    {
        if (strstr(line, text) != NULL)
        {
            printf("%s", line);
        }
        
    }
    
    fclose(file);

    return 0;
    
}