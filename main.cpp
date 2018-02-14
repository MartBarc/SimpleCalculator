/**
* -------------------------------------Info-----------------------------------
*	Name:				Date:			Current Version:
*	Martin Barcelon		01-29-2017		1.0
*
*	Email:
*	martin.barcelon@stonybrook.edu
*
*	Student ID:		Section Number:
*	110250249		01
*/
/**
* -------------------------------Short Description----------------------------
*	Modified version of calc3.cpp. This new version accepts a 3 dimensional 
* vector instead of 2 dimensions from calc3.cpp. Furthermore, a new format is
* introduced into the input.txt file shown here:
*	+  [ 1.1 2.2 3.3 ]  [ 4.4 5.5 6.6]
*	-  [ 1.1 2.2 3.3 ]  [ 4.4 5.5 6.6]
*	*  [ 1.1 2.2 3.3 ]  [ 4.4 5.5 6.6]
*	x  [ 1.1 2.2 3.3 ]  [ 4.4 5.5 6.6]
*	a  [ 1.1 2.2 3.3 ]  [ 4.4 5.5 6.6]
*	m  [ 1.1 2.2 3.3 ]
*	u  [ 1.1 2.2 3.3 ] 
*	s 2.5  [ 1.1 2.2 3.3 ]                         
*	q
* ----------------------------------------------------------------------------
*/
#include <iostream>
using namespace std;

#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]) {

	char c, v1start, v1end, v2start, v2end;
	float x, y, z, a, b, c1, num1, num2, num3, ans;

	cout << argc << endl;


	if (argc != 3) {
		cout << endl << "Usage:  " << argv[0] << "input-file output-file" << endl;
		exit(1);
	}

	ifstream  fin(argv[1]);
	ofstream  fout(argv[2]);

	if (!fin) {
		cerr << "cannot open " << argv[1] << endl;
		exit(1);
	}
	if (!fout) {
		cerr << "cannot open " << argv[2] << endl;
		exit(1);
	}

	fout << "Enter operation +, -, *, x, a, m, u, s or q to quit.\n";
	fin >> c;
	cout << c << endl;
	while (c != 'q') {
		cout << c << endl;
		if (! ((c == '+') || (c == '-') || (c == '*') || (c == 'x') 
			|| (c == 'a') || (c == 'm') || (c == 'u') || (c == 's')
			|| (c == '[') || (c == ']')))
		{
			fout << "Illegal Operation";
			return 0;
		}
		
		
		if ((c == '+') || (c == '-') || (c == '*') || (c == 'x') || (c == 'a'))
		{
			fin >> v1start;
			cout << v1start << endl;
			fout << "Enter x . \n";
			fin >> x;
			cout << x << endl;
			fout << "Enter y . \n";
			fin >> y;
			cout << y << endl;
			fout << "Enter z . \n";
			fin >> z;
			cout << z << endl;
			fin >> v1end;
			cout << v1end << endl;

			fin >> v2start;
			cout << v2start << endl;
			fout << "Enter a . \n";
			fin >> a;
			cout << a << endl;
			fout << "Enter b . \n";
			fin >> b;
			cout << b << endl;
			fout << "Enter c . \n";
			fin >> c1;
			cout << c1 << endl;
			fin >> v2end;
			cout << v2end << endl;
		}
		else if ((c == 'm') || (c == 'u'))
		{
			fin >> v1start;
			cout << v1start << endl;
			fout << "Enter x. \n";
			fin >> x;
			cout << x << endl;
			fout << "Enter y . \n";
			fin >> y;
			cout << y << endl;
			fout << "Enter z . \n";
			fin >> z;
			cout << z << endl;
			fin >> v1end;
			cout << v1end << endl;
		}
		else if (c == 's')
		{
			fout << "Enter scale a . \n";
			fin >> a;
			cout << a << endl;
			fin >> v1start;
			cout << v1start << endl;
			fout << "Enter x. \n";
			fin >> x;
			cout << x << endl;
			fout << "Enter y . \n";
			fin >> y;
			cout << y << endl;
			fout << "Enter z . \n";
			fin >> z;
			cout << z << endl;
			fin >> v1end;
			cout << v1end << endl;
		}
		else
		{
			fout << "Error loading values, check syntax." << endl;
			break;
		}

		switch (c) {
		case '+': 	
			fout << "Answer: ";
			fout << (x + a) << "\t" << (y + b) << "\t" << (z + c1) << endl;
			break;
		case '-': 
			fout << "Answer: ";
			fout << (x - a) << "\t" << (y - b) << "\t" << (z - c1) << endl;
			break;
		case '*': 
			fout << "Answer: ";
			ans = (x * a) + (y * b) + (z * c1);
			fout << ans << "\n";
			break;
		case 'x': 
			fout << "Answer: ";
			fout << (y*c1 - b * z) << "i\t" << (z*a - x * c) << "j\t" << (x*b - y * a) << "k\t" << endl;
			break;
		case 'a': //
			fout << "Answer: ";
			num1 = sqrt((x * x) + (y * y) + (z * z));
			num2 = sqrt((a * a) + (b * b) + (c1 * c1));
			num3 = (x * a) + (y * b) + (z * c1);
			fout << ((acos(num3 / (num1 * num2)))*180)/3.1459 << endl;
			break;
		case 'm':
			fout << "Answer: ";
			fout << sqrt((x * x) + (y * y) + (z * z)) << endl;
			break;
		case 'u':
			fout << "Answer: ";
			num1 = sqrt((x * x) + (y * y) + (z * z));
			fout << (x / num1) << "\t" << (y / num1) << "\t" << (z / num1) << endl;
			break;
		case 's':
			fout << "Answer: ";
			fout << (x * a) << "\t" << (y * a) << "\t" << (z * a) << endl;
			break;
		default:
			fout << "Illegal op\n";
		}

		fout << "Enter operation +, -, *, x, a, m, u, s or q to quit.\n";
		fin >> c;
		
	}
	return 0;
}
