#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{   

    FILE *file;
    char namefile[256];
    printf("Enter a name file : ");
    fgets(namefile, 256, stdin);
    int namefile_index = strcspn(namefile, "\n");
    namefile[namefile_index] = '\0';
    file = fopen(namefile, "r");
    

    if (file == NULL)
    {
        printf("Could not this open file : %s\n", namefile);
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
        
        result = strstr(line, text);
        line_number = line_number + 1;
        if (result != NULL)
        {
            if (isalpha(*(result + strlen(text))))
            {
                printf("Next character is a letter.\n");
            }
            printf("%d : %s", line_number , line);
        }
        
    }
    
    fclose(file);

    return 0;
    
}