#include "main.h"

MYSQL* connection(){
    MYSQL* con = mysql_init(NULL);
    if(!con){
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      return NULL;
    }

    if(!mysql_real_connect(con, HOST, USER, PASSWORD, NAME, PORT, NULL, CLIENT_MULTI_STATEMENTS)){
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      return NULL;
    }

    return con;
}

void create(MYSQL* con){

    char name[MAX_STRING], lastname[MAX_STRING], query[MAX_QUERY];

  
    printf("\nEnter the name: ");
    scanf("%s", name);
    printf("\nEnter last name: ");
    scanf("%s", lastname);

    snprintf(query, sizeof(query), "INSERT INTO USER (NAME, LASTNAME) VALUES ('%s', '%s')", name, lastname);

    if(mysql_query(con, query)){
      printf("\nOops!, something went wrong when inserting the data into database!\n");
      mysql_close(con);
      return;
    }else{
      printf("\nData enter into database succesfully!\n");
    }

}