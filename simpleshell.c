#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
#include <windows.h>
#define chdir _chdir

#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n"

void greeting() {
    printf("\n\n\n\n******************"
        "************************");
    printf("\n\n\n\t***SHELL***");
    printf("\n\n\tSTART WITH THE COMMAND HELP");
    printf("\n\n\n\n*******************"
        "***********************");
    printf("\n\n\n");
   
    return;
}

const char *instructions = "\nREAD THE INSTRUCTIONS BELOW***";

	static char *username = (const char *)getenv("USER");

	printf("The username is %s\n", username);



void openHelp() {

	  printf("Welcome to Shell, %s!\n", args);

  puts(instructions);

        printf("\nList of Commands supported:");
        printf("\n>cd");
        printf("\n>mkdir");
        printf("\n>rmdir");
        printf("\n>echo");
        printf("\n>pwd");
        printf("\n>help");
        printf("\n>date");
        printf("\n>exit");
        printf("\n>ls");
        printf("\n>clear");
        printf("\n");

  return 1;
}

void date() {
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);

    return;
}

void pwd() {
    char* PWD = (char*)malloc(1024 * sizeof(char));
    if (getcwd(PWD, 1024) == NULL) {
        perror("getcwd() error");
        exit(1);
    }

    else printf("%s\n", PWD);
    free(PWD);
    return;
}

void echo(char* command) {
    char* token = command;
    token = strtok(NULL, "\"\n\t\r");
    while (token != NULL) {
        printf("%s", token);
        token = strtok(NULL, "\"\n\t\r");
    }
    printf("\n");
    return;
}

void createDir(char* name) {
    char* token = name;
    token = strtok(NULL, "\"\n\t\r");
    while (token != NULL) {
        int stat = mkdir(token, 0777);
        token = strtok(NULL, "\"\n\t\r");
        
        if (stat == -1) {
            perror("Error in mkdir");
        }
    
    }

    return;
}

void removeDir(char* name) {
    char* token = name;
    token = strtok(NULL, "\"\n\t\r");
    while (token != NULL) {
        int stat = rmdir(token);
        token = strtok(NULL, "\"\n\t\r");

        if (stat == -1) {
            perror("Error in rmdir");
        }
    }

    return;
}

void cd(char* name) {
    if (!name) chdir("/");
    else chdir(name);
    
    return;
}

int main(int argc, char* argv[]) {
        char* cmd;
        char line[MAX_LENGTH];
        
        greeting();

        while (1) {
            printf("> ");
            if (!fgets(line, MAX_LENGTH, stdin)) break;

            if ((cmd = strtok(line, DELIMS))) {
                errno = 0;
                
                if (strcmp(cmd, "echo") == 0) {
                    echo(line);
                }

                else if(strcmp(cmd, "mkdir") == 0 ) {
                    createDir(line);
                }

                else if(strcmp(cmd, "rmdir") == 0 ) {
                    removeDir(line);
                }

                else if (strcmp(cmd, "date") == 0 ) {
                    date();
                }

                else if(strcmp(cmd, "pwd") == 0) {
                    pwd();
                }

                else if (strcmp(cmd, "help") == 0) {
                    openHelp(argv);
               
                } else if (strcmp(cmd, "cd") == 0) {
                    char* arg = strtok(0, DELIMS);
                    cd(arg);
               
                } else if (strcmp(cmd, "exit") == 0) {
                    break;
               
                } else system(line);

                if (errno) perror("Command failed");
            }
        }
    return 0;
}
