#include "queries.h"

int main(){

    MYSQL* con = connection();

    int opt = 0;

    printf("1.- CREATE\n2.- READ");
    printf("\nEnter option: ");
    scanf("%d", &opt);
    if(opt == 1){
        create(con);
    }else{
        read_data(con);
    }

    closeConnection(con);

    return 0;
}