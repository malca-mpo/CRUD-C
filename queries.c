#include "main.h"

int init(){
    MYSQL* con = mysql_init(NULL);
    if(!con){
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
      return 0;
    }

    if(!mysql_real_connect(con, HOST, USER, PASSWORD, NAME, PORT, NULL, 0)){
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
      return 0;
    }

    
    return 1;
}