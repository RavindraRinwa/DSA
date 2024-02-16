#include<iostream>
using namespace std;

class Fruit{
public:  // because data is private so not access direct so need to make data public
     string name;
     string colour;
};

class Student{
     string name;
     int roll_number;
};
int main(){
Fruit apple; // object
apple.name = "Apple";
apple.colour  = "Red";

cout<<apple.name<<endl<<apple.colour<<endl;

Fruit *mango = new Fruit(); // for pointer . chages to ->
mango->name = "Mango";
mango->colour = "Yellow";

cout<<mango->name<<endl<<mango->colour<<endl;
}