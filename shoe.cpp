#include <iostream>
using namespace std;

class Shoe
{
private: 
	string brand;
	int size;
	string color;
	double price;
	string typeOfShoes;
	
public:
	Shoe(string b, string c, int s, double p, string t){
		brand = b;
		color = c;
		size = s;
		price = p;
		typeOfShoes = t;
	}
	
	void displayShoeDetails()
	{
		cout<<brand<<endl;
		cout<<size<<endl;
		cout<<color<<endl;
		cout<<price<<endl;
		cout<<typeOfShoes<<endl;
	}
};
int main()
{
	
	Shoe Shoes1("Nike", "Black", 9, 1000.00, "Running");
	Shoe Shoes2("Adidas", "White", 8, 2000.00, "Basketball");
	Shoes1.displayShoeDetails();
	Shoes2.displayShoeDetails();
	
	return 0;
}