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

int isValidAge(int age) {
    return age > 0 && age < 120;
}


void deleteUser() {
    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("No users to delete.\n");
        return;
    }

    struct Student students[100];
    int count = 0;

    //burda oxunur 
    while (fscanf(file, "%s %d", students[count].name, &students[count].age) != EOF) {
        count++;
    }

    fclose(file);

    // qosteririk
    for (int i = 0; i < count; i++) {
        printf("%d. %s %d\n", i + 1, students[i].name, students[i].age);
    }

    int index;
    printf("Select user to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid choice!\n");
        return;
    }

    for (int i = index - 1; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    count--;

    // telebeni silirik
    file = fopen("students.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", students[i].name, students[i].age);
    }

    fclose(file);

    printf("User deleted!\n");
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

    while (!isValidAge(s.age)) {
        printf("Invalid age! Try again: ");
        scanf("%d", &s.age);
    }

    FILE *file = fopen("students.txt", "a");

    if (file == NULL) {
        printf("file is not exist\n");
        return;
    }

    fprintf(file, "%s %d\n", s.name, s.age);
    fclose(file);

    printf("user added\n");

}

void showUsers() {
    FILE *file = fopen("students.txt", "r");

    if(file == NULL){
        printf("users not found\n");
        return;
    }
    struct Student s;
    int index = 1;


    printf("------------ ALL USERS -------------\n");
    while (fscanf(file, "%s %d", s.name, &s.age) != EOF) {
        printf("%d. Name: %s, Age: %d\n", index, s.name, s.age);
        index++;
    }
    printf("------------------------------------");

    fclose(file);
    
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
                deleteUser();
                break;
            case 3:
                showUsers();
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