#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyFile(const char *sourceFile, const char *destinationFile, int convertCase) {
    FILE *source, *destination;
    char ch;

    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error opening source file.\n");
        exit(1);
    }

    destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Error creating destination file.\n");
        exit(1);
    }

    while ((ch = fgetc(source)) != EOF) {
        if (convertCase == 1)
            ch = toupper(ch);
        else if (convertCase == -1)
            ch = tolower(ch);
        else if (convertCase == 2)
            ch = islower(ch) ? toupper(ch) : ch;
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);
}

int main(int argc, char *argv[]) {
    int convertCase = 0;

    if (argc == 4) {
        if (argv[1][0] == '-' && argv[1][1] != '\0') {
            switch (argv[1][1]) {
                case 'u':
                    convertCase = 1;
                    break;
                case 'l':
                    convertCase = -1;
                    break;
                case 's':
                    convertCase = 2;
                    break;
                default:
                    printf("Invalid option.\n");
                    exit(1);
            }
        } else {
            printf("Invalid option.\n");
            exit(1);
        }
    }

    if (argc == 3 || argc == 4) {
        copyFile(argv[argc - 2], argv[argc - 1], convertCase);
    } else {
        printf("Invalid number of arguments.\n");
        exit(1);
    }

    return 0;
}
