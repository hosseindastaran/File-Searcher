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
    char *result;
    int line_number = 0;
    while (fgets(line,256,file) != NULL)
    {   
        line_number = line_number + 1;
        if (strstr(line, text) != NULL)
        {
            result = strstr(line, text);
            printf("%d : %s", line_number , line);
        }
        
    }
    
    fclose(file);

    return 0;
    
}