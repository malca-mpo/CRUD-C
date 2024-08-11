#ifndef QUERIES_H
#define QUERIES_H

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h" // MySQL credentials.

#define MAX_STRING 100
#define MAX_QUERY 255

// Prototypes
MYSQL* connection();
void closeConnection(MYSQL* con);
void create(MYSQL* con);
void read_data(MYSQL* con);
void update(MYSQL* con);


#endif