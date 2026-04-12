#include <stdio.h>
#include <ctype.h>

struct Student {
    char name[30];
    int age;
};

int isValidName(char name[]) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (isdigit(name[i])) {
            return 0;
        }
    }
    return 1;
}

void addUser() {
    struct Student s;

    printf("enter name: ");
    scanf("%s", s.name);

    while (!isValidName(s.name)) {
    printf("Name cannot contain numbers! Try again: ");
    scanf("%s", s.name);
}

    printf("enter age: ");
    scanf("%d", &s.age);

    FILE *file = fopen("students.txt", "a");

    if (file == NULL) {
        printf("file is not exist\n");
        return;
    }

    fprintf(file, "%s %d\n", s.name, s.age);
    fclose(file);

    printf("user added\n");

}

int main( ) {
    int number;

    while(1) {
        printf("\n1 - add user\n");
        printf("2 - delete user\n");
        printf("3 - show user\n");
        printf("4 - uptdate user\n");
        printf("5 - exit\n\n");
        

        printf("write option: ");
        scanf("%d", &number);

        if(number ==5){
            break;
        }

        switch (number) {
            case 1:
                addUser();
                break;
            case 2:
                printf("delete user\n");
                break;
            case 3:
                printf("show user\n");
                break;
            case 4:
                printf("uptdate user\n");
                break;
            default:
                printf("\n");
        }
    }
    return 0;
}