#include <iostream>
#include <strings.h>
#include "cars.h"
#include "customer.h"
#include "bus.h"


using namespace std;

//==========customer=====
//=============setter functions=============
 void CCustomer:: set_Cus_id(int id){
     Cus_ID=id;

    }
    void CCustomer:: set_Cus_name(char name[]){

      strcpy(Cus_name,name);

    }
     void CCustomer:: set_Cus_email(char email[]){

      strcpy(Cus_Email,email);

    }
  void CCustomer:: set_Cus_email_password(char password[]){

      strcpy(Email_Password,password);

    }



   //======================getter functions=================================
    int CCustomer:: get_Cus_id(){
     return Cus_ID;

    }
    char* CCustomer:: get_Cus_name(){

     return Cus_name;

    }
     char* CCustomer:: get_Cus_email(){

     return Cus_Email;

    }
     char* CCustomer:: get_Cus_email_password(){

     return Email_Password;

   }


   //=====================
   void CCustomer:: get_cus_info()
{
    cout<<Cus_ID<<endl;
    cout<<Cus_name<<endl;
    cout<<Cus_Email<<endl;
}




 void CCustomer:: add_customer_details_to_file() //adding the data of the cars to a file

    {

        char data_taken_array[4][20]={{"ID"},{"Name"},{"Email"},{"Password"}};
        data_file=fopen("customer_data.txt","a");

            for(int j=0;j<4;j++)
            {
                char data_wraiter_to_file[20];
                cout<<"please enter customer "<<data_taken_array[j];
                cin>>data_wraiter_to_file;
                fprintf(data_file,data_wraiter_to_file);
                fprintf(data_file,"-");
            }
            fprintf(data_file,"\n");

        fclose(data_file);

    }

//=======car==
//============Constructor====
car_system:: car_system()
    {
        car_number=0;
        strcpy(car_model,"");
        strcpy(car_type,"");
        car_price=0;
        rented=false;
        strcpy(return_time,"");
        strcpy(renter_name,"");
    }
//===set

    void car_system:: set_car_number(int data)
    {
        car_number=data;

    }

     void car_system:: set_car_model(char data[])
    {
        strcpy(car_model,data);

    }

     void car_system:: set_car_type(char data[])
    {
        strcpy(car_type,data);

    }

      void car_system:: set_car_price(float data)
    {
        car_price=data;

    }

      void car_system:: set_car_rented(bool data)
    {
        rented=data;

    }

    void car_system:: set_return_time(char data[])
    {
        strcpy(return_time,data);

    }

     void car_system:: set_renter_name(char data[])
    {
        strcpy(renter_name,data);

    }
//========gets functions for the private public inside the class
  int car_system:: get_car_number()
    {
        return car_number;
    }

        char* car_system:: get_car_model()
    {
        return car_model;
    }

       char* car_system:: get_car_type()
    {
        return car_type;
    }

       char* car_system:: get_renter_name()
    {
        return renter_name;
    }

    char* car_system:: get_return_time()
    {
        return return_time;
    }
    bool car_system:: get_rented()
    {
        return rented;
    }

     float car_system:: get_car_price()
    {
        return car_price;
    }

//==============================


       void car_system:: add_car_details_to_file() //adding the data of the cars to a file

    {

        char data_taken_array[4][20]={{"number"},{"model"},{"type"},{"price"}};
        data_file=fopen("cars_data.txt","a");

            for(int j=0;j<4;j++)
            {
                char data_wraiter_to_file[20];
                cout<<"please enter car "<<data_taken_array[j];
                cin>>data_wraiter_to_file;
                fprintf(data_file,data_wraiter_to_file);
                fprintf(data_file,"-");
            }
            fprintf(data_file,"\n");

        fclose(data_file);

    }




     void bus:: add_bus_details_to_file() //adding the data of the bus to a file

    {

        char data_taken_array[5][20]={{"number"},{"model"},{"type"},{"price"},{"driver name"}};
        data_file=fopen("bus_data.txt","a");

            for(int j=0;j<=4;j++)
            {
                char data_wraiter_to_file[20];
                cout<<"please enter bus "<<data_taken_array[j];
                cin>>data_wraiter_to_file;
                fprintf(data_file,data_wraiter_to_file);
                fprintf(data_file,"-");
            }
            fprintf(data_file,"\n");

        fclose(data_file);

    }























    void car_system:: rent_car(char renter_name_paste[],char return_time_paste[],int number_of_cars_in_the_system)          // read line by line and edit the line we want and concatenate lines to the whole_file var then open file in w mode and write the whole var
    {
        char dash[2]="-";
        char new_line[3]="\n";
        set_renter_name(renter_name_paste);
        set_return_time(return_time_paste);
        set_car_rented(true);
        FILE * edit_file;
        edit_file=fopen("cars_data.txt","r");
        char whole_file[2000]="";
        for(int i=1;i<=number_of_cars_in_the_system;i++)
        {
            char line_readed[200]="";
            if(i==get_car_number())
            {
                fgets(line_readed,199,edit_file);
                int back_slash_n_indicator=strlen(line_readed);
                line_readed[back_slash_n_indicator -1]='\0';
                strcat(line_readed,renter_name_paste);
                strcat(line_readed,dash);
                strcat(line_readed,return_time_paste);
                strcat(line_readed,dash);
                strcat(whole_file,line_readed);


            }
            else {
                  fgets(line_readed,199,edit_file);
                  strcat(whole_file,line_readed);
                  }


        }
         fclose(edit_file);
           edit_file=fopen("cars_data.txt","w");
           fprintf(edit_file,whole_file);
           fclose(edit_file);


    }


     void bus::rent_bus(char renter_name_paste[],char return_time_paste[],char number_of_passenger_paste[],int number_of_bus_in_the_system)          // read line by line and edit the line we want and concatenate lines to the whole_file var then open file in w mode and write the whole var
    {
        char dash[2]="-";
        char new_line[3]="\n";
        set_renter_name(renter_name_paste);
        set_return_time(return_time_paste);
        int number_of_passenger_int=atoi(number_of_passenger_paste);
        set_number_of_passenger(number_of_passenger_int);
        set_car_rented(true);
        FILE * edit_file;
        edit_file=fopen("bus_data.txt","r");
        char whole_file[2000]="";
        for(int i=1;i<=number_of_bus_in_the_system;i++)
        {
            char line_readed[200]="";
            if(i==get_car_number())
            {
                fgets(line_readed,199,edit_file);
                int back_slash_n_indicator=strlen(line_readed);
                line_readed[back_slash_n_indicator -1]='\0';
                strcat(line_readed,renter_name_paste);
                strcat(line_readed,dash);
                strcat(line_readed,return_time_paste);
                strcat(line_readed,dash);
                strcat(line_readed,number_of_passenger_paste);
                strcat(line_readed,dash);
                strcat(whole_file,line_readed);


            }
            else {
                  fgets(line_readed,199,edit_file);
                  strcat(whole_file,line_readed);
                  }




        }
           fclose(edit_file);
           edit_file=fopen("bus_data.txt","w");
           fprintf(edit_file,whole_file);
           fclose(edit_file);


    }





    void car_system:: get_car_info ()
    {
        cout<<"car model:"<<car_model<<endl;
        cout<<"car number:"<<car_number<<endl;
        cout<<"car type:"<<car_type<<endl;
        cout<<"car price:"<<car_price<<endl;
        cout<<"is it rented:"<<rented<<endl;
        cout<<"renter name:"<<renter_name<<endl;
        cout<<"return time:"<<return_time<<endl;

    }




      void bus:: get_bus_info ()
    {
        cout<<"car model:"<<get_car_model()<<endl;
        cout<<"car number:"<<get_car_number()<<endl;
        cout<<"car type:"<<get_car_type()<<endl;
        cout<<"car price:"<<get_car_price()<<endl;
        cout<<"is it rented:"<<get_rented()<<endl;
        cout<<"renter name:"<<get_renter_name()<<endl;
        cout<<"return time:"<<get_return_time()<<endl;
        cout<<"driver name:"<<name_of_driver<<endl;

    }







    void bus::set_number_of_passenger(int data)
    {
        number_of_passenger=data;
    }

     void bus::set_name_of_driver(char data[])
    {
       strcpy(name_of_driver,data);
    }


    int bus::get_number_of_passenger()
    {
        return number_of_passenger;
    }

    char* bus::get_name_of_driver()
    {
        return name_of_driver;
    }





