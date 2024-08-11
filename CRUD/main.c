#include "queries.h"

int main(){

    MYSQL* con = connection();

    int opt = 0;

    printf("1.- CREATE\n2.- READ\n3.- UPDATE\n4.- DELETE");
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
        default:
            printf("\nEnter a valid option.\n");
        break;
    }

    closeConnection(con);

    return 0;
}