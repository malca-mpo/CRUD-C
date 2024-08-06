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
    int numberColums;
    char tableName[MAX_STRING];
    char columName[MAX_STRING];
    char columType[MAX_STRING];
    char query[MAX_STRING * MAX_COLUMS];

    printf("\nEnter the table name: ");
    scanf(" %[^\n]", tableName);
    printf("\nEnter the number of columns: ");
    scanf("%d", &numberColums);

    // Start building the query
    snprintf(query, sizeof(query), "CREATE TABLE %s (", tableName);

    for(int i = 0; i < numberColums; i++){
      printf("\nEnter column %d name: ", i+1);
      scanf(" %[^\n]", columName);

      printf("\nEnter column %d type (e.g., INT, VARCHAR(100)): ", i+1);
      scanf(" %[^\n]", columType);

      if(i > 0){
        strncat(query, ", ", sizeof(query) - strlen(query) - 1);
      }
        
          snprintf(query + strlen(query), sizeof(query) - strlen(query), "%s %s", columName, columType);
    }
          strncat(query, ");", sizeof(query) - strlen(query));

    // Print full query
    printf("SQL Query: %s\n", query);

    if(mysql_query(con, query)){
        fprintf(stderr, "\nCREATE TABLE FAILED. Error: %s\n", mysql_error(con));
    }else{
        printf("\nTable create succesfully.\n");
    }
}

