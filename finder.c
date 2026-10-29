#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            printf("Error: Could not open file.\n");
            return 1;
        }

        char line[1024];
        int found_count = 0;
        int Line_counter = 0;

        while (fgets(line, sizeof(line), file) != NULL)
        {
            Line_counter++;

            if (strstr(line, argv[2]) != NULL)
            {
                int line_match_count = 0;
                char *match = strstr(line, argv[2]);

                while (match != NULL)
                {
                    line_match_count++;
                    match = strstr(match + 1, argv[2]);
                }

                found_count++;
                printf("Line %i:%i matches | %s", Line_counter, line_match_count, line);
            }
        }

        if (found_count == 0)
        {
            printf("Your word is not present in this file.\n");
        }

        fclose(file);
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "-w") == 0)
        {
            FILE *file = fopen(argv[2], "r");
            if (file == NULL)
            {
                printf("Error: Could not open file.\n");
                return 1;
            }

            char line[1024];
            int found_count = 0;
            int Line_counter = 0;

            while (fgets(line, sizeof(line), file) != NULL)
            {
                Line_counter++;

                int line_match_count = 0;
                char *match = strstr(line, argv[3]);

                while (match != NULL)
                {
                    if ((match == line || !isalnum((unsigned char)*(match - 1))) && !isalnum((unsigned char)*(match + strlen(argv[3]))))
                    {
                        line_match_count++;
                    }

                    match = strstr(match + 1, argv[3]);
                }

                if (line_match_count > 0)
                {
                    found_count++;
                    printf("Line %i:%i matches | %s", Line_counter, line_match_count, line);
                }
            }

            if (found_count == 0)
            {
                printf("Your word is not present in this file.\n");
            }

            fclose(file);
        }
        else if (strcmp(argv[1], "-s") == 0)
        {
            printf("in the -e\n");
        }
    }
    else
    {
        printf("Usage: ds <file_path> <search_word>\n");
        return 1;
    }

    return 0;
}