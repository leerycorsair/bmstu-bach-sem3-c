#include "fb_handling.h"
#include "err_codes.h"

int read_line(FILE *file, char *s, int str_len)
{
    int ch;
    int i = 0;
    while ((ch = fgetc(file)) != '\n' && ch != EOF && (i < str_len - 1))
        if (i < str_len - 1)
            s[i++] = ch;
    s[i] = '\0';
    if (ch != '\n' && ch != EOF && i > 0)
        return INCORRECT_CONTENT;
    return i;
}

int read_film(FILE *file, film_item *curr_film)
{
    if (read_line(file, curr_film->title, MAX_STR_LEN + 1) == INCORRECT_CONTENT)
        return INCORRECT_CONTENT;
    if (feof(file))
        return EOF;

    if (read_line(file, curr_film->name, MAX_STR_LEN + 1) == INCORRECT_CONTENT || strlen(curr_film->name) == 0)
        return INCORRECT_CONTENT;

    if (read_line(file, curr_film->year, MAX_NUMS + 1) == INCORRECT_CONTENT || check_year(curr_film->year) || strlen(curr_film->year) == 0)
        return INCORRECT_CONTENT;

    return SUCCESS;
}

int read_sort_fb(FILE *file, film_item fb[], size_t *fb_size, char *field)
{
    int e_c = SUCCESS;
    size_t i = 0;
    film_item buf;

    while (e_c == SUCCESS)
    {
        e_c = read_film(file, &buf);
        if (e_c == SUCCESS)
            put_item(buf, fb, &i, field);
        if (e_c != EOF && i == MAX_RECS)
            e_c = TOO_MUCH_RECS;
    }
    *fb_size = i;

    if (e_c == EOF && *fb_size > 0)
        return SUCCESS;
    else
        return e_c;
}

void put_item(film_item record, film_item fb[], size_t *fb_size, char *field)
{
    if (*fb_size == 0)
        fb[0] = record;
    else
    {
        int i = *fb_size;
        if (strcmp(field, "title") == 0)
            while (i > 0 && strcmp(record.title, fb[i - 1].title) < 0)
            {
                fb[i] = fb[i - 1];
                i -= 1;
            }
        if (strcmp(field, "name") == 0)
            while (i > 0 && strcmp(record.name, fb[i - 1].name) < 0)
            {
                fb[i] = fb[i - 1];
                i -= 1;
            }
        if (strcmp(field, "year") == 0)
            while (i > 0 && strcmp(record.year, fb[i - 1].year) < 0)
            {
                fb[i] = fb[i - 1];
                i -= 1;
            }
        fb[i] = record;
    }
    *fb_size += 1;
}

void print_fb(film_item fb[], size_t fb_size)
{
    for (size_t i = 0; i < fb_size; i++)
    {
        printf("%s\n", fb[i].title);
        printf("%s\n", fb[i].name);
        printf("%s\n", fb[i].year);
    }
}

int find_film(film_item fb[], size_t fb_size, char *field, char *key)
{
    int left = 0;
    int right = fb_size - 1;
    int search = -1;
    if (strcmp(field, "title") == 0)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (strcmp(key, fb[mid].title) == 0)
            {
                search = mid;
                break;
            }
            if (strcmp(key, fb[mid].title) < 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    else if (strcmp(field, "name") == 0)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (strcmp(key, fb[mid].name) == 0)
            {
                search = mid;
                break;
            }
            if (strcmp(key, fb[mid].name) < 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    else
    {
        if (!check_year(key))
        {
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (strcmp(key, fb[mid].year) == 0)
                {
                    search = mid;
                    break;
                }
                if (strcmp(key, fb[mid].year) < 0)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        else
            return INCORRECT_YEAR_KEY;
    }
    if (search == -1)
        printf("Not found");
    else
    {
        printf("%s\n", fb[search].title);
        printf("%s\n", fb[search].name);
        printf("%s\n", fb[search].year);
    }
    return SUCCESS;
}

int check_year(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return INCORRECT_YEAR_KEY;
    return SUCCESS;
}