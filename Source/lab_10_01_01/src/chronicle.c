#include "chronicle.h"
#include "err_codes.h"

#include <string.h>
#include <ctype.h>

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

int read_event(FILE *file, event_t *event)
{
    if (read_line(file, event->title, MAX_STR_LEN + 1) == INCORRECT_CONTENT)
        return INCORRECT_CONTENT;
    if (feof(file))
        return EOF;

    if (read_line(file, event->year, MAX_NUMS + 1) == INCORRECT_CONTENT || check_year(event->year) || strlen(event->year) == 0)
        return INCORRECT_CONTENT;

    return SUCCESS;
}

int check_year(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return INCORRECT_CONTENT;
    return SUCCESS;
}

int fread_chronicles(FILE *file, event_t db[], size_t *db_size)
{
    int e_c = SUCCESS;
    size_t i = 0;
    event_t buf;

    while (e_c == SUCCESS)
    {
        e_c = read_event(file, &buf);
        if (e_c == SUCCESS)
            db[i++] = buf;
        if (e_c != EOF && i == MAX_RECS)
            e_c = INCORRECT_CONTENT;
    }
    *db_size = i;

    if (e_c == EOF && *db_size > 0)
        return SUCCESS;
    else
        return e_c;
}

void fprint_chronicles(FILE *f, node_t *head)
{
    for (; head; head = head->next)
    {
        fprintf(f, "%s\n", (*(event_t *)(head->data)).title);
        fprintf(f, "%s\n", (*(event_t *)(head->data)).year);
    }
}

int form_list(event_t db[], size_t db_size, node_t **head)
{
    node_t *ptr;
    for (size_t i = 0; i < db_size; i++)
    {
        node_t *tmp = node_create(db + i);
        if (tmp == NULL)
        {
            list_wipe(*head);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        if (*head == NULL)
        {
            *head = tmp;
            ptr = tmp;
        }
        else
        {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }
    return SUCCESS;
}

int cmp_chronicles(const void *ptr1, const void *ptr2)
{
    return strcmp((*(event_t*)ptr1).year, (*(event_t*)ptr2).year);
}
