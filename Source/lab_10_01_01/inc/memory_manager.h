#ifndef __MEMORY_MANAGER_H__
#define __MEMORY_MANAGER_H__

#include "list.h"
#include <stdlib.h>

void list_wipe(node_t *head);
void del_node(node_t *node);
node_t *node_create(void *data);

#endif