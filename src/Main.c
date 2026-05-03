#if defined __linux__
#include "/home/codeleaded/System/Static/Library/CStr.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#define WALKER_PATH "/home/codeleaded/Hecke/C"
#elif defined _WINE
#include "/home/codeleaded/System/Static/Library/CStr.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#define WALKER_PATH "/home/codeleaded/Hecke/C"
#elif defined _WIN32
#include "F:/home/codeleaded/System/Static/Library/CStr.h"
#include "F:/home/codeleaded/System/Static/Library/Files.h"
#define WALKER_PATH "F:/home/codeleaded/Hecke/C"
#endif

/*
Windows:
TerminalCtl.h
Networking.h
InputMouse.h
Console_PB.h
HttpServer.h
Lib3D_Math.h
RLCamera.h
VM16_Devices.h
AlxParser.h
WindowEngineGL1.0.h

Linux:


Both:

*/

void Run_Cmd_Old(char* path) {
    char cwd[512];
    if (getcwd(cwd,sizeof(cwd)) != NULL) {
        if(CStr_Cmp(path,cwd)) return;
    } else {
        perror("getcwd() error");
        return;
    }
    
    printf(">> In directory: %s (%s)\n",path,basename(path));

    // char* bn = basename(path);
    // if(
    //     CStr_Cmp(bn,"Cmd_Walker") ||
    //     CStr_Cmp(bn,"Win_WINAPI")
    // ){
    //     return;
    // }
    // if(bn[0] == 'G' && bn[1] == 'u' && bn[2] == 'i'){
    //     if(!Files_HasSub(path,"bin")){
    //         char name[1024];
    //         snprintf(name,sizeof(name),"%s/Makefile.web",path);
    //         Files_CpyT("/home/codeleaded/Hecke/C/Gui_WINAPI/Makefile.web",name);
    //     }
    // }else if(bn[0] == 'C' && bn[1] == 'm' && bn[2] == 'd'){
    //     if(!Files_HasSub(path,"bin")){
    //         char name[1024];
    //         snprintf(name,sizeof(name),"%s/Makefile.web",path);
    //         Files_CpyT("/home/codeleaded/Hecke/C/Cmd_Walker/Makefile.web",name);
    //     }
    // }

    //Files_Rm_Path(path,"LICENSE");
    //Files_Rm_Path(path,".gitignore");
    //Files_Rm_Path(path,"README.md");
    //Files_Rm_Path(path,".git");

    // char name1[1024];
    // snprintf(name1,sizeof(name1),"%s/LICENSE",path);
    // Files_CpyT("./LICENSE",name1);

    //char name2[1024];
    //snprintf(name2,sizeof(name2),"%s/.gitignore",path);
    //Files_CpyT("./.gitignore",name2);

    // char name3[1024];
    // snprintf(name3,sizeof(name3),"%s/README.md",path);
    // Files_CpyT("./README.md",name3);

    // printf(">> Files added: %s\n", path);

    //char* bn = basename(path);
    //if(bn[0] == 'W' && bn[1] == 'i' && bn[2] == 'n'){
    // if(bn[0] == 'G' && bn[1] == 'u' && bn[2] == 'i'){
    //     char oldname[1024];
    //     snprintf(oldname,sizeof(oldname),"Win%s",bn + 3);

    //     char newname[1024];
    //     snprintf(newname,sizeof(newname),"Gui%s",bn + 3);

    //     printf(">> [%s] Rename: %s to %s\n",path,bn,newname);

    //     char cmd[1024];
    //     snprintf(
    //         cmd,
    //         sizeof(cmd),
    //         "cd %s;"
    //         "gh repo rename %s --yes;"
    //         "git remote set-url origin https://github.com/codeleaded/%s.git;"
    //         "cd %s; mv %s %s"
    //         ,path,newname,newname
    //         ,dirname(path),bn,newname
    //     );
    //     printf(">> Execute: %s\n", cmd);
    //     int ret = system(cmd);
    //     printf(">> Done: %s\n", path);
    // }

    char cmd[1024];
    
    //snprintf(
    //    cmd,
    //    sizeof(cmd),
    //    "cd %s; git init; git add .; git commit -m \"init commit\"";
    //    "git remote add origin https://github.com/codeleaded/%s.git";
    //    "git push --force --set-upstream origin master",
    //    path,basename(path)
    //    //gh repo create %s --public --source=. --remote=origin --push;
    //);

    snprintf(
        cmd,
        sizeof(cmd),
        "cd %s;"
        //"git config user.email \"gnu.c.reaper@gmail.com\";"
        //"git filter-repo --commit-callback '\n"
        //"if commit.author_email == b\"codeleaded@gmail.com\":\n"
        //"    commit.author_email = b\"gnu.c.reaper@gmail.com\"\n"
        //"    commit.author_name = b\"C-Reaper\"\n"
        //"if commit.committer_email == b\"codeleaded@gmail.com\":\n"
        //"    commit.committer_email = b\"gnu.c.reaper@gmail.com\"\n"
        //"    commit.committer_name = b\"C-Reaper\"\n"
        //"' --force;"
        //"git remote set-url origin https://github.com/C-Reaper/%s.git;"
        //"git remote remove origin;"
        //"git remote add origin https://github.com/C-Reaper/%s.git;"
        //"make -f Makefile.linux clean; make -f Makefile.linux all;"
        "git add .; git commit -m \"update\";"
        "git push --force --set-upstream origin master"
        ,path//,basename(path)
    );

    
    //printf(">> execute: %s\n", cmd);
    int ret = system(cmd);

    if (ret == -1) {
        perror("system failed");
    } else {
        if (WIFEXITED(ret)) {
            const int exit_code = WEXITSTATUS(ret);
            printf(">> done: %s -> %d\n",path,exit_code);
        } else if (WIFSIGNALED(ret)) {
            //printf(">> killed: signal %d\n",WTERMSIG(ret));
            exit(1);
        } else {
            //printf(">> Unknown termination!\n");
        }
    }
}

void Run_Cmd(char* path) {
    char* bn = basename(path);
    //printf(">> In directory: %s (%s)\n",path,bn);
    
    char cmd[1024];
    snprintf(
        cmd,
        sizeof(cmd),
        "cd %s;"
        //"git config user.email \"gnu.c.reaper@gmail.com\";"
        //"git filter-repo --commit-callback '\n"
        //"if commit.author_email == b\"codeleaded@gmail.com\":\n"
        //"    commit.author_email = b\"gnu.c.reaper@gmail.com\"\n"
        //"    commit.author_name = b\"C-Reaper\"\n"
        //"if commit.committer_email == b\"codeleaded@gmail.com\":\n"
        //"    commit.committer_email = b\"gnu.c.reaper@gmail.com\"\n"
        //"    commit.committer_name = b\"C-Reaper\"\n"
        //"' --force;"
        //"git init;"
        //"git remote add origin https://github.com/C-Reaper/%s.git;"
        //"git fetch;"
        //"git reset --hard origin/master;"
        //"git remote set-url origin https://github.com/C-Reaper/%s.git;"
        //"git remote remove origin;"
        //"git remote add origin https://github.com/C-Reaper/%s.git;"
        //"make -f Makefile.linux clean;"
        //"make -f Makefile.linux all;"
        //"make -f Makefile.wine all;"
        //"make -f Makefile.web all;"
        "git add .; git commit -m \"update\";"
        "git push --force --set-upstream origin master"
        ,path//,basename(path)
    );

    // WARNINGS = -Werror
    // CFLAGS = -O0 -mavx2 -std=gnu17 $(WARNINGS)

    if(CStr_CmpLike(bn,"Cmd_*",'*')){
        printf(">> Cmd: %s\n",bn);

        //if(!Files_HasSub(path,".git")){
        //    printf(">>   No dir .git: %s\n", bn);
        //    return;
        //}

        //if(Files_HasSub(path,"build")){
        //    char build[1024];
        //    snprintf(
        //        build,
        //        sizeof(build),
        //        "%s/build",path
        //    );
        //    Files_Rmdir_R(build);
        //    Files_Mkdir(build);
        //}

        //char file[1024];
        //snprintf(
        //    file,
        //    sizeof(file),
        //    "%s/Makefile.web",path
        //);
        //Files_CpyT("/home/codeleaded/Hecke/C/Cmd_Walker/Makefile.web",file);

        printf(">>   Execute: %s\n", cmd);
        int ret = system(cmd);

        if (ret == -1) {
            perror("system failed");
        } else {
            if (WIFEXITED(ret)) {
                const int exit_code = WEXITSTATUS(ret);
                printf(">>   Done: %s -> %d\n",path,exit_code);
                
                //if(exit_code)
                //    exit(1);
            } else if (WIFSIGNALED(ret)) {
                printf(">>   Killed: signal %d\n",WTERMSIG(ret));
                exit(1);
            } else {
                printf(">>   Unknown termination!\n");
            }
        }
    }else if(CStr_CmpLike(bn,"Gui_*",'*')){
        printf(">> Gui: %s\n",bn);
        
        //if(!Files_HasSub(path,".git")){
        //    printf(">>   No dir .git: %s\n", bn);
        //    return;
        //}
        
        //if(Files_HasSub(path,"build")){
        //    char build[1024];
        //    snprintf(
        //        build,
        //        sizeof(build),
        //        "%s/build",path
        //    );
        //    Files_Rmdir_R(build);
        //    Files_Mkdir(build);
        //}

        //char file[1024];
        //snprintf(
        //    file,
        //    sizeof(file),
        //    "%s/Makefile.web",path
        //);
        //Files_CpyT("/home/codeleaded/Hecke/C/Gui_Raycaster_Modern/Makefile.web",file);

        printf(">>   Execute: %s\n", cmd);
        int ret = system(cmd);

        if (ret == -1) {
            perror("system failed");
        } else {
            if (WIFEXITED(ret)) {
                const int exit_code = WEXITSTATUS(ret);
                printf(">>   Done: %s -> %d\n",path,exit_code);
                
                //if(exit_code)
                //    exit(1);
            } else if (WIFSIGNALED(ret)) {
                printf(">>   Killed: signal %d\n",WTERMSIG(ret));
                exit(1);
            } else {
                printf(">>   Unknown termination!\n");
            }
        }
    }else{
        printf(">> None: %s\n",bn);
    }
}

int main(int argc, char* argv[]) {
    Files_Walk(WALKER_PATH,Run_Cmd);
    return 0;
}
