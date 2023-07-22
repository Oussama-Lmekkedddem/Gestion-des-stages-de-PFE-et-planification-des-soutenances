#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/////////////////////////

FILE *log,*fp,*ft,*fc,*fm,*fi,*ftc,*logc,*fpc,*lag,*fma,*fin,*fmac,*finc,*fpm;

typedef struct str4{
    int h,d,s;
    int *ts,*td,*th;
}time;
typedef struct log{
    char fname[30];
    char lname[30];
    char IDstudent[30];
    char password[20];

}login;
typedef struct pfe{
    char Faculty[30];
    char IDpfe[20];
    char title[50];
    char intsupervisor[20];
    char extsupervisor[20];
    char addresstraine[30];
    char emailtraine[30];
}Stage;
typedef struct tch{
    char firstname[50];
    char lastname[50];
    char IDt[20];
    char subject[50];
    int nbtime;
}teacher;
typedef struct str5{
    char id[30];
    char code[20];
    char fname[30];
    char lname[30];
    int etat;
    struct str5 *next;
}*liste1;
typedef struct str6{
    char IDt[20];
    char subject[50];
    char firstname[50];
    char lastname[50];
    int chang;
    int nbtime;
    struct str6 *next;
}*liste2;


void home();
void Etd_Op(login l);
void Login();
bool existsID(char id[20]);
void registration();
void Etd();
void Cord();
void St_inf(login l);
void exists_inf_std(login l);
void cherche_all();
void cherche_filier();
void cherche_ID();
void consult_pfe(login l);
void display_inf(login l);
void consult_student();
void consult_student_all();
void consult_student_ID();
void consult_student_filier();
void registrationteach();
void showteacher();
void tab1(char etudln1[15],char sujt1[40],char jury1[30],char jury2[30],char jury3[30],int heure,int date,int salle);
void planning_sout();
void reglage1(char etudfn1[15],char etudln1[15],char etudfn2[15],char etudln2[15],char etudfn3[15],char etudln3[15]);
void espace1(char etudln1[15],char etudln2[15],char etudln3[15],char etudln4[15],char sujt1[40]);
void affiche_inf_sout(int day,int salle,int heur,char fname[15],char lname[15],char firstname1[15],char lastname1[15],char titre[50],char firstname2[15],char lastname2[15],char encinterne[30]);
void soutnance_affiche();
void lire_modifier_time(int md);
void enfilier_login(liste1 &L, char id[30],char code[20],char fname[30],char lname[30],int etat);
void modifier_login_liste(liste1 &L, char id[30]);
void lire_modifier_login(char ident[30]);
void enfilier_infot(liste2 &L,char IDt[20],char subject[50], char firstname[50],char lastname[50],int chang,int nbtime);
void modifier_infot_liste(liste2 &L, char IDt[20]);
void lire_modifier_infot(char ident[20]);
void modifier_ou_non();
void soutnan();

////////////////////////////       main        /////////////////////////////////
int main(){
    home();
}
///////////////////////////////////////////////////////////////////////////////

void home(){
    system("color F5");
    int option;
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  GESTION DES STAGES DE PFE ET  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  PLANIFICATION DES SOUTENANCES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\t\t\t             Press '1' to student                 \n\n");
    printf("\t\t\t\t\t             Press '2' to coordinator             \n\n");
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t -> ");
    scanf("%d",&option);
    switch (option) {
        case 1: {
            system("cls");
            Etd();
        }
        case 2: {
            system("cls");
            Cord();
        }
        default:
            home();
    }
}

//////////////////////////////////////////////////////
void Etd(){
    system("color 79");
    int option;
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2      STUDENT      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\t\t\t                Press '1' to Register  \n\n");
    printf("\t\t\t\t\t                Press '2' to Login     \n\n");
    printf("\t\t\t\t\t                Press '3' to exit      \n\n");
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t -> ");
    scanf("%d",&option);

    switch (option) {
        case 1: {
            system("color B1");
            system("CLS");
            registration();
        }
        case 2: {
            system("color B1");
            system("CLS");
            Login();
        }
        case 3: {
            system("cls");
            home();
        }
        default:
            Etd();
    }
}

// regeistration and login

void registration(){
    login l;
    printf("\n\t\t\tEnter First Name:");
    scanf("%s",l.fname);
    printf("\n\t\t\tEnter Last Name:");
    scanf("%s",l.lname);
    printf("\n\t\t\tNow please choose a IDstudent(form M1235986)\nPassword(max=8 characters/numerical/lowercase/uppercase)\n");
    printf("\n\t\t\tEnter IDstudent:");
    scanf("%s",l.IDstudent);
    while(strlen(l.IDstudent) >= 30){
        printf("\n\t\t\tEnter IDstudent:");
        scanf("%s",l.IDstudent);
    }
    while(existsID(l.IDstudent)==true){
        printf("\n\t\t\tIDstudent already existe !!");
        printf("\n\t\t\tEnter IDstudent:");
        scanf("%s",l.IDstudent);
    }
    printf("\n\t\t\tEnter Password:");
    scanf("%s",l.password);
    while(strlen(l.password)>=8){
        printf("\n\t\t\tEnter Password:");
        scanf("%s",l.password);
    }

    log=fopen("login.txt","a");
    fp=fopen("logincopie.txt","a");
    fprintf(log, "%s\t%s\t%s\t%s\t0\n", l.IDstudent, l.password,l.fname,l.lname);
    fprintf(fp, "%s\t%s\t%s\t%s\t0\n", l.IDstudent, l.password,l.fname,l.lname);
    fclose(log);
    fclose(fp);
    printf("\n\t\t\tConfirming details...\n...\nWelcome, %s %s!\n\n",l.lname,l.fname);
    printf("\n\t\t\tRegistration Successful!\n");
    printf("\t\t\tPress any key to continue...\n");
    getchar();
    system("cls");
    Login();
}
bool existsID(char id[20]){
    int na,nb;
    login l,l1;
    int tem=0;
    int nblignes=0;
    log=fopen("login.txt","r");
    while(!feof(log)) {
        fscanf(log, "%s\t%s\t%s\t%s\t%d\n", l1.IDstudent, l1.password,l1.fname,l1.lname,&nb);
        nblignes++;
    }
    if(nblignes==1) {
        return false;
    }
    else{
        rewind(log);
    
        while(!feof(log)) {
           fscanf(log, "%s\t%s\t%s\t%s\t%d\n", l.IDstudent, l.password,l.fname,l.lname,&na);
           if (strcmp( l.IDstudent,id) == 0){
              tem=1;
              break;
            }
        }
    }
    fclose(log);
    if(tem==1) {
        return true;
    }
    else
        return false;
}

void Login(){
    login l;
    int tem=0,na;
    char nom[30],code[10];
    log= fopen("login.txt","r");
    if(log==NULL){
        printf("\n\t\t\tPas de memoire \n");
        exit(0);
    }
    printf("\n\t\t\tPlease Enter your login credentials below \n\n");
    printf("\n\t\t\tIDstudent:  ");
    scanf("%s",nom);
    printf("\n\t\t\tpassword:  ");
    scanf("%s",code);
    while(!feof(log)) {
        fscanf(log, "%s\t%s\t%s\t%s\t%d\n", l.IDstudent, l.password,l.fname,l.lname,&na);
        if (strcmp(l.IDstudent, nom) == 0 && strcmp(l.password, code) == 0) {
            tem = 1;
            break;
        }
    }
    if(tem==1){
        system("cls");
        printf("\n\t\t\tSuccessful Login\n");
        Etd_Op(l);
    }
    else{
        system("cls");
        printf("\n\t\t\tIncorrect Login Details\nPlease enter the correct credentials\n");
        Login();
    }
    fclose(log);
}

//student option

void Etd_Op(login l){
    system("color 5F");
    int option;
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   ENTER YOUR CHOICE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\t\t\t      Press '1' to enter the information of your rapport \n\n");
    printf("\t\t\t\t\t      Press '2' to display your information               \n\n");
    printf("\t\t\t\t\t      Press '3' to consult the pfe internships             \n\n");
    printf("\t\t\t\t\t      Press '4' to consult the defenses                     \n\n");
    printf("\t\t\t\t\t      Press '5' to exit                                      \n\n");
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t -> ");
    scanf("%d",&option);
    switch (option) {
        case 1: {
            system("cls");
            system("color B1");
            exists_inf_std(l);
            Etd_Op(l);
        }
        case 2: {
            system("cls");
            system("color B1");
            display_inf(l);
            Etd_Op(l);
        }
        case 3: {

            system("cls");
            system("color B1");
            consult_pfe(l);
            Etd_Op(l);
        }
        case 4: {
            system("cls");
            system("color B1");
            soutnance_affiche();
            Etd_Op(l);
        }
        case 5: {
            system("cls");
            Etd();
        }
        default:
            Etd_Op( l);
    }
}
//enter your information

void exists_inf_std(login l){
    char nom[20];
    int tem=0;
    fp=fopen("information.txt","r");
    while(!feof(fp)) {
        fscanf(fp, "%s\n",nom);
        if (strcmp( nom,l.IDstudent) == 0){
            tem=1;
            break;
        }
    }
    fclose(log);
    if(tem==1) {
        printf("\n\t\t\tYou have already entered your information!!\n");
        Etd_Op(l);
    }
    else
        St_inf(l);
}

void St_inf(login l){
    fp=fopen("information.txt","a");
    Stage s;
    int type;
    printf("\n\t\t\tenter your information\n");
    next :
    printf("\n\t\t\tEnter Faculty(ID'1'/GI'2'):");
    scanf("%d",&type);
    if(type==1){
        strcpy(s.Faculty,"ID");
    }
    else {
        if (type == 2) {
            strcpy(s.Faculty, "GI");
        }
        else {
            goto next ;
        }
    }
    printf("\n\t\t\tEnter IDpfe:");
    scanf("%s",s.IDpfe);
    printf("\n\t\t\tEnter internship title ( USE - BETWEEN EACH WORD) :");
    scanf("%s",s.title);
    printf("\n\t\t\tEnter external supervisor ( USE - BETWEEN EACH WORD) :");
    scanf("%s",s.extsupervisor);
    printf("\n\t\t\tEnter internal supervisor ( USE - BETWEEN EACH WORD) :");
    scanf("%s",s.intsupervisor);
    printf("\n\t\t\tEnter traineeship address ( USE - BETWEEN EACH WORD) :");
    scanf("%s",s.addresstraine);
    printf("\n\t\t\tEnter traineeship email:");
    scanf("%s",s.emailtraine);
    printf("\n\t\t\t PLEASE SEND YOUR RAPPORT IN THIS EMAIL (ensah@etu.uae.ac.ma) : \n");
    fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l.IDstudent,s.Faculty,s.IDpfe,s.title,s.extsupervisor,s.intsupervisor,s.addresstraine,s.emailtraine);
    fclose(fp);
    printf("\n\t\t\tRegistration Successful!\n");
}

//consult the pfe internships

void cherche_filier(){
    login l;
    Stage s;
    char filier[5],IDtemp[20];
    int type,na;
    fp= fopen("information.txt","r");
    log= fopen("login.txt","r");
    next :
    printf("\n\t\t\tEnter Faculty(ID'1'/GI'2'):");
    scanf("%d", &type);
    if (type == 1) {
        strcpy(filier, "ID");
    } else {
        if (type == 2) {
            strcpy(filier, "GI");
        } else {
            goto next;
        }
    }
    while (!feof(fp)) {
        first:
        fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l.IDstudent,s.Faculty,s.IDpfe,s.title,s.extsupervisor,s.intsupervisor,s.addresstraine,s.emailtraine);
        if (strcmp(s.Faculty, filier) == 0) {
            while (!feof(log)) {
                fscanf(log, "%s\t%s\t%s\t%s\t%d\n", IDtemp, l.password, l.fname, l.lname,&na);
                if (strcmp(IDtemp,l.IDstudent) == 0) {
                    printf("\n\n\t\t\tStudent: ");
                    printf("\n\n\t\t\tIDstudent     : %s ",l.IDstudent);
                    printf("\n\n\t\t\tname          : %s %s", l.fname,l.lname);
                    printf("\n\n\t\t\tfaculty       : %s ", s.Faculty);
                    printf("\n\n\t\t\ttitle         : %s ", s.title);
                    printf("\n\n\t\t\tintsupervisor : %s ", s.intsupervisor);
                    goto first;
                }
            }
        }
    }
    fclose(fp);
    fclose(log);
}
void cherche_all(){
    login l;
    Stage s;
    char IDtemp[20];
    int na;
    fp= fopen("information.txt","r");
    log= fopen("login.txt","r");
    while (!feof(fp)) {
        first:
        fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l.IDstudent,s.Faculty,s.IDpfe,s.title,s.extsupervisor,s.intsupervisor,s.addresstraine,s.emailtraine);
        while (!feof(log)) {
            fscanf(log, "%s\t%s\t%s\t%s\t%d\n", IDtemp, l.password, l.fname, l.lname,&na);
            if (strcmp(IDtemp, l.IDstudent) == 0) {
                printf("\n\n\t\t\tStudent: ");
                printf("\n\n\t\t\tIDstudent     : %s ",l.IDstudent);
                printf("\n\n\t\t\tname          : %s %s", l.fname,l.lname);
                printf("\n\n\t\t\tfaculty       : %s ", s.Faculty);
                printf("\n\n\t\t\ttitle         : %s ", s.title);
                printf("\n\n\t\t\tintsupervisor : %s ", s.intsupervisor);
                goto first;
            }
        }
    }
    fclose(fp);
    fclose(log);
}
void cherche_ID(){
    login l;
    Stage s;
    char IDstd[20],IDtemp[20];
    int na;
    fp= fopen("information.txt","r");
    log= fopen("login.txt","r");
    printf("\n\t\t\tEnter ID of student:");
    scanf("%s", IDstd);
    while (!feof(fp)) {
        fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l.IDstudent,s.Faculty,s.IDpfe,s.title,s.extsupervisor,s.intsupervisor,s.addresstraine,s.emailtraine);
        if (strcmp(l.IDstudent, IDstd) == 0) {
            while (!feof(log)) {
                fscanf(log, "%s\t%s\t%s\t%s\t%d\n", IDtemp, l.password, l.fname, l.lname,&na);
                if (strcmp(IDtemp,l.IDstudent) == 0) {
                    printf("\n\n\t\t\tIDstudent     : %s ",l.IDstudent);
                    printf("\n\n\t\t\tname          : %s %s", l.fname,l.lname);
                    printf("\n\n\t\t\tfaculty       : %s ", s.Faculty);
                    printf("\n\n\t\t\ttitle         : %s ", s.title);
                    printf("\n\n\t\t\tintsupervisor : %s ", s.intsupervisor);
                }
            }
        }
    }
    fclose(fp);
    fclose(log);
}
void consult_pfe(login l){
    system("color F9");
    int option;
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   ENTER YOUR CHOICE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\t\t\t      Press '1' to Show all pfe                   \n\n");
    printf("\t\t\t\t\t      Press '2' to search by IDstudent            \n\n");
    printf("\t\t\t\t\t      Press '3' to search by faculty              \n\n");
    printf("\t\t\t\t\t      Press '4' to exit                           \n\n");
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t -> ");
    scanf("%d",&option);
    switch (option) {
        case 1:{
            system("cls");
            system("color F5");
            cherche_all();
            consult_pfe(l);
        }
        case 2: {
            system("cls");
            system("color F5");
            cherche_ID();
            consult_pfe(l);
        }
        case 3: {
            system("cls");
            system("color F5");
            cherche_filier();
            consult_pfe(l);
        }
        case 4: {
            system("cls");
            Etd_Op(l);
        }
        default:
            consult_pfe(l);
    }
}
void display_inf(login l){
    Stage s;
    char IDstd[20],IDtemp[20];
    int na;
    fp= fopen("information.txt","r");
    log= fopen("login.txt","r");
    while (!feof(fp)) {
        fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",IDstd,s.Faculty,s.IDpfe,s.title,s.extsupervisor,s.intsupervisor,s.addresstraine,s.emailtraine);
        if (strcmp(IDstd,l.IDstudent) == 0) {
            while (!feof(log)) {
                fscanf(log, "%s\t%s\t%s\t%s\t%d\n", IDtemp, l.password, l.fname, l.lname,&na);
                if (strcmp(IDtemp,l.IDstudent) == 0) {
                    printf("\n\n\t\t\tIDstudent     : %s ",l.IDstudent);
                    printf("\n\n\t\t\tname          : %s %s", l.fname,l.lname);
                    printf("\n\n\t\t\tfaculty       : %s ", s.Faculty);
                    printf("\n\n\t\t\tIDpfe         : %s ", s.IDpfe);
                    printf("\n\n\t\t\ttitle         : %s ", s.title);
                    printf("\n\n\t\t\tintsupervisor : %s ", s.intsupervisor);
                    printf("\n\n\t\t\textsupervisor : %s ", s.extsupervisor);
                    printf("\n\n\t\t\taddresstraine : %s ", s.addresstraine);
                    printf("\n\n\t\t\temailtraine   : %s \n", s.emailtraine);
                }
            }
        }
    }
    fclose(fp);
    fclose(log);
}

////////////////////////////////////////////////////

void Cord(){
    system("color 5F");
    int option;
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    COORDINATOR     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\t\t\t      Press '1' to add teacher                    \n\n");
    printf("\t\t\t\t\t      Press '2' to show teachers                   \n\n");
    printf("\t\t\t\t\t      Press '3' to consult the students           \n\n");
    printf("\t\t\t\t\t      Press '4' to show defenses                  \n\n");
    printf("\t\t\t\t\t      Press '5' to plan defenses                  \n\n");
    printf("\t\t\t\t\t      Press '6' to exit                           \n\n");
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t -> ");
    scanf("%d",&option);
    switch (option) {
        case 1: {
            system("cls");
            system("color F8");
            registrationteach();
            Cord();
        }
        case 2: {
            system("cls");
            system("color F8");
            showteacher();
            Cord();
        }
        case 3: {
            system("cls");
            system("color F8");
            consult_student();
            Cord();
        }
        case 4: {
            system("cls");
            system("color F8");
            soutnance_affiche();
            Cord();
        }
        case 5:{
            system("cls");
            system("color F8");
            modifier_ou_non();
            Cord();
        }
        case 6: {
            system("cls");
            home();
        }
        default:
            Cord();
    }
}

////////////////////////////

void consult_student(){
    system("color 75");
    int option;
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   ENTER YOUR CHOICE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\t\t\t      Press '1' to Show all student               \n\n");
    printf("\t\t\t\t\t      Press '2' to search by IDstudent            \n\n");
    printf("\t\t\t\t\t      Press '3' to search by faculty              \n\n");
    printf("\t\t\t\t\t      Press '4' to exit                           \n\n");
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t -> ");
    scanf("%d",&option);
    switch (option) {
        case 1:{
            system("cls");
            system("color F8");
            consult_student_all();
            consult_student();
        }
        case 2: {
            system("cls");
            system("color F8");
            consult_student_ID();
            consult_student();
        }
        case 3: {
            system("cls");
            system("color F8");
            consult_student_filier();
            consult_student();
        }
        case 4: {
            system("cls");
            Cord();
        }
        default:
            consult_student();
    }
}
void consult_student_ID(){
    login l;
    Stage s;
    int tr=0,na;
    char IDstd[20],IDtemp[20];
    fp= fopen("information.txt","r");
    log= fopen("login.txt","r");
    printf("\n\t\t\tEnter ID of student:");
    scanf("%s", IDstd);
    while (!feof(fp)) {
        fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l.IDstudent,s.Faculty,s.IDpfe,s.title,s.extsupervisor,s.intsupervisor,s.addresstraine,s.emailtraine);
        if (strcmp(l.IDstudent, IDstd) == 0) {
            while (!feof(log)) {
                fscanf(log, "%s\t%s\t%s\t%s\t%d\n", IDtemp, l.password, l.fname, l.lname,&na);
                if (strcmp(IDtemp,l.IDstudent) == 0) {
                    tr=1;
                    printf("\n\n\t\t\tIDstudent     : %s ",l.IDstudent);
                    printf("\n\n\t\t\tname          : %s %s", l.fname,l.lname);
                    printf("\n\n\t\t\tfaculty       : %s ", s.Faculty);
                    printf("\n\n\t\t\tIDpfe         : %s ", s.IDpfe);
                    printf("\n\n\t\t\ttitle         : %s ", s.title);
                    printf("\n\n\t\t\tintsupervisor : %s ", s.intsupervisor);
                    printf("\n\n\t\t\textsupervisor : %s ", s.extsupervisor);
                    printf("\n\n\t\t\taddresstraine : %s ", s.addresstraine);
                    printf("\n\n\t\t\temailtraine   : %s \n", s.emailtraine);
                }
            }
        }
    }
    if(tr==0)
        printf("\t\t\tThe student doesn't exist !!!!! \n");
    fclose(fp);
    fclose(log);
}
void consult_student_filier(){
    login l;
    Stage s;
    char filier[5],IDtemp[20];
    int type,na;
    fp= fopen("information.txt","r");
    log= fopen("login.txt","r");
    next :
    printf("\n\t\t\tEnter Faculty(ID'1'/GI'2'):");
    scanf("%d", &type);
    if (type == 1) {
        strcpy(filier, "ID");
    } else {
        if (type == 2) {
            strcpy(filier, "GI");
        } else {
            goto next;
        }
    }
    while (!feof(fp)) {
        first:
        fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l.IDstudent,s.Faculty,s.IDpfe,s.title,s.extsupervisor,s.intsupervisor,s.addresstraine,s.emailtraine);
        if (strcmp(s.Faculty, filier) == 0) {
            while (!feof(log)) {
                fscanf(log, "%s\t%s\t%s\t%s\t%d\n", IDtemp, l.password, l.fname, l.lname,&na);
                if (strcmp(IDtemp,l.IDstudent) == 0) {
                    printf("\n\n\t\t\tStudent: ");
                    printf("\n\n\t\t\tIDstudent     : %s ",l.IDstudent);
                    printf("\n\n\t\t\tname          : %s %s", l.fname,l.lname);
                    printf("\n\n\t\t\tfaculty       : %s ", s.Faculty);
                    printf("\n\n\t\t\tIDpfe         : %s ", s.IDpfe);
                    printf("\n\n\t\t\ttitle         : %s ", s.title);
                    printf("\n\n\t\t\tintsupervisor : %s ", s.intsupervisor);
                    printf("\n\n\t\t\textsupervisor : %s ", s.extsupervisor);
                    printf("\n\n\t\t\taddresstraine : %s ", s.addresstraine);
                    printf("\n\n\t\t\temailtraine   : %s \n", s.emailtraine);
                    goto first;
                }
            }
        }
    }
    fclose(fp);
    fclose(log);
}
void consult_student_all(){
    login l;
    Stage s;
    char IDtemp[20];
    int an;
    fp= fopen("information.txt","r");
    log= fopen("login.txt","r");
    while (!feof(fp)) {
        first:
        fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l.IDstudent,s.Faculty,s.IDpfe,s.title,s.extsupervisor,s.intsupervisor,s.addresstraine,s.emailtraine);
        while (!feof(log)) {
            fscanf(log, "%s\t%s\t%s\t%s\t%d\n", IDtemp, l.password, l.fname, l.lname,&an);
            if (strcmp(IDtemp, l.IDstudent) == 0) {
                printf("\n\n\t\t\tStudent: ");
                printf("\n\n\t\t\tIDstudent     : %s ",l.IDstudent);
                printf("\n\n\t\t\tname          : %s %s", l.fname,l.lname);
                printf("\n\n\t\t\tfaculty       : %s ", s.Faculty);
                printf("\n\n\t\t\tIDpfe         : %s ", s.IDpfe);
                printf("\n\n\t\t\ttitle         : %s ", s.title);
                printf("\n\n\t\t\tintsupervisor : %s ", s.intsupervisor);
                printf("\n\n\t\t\textsupervisor : %s ", s.extsupervisor);
                printf("\n\n\t\t\taddresstraine : %s ", s.addresstraine);
                printf("\n\n\t\t\temailtraine   : %s \n", s.emailtraine);
                goto first;
            }
        }
    }
    fclose(fp);
    fclose(log);
}
void registrationteach(){
    int fil;
    fp=fopen("infotcopie.txt","a");
    ft=fopen("infot.txt","a");
    fma=fopen("math.txt","a");
    fin=fopen("informatique.txt","a");
    fmac=fopen("mathcopie.txt","a");
    finc=fopen("informatiquecopie.txt","a");
    teacher t;
    printf("\n\t\t\tEnter the First Name of the teacher:");
    scanf("%s",t.firstname);
    printf("\n\t\t\tEnter the Last Name of the teacher:");
    scanf("%s",t.lastname);
    printf("\n\t\t\tNow please choose a IDteacher(form M1235986)\nPassword(max=8 characters/numerical/lowercase/uppercase)\n");
    printf("\n\t\t\tEnter IDteacher:");
    scanf("%s",t.IDt);
    while(strlen(t.IDt) >= 20){
        printf("\n\t\t\tEnter IDstudent:");
        scanf("%s",t.IDt);
    }
    printf("\n\t\t\tEnter the subject(math'1'/info'2'):");
    scanf("%d",&fil);
    if(fil==1){
        strcpy(t.subject,"math");
    }
    else {
        if (fil == 2) {
            strcpy(t.subject, "info");
        }
        else {
            printf("\n\t\t\tEnter the subject(math'1'/info'2'):");
            scanf("%d",&fil);
        }
    }
    printf("\n\t\t\tEnter the maximum number of times the jury can be present:");
    scanf("%d",&t.nbtime);
    fprintf(ft, "%s\t%s\t%s\t%s\t0\t%d\n", t.IDt, t.subject,t.firstname,t.lastname,t.nbtime);
    fprintf(fp, "%s\t%s\t%s\t%s\t0\t%d\n", t.IDt, t.subject,t.firstname,t.lastname,t.nbtime);
    if(fil==2){
        fprintf(fin, "%s\t%s\t%s\t%s\t0\t%d\n", t.IDt, t.subject,t.firstname,t.lastname,t.nbtime);

        fprintf(finc, "%s\t%s\t%s\t%s\t0\t%d\n", t.IDt, t.subject,t.firstname,t.lastname,t.nbtime);

    }
     else{
        fprintf(fma, "%s\t%s\t%s\t%s\t0\t%d\n", t.IDt, t.subject,t.firstname,t.lastname,t.nbtime);

        fprintf(fmac, "%s\t%s\t%s\t%s\t0\t%d\n", t.IDt, t.subject,t.firstname,t.lastname,t.nbtime);

    }
    fclose(ft);
    fclose(fp);
    fclose(fpm);
    fclose(fin);
    fclose(fma);
    fclose(finc);
    fclose(fmac);
    printf("\n\t\t\tRegistration Successful!\n");
}
void showteacher(){

    teacher k;
    int nb;
    ft=fopen("infot.txt","r");
    fc=fopen("showing.txt","a");
    while (!feof(ft)){

        fscanf(ft,"%s\t%s\t%s\t%s\t%d\t%d\n", k.IDt, k.subject,k.firstname,k.lastname,&nb,&k.nbtime);
        printf("\n\n\t\t\t ***");
        printf("\n\n\t\t\t|Teacher:| ");
        printf("\n\n\t\t\tIDteacher    : %s ",k.IDt);
        printf("\n\n\t\t\tname          : %s %s", k.firstname,k.lastname);
        printf("\n\n\t\t\tSubject       : %s ", k.subject);

    }
    fclose(ft);
    fclose(fc);
}



///////////////////////////////////////////////////////soutenance///////////////////////////////////////////////////////
void Remplir_h_d_s(){
    time t;
    printf("\nenter the nomber of days to pass all the defense :");
    scanf("%d",&t.d);
    t.td=(int*)malloc(sizeof(int)*t.d);
    for ( int i = 0; i < t.d; i++){
        printf("\nday  :");
        scanf("%d",t.td+i);
    }
    printf("\nenter the number of defenses per classroom :");
    scanf("%d",&t.h);
    t.th=(int*)malloc(sizeof(int)*t.h);
    for ( int i = 0; i < t.h; i++){
        printf("\nhour :");
        scanf("%d",t.th+i);
    }
    printf("\nenter the number of classrooms exists :");
    scanf("%d",&t.s);
    t.ts=(int*)malloc(sizeof(int)*t.s);
    for ( int i = 0; i < t.s; i++){
        printf("\nclassrooms :");
        scanf("%d",t.ts+i);
    }
    fp = fopen("timecopie.txt", "w");
    ft = fopen("time.txt", "w");
    int d=0;
    int s;
    for (int i = 0; i < t.h*t.s*t.d; ++i) {
        if(i%(t.s*t.h)==0){
            d++;
        }
        if(i%t.h==0){
            s++;
            if(i%(t.s*t.h)==0) {
                s = 0;
            }
        }
        fprintf(ft,"0\t%d\t%d\t%d\n",t.td[d-1],t.ts[s],t.th[i%t.h]);
        fprintf(fp,"0\t%d\t%d\t%d\n",t.td[d-1],t.ts[s],t.th[i%t.h]);
    }
    fprintf(ft,"0\t%d\t%d\t%d\n",t.d,t.s,t.h);
    fprintf(fp,"0\t%d\t%d\t%d\n",t.d,t.s,t.h);
    fclose(fp);
    fclose(ft);
}
void lire_modifier_time(int md){
    int i=0,cmp=0;
    int etat,day,salle,heur;
    int nblignes=0;
    ft=fopen("time.txt","r");
    while(!feof(ft)) {
        fscanf(ft, "%d\t%d\t%d\t%d\n", &etat, &day, &salle, &heur);
        nblignes++;
    }
    rewind(ft);
    int tab[nblignes][4];
    for (int j = 0; j <nblignes ; ++j) {
        fscanf(ft, "%d\t%d\t%d\t%d\n", &etat, &day, &salle, &heur);
        tab[i][0] = etat;
        tab[i][1] = day;
        tab[i][2] = salle;
        tab[i][3] = heur;
        i++;
    }
    fclose(ft);

    fp=fopen("time.txt","w");
    for (int j = 0; j < nblignes; ++j) {
        if(cmp==md){
            fprintf(fp, "1\t%d\t%d\t%d\n", tab[j][1], tab[j][2], tab[j][3]);
        }
        else {
            fprintf(fp, "%d\t%d\t%d\t%d\n", tab[j][0], tab[j][1], tab[j][2], tab[j][3]);
        }
        cmp++;
    }
    fclose(fp);
}
void enfilier_login(liste1 &L, char id[30],char code[20],char fname[30],char lname[30],int etat){
    liste1 p=(liste1) malloc(sizeof(str5));
    strcpy(p->id,id);
    strcpy(p->code,code);
    strcpy(p->fname,fname);
    strcpy(p->lname,lname);
    p->etat=etat;
    p->next=NULL;
    if(L==NULL){
        L = p;
    }
    else{
        liste1 q=L;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
    }
}
void modifier_login_liste(liste1 &L, char id[30]){
    if(L!=NULL){
        liste1 p=L;
        while(p!=NULL){
            if(strcmp(id,p->id)==0){
                p->etat=1;
            }
            p=p->next;
        }
    }
}
void lire_modifier_login(char ident[30]){
    int etat;
    char id[30],code[20],fname[30],lname[30];
    liste1 L=NULL;
    ft=fopen("login.txt","r");
    while(!feof(ft)) {
        fscanf(ft, "%s\t%s\t%s\t%s\t%d\n",id,code ,fname ,lname,&etat);
        enfilier_login(L,id,code,fname,lname,etat);
    }
    fclose(ft);
    modifier_login_liste(L, ident);

    fp=fopen("login.txt","w");
    liste1 p=L;
    while(p!=NULL){
        fprintf(fp,"%s\t%s\t%s\t%s\t%d\n", p->id,p->code,p->fname,p->lname,p->etat);
        p=p->next;
    }
    fclose(fp);
}
void enfilier_infot(liste2 &L,char IDt[20],char subject[50], char firstname[50],char lastname[50],int chang,int nbtime){
    liste2 p=(liste2) malloc(sizeof(str6));
    strcpy(p->IDt,IDt);
    strcpy(p->subject,subject);
    strcpy(p->firstname,firstname);
    strcpy(p->lastname,lastname);
    p->chang=chang;
    p->nbtime=nbtime;
    p->next=NULL;
    if(L==NULL){
        L = p;
    }
    else{
        liste2 q=L;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
    }
}
void modifier_infot_liste(liste2 &L, char IDt[20]){
    if(L!=NULL){
        liste2 p=L;
        while(p!=NULL){
            if(strcmp(IDt,p->IDt)==0){
                p->chang++;
            }
            p=p->next;
        }
    }
}
void lire_modifier_infot(char ident[20]){
    char id[20],mathere[50],fname[50],lname[50];
    int chat,foix;
    liste2 L=NULL;
    fp=fopen("infot.txt","r");
    while(!feof(fp)) {
        fscanf(fp, "%s\t%s\t%s\t%s\t%d\t%d\n",id,mathere,fname,lname,&chat,&foix);
        enfilier_infot(L,id,mathere,fname,lname,chat,foix);
    }
    fclose(fp);
    modifier_infot_liste(L,ident);

    fp=fopen("infot.txt","w");
    liste2 p=L;
    while(p!=NULL){
        fprintf(fp,"%s\t%s\t%s\t%s\t%d\t%d\n",p->IDt,p->subject,p->firstname,p->lastname,p->chang,p->nbtime);
        p=p->next;
    }
    fclose(fp);
}
void modifier_ou_non() {
    char verf[5];
    int etat,day,salle,heur;
    int nblignes=0;
    ft = fopen("time.txt", "r");
    while(!feof(ft)) {
        fscanf(ft, "%d\t%d\t%d\t%d\n", &etat, &day, &salle, &heur);
        nblignes++;
    }
    fclose(ft);
    if(nblignes==1) {
        printf("\nData file is emtpy");
        Remplir_h_d_s();
    }
    else{
        printf("\nYou have already entered the information!!");
        printf("\ndo you wanna modify the information yes/no :");
        scanf("%s",verf);
        if(strcmp(verf,"yes")==0){
            Remplir_h_d_s();
        }
        else{
            printf("\n retourner au mineau de coordinateur ");
        }
    }
    home();
}
void soutnance_affiche() {
    login l;
    teacher p[5],b;
    Stage s;
    char IDtemp[20],titre[60],encinterne[30];
    int tem[3], pass,tm;
    int day, salle, heur;
    int mb = -1,comp1=-1,comp2=-1,nbligne1=0,nbligne2=0;
    int etat1, day1, salle1, heur1;
    planning_sout();

    log = fopen("login.txt", "r");
    lag = fopen("information.txt", "r");
    while (!feof(log)) {
        first:
        fscanf(log, "%s\t%s\t%s\t%s\t%d\n", l.IDstudent, l.password, l.fname, l.lname, &pass);
        if (pass == 1) {
            goto first;
        } else {
            while (!feof(lag)) {
                fscanf(lag, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",IDtemp,s.Faculty,s.IDpfe,s.title,s.extsupervisor,s.intsupervisor,s.addresstraine,s.emailtraine);
                if (strcmp(l.IDstudent,IDtemp ) == 0) {
                    strcpy(titre, s.title);
                    strcpy(encinterne, s.intsupervisor);
                }
                break;
                fclose(lag);
            }
            fin = fopen("informatique.txt", "r");
            while(!feof(fin)) {
                fscanf(fin, "%s\t%s\t%s\t%s\t%d\t%d\n", b.IDt, b.subject, b.firstname, b.lastname, &tm,&b.nbtime);
                if (tm < b.nbtime) {
                    nbligne1++;
                }
            }
            fma=fopen("math.txt", "r");
            while(!feof(fma)) {
                fscanf(fma, "%s\t%s\t%s\t%s\t%d\t%d\n", b.IDt, b.subject, b.firstname, b.lastname, &tm,&b.nbtime);
                if (tm < b.nbtime) {
                    nbligne2++;

                }
            }
            rewind(fin);
            rewind(fma);
            while (!feof(fin)) {
                depart1:
                fscanf(fin, "%s\t%s\t%s\t%s\t%d\t%d\n", p[1].IDt, p[1].subject, p[1].firstname, p[1].lastname, &tem[1],&p[1].nbtime);
                if (tem[1] >= p[1].nbtime) {
                    goto depart1;
                } else {
                    comp1++;
                    for (int j = 0; j < comp1; j++) {
                        fscanf(fin, "%s\t%s\t%s\t%s\t%d\t%d\n", p[1].IDt, p[1].subject, p[1].firstname, p[1].lastname, &tem[1],
                               &p[1].nbtime);
                    }
                    strcpy(p[3].firstname, p[1].firstname);
                    strcpy(p[3].lastname, p[1].lastname);
                    strcpy(p[3].IDt, p[1].IDt);
                    if(comp1==nbligne1){
                        comp1=-1;
                        rewind(fin);
                    }
                }
                break;
            }
            rewind(fin);
            while(!feof(fma)){
                depart2:
                fscanf(fma, "%s\t%s\t%s\t%s\t%d\t%d\n", p[2].IDt, p[2].subject, p[2].firstname, p[2].lastname, &tem[2],&p[2].nbtime);
                if (tem[2] >= p[2].nbtime) {
                    goto depart2;
                } else {
                    comp2++;
                    for (int j = 0; j < comp2; j++) {
                        fscanf(fma, "%s\t%s\t%s\t%s\t%d\t%d\n", p[2].IDt, p[2].subject, p[2].firstname, p[2].lastname, &tem[2],&p[2].nbtime);
                    }
                    strcpy(p[4].firstname, p[2].firstname);
                    strcpy(p[4].lastname, p[2].lastname);
                    strcpy(p[4].IDt, p[2].IDt);
                    if(comp2==nbligne2){
                        comp2=-1;
                        rewind(fma);
                    }
                }
                break;
            }
            rewind(fma);
            fclose(fin);
            fclose(fma);
            ft = fopen("time.txt", "r");
            while (!feof(ft)) {
                fscanf(ft, "%d\t%d\t%d\t%d\n", &etat1, &day1, &salle1, &heur1);
                mb++;
                for (int i = 0; i < mb; ++i) {
                    fscanf(ft, "%d\t%d\t%d\t%d\n", &etat1, &day1, &salle1, &heur1);
                }
                day = day1;
                salle = salle1;
                heur = heur1;
                break;
            }
            fclose(ft);
            affiche_inf_sout(day,salle, heur, l.fname, l.lname,p[3].firstname, p[3].lastname,titre, p[4].firstname, p[4].lastname,encinterne);
            lire_modifier_time(mb);
            lire_modifier_infot(p[3].IDt);
            lire_modifier_infot(p[4].IDt);
            lire_modifier_login(l.IDstudent);
        }
    }
    fclose(log);

    fmac= fopen("mathcopie.txt", "r");
    fma = fopen("math.txt", "w");
    while(!feof(fmac)) {
        fscanf(fmac, "%s\t%s\t%s\t%s\t%d\t%d\n", b.IDt, b.subject, b.firstname, b.lastname, &tm,
               &b.nbtime);
        fprintf(fma, "%s\t%s\t%s\t%s\t%d\t%d\n", b.IDt, b.subject, b.firstname, b.lastname, tm,
                b.nbtime);
    }
    fclose(fmac);
    fclose(fma);
    finc= fopen("informatiquecopie.txt", "r");
    fin = fopen("informatique.txt", "w");
    while(!feof(finc)) {
        fscanf(finc, "%s\t%s\t%s\t%s\t%d\t%d\n", b.IDt, b.subject, b.firstname, b.lastname, &tm,
               &b.nbtime);
        fprintf(fin, "%s\t%s\t%s\t%s\t%d\t%d\n", b.IDt, b.subject, b.firstname, b.lastname, tm,
                b.nbtime);
    }
    fclose(finc);
    fclose(fin);
    ftc= fopen("timecopie.txt", "r");
    ft = fopen("time.txt", "w");
    while(!feof(ftc)) {
        fscanf(ftc, "%d\t%d\t%d\t%d\n", &etat1, &day1, &salle1, &heur1);
        fprintf(ft, "%d\t%d\t%d\t%d\n", etat1, day1, salle1, heur1);
    }
    fclose(ftc);
    fclose(ft);
    logc= fopen("logincopie.txt", "r");
    log= fopen("login.txt", "w");
    while(!feof(logc)) {
        fscanf(logc, "%s\t%s\t%s\t%s\t%d\n", l.IDstudent, l.password, l.fname, l.lname, &pass);
        fprintf(log, "%s\t%s\t%s\t%s\t%d\n", l.IDstudent, l.password, l.fname, l.lname, pass);
    }
    fclose(logc);
    fclose(log);


    home();
}
void reglage1(char etudfn1[15],char etudln1[15],char etudfn2[15],char etudln2[15],char etudfn3[15],char etudln3[15]){
    strcpy(etudln1,etudln1);
    strcat(etudln1," ");
    strcat(etudln1,etudfn1);
    strcpy(etudln2,etudln2);
    strcat(etudln2," ");
    strcat(etudln2,etudfn2);
    strcpy(etudln3,etudln3);
    strcat(etudln3," ");
    strcat(etudln3,etudfn3);
}
void espace1(char etudln1[15],char etudln2[15],char etudln3[15],char etudln4[15],char sujt1[40]){
    char t[50] = "                                              ";
    int y1 = 19,y2=44,y3=20;
    strncat(etudln1, t, y1 - strlen(etudln1));
    strncat(sujt1, t, y2 - strlen(sujt1));
    strncat(etudln2, t, y3 - strlen(etudln2));
    strncat(etudln3, t, y3 - strlen(etudln3));
    strncat(etudln4, t, y3 - strlen(etudln4));
}
void affiche_inf_sout(int day,int salle,int heur,char fname[15],char lname[15],char firstname1[15],char lastname1[15],char titre[50],char firstname2[15],char lastname2[15],char encinterne[30]){
    reglage1(fname,lname,firstname1,lastname1,firstname2,lastname2);
    espace1(lname,lastname1,lastname2,encinterne,titre);
    tab1(lname,titre,lastname1,lastname2,encinterne,heur,day,salle);
}
void planning_sout(){
    printf("\n+---------------------------+--------------------------------------------------------+-----------------------------+");
    printf("\n|    Ecole Nationale des    |            Planning des soutenances des                |          UNIVERSITE         |");
    printf("\n|    Sciences Appliquees    |               projets de fin d'etudes                  |          ABDELMALEK         |");
    printf("\n|       d'Al-Hoceima        |                         2023                           |           ESSAADI           |");
    printf("\n+---------------------------+--------------------------------------------- ----------+-----------------------------+\n");
    printf("\n+------+-------+-------+----------------------+---------------------+----------------------------------------------+");
    printf("\n| Date | Salle | Heure |    Membres de jury   |      Etudiants      |                    Sujet                     |");
    printf("\n+------+-------+-------+----------------------+---------------------+----------------------------------------------+");
   fp= fopen("planning.txt","w");
    fprintf(fp,"\n+---------------------------+--------------------------------------------------------+-----------------------------+");
    fprintf(fp,"\n|    Ecole Nationale des    |            Planning des soutenances des                |          UNIVERSITE         |");
    fprintf(fp,"\n|    Sciences Appliquees    |               projets de fin d'etudes                  |          ABDELMALEK         |");
    fprintf(fp,"\n|       d'Al-Hoceima        |                         2023                           |           ESSAADI           |");
    fprintf(fp,"\n+---------------------------+--------------------------------------------- ----------+-----------------------------+\n");
    fprintf(fp,"\n+------+-------+-------+----------------------+---------------------+----------------------------------------------+");
    fprintf(fp,"\n| Date | Salle | Heure |    Membres de jury   |      Etudiants      |                    Sujet                     |");
    fprintf(fp,"\n+------+-------+-------+----------------------+---------------------+----------------------------------------------+");
    fclose(fp);

}
void tab1(char etudln1[15],char sujt1[40],char jury1[30],char jury2[30],char jury3[30],int heure,int date,int salle){
    printf("\n|      |       |       | %s | %s | %s |",jury1,etudln1,sujt1);
    printf("\n| %d   |  %d    |  %d   | %s |                     |                                              |",date,salle,heure,jury2);
    printf("\n|      |       |       | %s |                     |                                              |",jury3);
    printf("\n+------+-------+-------+----------------------+---------------------+----------------------------------------------+");
    fp= fopen("planning.txt","a");
    fprintf(fp,"\n|      |       |       | %s | %s | %s |",jury1,etudln1,sujt1);
    fprintf(fp,"\n| %d   |  %d    |  %d   | %s |                     |                                              |",date,salle,heure,jury2);
    fprintf(fp,"\n|      |       |       | %s |                     |                                              |",jury3);
    fprintf(fp,"\n+------+-------+-------+----------------------+---------------------+----------------------------------------------+");
    fclose(fp);

}
