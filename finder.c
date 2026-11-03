#include <stdio.h>
#include <string.h>
#include <ctype.h>

int search_file(const char *file_path, const char *search_word, char search_mode);

int search_file(const char *file_path, const char *search_word, char search_mode)
{
    if (search_word[0] == '\0')
    {
        printf("Error: Search word cannot be empty.\n");
        return 1;
    }

    FILE *file = fopen(file_path, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char line[1024];
    int found_count = 0;
    int line_counter = 0;
    long line_start_offset = 0;

    while (1)
    {
        line_start_offset = ftell(file);

        if (fgets(line, sizeof(line), file) == NULL)
        {
            break;
        }

        line_counter++;
        int line_match_count = 0;
        char *match = strstr(line, search_word);

        while (match != NULL)
        {
            int valid_match = 0;

            if (search_mode == 'n')
            {
                valid_match = 1;
            }
            else if (search_mode == 'w')
            {
                if ((match == line || !isalnum((unsigned char)*(match - 1))) && !isalnum((unsigned char)*(match + strlen(search_word))))
                {
                    valid_match = 1;
                }
            }
            else if (search_mode == 's')
            {
                if ((match == line || *(match - 1) == ' ') && (*(match + strlen(search_word)) == ' ' || *(match + strlen(search_word)) == '\n' || *(match + strlen(search_word)) == '\0'))
                {
                    valid_match = 1;
                }
            }

            if (valid_match)
            {
                long file_offset = line_start_offset + (match - line);
                printf("Byte Offset: %ld\n", file_offset);
                line_match_count++;
            }

            match = strstr(match + 1, search_word);
        }
        if (line_match_count > 0)
        {
            found_count++;
            printf("Line %i:%i matches | %s",line_counter, line_match_count, line);
        }
    }

    if (found_count == 0)
    {
        printf("Your word is not present in this file.\n");
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        return search_file(argv[1], argv[2], 'n');
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "-w") == 0)
        {
            return search_file(argv[2], argv[3], 'w');
        }
        else if (strcmp(argv[1], "-s") == 0)
        {
            return search_file(argv[2], argv[3], 's');
        }
        else
        {
            printf("Error: Unknown option '%s'\n", argv[1]);
            printf("Usage: ds [-w | -s] <file_path> <search_word>\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ds [-w | -s] <file_path> <search_word>\n");
        return 1;
    }

    return 0;
}