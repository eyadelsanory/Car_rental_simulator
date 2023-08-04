
#include <iostream>
#include <strings.h>
using namespace std;


typedef class bus: public car_system
{

int number_of_passenger;
char name_of_driver[20];
int car_number;
char car_model[10];
char car_type[10] ;
float car_price;
bool rented;
char return_time[10];
char renter_name[50];
FILE* data_file;

public:

     bus()
    {
        car_number=0;
        strcpy(car_model,"");
        strcpy(car_type,"");
        car_price=0;
        rented=false;
        strcpy(return_time,"");
        strcpy(renter_name,"");
        strcpy(name_of_driver,"");
        number_of_passenger=0;

    }
    void add_bus_details_to_file();
    void get_bus_info ();
    void rent_bus(char[],char[],char[],int);
    void set_number_of_passenger(int);
    void set_name_of_driver(char[]);
    int get_number_of_passenger();
    char* get_name_of_driver();

};
