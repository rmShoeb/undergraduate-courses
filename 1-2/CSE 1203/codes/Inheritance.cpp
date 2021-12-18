/**
    author_rmShoeb
    edited
    started_at_1900_12_23_2017
    finished_at_
    modified_at_
    there_is_nothing_special_about_this_code
**/

#include<iostream>      ///for_stream_input_output
#include<cstdio>        ///for_standard_input_output
#include<cstdlib>       ///for_using_library_functions
#include<cstring>       ///for_string_and_string_related_functions
#include<conio.h>       ///I_do_not_know_what_this_does
using namespace std;


class House
{
public:
    int get_rooms(void);
    void set_rooms(int);

protected:
    //int rooms=0;

private:        ///private_and_protected_members_of_base_class_cannot_be_inherited
    int rooms=0;
    int others;
};


class Area:public House
{
public:
    void print(void);

protected:

private:
    int hudai=0;

};


int House::get_rooms()
{
    return rooms;
}


void House::set_rooms(int x=0)
{
    rooms+=x;
}


void Area::print()
{
    cout<<endl;
}




int main(void)
{
    Area a_51;

    a_51.set_rooms(3);
    cout<<a_51.get_rooms();
    a_51.print();
    cout<<sizeof(a_51)<<endl;

    getch();
    return 0;
}
