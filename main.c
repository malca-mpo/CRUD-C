#include "queries.c"

int main(){

    MYSQL* con = connection();

    if(!con){
        printf("Ups! Error initializing database!\n");
        exit(1);
    }

    int opt;
    printf("-----------------CRUD IN C-----------------\n");
    printf("1.-Create\n2.-Read\n3.-Update\n4.-Delete\n");
    printf("Enter your option: ");
    scanf("%d", &opt);

        

    return 0;
}