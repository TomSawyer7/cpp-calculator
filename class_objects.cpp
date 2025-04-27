#include <iostream>
using namespace std;

class Car
{
public: 
	string brand;
	string color;
	int yearModel;
	string carType;
	double price;
	bool isFullyPaid;
	
	
	void displayCarDetails(){
		cout<<brand<<endl;
		cout<<color<<endl;
		cout<<yearModel<<endl;
		cout<<carType<<endl;
		cout<<price<<endl;
		if (isFullyPaid == 0){
			cout<<"IT IS FULLY PAID.";
		}
		else {
			cout<<"IT IS NOT FULLY PAID.";
		}
	}
};

int main(){
	
	Car myFirstCar;
	myFirstCar.brand = "Toyota";
	myFirstCar.color = "Pearl White";
	myFirstCar.yearModel = 1992;
	myFirstCar.carType = "Sedan";
	myFirstCar.price = 20.00;
	myFirstCar.isFullyPaid = false;
	
	Car mySecondCar;
	mySecondCar.brand = "BMW";
	mySecondCar.color = "Pearl White";
	mySecondCar.yearModel = 2024;
	mySecondCar.carType = "Sedan";
	mySecondCar.price = 1.00;
	mySecondCar.isFullyPaid = true;
	
	Car myThirdCar;
		
	myFirstCar.displayCarDetails();
	cout<<endl;
	mySecondCar.displayCarDetails();
	return 0;
}