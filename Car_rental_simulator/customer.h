
#include <strings.h>
#include <iostream>

typedef class CCustomer{

private:
    int Cus_ID;
    char Cus_name[50];
    char Cus_Email[50];
    char Email_Password[30];
    FILE* data_file;



public:

    //============Constructor====
//=======set
void set_Cus_id(int );
void set_Cus_name(char[] );
void set_Cus_email(char[] );
void set_Cus_email_password(char[] );
//========get
int get_Cus_id();
char* get_Cus_name();
 char* get_Cus_email();
 char* get_Cus_email_password();
//========
void get_cus_info();
void add_customer_details_to_file();











};

