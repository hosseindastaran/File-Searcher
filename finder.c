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

    printf("Type what you want to search for : ");
    char text[256];
    fgets(text, 256, stdin);
    
    int newline_index = strcspn(text, "\n");
    text[newline_index] = '\0';

    char line[256];
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