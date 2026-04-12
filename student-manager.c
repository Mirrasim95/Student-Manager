#include <stdio.h>

int main( ) {
    int pick;

    while(1) {
        printf("add user\n");
        printf("delete user\n");
        printf("show user\n");
        printf("uptdate user\n");
        printf("exit\n");
        

        printf("write option: ");
        scanf("%d", &pick);

        if(pick ==5){
            break;
        }

        switch (choice) {
            case 1:
                printf("Add user selected\n");
                break;
            case 2:
                printf("Delete user selected\n");
                break;
            case 3:
                printf("Show users selected\n");
                break;
            case 4:
                printf("Update user selected\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}