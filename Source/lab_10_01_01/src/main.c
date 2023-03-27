#define __USE_MINGW_ANSI_STDIO

#include "err_codes.h"
#include "memory_manager.h"
#include "chronicle.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    event_t database[100];
    size_t db_size = 0;
    if (argc == 4 && strcmp(argv[3], "pop_front"))
    {
        FILE *f_in = fopen(argv[1], "r");
        if (f_in == NULL)
            return NO_FILE;
        if (fread_chronicles(f_in, database, &db_size))
        {
            fclose(f_in);
            return INCORRECT_CONTENT;
        }
        fclose(f_in);
        node_t *head;
        if (form_list(database, db_size, &head))
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        event_t *event;
        event = pop_front(&head);
        FILE *f_out = fopen(argv[2], "w");
        if (f_out == NULL)
        {
            list_wipe(head);
            return NO_FILE;
        }
        fprintf(f_out, "%s\n", event->title);
        fprintf(f_out, "%s\n", event->year);
        fclose(f_out);
        list_wipe(head);
        return SUCCESS;
    }
    else if (argc == 4 && strcmp(argv[3], "copy"))
    {
        FILE *f_in = fopen(argv[1], "r");
        if (f_in == NULL)
            return NO_FILE;
        if (fread_chronicles(f_in, database, &db_size))
        {
            fclose(f_in);
            return INCORRECT_CONTENT;
        }
        fclose(f_in);
        node_t *head;
        if (form_list(database, db_size, &head))
            return UNSUCCESSFUL_MEMORY_ALLOCATION;

        node_t *copy_head;
        if (copy(head, &copy_head))
        {
            list_wipe(head);
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        }
        FILE *f_out = fopen(argv[2], "w");
        if (f_out == NULL)
        {
            list_wipe(head);
            return NO_FILE;
        }
        fprint_chronicles(f_out, copy_head);
        list_wipe(head);
        list_wipe(copy_head);
        fclose(f_out);
        return SUCCESS;
    }
    else if (argc == 4 && strcmp(argv[3], "sort"))
    {
        FILE *f_in = fopen(argv[1], "r");
        if (f_in == NULL)
            return NO_FILE;
        if (fread_chronicles(f_in, database, &db_size))
        {
            fclose(f_in);
            return INCORRECT_CONTENT;
        }
        fclose(f_in);
        node_t *head;
        if (form_list(database, db_size, &head))
            return UNSUCCESSFUL_MEMORY_ALLOCATION;
        head = sort(head, &cmp_chronicles);
        FILE *f_out = fopen(argv[2], "w");
        if (f_out == NULL)
        {
            list_wipe(head);
            return NO_FILE;
        }
        fprint_chronicles(f_out, head);
        fclose(f_out);
        list_wipe(head);
        return SUCCESS;
    }
    else
        return INCORRECT_PARAMS;
}