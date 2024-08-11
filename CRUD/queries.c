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
      printf("\nError with query!\n");
    }

    MYSQL_RES* res = mysql_store_result(con);
    if(!res){
      printf("\nError storing result!\n");
    }

    int num_fields = mysql_num_fields(res);

    MYSQL_ROW row;

    printf("\n");
    while((row = mysql_fetch_row(res))){
        for(int i = 0; i < num_fields; i++){
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

void update(MYSQL* con){

  int id;
  char query[MAX_QUERY];
  char name[MAX_STRING], lastname[MAX_STRING];
    printf("\nEnter user id: ");
    scanf("%d", &id);
    snprintf(query, sizeof(query),"SELECT COUNT(*) FROM CRUD.USER WHERE ID=%d", id);

    if(mysql_query(con, query)){
        fprintf(stderr, "MYSQL: %s", mysql_error(con));
    }

    MYSQL_RES* res = mysql_store_result(con);
    if(!res){
      fprintf(stderr, "MYSQL: %s", mysql_error(con));
    }
    MYSQL_ROW row = mysql_fetch_row(res);
    int count = atoi(row[0]);

    if(count == 0){
      printf("\nThe entered id does not exist.\n");
      return;
    }

    printf("\nEnter the new name: ");
    scanf(" %[^\n]", name);
    printf("\nEnter the new lastname: ");
    scanf(" %[^\n]", lastname);

    snprintf(query, sizeof(query),"UPDATE CRUD.USER SET NAME='%s', LASTNAME='%s' WHERE ID=%d", name, lastname, id);

    if(mysql_query(con, query)){
      fprintf(stderr ,"\nMY SQL: %s\n", mysql_error(con));
    }

    printf("\nUSER UPDATE SUCCESFULLY.\n");

    mysql_free_result(res);

}

void delete(MYSQL* con){
    int id;
    char query[MAX_QUERY];

    printf("\nEnter user id: ");
    scanf("%d", &id);
    snprintf(query, sizeof(query),"SELECT COUNT(*) FROM CRUD.USER WHERE ID=%d", id);

    if(mysql_query(con, query)){
        fprintf(stderr, "MYSQL: %s", mysql_error(con));
    }

    MYSQL_RES* res = mysql_store_result(con);
    if(!res){
      fprintf(stderr, "MYSQL: %s", mysql_error(con));
    }
    MYSQL_ROW row = mysql_fetch_row(res);
    int count = atoi(row[0]);

    if(count == 0){
      printf("\nThe entered id does not exist.\n");
      return;
    }

    snprintf(query, sizeof(query), "DELETE FROM CRUD.USER WHERE ID=%d", id);

    if(mysql_query(con, query)){
     fprintf(stderr, "MY SQL: %s", mysql_error(con));
    }  

     printf("\nUSER DELETED SUCCESFULLY.\n");

    mysql_free_result(res); 
}