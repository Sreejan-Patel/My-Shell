#include "ls.h"

// executes the commands ls with many of it's flags

void command_ls(token_mat arg){
    int flag_l = 0;
    int flag_a = 0;
    int flag_la = 0;
    int flag = 0;

    if(arg.num_args == 0){
        char* path = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
        strcat(path,".");

        ls(path,flag_a);
        free(path);
    }
    else if(arg.num_args == 1){
        unsigned int arg_length = strlen(arg.args[1]);
        if(arg.args[1][0] == '-')
            flag = 1;
        if(flag == 1){
            if(arg_length == 2 && strcmp(arg.args[1],"-l") == 0) {
                flag_l = 1;
                char *path = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
                strcat(path,".");
                ls_l(path,flag_a);
                free(path);
            }
            else if(arg_length == 2 && strcmp(arg.args[1],"-a") == 0){
                flag_a = 1;
                char *path = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
                strcat(path,".");
                ls(path,flag_a);
                free(path);
            }
            else if(arg_length == 3 && (strcmp(arg.args[1],"-la") == 0 || strcmp(arg.args[1],"-al") == 0)){
                flag_la = 1;
                flag_a = 1;
                flag_l = 1;
                char *path = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
                strcat(path,".");
                ls_l(path,flag_a);
                free(path);

            }
            return;
        }
        else{
            dir_arg(arg.args[1],flag_a,flag_l,flag_la);
        }

    }
    else if(arg.num_args >= 2){
        unsigned int num = arg.num_args;
        token_mat dir;
        dir = make_args_mat();
        dir.num_args = 0;
        int j = 0;
        for(int i = 1 ; i <= num ; i++){
            if(strcmp(arg.args[i],"-l") == 0)
                flag_l = 1;
            else if(strcmp(arg.args[i],"-a") == 0){
                flag_a = 1;
            }
            else if((strcmp(arg.args[i],"-la") == 0) || (strcmp(arg.args[i],"-al") == 0)){
                flag_la = 1;
                flag_a = 1;
                flag_l = 1;
            }

            else{
                strcat(dir.args[j],arg.args[i]);
                dir.num_args++;
                j++;

            }

        }

        if(flag_l == 1 && flag_a == 1){
            flag_la = 1;
        }
            if(dir.num_args == 0){
                dir.args[0] = ".";
                dir_arg(dir.args[0],flag_a,flag_l,flag_la);
            }

            else if(dir.num_args == 1){
                dir_arg(dir.args[0],flag_a,flag_l,flag_la);
            }
            else if(dir.num_args > 1){
                for(int i = 0 ; i < dir.num_args ; i++){
                    printf(ANSI_GREEN_BOLD "%s:\n" ANSI_DEFAULT,dir.args[i]);
                    dir_arg(dir.args[i],flag_a,flag_l,flag_la);
                    printf("\n");
                }

            }



    }






}

// checks the dir and calls for the req functions i.e ls_l or ls

void dir_arg(char* arg,int flag_a,int flag_l,int flag_la){

    struct dirent **namelist;
    int n;
    if(strcmp(arg,".") == 0){
        char path[MAX_TOKEN_LENGTH] = {0};
        strcat(path,".");
        if(flag_l != 1)
            ls(path,flag_a);
        else{
            if(flag_la == 1){
                flag_a = 1;
            }
            ls_l(path,flag_a);
        }
    }
    else if(strcmp(arg,"..") == 0){
        char path[MAX_TOKEN_LENGTH] = {0};
        strcat(path,"..");
        if(flag_l != 1)
            ls(path,flag_a);
        else{
            if(flag_la == 1){
                flag_a = 1;
            }
            ls_l(path,flag_a);
        }
    }
    else if(strcmp(arg,"~") == 0){
        char path[MAX_TOKEN_LENGTH] = {0};
        strcat(path,shell_path);
        if(flag_l != 1)
            ls(path,flag_a);
        else{
            if(flag_la == 1){
                flag_a = 1;
            }
            ls_l(path,flag_a);
        }
    }
    else if(arg[0] == '~' && arg[1] == '/'){
        char temp1[MAX_TOKEN_LENGTH] = {0};
        strcat(temp1,shell_path);
        strcat(temp1,"/");
        strcat(temp1,arg + 2);
        if(flag_l != 1)
            ls(temp1,flag_a);
        else{
            if(flag_la == 1){
                flag_a = 1;
            }
            ls_l(temp1,flag_a);
        }
    }
    else if(arg[0] == '.' && arg[1] == '.' && arg[2] == '/'){
        char path[MAX_TOKEN_LENGTH] = {0};
        strcat(path,"..");
        strcat(path,arg + 2);
        if(flag_l != 1)
            ls(path,flag_a);
        else{
            if(flag_la == 1){
                flag_a = 1;
            }
            ls_l(path,flag_a);
        }

    }
    else{
        char temp2[MAX_TOKEN_LENGTH] = {0};
        strcat(temp2,shell_path);
        strcat(temp2,"/");
        strcat(temp2,arg);
        if(flag_l != 1)
            ls(temp2,flag_a);
        else{
            if(flag_la == 1){
                flag_a = 1;
            }
            ls_l(temp2,flag_a);
        }
    }
}

// executes ls with/without -a

void ls(char* path,int flag_a){
    struct dirent **namelist;
    int n;

    n = scandir(path, &namelist, NULL, alphasort);
    if (n < 0){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: ls - scandir\n");
        error(error1);
        free(error1);
    }
    else{
        while(n--){
            if(flag_a == 0){
                if(namelist[n]->d_name[0] != '.') {
                    printf(ANSI_GREEN_BOLD "%s\n" ANSI_DEFAULT ,namelist[n]->d_name);
                    free(namelist[n]);
                }
            }
            else{
                printf(ANSI_GREEN_BOLD "%s\n" ANSI_DEFAULT, namelist[n]->d_name);
                free(namelist[n]);
            }


        }
        free(namelist);

    }
}

// executes ls with -l flag and with/without -a flag

void ls_l(char* path,int flag_a){
    DIR *dir = opendir(path);
    if(dir == NULL) {
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: ls_l - opendir\n");
        error(error1);
        free(error1);
        return;
    }

    long long int total = get_block_size(path,flag_a);
    printf(ANSI_GREEN_BOLD "total %lld\n" ANSI_DEFAULT ,total);
    struct dirent *input_dir;
    while((input_dir = readdir(dir)) != NULL){
        if(flag_a == 0){
            if(input_dir->d_name[0] != '.'){
                struct stat buffer;
                char *fp = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
                sprintf(fp, "%s/%s", path, input_dir->d_name);
                if(stat(fp, &buffer) == -1) {
                    char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
                    sprintf(error1,"Error: ls_l - stat\n");
                    error(error1);
                    free(error1);
                    return;
                }

                // permissions
                if((S_ISDIR(buffer.st_mode)))
                    printf(ANSI_GREEN_BOLD "d" ANSI_DEFAULT);
                else if((S_ISBLK(buffer.st_mode)))
                    printf(ANSI_GREEN_BOLD "b" ANSI_DEFAULT);
                else if((S_ISCHR(buffer.st_mode)))
                    printf(ANSI_GREEN_BOLD "c" ANSI_DEFAULT);
                else if((S_ISLNK(buffer.st_mode)))
                    printf(ANSI_GREEN_BOLD "l" ANSI_DEFAULT);
                else if((S_ISFIFO(buffer.st_mode)))
                    printf(ANSI_GREEN_BOLD "p" ANSI_DEFAULT);
                else if((S_ISSOCK(buffer.st_mode)))
                    printf(ANSI_GREEN_BOLD"s"ANSI_DEFAULT);
                else if((S_ISREG(buffer.st_mode)))
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"n"ANSI_DEFAULT);


                if((buffer.st_mode & S_IRUSR))
                    printf(ANSI_GREEN_BOLD"r"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                if((buffer.st_mode & S_IWUSR))
                    printf(ANSI_GREEN_BOLD"w"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                if((buffer.st_mode & S_IXUSR))
                    printf(ANSI_GREEN_BOLD"x"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                if((buffer.st_mode & S_IRGRP))
                    printf(ANSI_GREEN_BOLD"r"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                if((buffer.st_mode & S_IWGRP))
                    printf(ANSI_GREEN_BOLD"w"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                if((buffer.st_mode & S_IXGRP))
                    printf(ANSI_GREEN_BOLD"x"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                if((buffer.st_mode & S_IROTH))
                    printf(ANSI_GREEN_BOLD"r"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                if((buffer.st_mode & S_IWOTH))
                    printf(ANSI_GREEN_BOLD"w"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                if((buffer.st_mode & S_IXOTH))
                    printf(ANSI_GREEN_BOLD"x"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
                if((buffer.st_mode & S_IEXEC))
                    printf(ANSI_GREEN_BOLD"@"ANSI_DEFAULT);
                else
                    printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);

                printf(ANSI_GREEN_BOLD" %lu\t"ANSI_DEFAULT, buffer.st_nlink);


                printf(ANSI_GREEN_BOLD"%s "ANSI_DEFAULT,user_name);

                struct group *grp;
                grp = getgrgid(buffer.st_gid);
                printf(ANSI_GREEN_BOLD"%s "ANSI_DEFAULT,grp->gr_name);

                printf(ANSI_GREEN_BOLD"\t%ld\t"ANSI_DEFAULT, buffer.st_size);

                long int time0;
                time(&time0);
                long int time1 = buffer.st_mtime;
                long double sec = difftime(time0,time1);
                if(sec >= 15636400){
                    char *time = ctime(&buffer.st_mtime);
                    char *time_stamp = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
                    strncpy(time_stamp,time+4,6);
                    strncat(time_stamp,time+19,5);
                    printf(ANSI_GREEN_BOLD"%s\t"ANSI_DEFAULT,time_stamp);
                    free(time_stamp);
                }
                else {
                    char *time = ctime(&buffer.st_mtime);
                    char *time_stamp = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
                    strncpy(time_stamp,time+4,12);
                    printf(ANSI_GREEN_BOLD"%s\t"ANSI_DEFAULT,time_stamp);
                    free(time_stamp);
                }

                printf(ANSI_GREEN_BOLD"%s\n"ANSI_DEFAULT,input_dir->d_name);
            }
        }
        else{
            struct stat buffer;
            char *fp = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
            sprintf(fp, "%s/%s", path, input_dir->d_name);
            if(stat(fp, &buffer) == -1) {
                char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
                sprintf(error1,"Error: ls_l - stat\n");
                error(error1);
                free(error1);
                return;
            }

            // permissions
            if((S_ISDIR(buffer.st_mode)))
                printf(ANSI_GREEN_BOLD"d"ANSI_DEFAULT);
            else if((S_ISBLK(buffer.st_mode)))
                printf(ANSI_GREEN_BOLD"b"ANSI_DEFAULT);
            else if((S_ISCHR(buffer.st_mode)))
                printf(ANSI_GREEN_BOLD"c"ANSI_DEFAULT);
            else if((S_ISLNK(buffer.st_mode)))
                printf(ANSI_GREEN_BOLD"l"ANSI_DEFAULT);
            else if((S_ISFIFO(buffer.st_mode)))
                printf(ANSI_GREEN_BOLD"p"ANSI_DEFAULT);
            else if((S_ISSOCK(buffer.st_mode)))
                printf(ANSI_GREEN_BOLD"s"ANSI_DEFAULT);
            else if((S_ISREG(buffer.st_mode)))
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"n"ANSI_DEFAULT);


            if((buffer.st_mode & S_IRUSR))
                printf(ANSI_GREEN_BOLD"r"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
            if((buffer.st_mode & S_IWUSR))
                printf(ANSI_GREEN_BOLD"w"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
            if((buffer.st_mode & S_IXUSR))
                printf(ANSI_GREEN_BOLD"x"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
            if((buffer.st_mode & S_IRGRP))
                printf(ANSI_GREEN_BOLD"r"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
            if((buffer.st_mode & S_IWGRP))
                printf(ANSI_GREEN_BOLD"w"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
            if((buffer.st_mode & S_IXGRP))
                printf(ANSI_GREEN_BOLD"x"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
            if((buffer.st_mode & S_IROTH))
                printf(ANSI_GREEN_BOLD"r"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
            if((buffer.st_mode & S_IWOTH))
                printf(ANSI_GREEN_BOLD"w"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);
            if((buffer.st_mode & S_IXOTH))
                printf(ANSI_GREEN_BOLD"x"ANSI_DEFAULT);
            else
                printf(ANSI_GREEN_BOLD"-"ANSI_DEFAULT);

            printf(ANSI_GREEN_BOLD" %lu\t"ANSI_DEFAULT, buffer.st_nlink);


            printf(ANSI_GREEN_BOLD"%s "ANSI_DEFAULT,user_name);

            struct group *grp;
            grp = getgrgid(buffer.st_gid);
            printf(ANSI_GREEN_BOLD"%s "ANSI_DEFAULT,grp->gr_name);

            printf(ANSI_GREEN_BOLD"\t%ld\t"ANSI_DEFAULT, buffer.st_size);

            long int time0;
            time(&time0);
            long int time1 = buffer.st_mtime;
            long double sec = difftime(time0,time1);
            if(sec >= 15636400){
                char *time = ctime(&buffer.st_mtime);
                char *time_stamp = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
                strncpy(time_stamp,time+4,6);
                strncat(time_stamp,time+19,5);
                printf(ANSI_GREEN_BOLD"%s\t"ANSI_DEFAULT,time_stamp);
                free(time_stamp);
            }
            else {
                char *time = ctime(&buffer.st_mtime);
                char *time_stamp = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
                strncpy(time_stamp,time+4,12);
                printf(ANSI_GREEN_BOLD"%s\t"ANSI_DEFAULT,time_stamp);
                free(time_stamp);
            }

            printf(ANSI_GREEN_BOLD"%s\n"ANSI_DEFAULT,input_dir->d_name);
        }
    }



}

// gets the total block size

long long int get_block_size(char* directory,int flag_a) {
    long long int size = 0;

    DIR *d;
    struct dirent *dir;
    struct stat fileStat;
    d = opendir(directory);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if(flag_a == 0){
                if (dir->d_name[0] != '.') {                                // Ignore hidden files
                    char info_path[MAX_TOKEN_LENGTH + 1];
                    strcpy(info_path, directory);
                    if (directory[strlen(directory) - 1] != '/')
                        strcat(info_path, "/");
                    strcat(info_path, dir->d_name);

                    stat(info_path, &fileStat);

                    size += fileStat.st_blocks;
                }
            }
            else{
                char info_path[MAX_TOKEN_LENGTH + 1];
                strcpy(info_path, directory);
                if (directory[strlen(directory) - 1] != '/')
                    strcat(info_path, "/");
                strcat(info_path, dir->d_name);

                stat(info_path, &fileStat);

                size += fileStat.st_blocks;
            }
        }
    }

    return size;
}