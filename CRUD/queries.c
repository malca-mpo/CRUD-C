#include "queries.h"

MYSQL* connection(){
    MYSQL* con = mysql_init(NULL);
    if(!con){
      fprintf(stderr, "%s\n", mysql_error(con));
      return NULL;
    }

    if(!mysql_real_connect(con, HOST, USER, PASSWORD, NAME, PORT, NULL, 0)){
      fprintf(stderr, "%s\n", mysql_error(con));
      return NULL;
    }

    return con;
}

void closeConnection(MYSQL* con){
    mysql_close(con);
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
      return;
    }else{
      printf("\nData enter into database succesfully!\n");
    }

}

void read_data(MYSQL* con){

    if(mysql_query(con, "SELECT * FROM CRUD.USER")){
      printf("\nError jaskdas\n");
    }

    MYSQL_RES* res = mysql_store_result(con);
    if(!res){
      printf("\nERROR PUTITO\n");
    }

    int num_fields = mysql_num_fields(res);

    MYSQL_ROW row;

    while((row = mysql_fetch_row(res))){
        for(int i = 0; i < num_fields; i++){
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

}