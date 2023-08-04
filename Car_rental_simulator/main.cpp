
#include <iostream>
#include "cars.h"
#include "customer.h"
#include <strings.h>
#include "bus.h"
#include <conio.h>
using namespace std;
int login(int);



int numbers_of_system(char c)
{
    FILE* f;
    f=fopen("saved_num.txt","r");
    int cars_num;
    int bus_num;
    int customer_num;
    for(int i=1;i<=5;i++)
    {
        if(i==1)
        {
            customer_num=fgetc(f)-'0';
            fgetc(f);

        }

          else if(i==3)
        {
            cars_num=fgetc(f)-'0';
            fgetc(f);

        }
        else if(i==5)
        {
            bus_num=fgetc(f)-'0';

        }

    }
    switch(c)
    {
    case 'a':
        {return customer_num;}


    case 'b':
    {return bus_num;}


    case 'c':
    {return cars_num;}
    }


}





void menu(bus bus_array[],car_system cars_array[],CCustomer customer_array[],int number_of_cars,int number_of_bus,int number_of_customer)
{
            char key_taken;
            cout<<"\nfor vehicle information click (a) for loging in the system and rent click (b)"<<endl;
            key_taken=getch();
            if(key_taken=='a')
            {

                cout<<"for cars details click(a) for bus details click(b) for customer details click(c)"<<endl;
                key_taken=getch();
                switch(key_taken)
                {
                    case 'a':
                    {
                        for(int i=0;i<number_of_cars;i++)
                         cars_array[i].get_car_info();

                    }break;
                    case 'b':
                        {
                            for(int i=0;i<number_of_bus;i++)
                               bus_array[i].get_bus_info();
                        }break;

                         case 'c':
                        {
                            for(int i=0;i<number_of_bus;i++)
                               customer_array[i].get_cus_info();
                        }break;}
                        cout<<"\n to get back to meneu click (a) to exit click (b)"<<endl;
                        key_taken=getch();;
                        switch(key_taken)
                        {
                        case 'a':{
                            menu(bus_array,cars_array,customer_array,number_of_cars,number_of_bus,number_of_customer);}
                            break;

                        }

                        }
                        else
                        {
                            int user_loged=login(number_of_customer);
                            cout<<"\t\t\t\t\twelcome "<<customer_array[user_loged].get_Cus_name()<<endl;
                            cout<<"TO RENT CAR (c) TO RENT BUS (b)";
                            key_taken=getch();
                            switch (key_taken)
                            {
                                case 'c':
                                {   cout<<"avilable cars are : ";
                                    for(int i=0;i<number_of_cars;i++)
                                    {
                                        bool t=cars_array[i].get_rented();
                                        if(!t)

                                        cout<<"("<<i+1<<")"<<cars_array[i].get_car_type()<<" "<<cars_array[i].get_car_model()<<" "<<cars_array[i].get_car_price()<<endl;

                                    }
                                    int the_picked_car;
                                    cout<<"write the car number inside the brackets to pick the car you want and click enter ";
                                    cin>>the_picked_car;
                                    char return_time[20];
                                    cout<<"when you going to return it? ";
                                    cin>>return_time;
                                    cars_array[the_picked_car-1].rent_car(customer_array[user_loged].get_Cus_name(),return_time,number_of_cars);
                                    cout<<"\n to get back to meneu click (a) to exit click (b)";
                                    key_taken=getch();
                                    switch(key_taken)
                                   {
                                    case 'a':{
                                               menu(bus_array,cars_array,customer_array,number_of_cars,number_of_bus,number_of_customer);}
                                             break;

                                    }



                                }break;

                                 case 'b':
                                {   cout<<"avilable bus are : ";
                                    for(int i=0;i<number_of_bus;i++)
                                    {   bool t=bus_array[i].get_rented();
                                        if(!t)
                                        cout<<"("<<i+1<<")"<<bus_array[i].get_car_type()<<" "<<bus_array[i].get_car_model()<<" "<<bus_array[i].get_car_price()<<endl;


                                    }

                                     int the_picked_bus;
                                    cout<<"write the bus number inside the brackets to pick the bus you want and click enter ";
                                    cin>>the_picked_bus;
                                    char return_time[20];
                                    cout<<"when you going to return it? ";
                                    cin>>return_time;
                                     char number_passenger[20];
                                    cout<<"how many passenger?";
                                    cin>>number_passenger;
                                    bus_array[the_picked_bus-1].rent_bus(customer_array[user_loged].get_Cus_name(),return_time,number_passenger,number_of_bus);
                                    cout<<"\n to get back to meneu click (a) to exit click (b)";
                                    key_taken=getch();
                                    switch(key_taken)
                                   {
                                    case 'a':{
                                               menu(bus_array,cars_array,customer_array,number_of_cars,number_of_bus,number_of_customer);}
                                             break;

                                    }


                                }break;






                            }


                        }

















}



void set_data_to_private_var_bus(class bus cars[],int number_of_cars)
    {
        FILE *file_read;
        file_read=fopen("bus_data.txt","r");

        for(int z=0;z<number_of_cars;z++)
        {
        char line_readed[200];
        fgets(line_readed,180,file_read);
        char *data_splited=strtok(line_readed,"-");
        int data_cursor=1;
        while(data_splited!=NULL)
        {
            switch(data_cursor){
            case 1:
                {int car_number=atoi(data_splited);
                cars[z].set_car_number(car_number);}
                break;
            case 2:{
                cars[z].set_car_model(data_splited);}
                break;
            case 3:{
                cars[z].set_car_type(data_splited);}
                break;
            case 4:{
                float car_price=atof(data_splited);
                 cars[z].set_car_price(car_price);}
                 break;
            case 5:{
                 cars[z].set_name_of_driver(data_splited);}
                 break;

        }
        data_splited=strtok(NULL,"-");
        data_cursor+=1;
        }

    }
    }







void set_data_to_private_var_bus_not_first(class bus cars[],int number_of_cars)
    {
        FILE *file_read;
        file_read=fopen("bus_data.txt","r");

        for(int z=0;z<number_of_cars;z++)
        {
        char line_readed[200];
        fgets(line_readed,180,file_read);
        char *data_splited=strtok(line_readed,"-");
        int data_cursor=1;
        while(data_splited!=NULL)
        {
            switch(data_cursor){
            case 1:
                {int car_number=atoi(data_splited);
                cars[z].set_car_number(car_number);}
                break;
            case 2:{
                cars[z].set_car_model(data_splited);}
                break;
            case 3:{
                cars[z].set_car_type(data_splited);}
                break;
            case 4:{
                float car_price=atof(data_splited);
                 cars[z].set_car_price(car_price);}
                 break;
            case 5:{
                 cars[z].set_name_of_driver(data_splited);}
                 break;
             case 6:{
                 cars[z].set_return_time(data_splited);}
                 break;
            case 7:{
                int pass_num=atoi(data_splited);
                 cars[z].set_number_of_passenger(pass_num);cars[z].set_car_rented(true);}
                 break;

        }
        data_splited=strtok(NULL,"-");
        data_cursor+=1;
        }

    }
    }





void set_data_to_private_var_customer(class CCustomer customers[],int number_of_customer)
    {
        FILE *file_read;
        file_read=fopen("customer_data.txt","r");

        for(int z=0;z<number_of_customer;z++)
        {
        char line_readed[200];
        fgets(line_readed,180,file_read);
        char *data_splited=strtok(line_readed,"-");
        int data_cursor=1;
        while(data_splited!=NULL)
        {
            switch(data_cursor){
            case 1:
                {int customer_id=atoi(data_splited);
                customers[z].set_Cus_id(customer_id);}
                break;
            case 2:{
                customers[z].set_Cus_name(data_splited);}
                break;
            case 3:{
                customers[z].set_Cus_email(data_splited);}
                break;
            case 4:{
                 customers[z].set_Cus_email_password(data_splited);}
                 break;

        }
        data_splited=strtok(NULL,"-");
        data_cursor+=1;
        }

    }
    }

//============================================================================================================================================


 void set_data_to_private_var_cars(class car_system cars[],int number_of_cars)
    {
        FILE *file_read;
        file_read=fopen("cars_data.txt","r");

        for(int z=0;z<number_of_cars;z++)
        {
        char line_readed[200];
        fgets(line_readed,180,file_read);
        char *data_splited=strtok(line_readed,"-");
        int data_cursor=1;
        while(data_splited!=NULL)
        {
            switch(data_cursor){
            case 1:
                {int car_number=atoi(data_splited);
                cars[z].set_car_number(car_number);}
                break;
            case 2:{
                cars[z].set_car_model(data_splited);}
                break;
            case 3:{
                cars[z].set_car_type(data_splited);}
                break;
            case 4:{
                float car_price=atof(data_splited);
                 cars[z].set_car_price(car_price);}
                 break;

        }
        data_splited=strtok(NULL,"-");
        data_cursor+=1;
        }

    }
    }



    //===========================================================================================
    int login(int number_of_customer)
    {
        FILE* login_check;
        login_check=fopen("customer_data.txt","r");
        char email[50];
        char password[50];
        cout<<"please enter your email:";
        cin>>email;
        cout<<"please enter your password";
        cin>>password;
        int i;
        for(i=0;i<number_of_customer;i++)
        {
            char line_splited[200];
            fgets(line_splited,190,login_check);
            char *segment;
            int cursor=1;
            bool is_email_true=false;
            bool is_pass_true=false;
            segment=strtok(line_splited,"-");
            while(segment!=NULL)
            {
                switch(cursor)
                {
                case 3:
                    {
                        bool checker=strcmp(email,segment);
                        if (!checker)
                            is_email_true=true;
                    }break;

                case 4:
                {
                    bool checker=strcmp(password,segment);
                    if (!checker)
                        is_pass_true=true;
                }break;
                }
                cursor+=1;
                segment=strtok(NULL,"-");

            }
            if(is_email_true&&is_pass_true){
                fclose(login_check);

                return i;}

        }
        fclose(login_check);
        cout<<"the email or password you enterd are incorrect"<<endl;
        cout<<"please try again"<<endl;
        login(1);
    }

//===============================================================================================================================

void set_data_to_private_var_cars_not_first_run(class car_system cars[],int number_of_cars)
    {
        FILE *file_read;
        file_read=fopen("cars_data.txt","r");

        for(int z=0;z<number_of_cars;z++)
        {
        char line_readed[200];
        fgets(line_readed,180,file_read);
        char *data_splited=strtok(line_readed,"-");
        int data_cursor=1;
        while(data_splited!=NULL)
        {
            switch(data_cursor){
            case 1:
                {int car_number=atoi(data_splited);
                cars[z].set_car_number(car_number);}
                break;
            case 2:{
                cars[z].set_car_model(data_splited);}
                break;
            case 3:{
                cars[z].set_car_type(data_splited);}
                break;
            case 4:{
                float car_price=atof(data_splited);
                 cars[z].set_car_price(car_price);}
                 break;
            case 5:{
                 cars[z].set_renter_name(data_splited);}
                 break;
            case 6:{
            cars[z].set_return_time(data_splited);cars[z].set_car_rented(true);}
            break;

        }
        data_splited=strtok(NULL,"-");
        data_cursor+=1;
        }

    }
    }



int main()
{
    FILE* check_cars;
    FILE* check_bus;
    int check_carss;
    int check_buss;
    check_cars=fopen("cars_data.txt","r");
    check_bus=fopen("bus_data.txt","r");
    check_carss=fgetc(check_cars)==-1?0:1;
    check_buss=fgetc(check_bus)==-1?0:1;
    int runner=check_buss||check_carss;
    switch(runner)
    {
    case 0:
        {
            cout<<"\t\t\t\t\t\tWelcome to Car Rental App\n";
            int number_of_cars;
            int number_of_bus;
            int number_of_customer;
            cout<<"please enter number of cars: ";
            cin>>number_of_cars;
            cout<<"please enter number of bus: ";
            cin>>number_of_bus;
            cout<<"please enter number of customers: ";
            cin>>number_of_customer;
            FILE* save;
            save=fopen("saved_num.txt","w");
            fprintf(save,"%d",number_of_customer);
            fputc('-',save);
            fprintf(save,"%d",number_of_cars);
            fputc('-',save);
            fprintf(save,"%d",number_of_bus);
            fputc('-',save);
            fclose(save);


            bus bus_array[number_of_bus];
            car_system cars_array[number_of_cars];
            CCustomer customer_array[number_of_customer];
            for(int i=0;i<number_of_customer;i++)
            {
                customer_array[i].add_customer_details_to_file();
            }
            set_data_to_private_var_customer(customer_array,number_of_customer);
            for(int i=0;i<number_of_cars;i++)
            {
                cars_array[i].add_car_details_to_file();
            }
            set_data_to_private_var_cars(cars_array,number_of_cars);
            for(int i=0;i<number_of_bus;i++)
            {
                bus_array[i].add_bus_details_to_file();
            }
            set_data_to_private_var_bus(bus_array,number_of_bus);
            cout<<"\n\t\t\t\t\tAdding cars to the system is done"<<endl;
            menu(bus_array,cars_array,customer_array,number_of_cars,number_of_bus,number_of_customer);


        }
        break;










    case 1:
        {
            int number_of_cars=numbers_of_system('c');
            int number_of_bus=numbers_of_system('b');
            int number_of_customer=numbers_of_system('a');
            CCustomer customer_array[number_of_customer];
            car_system  cars_array[number_of_cars];
            bus bus_array[number_of_bus];
            set_data_to_private_var_customer(customer_array,number_of_customer);
            set_data_to_private_var_cars_not_first_run(cars_array,number_of_cars);
            set_data_to_private_var_bus_not_first(bus_array,number_of_bus);
            menu(bus_array,cars_array,customer_array,number_of_cars,number_of_bus,number_of_customer);

        }

    }




    return 0;
}


