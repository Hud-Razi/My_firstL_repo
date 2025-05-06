#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*FILE VARIABLE CUSTOMER*/
FILE *cust_db;
/*customer struct*/
typedef struct {
    int id;
    char *name;
    char *adrs;
    char *phone;
}customer;

customer *cust;

/*size variable for memeory*/
int size = 0;
int id_addr;

/*Add customer function*/
void add_cust(){
    /*size increment on adding customers*/
    size++;
    id_addr++;

    
    /*memory allocation second*/
    cust = realloc(cust,size * sizeof(customer));
    /*temp characteer for strings*/
    char temp[20];
    /*file opening for append*/
    cust_db = fopen("customer_database.txt","a");
    /*adding name*/
    printf("Enter customer name: \n");
    scanf(" %[^\n]",temp);
    /*allocating memory to name*/
    cust[size-1].name = (char *)malloc(sizeof(temp)+1);
    strcpy(cust[size-1].name,temp);


    /*adding address*/
    printf("Add customer address for %s",cust[size-1].name);
    scanf(" %[^\n]",temp);

    cust[size - 1].adrs = (char *)malloc(sizeof(temp)+1);

    strcpy(cust[size-1].adrs,temp);

    /*adding customer id*/
    cust[size-1].id = 1000 + id_addr;

    /*adding customer phone no*/
    printf("Add customer phone no for %s",cust[size-1].name);
    scanf(" %[^\n]",temp);

    cust[size - 1].phone = (char *)malloc(sizeof(temp)+1);

    strcpy(cust[size-1].phone,temp);


    /*printing cusotmer details to file*/
    fprintf(cust_db,"%-10d %-10s %-10s %-10s\n",cust[size-1].id,cust[size-1].name,cust[size-1].adrs,cust[size-1].phone);

    /*closing file*/
    fclose(cust_db);
    
}
void del_cust(){
    int cmp_var;
    int del_var;
    char name_cmp[30];

    /*Searching names*/
    printf("Enter name to find: ");
    scanf(" %[^\n]",name_cmp);

    /*searching loop*/

    for (int i = 0;i < size ;i++){
        cmp_var = strcmp(name_cmp,cust[i].name);
        if(cmp_var == 0){
            printf("%-10d %-10s %-10s %-10s\n",cust[i].id,cust[i].name,cust[i].adrs,cust[i].phone);
          
        }
    }
    /*using id to delete user*/
    printf("Enter the customer id to delete  :");
    scanf("%d",&del_var);

    /*loop to find matching ids*/

    for (int i = 0;i < size;i++){
        if(del_var == cust[i].id){
            /*we cannot free cust[i].id coz is an int not pointer*/
            free(cust[i].name);
            free(cust[i].adrs);
            free(cust[i].phone);

            /*assigning values from i+1 to i*/
            for (int j = i;j < size;j++) {
                cust[j] = cust[j+1];
            }   
                
        }

    }
    

    cust_db = fopen("customer_database.txt","w");
    for (int i = 0;i < size-1;i++){
        fprintf(cust_db,"%-10d %-10s %-10s %-10s\n",cust[i].id,cust[i].name,cust[i].adrs,cust[i].phone);
    }
    fclose(cust_db);
    size--;
    cust = realloc(cust, size * sizeof(customer));
    /*decalration*/
    printf("Name delted.");
    


}
void upd_name(){
    char name_cmp[30];
    int cmp_var;
    int id_cmp;
    char new_name[30];
     /*Searching names*/
     printf("Enter name to find: ");
     scanf(" %[^\n]",name_cmp);
 
     /*searching loop*/
 
     for (int i = 0;i < size ;i++){
         cmp_var = strcmp(name_cmp,cust[i].name);
         if(cmp_var == 0){
             printf("%-10d %-10s %-10s %-10s\n",cust[i].id,cust[i].name,cust[i].adrs,cust[i].phone);
           
         }
     }
     
     printf("Enter the id of customer whose name to update: ");
     scanf("%d",&id_cmp);

     for (int i = 0;i < size ;i++){
        if(id_cmp == cust[i].id){
            printf("Enter new name: ");
            scanf(" %[^\n]",new_name);
            /*reallocating memory based on new name */
            cust[i].name = realloc(cust[i].name,strlen(new_name)+1);
            strcpy(cust[i].name,new_name);
        }
     }
     cust_db = fopen("customer_database.txt","w");
     for (int i = 0;i < size;i++){
         fprintf(cust_db,"%-10d %-10s %-10s %-10s\n",cust[i].id,cust[i].name,cust[i].adrs,cust[i].phone);
     }
     fclose(cust_db);
    
}
void upd_id(){
    char u_name[30];
    int id_cmp;
    int n_id;
    printf("enter the name to find: ");
    scanf(" %[^\n]",u_name);
    for (int i = 0;i < size; i++){
        if (strcmp(cust[i].name,u_name)==0){
            printf("%-10d %-10s %-10s %-10s\n",cust[i].id,cust[i].name,cust[i].adrs,cust[i].phone);
            printf("Enter the id to change : ");
            scanf("%d",&id_cmp);            
        }
        else {
            printf("Name not found .");
        }
    }
    for (int i = 0;i < size;i++){
            if (id_cmp == cust[i].id){
                printf("Enter the new id : ");
                scanf("%d",&n_id);

                cust[i].id = n_id;
            }
    }
    cust_db = fopen("customer_database.txt","w");
     for (int i = 0;i < size;i++){
         fprintf(cust_db,"%-10d %-10s %-10s %-10s\n",cust[i].id,cust[i].name,cust[i].adrs,cust[i].phone);
     }
     fclose(cust_db);
}
void upd_adrs(){}
void upd_phone(){}
void update_cust(){
    /*using this for a second switch */
    int upd_var;

    /*switch to choose what to change: 
    using  another function to then upadate voz it is too messy otherwise*/
    printf("SELECT WHAT YOU WANT TO UPDATE\n1-Name\n2-Id\n3-ADDRESS\n4-Phone\n5-cancel ");
    scanf(" %d",&upd_var);
    /*loop to then select the updation criterion*/
    while(1){
        switch(upd_var){
            case 1:{
                upd_name();
                return;
            }
            case 2:{
                upd_id();
                break;
            }
            case 3:{
                upd_adrs();
                break;
            }
            case 4:{
                upd_phone();
                break;
            }
            case 5:{
                return;
            }
            default:{
                printf("Monkeys dont need keyboards,choose again.");
            }
        }

    }

    

}
int read_cust_data(){
    char temp_name[30];
    char temp_adrs[30];
    char temp_phone[30];
    int temp_id;

    cust = NULL;
    
    int counter = 0;
    cust_db = fopen("customer_database.txt","r");
    if (cust_db==NULL){
        printf("File not found.");
        return 0;
    }

    while(fscanf(cust_db,"%d %s %s %s",&temp_id,temp_name,temp_adrs,temp_phone) != EOF){
        /*memory allocation fr*/
        cust = realloc(cust, (counter + 1) * sizeof(customer));
        cust[counter].name = (char *)malloc(sizeof(strlen(temp_name))+1);
        cust[counter].adrs = (char *)malloc(sizeof(strlen(temp_adrs))+1);
        cust[counter].phone = (char *)malloc(sizeof(strlen(temp_phone))+1);

        /*value assignment fr fr */
        strcpy(cust[counter].name,temp_name);
        strcpy(cust[counter].adrs,temp_adrs);
        strcpy(cust[counter].phone,temp_phone);
        cust[counter].id = temp_id;
        counter++;
    }

    size = counter;

    return counter;

}


int main(){
    /*creating file
    cust_db = fopen("customer_database.txt","w");
    fprintf(cust_db,"Customer database.");
    fclose(cust_db);*/
    read_cust_data();

    //switch variable.
    int sw_var;
    /*manual memory allocation first*/
    //cust = (customer *)malloc(size * sizeof(customer));

    while(1){

        printf("CUSTOMER & ITEM MANAGEMENT MENU\n");
        printf("1-ADD CUSTOMER\n2-DELETE CUSTOMER\n3-UPDATE CUSTOMER\n4-DISPLAY CUSTOMERS\n5-EXIT");
        scanf("%d",&sw_var);

        switch(sw_var){
            case 1:{
                add_cust();
                break;
            }
            case 2:{
                del_cust();
                break;
            }
            case 3:{
                update_cust();
                break;
            }
            case 4:{
                for (int i = 0;i < size ;i++){
                    printf("%-10d %-10s %-10s %-10s\n",cust[i].id,cust[i].name,cust[i].adrs,cust[i].phone);
                }
                
                break;
            }
            case 5:{
                printf("Exiting.");
                exit(0);
            }

        }
    }
    return 0;
}