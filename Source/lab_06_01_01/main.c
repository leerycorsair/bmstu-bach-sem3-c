

#include "err_codes.h"
#include "fb_handling.h"

int main(int argc, char **argv)
{
    if (argc == 3 || argc == 4)
    {
        if (strcmp(argv[2], "title") != 0 && strcmp(argv[2], "name") != 0 && strcmp(argv[2], "year") != 0)
            return INCORRECT_FIELD;

        FILE *file;
        file = fopen(argv[1], "r");
        if (file == NULL)
            return NO_FILE;

        film_item fb[MAX_RECS];
        size_t fb_size = 0;
        int e_c = read_sort_fb(file, fb, &fb_size, argv[2]);

        if (argc == 3 && e_c == SUCCESS)
            print_fb(fb, fb_size);
        else if (argc == 4 && e_c == SUCCESS)
        {
            if (strlen(argv[3]) > MAX_STR_LEN || (strlen(argv[3]) > MAX_NUMS && strcmp(argv[2], "year") == 0))
            {
                fclose(file);
                return INCORRECT_SEARCH_KEY;
            }
            e_c = find_film(fb, fb_size, argv[2], argv[3]);
        }
        fclose(file);
        return e_c;
    }
    else
        return INCORRECT_NUMBER_OF_PARAMETERS;
}