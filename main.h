#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "config.h" // MySQL credentials.

#define MAX_STRING 255
#define MAX_COLUMS 255

// Prototypes
int init();
void create();