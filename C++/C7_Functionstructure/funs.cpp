#include<iostream>
#include<cmath>

using namespace std;

const double pi=3.1415926535;

struct polar{
	double radius;
	double angle; // In degree, but default radicular
};
struct carte{
	double dim_x;
	double dim_y;
};

// Prototypes
carte po_ca(polar*);
polar ca_po(carte*);

int main(void){

	carte input1, output2;
	polar input2, output1;

	cout << fixed;
	cout.precision(6);
	cout.setf(ios_base::showpoint);

	// Cartesian to polar
	cout << "Input the x coordinates: ";
	cin >> input1.dim_x;
	cout << "Input the y coordinates: ";
	cin >> input1.dim_y;
	output1 = ca_po(&input1);
	cout << "Output the radius: " << output1.radius << endl;
	cout << "Output the angle: " << output1.angle << " deg"<< endl;

	// Polar to cartesian
	cout << "Input the radius: ";
	cin >> input2.radius;
	cout << "Input the angle in degree: ";
	cin >> input2.angle;
	output2 = po_ca(&input2);
	cout << "Output the x coordinates: " << output2.dim_x << endl;
	cout << "Output the y coordinates: " << output2.dim_y << endl;

	return 0;
}

carte po_ca(polar* pol){
	carte car;
	double angle_rad = (pol->angle)*pi/180.0;
	car.dim_x = (pol->radius)*cos(angle_rad);
	car.dim_y = (pol->radius)*sin(angle_rad);
	return car;
}

polar ca_po(carte* car){
	polar pol;
	pol.radius = sqrt(pow(car->dim_x,2)+pow(car->dim_y,2));
	pol.angle = atan2(car->dim_y, car->dim_x)*180.0/pi;
	return pol;
}
