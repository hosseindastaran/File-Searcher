#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{

    if (argc !=3)
    {
        printf("Usage: ds <file_path> <search_word>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char line[1024];
    int found_count = 0;
    int Line_counter = 0;
    while (fgets(line,sizeof(line),file) != NULL)
    {
        Line_counter = Line_counter + 1;
        if (strstr(line, argv[2]) != NULL)
        {
            found_count = found_count + 1;
            printf("%i : %s", Line_counter, line);
        }
        
    }

    if (found_count == 0)
    {
        printf("Your word is not present in this file.");
    }
    
    
    fclose(file);
    return 0;

}