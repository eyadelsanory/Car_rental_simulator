#include <strings.h>
#include <iostream>

using namespace std;

typedef class  car_system

{
    private:

int car_number;
char car_model[10];
char car_type[10] ;
float car_price;
bool rented;
char return_time[10];
char renter_name[50];
FILE* data_file;



public:


     car_system();

   //============set==============
   void set_car_number(int );
   void set_car_model(char[]);
   void set_car_type(char[] );
   void set_car_price(float );
   void set_car_rented(bool );
   void set_return_time(char[] );
   void set_renter_name(char []);

    //====================================================== all_gets_functions()=================
int get_car_number();
char *get_car_model();
char *get_car_type();
char *get_renter_name();
char *get_return_time();
bool get_rented();
float get_car_price();

//===================================
 void add_car_details_to_file();

  void rent_car(char[],char[],int );

  void get_car_info ();
};


