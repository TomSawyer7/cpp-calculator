#include <iostream>
using namespace std;

class Person{
private:
	string name;
	int age;
	
public:
	void Breathe(){
		cout<<"Breathing"<<endl;
	}
	void Talk(){
		cout<<"Talking"<<endl;
	}
	
	Person(string name, int age): name (name), age (age){}
	
	string getName(){
		return name;
	}
	
	int getAge(){
		return age;
	}
};

class Employee: public Person{
public:
	void work(){
		cout<<"Working"<<endl;
	}
	void write(){
		cout<<"Write"<<endl;
	}
};

class Corporate: public Person{
public:
	Corporate(string name, int age): Person(name, age){}
};




int main(){
	Employee employee1("John", 20);
	employee1.work();
	employee1.write();
		
	
	
	return 0;
}