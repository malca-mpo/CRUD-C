#include "queries.h"

int main(){

    MYSQL* con = connection();

    int opt = 0;

    

    do{
    printf("\n----CRUD----\n");
    printf("1.- CREATE\n2.- READ\n3.- UPDATE\n4.- DELETE\n5.- EXIT");
    printf("\nEnter option: ");
    scanf("%d", &opt);
    switch (opt){
        case 1:
            create(con);
        break;
        case 2:
            read_data(con);
        break;
        case 3:
            update(con);
        break;
        case 4:
            delete(con);
        break;
        case 5:
            closeConnection(con);
            printf("\nBye.\n");
            break;
        default:
            printf("\nEnter a valid option.\n");
        break;
    }
    }while(opt != 5);

    return 0;
}