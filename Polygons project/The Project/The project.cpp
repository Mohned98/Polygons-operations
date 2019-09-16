#include<iostream>
#include<math.h>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
 
//Polygons=[(-6,6),(-6,6),(-8,0),(-3,0),(-3,6),(-6,6);(-5,6),(-7,3.5),(-9,1),(-1.5,-1);(-5,4),(1,4),(1,4),(1,4),(3,1),(1,-2),(-3,-2);(-4,3),(-10,3),(-8,7),(-4,8),(-4,5);(5,7),(3,5),(2,8),(4,11),(6,9);(6,6),(7,9),(10,9),(10,7),(10,6),(8,6);(6,3),(6,3),(5,0),(5,0),(4,2),(4,2);(6,-1),(8,-2),(9,-1),(9,2),(7,3),(6,1);(8,2),(5,2),(5,8),(7,8),(8,8);(-20,-20),(-20,-7),(-16,-6),(-12,-5),(-2,-15),(-9,-19);(-17,-10),(-6,-7),(8,-12),(-4,-20);(21,-5),(53,-5),(47,-29),(22,-29);(-13,0),(-19,2),(-18,4),(-16,8);(12,1),(20,-2),(30,9);(15,-19),(15,-10),(13,-10),(12,-10),(10,-10),(10,-19);(15,-10),(18,-18),(17,-7);(15,-7),(12,-6),(15,-10)]
/* 

Polygons=[(15,-19),(15,-10),(13,-10),(12,-10),(10,-10),(10,-19);(15,-10),(15,-10),(18,-18),(17,-7),(15,-10);(15,-7),(12,-6),(15,-10),(15,-9),(15,-8);(6,5),(16,30),(35,30),(35,5),(13,5);(-20,-20),(-20,-7),(-16,-6),(-12,-5),(-2,-15),(-9,-19);(-17,-10),(-6,-7),(8,-12),(-4,-20);(0,0),(0,5),(0,5),(0,10),(-8,0);(-8,0),(-8,3),(-8,6),(-14,6),(-20,0),(-10,0);(-7,15),(-15,15),(-20,15),(-20,15),(-20,15),(-20,8),(-7,8)] 

Inside_Rectangle (-25,-20),(-25,-5),(20,-5),(20,-20)
Inside_Circle (14,-13),8
;(-7,15),(-15,15),(-20,15),(-20,15),(-20,15),(-20,8),(-7,8)]

*/
int Number_Polygons(string s);
int Total_Number_Points(string s);
float Minimum_X(string s, float X[], int size);
float Maximum_X( float X[], int size);
float Minimum_Y(string s, float Y[], int size); 
float Maximum_Y( float Y[], int size);
void Enclosing_Rectangle(string s, float X[], float Y[], int size);
void Total_Redundant_Points1(string s, float X2[][100], float Y2[][100]);
int Total_Redundant_Points(string s, vector<vector<float>>&, vector<vector<float>>&); 
int Number_Points_Polygon(string s, int numberofpolygon);
void Polygon_Points(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Point_Polygons(string s, float X2[][100], float Y2[][100]);
void List_Polygons_Points(string s, vector<vector<float>>&, vector<vector<float>>&);
void List_Points_Polygons(string s, float X2[][100], float Y2[][100]);
float length(float x1, float y1, float x2, float y2);
void Polygon_Perimeter(string s, vector<vector<float>>&, vector<vector<float>>&);
void List_Triangles(string s, vector<vector<float>>&, vector<vector<float>>&);
void List_Rectangles(string s, vector<vector<float>>&, vector<vector<float>>&);
void List_Trapezoid(string s, vector<vector<float>>&, vector<vector<float>>&);
void Inside_Rectangle(string s, vector<vector<float>>&, vector<vector<float>>&);
void Inside_Circle(string s, vector<vector<float>>&, vector<vector<float>>&);
float Area(string s, int index, vector<vector<float>>&, vector<vector<float>>&);
void Polygon_Area(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Polygons_Area_Range(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
bool Enclosing_Point(float x,float y, int index, string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Polygons_Enclosing_Point(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
bool Intersecting(int index1, int index2, string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Is_Intersecting(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Intersecting_Group(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Largest_Intersecting_Pair(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
bool Connected(int index1, int index2, string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Is_Connected(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Is_Connected_Group(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Maximum_Intersecting_Group(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new);
void Maximum_Connected_Group(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new); 
int main()
{
	string input  ,operation;
	getline(cin, input);
	


	int m, n, e, q, w;
	float num;
	float X[10000];
	float Y[10000];
	float X2[100][100];
	float Y2[100][100];
	vector<vector<float>>X2new;
	vector<vector<float>>Y2new;
	
	string inputn, inputnew, inputnew2, s,inp;
		inputn = input;
	for (unsigned int i = 0; i <= inputn.length(); i++)
		if (inputn[i] == ',' || inputn[i] == ')' || inputn[i] == '(' || inputn[i] == ';' || inputn[i] == ']')
			inputnew = inputn.replace(i, 1, "&");
	inputnew = inputnew.replace(0, 9, "");
	inputnew2 = inputnew;
	for (int k = 0; k < 20000; k++)
	{
		m = inputnew2.find("&");
		q = m;
		w = 0;
		while (1)
		{
			if (inputnew2[q] != '&')
				break;
			q = q + 1;
			w = w + 1;
		}
		e = m + w;
		n = 0;
		while (inputnew2[e] == '0' || inputnew2[e] == '1' || inputnew2[e] == '2' || inputnew2[e] == '3' || inputnew2[e] == '4' || inputnew2[e] == '5' || inputnew2[e] == '6' || inputnew2[e] == '7' || inputnew2[e] == '8' || inputnew2[e] == '9' || inputnew2[e] == '.' || inputnew2[e] == '-' || inputnew2[e] == '&')
		{
			if (inputnew2[e] == '&')
				break;
			e += 1;
			n += 1;
		}
		if (!(inputnew2[e] == '0' || inputnew2[e] == '1' || inputnew2[e] == '2' || inputnew2[e] == '3' || inputnew2[e] == '4' || inputnew2[e] == '5' || inputnew2[e] == '6' || inputnew2[e] == '7' || inputnew2[e] == '8' || inputnew2[e] == '9' || inputnew2[e] == '.' || inputnew2[e] == '-' || inputnew2[e] == '&'))
			break;
		s = inputnew2.substr(m + w, n);
		num = atof(s.c_str());
		if (k % 2 == 0)
			X[k / 2] = num;
		else if (k % 2 == 1)
			Y[(k - 1) / 2] = num;

		inputnew2 = inputnew2.replace(m, w, "");
	}

	int v=0,c = 0;
	inp = input;
	inp = inp.replace(0, 9, "");
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			X2[i][j] = X[c];
			Y2[i][j] = Y[c];
			v = inp.find(")");
			c += 1;
			if (inp[v + 1] == ';')
			{
				inp = inp.replace(v, 1, "");
				break;
			}
        	if (inp[v + 1] == ']')
				break;
			inp = inp.replace(v, 1, "");
		}
		if (inp[v + 1] == ']')
			break;
	}

	for (int i = 0; i < Number_Polygons(input); i++)
	{
		vector<float>tempx;
		vector<float>tempy;
		
		for (int j = 0; j < Number_Points_Polygon(input, i); j++)
		{
			tempx.push_back(X2[i][j]);
			tempy.push_back(Y2[i][j]);
		}
		X2new.push_back(tempx);
		Y2new.push_back(tempy);
	}

	

	while (1)
	{
		cin >> operation;
		if (operation == "Number_Polygons")
			cout <<Number_Polygons(input)<<endl ;
		if (operation == "Total_Number_Points")
			cout << Total_Number_Points(input)<<endl;
		if (operation == "Minimum_X")
			cout << Minimum_X(input, X, 10000)<<endl;
		if (operation == "Maximum_X")
			cout << Maximum_X( X, 10000)<<endl;
		if (operation == "Minimum_Y")
			cout << Minimum_X(input, Y, 10000)<<endl;
		if (operation == "Maximum_Y")
			cout << Maximum_Y(Y,10000)<<endl;
		if (operation == "Enclosing_Rectangle")
			Enclosing_Rectangle(input, X, Y, 10000);
		if (operation == "Total_Redundant_Points")
			 Total_Redundant_Points1(input, X2, Y2);
		if (operation == "Quit")
			break;
		if (operation == "Polygon_Points")
			Polygon_Points(input, X2new, Y2new);
		if (operation == "Point_Polygons")
		Point_Polygons(input,X2,Y2);
		if (operation == "List_Polygons_Points")
			List_Polygons_Points(input,X2new,Y2new);
		if (operation == "List_Points_Polygons")
		List_Points_Polygons(input, X2, Y2);
		if (operation == "Polygon_Perimeter")
			Polygon_Perimeter(input, X2new, Y2new);
		if (operation == "List_Triangles")
			List_Triangles(input, X2new, Y2new);
		if (operation == "List_Rectangles")
			List_Rectangles(input, X2new, Y2new);
		if (operation == "List_Trapezoid")
			List_Trapezoid(input, X2new, Y2new);
		if (operation == "Inside_Rectangle")
		Inside_Rectangle(input, X2new, Y2new);
		if (operation == "Inside_Circle")
		Inside_Circle(input, X2new, Y2new);
		if (operation == "Polygon_Area")
			Polygon_Area(input, X2new, Y2new);
		if (operation == "Polygons_Area_Range")
		Polygons_Area_Range(input, X2new, Y2new);
		if (operation == "Polygons_Enclosing_Point")
		Polygons_Enclosing_Point(input, X2new, Y2new);  
		if (operation == "Is_Intersecting")
			Is_Intersecting(input, X2new, Y2new);
		if (operation == "Intersecting_Group")
			Intersecting_Group(input, X2new, Y2new);
		if (operation == "Largest_Intersecting_Pair")
			Largest_Intersecting_Pair(input, X2new, Y2new);
		if (operation == "Is_Connected")
		Is_Connected(input, X2new, Y2new);
		if (operation == "Is_Connected_Group")
		Is_Connected_Group(input, X2new, Y2new);
		if (operation == "Maximum_Intersecting_Group")
		Maximum_Intersecting_Group(input, X2new, Y2new);
		if (operation == "Maximum_Connected_Group")
			Maximum_Connected_Group(input, X2new, Y2new);

	}
	

	return 0;
}
int Number_Polygons(string s)
{
	int n = 0;
	for (unsigned int i = 0; i <= s.length(); i++)
		if (s[i] == ';')
			n = n + 1;
		return n+1;
}
int Total_Number_Points(string s)
{
	int n = 0;
	for (unsigned int i = 0; i <= s.length(); i++)
		if (s[i] == '(')
			n = n + 1;
	return n ;
}
float Minimum_X(string s, float X[], int size)
{
	int i;
	float minx;
	minx = X[0];
	for (i = 0; i < size; i++)
	{
		if (X[i] < minx)
			minx = X[i];
		if (i == Total_Number_Points(s)-1)
			break;
	}
	return minx;
}
float Maximum_X( float X[], int size)
{
	float maxx;
	maxx = X[0];
	for (int i = 0; i < size; i++)
	{
		if (X[i] > maxx)
			maxx = X[i];
	}
	return maxx;
}
float Minimum_Y(string s, float Y[], int size)
{
	int i;
	float miny;
	miny = Y[0];
	for (i = 0; i < size; i++)
	{
		if (Y[i] < miny)
			miny = Y[i];
		if (i == Total_Number_Points(s)-1)
			break;
	}
	return miny;
}
float Maximum_Y(float Y[], int size)
{
	float maxy;
	maxy = Y[0];
	for (int i = 0; i < size; i++)
	{
		if (Y[i] > maxy)
			maxy = Y[i];
	}
	return maxy;
}
void Enclosing_Rectangle(string s, float X[], float Y[], int size)
{
	cout << "(" << Minimum_X(s,X, size) << "," << Minimum_Y(s,Y, size) << ")" << "," <<
		"(" << Minimum_X(s, X, size) << "," << Maximum_Y(Y, size) << ")" << ","
		"(" << Maximum_X(X, size) << "," << Maximum_Y(Y, size) << ")" << ","
		"(" << Maximum_X(X, size) << "," << Minimum_Y(s, Y, size) << ")" << endl;
}
void Total_Redundant_Points1(string s, float X2[][100], float Y2[][100])
{
	vector< vector<float> >X2new;
	vector< vector<float> >Y2new;
	for (int i = 0; i < Number_Polygons(s); i++)
	{
		vector<float>tempx;
		vector<float>tempy;
		for (int j = 0; j < Number_Points_Polygon(s, i); j++)
		{
			tempx.push_back(X2[i][j]);
			tempy.push_back(Y2[i][j]);
		}
		X2new.push_back(tempx);
		Y2new.push_back(tempy);
	}
	cout << Total_Redundant_Points(s, X2new, Y2new) << endl;
}
int Total_Redundant_Points(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red1= 0, red2= 0, red3=0, red4= 0, red5=0, red6=0,red7=0 ,red8=0;
	for (unsigned int i = 0; i < X2new.size(); i++)
		for (unsigned int j = 0; j <X2new[i].size()-1; j++)
			if ((X2new[i][j] == X2new[i][j + 1]) && (Y2new[i][j] == Y2new[i][j + 1]))
			{
				red1 += 1;
				X2new[i].erase(X2new[i].begin() + (j + 1));
				Y2new[i].erase(Y2new[i].begin() + (j + 1));
				j -= 1;	
			}
	for (unsigned int i = 0; i < X2new.size(); i++)
	       if ((X2new[i][0] == X2new[i][X2new[i].size() - 1]) && (Y2new[i][0] == Y2new[i][Y2new[i].size()-1]))
	       {
	            red2 += 1;
	            X2new[i].erase(X2new[i].begin() + (X2new[i].size() - 1));
	            Y2new[i].erase(Y2new[i].begin() + (Y2new[i].size() - 1));
	       }
	for (unsigned int i = 0; i < X2new.size(); i++)
		for (unsigned int j = 0; j <X2new[i].size() - 2; j++)
			if ((X2new[i][j] == X2new[i][j + 1]) && (X2new[i][j] == X2new[i][j + 2]))
			{
				red3 += 1;
				X2new[i].erase(X2new[i].begin() + (j + 1));
				Y2new[i].erase(Y2new[i].begin() + (j + 1));
				j -= 1;
			}
	for (unsigned int i = 0; i < X2new.size(); i++)
		for (unsigned int j = 0; j <X2new[i].size() - 2; j++)	
			if ((Y2new[i][j]-Y2new[i][j+1])/(X2new[i][j]-X2new[i][j+1]) == (Y2new[i][j] - Y2new[i][j + 2]) / (X2new[i][j] - X2new[i][j + 2]))
			{
				red4 += 1;
				X2new[i].erase(X2new[i].begin() + (j + 1));
				Y2new[i].erase(Y2new[i].begin() + (j + 1));
				j -= 1;
			}
	for (unsigned int i = 0; i < X2new.size(); i++)
		if ((X2new[i][X2new[i].size() - 2] == X2new[i][X2new[i].size() - 1]) && (X2new[i][X2new[i].size() - 2] == X2new[i][0]))
		{
			red5 += 1;
			X2new[i].erase(X2new[i].begin() + (X2new[i].size() - 1));
			Y2new[i].erase(Y2new[i].begin() + (Y2new[i].size() - 1));
		}
	for (unsigned int i = 0; i < X2new.size(); i++)
		if ((Y2new[i][X2new[i].size() - 2] - Y2new[i][X2new[i].size() - 1]) / (X2new[i][X2new[i].size() - 2] - X2new[i][X2new[i].size() - 1]) == (Y2new[i][X2new[i].size() - 2] - Y2new[i][0]) / (X2new[i][X2new[i].size() - 2] - X2new[i][0]))
		{
			red6 += 1;
			X2new[i].erase(X2new[i].begin() + (X2new[i].size() - 1));
			Y2new[i].erase(Y2new[i].begin() + (Y2new[i].size() - 1));
		}

	for (unsigned int i = 0; i < X2new.size(); i++)
		if ((X2new[i][X2new[i].size() - 1] == X2new[i][0]) && (X2new[i][X2new[i].size() - 1] == X2new[i][1]))
		{
			red7 += 1;
			X2new[i].erase(X2new[i].begin());
			Y2new[i].erase(Y2new[i].begin());
		}
	for (unsigned int i = 0; i < X2new.size(); i++)
		if ((Y2new[i][X2new[i].size() - 1] - Y2new[i][0]) / (X2new[i][X2new[i].size() - 1] - X2new[i][0]) == (Y2new[i][X2new[i].size() - 1] - Y2new[i][1]) / (X2new[i][X2new[i].size() - 1] - X2new[i][1]))
		{
			red8 += 1;
			X2new[i].erase(X2new[i].begin());
			Y2new[i].erase(Y2new[i].begin());
		}

	return red1+red2+red3+red4+red5+red6+red7+red8;
}
int Number_Points_Polygon(string s,int numberofpolygon)
{
	int i=0, l = 0, number ;
	string str;
	str = s;
	
	while (1)
	{
		number = 0;

		while (1)
		{
			l = str.find(")");
			number += 1;
			if (str[l + 1] == ';' || str[l + 1] == ']')
			{
				str = str.replace(l, 1, "");
				break;
			}
			str = str.replace(l, 1, "");

		}
		if (i == numberofpolygon)
			break;
		i += 1;

	}
		return number;
	
}
void Polygon_Points(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int num;
	cin >> num;
	int red=0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	for (unsigned int j = 0; j < X2new[num-1].size(); j++)
	{
		cout << "(" << X2new[num - 1][j] << "," << Y2new[num - 1][j] << ")";
		if (j != X2new[num - 1].size() - 1)
			cout << ",";
	}
	cout << endl;
}
void Point_Polygons(string s, float X2[][100], float Y2[][100])
{
	vector<int>output;
	string point , strx , stry;
	float x, y;
	int m,z;
	cin >> point;
	m = point.find(",");
	z = point.find(")");
	strx = point.substr(1, m - 1);
	x = atof(strx.c_str());
	stry = point.substr(m+1, z-m-1);
	y = atof(stry.c_str());
	for(int i=0 ; i< Number_Polygons(s); i++)
		for (int j = 0; j < Number_Points_Polygon(s, i); j++)
			if (X2[i][j] == x && Y2[i][j] == y)
			{
				output.push_back(i + 1);
				break;
			}
				for (unsigned int i = 0; i < output.size(); i++)
				{
					cout << output[i];
					if (i != output.size() - 1)
						cout << ",";
				}
				if (output.size() == 0)
					cout << "none";
				cout << endl;
			}
void List_Polygons_Points(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	vector<int>output;
	string inp;
	float num;
	red = Total_Redundant_Points(s, X2new, Y2new);
	cin >> inp;
	cin >> num;
	if (inp == "More")
	{
		for (unsigned int i = 0; i < X2new.size(); i++)
			if (X2new[i].size() > num)
				output.push_back(i + 1);
		for (unsigned int i = 0; i < output.size(); i++)
		{
			cout << output[i];
			if (i != output.size() - 1)
				cout << ",";
		}
		if (output.size() == 0)
			cout << "none";
		cout << endl;
	}
	output.clear();
	 if (inp == "Less")
	 {
		 for (unsigned int i = 0; i < X2new.size(); i++)
			 if (X2new[i].size() < num)
				 output.push_back(i + 1);
		 for (unsigned int i = 0; i < output.size(); i++)
		 {
			 cout << output[i];
			 if (i != output.size() - 1)
				 cout << ",";
		 }
		 if (output.size() == 0)
			 cout << "none";
		 cout << endl;
	 }
	 output.clear();
	 if (inp == "Equal")
	 {
		 for (unsigned int i = 0; i < X2new.size(); i++)
			 if (X2new[i].size() == num)
				 output.push_back(i + 1);
		 for (unsigned int i = 0; i < output.size(); i++)
		 {
			 cout << output[i];
			 if (i != output.size() - 1)
				 cout << ",";
		 }
		 if (output.size() == 0)
			 cout << "none";
		 cout << endl;
	 }
	 output.clear();
}
void List_Points_Polygons(string s, float X2[][100], float Y2[][100])
{
	vector< vector<float> >X2new;
	vector< vector<float> >Y2new;
	for (int i = 0; i < Number_Polygons(s); i++)
	{
		vector<float>tempx;
		vector<float>tempy;
		for (int j = 0; j < Number_Points_Polygon(s, i); j++)
		{
			tempx.push_back(X2[i][j]);
			tempy.push_back(Y2[i][j]);
		}
		X2new.push_back(tempx);
		Y2new.push_back(tempy);
	}
	vector<float>outputx;
	vector<float>outputy;
	int n = 0;
	string inp;
	float num;
	cin >> inp;
	cin >> num;
	if (inp == "More")
	{
		for (unsigned int ip = 0; ip < X2new.size(); ip++)
		{
			for (unsigned int jp = 0; jp < X2new[ip].size(); jp++)
			{
				for (unsigned int i = 0; i < X2new.size(); i++)
				{
					for (unsigned int j = 0; j < X2new[i].size(); j++)
						if (X2new[ip][jp] == X2new[i][j] && Y2new[ip][jp] == Y2new[i][j])
						{
							n++;
							break;
						}
				}
				if (n > num)
				{
					outputx.push_back(X2new[ip][jp]);
					outputy.push_back(Y2new[ip][jp]);
				}
				n = 0;
			}
		}
		if(!(outputx.size()== 0))
		for(unsigned int ip=0; ip<outputx.size();ip++)
		for (unsigned int i = 0; i < outputx.size(); i++)
			if (outputx[ip] == outputx[i] && outputy[ip] == outputy[i] && (i!=ip))
			{
				outputx.erase(outputx.begin() + i );
				outputy.erase(outputy.begin() + i );
			}
		for (unsigned int i = 0; i < outputx.size(); i++)
		{
			cout <<"("<< outputx[i]<<","<<outputy[i]<<")";
			if (i != outputx.size() - 1)
				cout << ",";
		}
		if (outputx.size() == 0)
			cout << "none";
		cout << endl;
	}
	outputx.clear();
	outputy.clear();
	n = 0;	
	if (inp == "Less")
	{
		for (unsigned int ip = 0; ip < X2new.size(); ip++)
		{
			for (unsigned int jp = 0; jp < X2new[ip].size(); jp++)
			{
				for (unsigned int i = 0; i < X2new.size(); i++)
				{
					for (unsigned int j = 0; j < X2new[i].size(); j++)
						if (X2new[ip][jp] == X2new[i][j] && Y2new[ip][jp] == Y2new[i][j])
						{
							n++;
							break;
						}
				}
				if (n < num)
				{
					outputx.push_back(X2new[ip][jp]);
					outputy.push_back(Y2new[ip][jp]);
				}
				n = 0;
			}
		}
		if (!(outputx.size() == 0))
			for (unsigned int ip = 0; ip<outputx.size(); ip++)
			for (unsigned int i = 0; i < outputx.size(); i++)
					if (outputx[ip] == outputx[i] && outputy[ip] == outputy[i] && (i != ip))
			{
				outputx.erase(outputx.begin() + i );
				outputy.erase(outputy.begin() + i );
			}
		for (unsigned int i = 0; i < outputx.size(); i++)
		{
			cout << "(" << outputx[i] << "," << outputy[i] << ")";
			if (i != outputx.size() - 1)
				cout << ",";
		}
		if (outputx.size() == 0)
			cout << "none";
		cout << endl;
	}
	outputx.clear();
	outputy.clear();
	n = 0;
	if (inp == "Equal")
	{
		for (unsigned int ip = 0; ip < X2new.size(); ip++)
		{
			for (unsigned int jp = 0; jp < X2new[ip].size(); jp++)
			{
				for (unsigned int i = 0; i < X2new.size(); i++)
				{
					for (unsigned int j = 0; j < X2new[i].size(); j++)
						if (X2new[ip][jp] == X2new[i][j] && Y2new[ip][jp] == Y2new[i][j])
						{
							n++;
							break;
						}
				}
				if (n == num)
				{
					outputx.push_back(X2new[ip][jp]);
					outputy.push_back(Y2new[ip][jp]);
				}
				n = 0;
			}
		}
		if (!(outputx.size() == 0))
			for (unsigned int ip = 0; ip<outputx.size(); ip++)
				for (unsigned int i = 0; i < outputx.size(); i++)
					if (outputx[ip] == outputx[i] && outputy[ip] == outputy[i] && (i != ip))
			{
				outputx.erase(outputx.begin() + i );
				outputy.erase(outputy.begin() + i );
			}
		for (unsigned int i = 0; i < outputx.size(); i++)
		{
			cout << "(" << outputx[i] << "," << outputy[i] << ")";
			if (i != outputx.size() - 1)
				cout << ",";
		}
		if (outputx.size() == 0)
			cout << "none";
		cout << endl;
	}
}
float length(float x1, float y1, float x2, float y2)
{
	float length;
	length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return length;
} 
void Polygon_Perimeter(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	int num;
	float per=0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	cin >> num;
	for (unsigned int j = 0; j < X2new[num-1].size()-1; j++)
		per += length(X2new[num - 1][j], Y2new[num - 1][j], X2new[num - 1][j+1], Y2new[num - 1][j+1]);
	cout << per + length(X2new[num - 1][X2new[num - 1].size() - 1], Y2new[num - 1][Y2new[num - 1].size() - 1], X2new[num - 1][0], Y2new[num - 1][0])<<endl;
}
void List_Triangles(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	vector<int>output;
	red = Total_Redundant_Points(s, X2new, Y2new);
	for (unsigned int i = 0; i < X2new.size(); i++)
		if (X2new[i].size() == 3)
			output.push_back(i + 1);
			for (unsigned int i = 0; i < output.size(); i++)
			{
				cout << output[i];
				if (i != output.size() - 1)
					cout << ",";
			}
			if (output.size() == 0)
				cout << "none";
			cout << endl;
}
void List_Rectangles(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	vector<int>output;
	red = Total_Redundant_Points(s, X2new, Y2new);
	for (unsigned int i = 0; i < X2new.size(); i++)
		if (X2new[i].size() == 4 && length(X2new[i][0], Y2new[i][0], X2new[i][1], Y2new[i][1]) == length(X2new[i][2], Y2new[i][2], X2new[i][3], Y2new[i][3]) && length(X2new[i][0], Y2new[i][0], X2new[i][3], Y2new[i][3]) == length(X2new[i][1], Y2new[i][1], X2new[i][2], Y2new[i][2]) && length(X2new[i][0], Y2new[i][0], X2new[i][2], Y2new[i][2]) == length(X2new[i][1], Y2new[i][1], X2new[i][3], Y2new[i][3]))
			output.push_back(i + 1);
	for (unsigned int i = 0; i < output.size(); i++)
	{
		cout << output[i];
		if (i != output.size() - 1)
			cout << ",";
	}
	if (output.size() == 0)
		cout << "none";
	cout << endl;
} 
void List_Trapezoid(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	vector<int>output;
	red = Total_Redundant_Points(s, X2new, Y2new);
	for (unsigned int i = 0; i < X2new.size(); i++)
		if (X2new[i].size() == 4 && (((X2new[i][2] == X2new[i][1]) && (X2new[i][0] == X2new[i][3])) && ((Y2new[i][1] - Y2new[i][0]) / (X2new[i][1] - X2new[i][0]) != (Y2new[i][3] - Y2new[i][2]) / (X2new[i][3] - X2new[i][2]))))
			output.push_back(i + 1);
	for (unsigned int i = 0; i < X2new.size(); i++)
		if (X2new[i].size() == 4 && (((Y2new[i][2] - Y2new[i][1]) / (X2new[i][2] - X2new[i][1]) == (Y2new[i][0] - Y2new[i][3]) / (X2new[i][0] - X2new[i][3]) && (Y2new[i][1] - Y2new[i][0]) / (X2new[i][1] - X2new[i][0]) != (Y2new[i][3] - Y2new[i][2]) / (X2new[i][3] - X2new[i][2])  && !(length(X2new[i][0], Y2new[i][0], X2new[i][1], Y2new[i][1]) == length(X2new[i][2], Y2new[i][2], X2new[i][3], Y2new[i][3]) && length(X2new[i][0], Y2new[i][0], X2new[i][3], Y2new[i][3]) == length(X2new[i][1], Y2new[i][1], X2new[i][2], Y2new[i][2]) && length(X2new[i][0], Y2new[i][0], X2new[i][2], Y2new[i][2]) == length(X2new[i][1], Y2new[i][1], X2new[i][3], Y2new[i][3]))  )))
			output.push_back(i + 1);
	for (unsigned int i = 0; i < X2new.size(); i++)
		if (X2new[i].size() == 4 &&(((Y2new[i][1]-Y2new[i][0])/(X2new[i][1]-X2new[i][0]) == (Y2new[i][3] - Y2new[i][2])/(X2new[i][3] - X2new[i][2]) && (Y2new[i][2] - Y2new[i][1]) / (X2new[i][2] - X2new[i][1]) != (Y2new[i][3] - Y2new[i][0]) / (X2new[i][3] - X2new[i][0]))))
			output.push_back(i + 1);
	int temp;
	for (unsigned int i = 0; i<output.size(); i++)
		for (unsigned int j = i + 1; j<output.size(); j++)
		{
			if (output[j] < output[i])
			{
				temp = output[i];
				output.insert(output.begin()+ i, output[j]);
				output.erase(output.begin()+ i+ 1);
				//output[i] = output[j];
				output.insert(output.begin()+ j, temp);
				output.erase(output.begin()+ j+ 1);

				//output[j] = temp;
			}
		}
	for (unsigned int i = 0; i < output.size(); i++)
	{
		cout << output[i];
		if (i != output.size() - 1)
			cout << ",";
	}
	if (output.size() == 0)
		cout << "none";
	cout << endl;
}
void Inside_Rectangle(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	string in,strx,stry;
	vector<int>output;
	double x[3];
	double y[3];
	int m, z;
	cin >> in;
	for (int i = 0; i < 3; i++)
	{	
		m = in.find(",");
		z = in.find(")");
		strx = in.substr(1, m - 1);
		 x[i] = atof(strx.c_str());
		stry = in.substr(m + 1, z - m - 1);
		y[i] = atof(stry.c_str());
		in.replace(0, z + 2, "");
	}
	double temp1,temp2;
	for (int i = 0; i<3; i++)
		for (int j = i + 1; j<3; j++)
		{
			if (x[j] < x[i])
			{
				temp1 = x[i];
				x[i] = x[j];
				x[j] = temp1;
				temp2 = y[i];
				y[i] = y[j];
				y[j] = temp2;
			}
		}
	temp2 = 0;
	if (y[1] < y[2])
	{
		temp2 = y[1];
		y[1] = y[2];
		y[2] = temp2;
	}
	int choice;
	for (unsigned int i = 0; i < X2new.size(); i++)
	{
		for (unsigned int j = 0; j <X2new[i].size() ; j++)
		{
			if (!(X2new[i][j] >= x[0] && X2new[i][j] <= x[1] && Y2new[i][j] <= y[1] && Y2new[i][j] >= y[2]))
			{
				choice = 0;
				break;
			}
			choice = 1;
		}
		if(choice==1)
		output.push_back(i + 1);
	}
	for (unsigned int i = 0; i < output.size(); i++)
	{
		cout << output[i];
		if (i != output.size() - 1)
			cout << ",";
	}
	if (output.size() == 0)
		cout << "none";
	cout << endl;
}
void Inside_Circle(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);

	string cx = s.substr(1, s.find(","));
	float cx = atof(cx.c_str());
	string cy = s.substr(s.find(",") + 1, s.find(")"));
	float cy = atof(cy.c_str());
	string radius = s.substr(s.find(")") + 2);
	float radius = atof(radius.c_str());
	cout << cx << " " << cy << " " << radius;



	/*string in, strx, stry,strr;
	vector<int>output;
	double x, y, r;
	int m, z,choice;
	cin >> in;
		m = in.find(",");
		z = in.find(")");
		strx = in.substr(1, m - 1);
		x = atof(strx.c_str());
		stry = in.substr(m + 1, z - m - 1);
		y = atof(stry.c_str());
		in.replace(0, z + 2, "");
		strr = in.substr(0, in.length());
		r = atof(strr.c_str());
		for (unsigned int i = 0; i < X2new.size(); i++)
		{
			for (unsigned int j = 0; j <X2new[i].size(); j++)
			{
				if (!(length(x,y,X2new[i][j],Y2new[i][j])<=r))
				{
					choice = 0;
					break;
				}
				choice = 1;
			}
			if (choice == 1)
				output.push_back(i + 1);
		}
		for (unsigned int i = 0; i < output.size(); i++)
		{
			cout << output[i];
			if (i != output.size() - 1)
				cout << ",";
		}
		if (output.size() == 0)
			cout << "none";
		cout << endl;*/
}
float Area(string s,int index, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	float area,X=0,Y=0;
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	for (unsigned int j = 0; j < X2new[index - 1].size()-1; j++)
	{
		X += X2new[index - 1][j] * Y2new[index - 1][j + 1];
		Y += Y2new[index - 1][j] * X2new[index - 1][j + 1];
	}
	X+= X2new[index - 1][X2new[index - 1].size()-1] * Y2new[index - 1][0];
	Y += Y2new[index - 1][Y2new[index - 1].size() - 1] * X2new[index - 1][0];
	area = 0.5*fabs(Y-X);
	return area;
}
void Polygon_Area(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int num;
	cin >> num;
	cout << Area(s, num, X2new, Y2new)<<endl;
}
void Polygons_Area_Range(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	string in, strmin, strmax;
	vector<int>output;
	double minarea,maxarea;
	int m;
	cin >> in;
	m = in.find(",");
	strmin = in.substr(0, m);
	minarea = atof(strmin.c_str());
	strmax = in.substr(m + 1,in.length()-m-1);
	maxarea = atof(strmax.c_str());
	for (unsigned int i = 0; i < X2new.size(); i++)
		if (Area(s, i + 1, X2new, Y2new) <= maxarea && Area(s, i + 1, X2new, Y2new) >= minarea)
			output.push_back(i + 1);
	for (unsigned int i = 0; i < output.size(); i++)
	{
		cout << output[i];
		if (i != output.size() - 1)
			cout << ",";
	}
	if (output.size() == 0)
		cout << "none";
	cout << endl;
}
bool Enclosing_Point(float x, float y,int index, string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	float X = 0, Y = 0;
	double area, sum = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	for (unsigned int j = 0; j < X2new[index - 1].size()-1; j++)
	{
		X = x*Y2new[index - 1][j] + X2new[index - 1][j] * Y2new[index - 1][j + 1] + X2new[index - 1][j + 1] * y;
		Y = y*X2new[index - 1][j] + Y2new[index - 1][j] * X2new[index - 1][j + 1] + Y2new[index - 1][j + 1] * x;
		area = 0.5*fabs(Y - X);
		sum += area;
	}
	X = x*Y2new[index - 1][X2new[index - 1].size() - 1] + X2new[index - 1][X2new[index - 1].size() - 1] * Y2new[index - 1][0] + X2new[index - 1][0] * y;
	Y = y*X2new[index - 1][Y2new[index - 1].size() - 1] + Y2new[index - 1][Y2new[index - 1].size() - 1] * X2new[index - 1][0] + Y2new[index - 1][0] * x;
	area = 0.5*fabs(Y - X);
	sum += area;
	if (sum > Area(s, index, X2new, Y2new))
		return 0;
	return 1;
}
void Polygons_Enclosing_Point(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	vector<int>output;
	string point, strx, stry;
	float x, y;
	int m, z;
	cin >> point;
	m = point.find(",");
	z = point.find(")");
	strx = point.substr(1, m - 1);
	x = atof(strx.c_str());
	stry = point.substr(m + 1, z - m - 1);
	y = atof(stry.c_str());
	for (unsigned int i = 0; i < X2new.size(); i++)
		if (Enclosing_Point(x, y, i + 1, s, X2new, Y2new) == 1)
			output.push_back(i + 1);
	for (unsigned int i = 0; i < output.size(); i++)
	{
		cout << output[i];
		if (i != output.size() - 1)
			cout << ",";
	}
	if (output.size() == 0)
		cout << "none";
	cout << endl;
}
bool Intersecting(int index1, int index2, string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	int choice;
	for (unsigned int j = 0; j < X2new[index2-1].size(); j++)
	{
		if (Enclosing_Point(X2new[index2 - 1][j], Y2new[index2 - 1][j], index1, s, X2new, Y2new))
		{
			choice = 1;
			break;
		}
		choice = 0;
	}
	if (choice == 1)
		return 1;
	return 0;
}
void Is_Intersecting(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	string in, str1, str2;
	int index1, index2;
	int m;
	cin >> in;
	m = in.find(",");
	str1 = in.substr(0, m);
	index1 = atof(str1.c_str());
	str2 = in.substr(m + 1, in.length() - m - 1);
	index2 = atof(str2.c_str());
	if (Intersecting(index1, index2, s, X2new, Y2new))
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
}
void Intersecting_Group(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	string in, str,str2;
	vector<int>index;
	int m,z;
	cin >> in;
	while (1)
	{
		m = in.find(",");
		if (m == -1)
		{
			str = in.substr(0,in.size());
			index.push_back(atof(str.c_str()));
			break;
		}
		z = in.find(",", m + 1);
		str = in.substr(0, m);
		index.push_back(atof(str.c_str()));
		if (!(z == -1))
		{
			str2 = in.substr(m + 1, z - m - 1);
			index.push_back(atof(str2.c_str()));
			in.replace(0, z + 1, "");
		}
		else 
			in.replace(0, m + 1, "");
	}
	int choice = 0;
	for (unsigned int ip = 0; ip < index.size(); ip++)
	{
		for (unsigned int i = 0; i < index.size(); i++)
		{
			if (Intersecting(index[ip], index[i], s, X2new, Y2new))
				choice = 1;
			else
			{
				choice = 0;
				break;
			}
		}
		if (choice == 0)
			break;
	}
	if (choice == 1)
		cout << "TRUE" << endl;
	else
	    cout << "FALSE" << endl;
}
void Largest_Intersecting_Pair(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	float sum = 0;
	int n=0, m=1;
	red = Total_Redundant_Points(s, X2new, Y2new);
	sum = Area(s, n+1, X2new, Y2new) + Area(s, m+1, X2new, Y2new);
	for (unsigned int i = 0; i < X2new.size(); i++)
		for (unsigned int j = i+1; j < X2new.size();j++)
			if (Intersecting(i + 1, j + 1, s, X2new, Y2new) && Area(s, i + 1, X2new, Y2new) + Area(s, j + 1, X2new, Y2new) > sum)
			{
				sum = Area(s, i + 1, X2new, Y2new) + Area(s, j + 1, X2new, Y2new);
				n = i + 1;
				m = j + 1;
			}
	cout << n << "," << m << endl;
}
bool Connected(int index1, int index2, string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new); 
	int choice=0;
	if (Intersecting(index1, index2, s, X2new, Y2new))
		choice = 1;
	for (unsigned int i = 0; i < X2new.size(); i++)
		if (Intersecting(index1, i + 1, s, X2new, Y2new) && Intersecting(index2, i + 1, s, X2new, Y2new))
			choice = 1;
	if (choice == 1)
		return 1;
	return 0;
}
void Is_Connected(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	string in, str1, str2;
	int index1, index2;
	int m;
	cin >> in;
	m = in.find(",");
	str1 = in.substr(0, m);
	index1 = atof(str1.c_str());
	str2 = in.substr(m + 1, in.length() - m - 1);
	index2 = atof(str2.c_str());
	if (Connected(index1, index2, s, X2new, Y2new))
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
}
void Is_Connected_Group(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	string in, str, str2;
	vector<int>index;
	int m, z;
	cin >> in;
	while (1)
	{
		m = in.find(",");
		if (m == -1)
		{
			str = in.substr(0, in.size());
			index.push_back(atof(str.c_str()));
			break;
		}
		z = in.find(",", m + 1);
		str = in.substr(0, m);
		index.push_back(atof(str.c_str()));
		if (!(z == -1))
		{
			str2 = in.substr(m + 1, z - m - 1);
			index.push_back(atof(str2.c_str()));
			in.replace(0, z + 1, "");
		}
		else
			in.replace(0, m + 1, "");
	}
	int choice = 0;
	for (unsigned int ip = 0; ip < index.size(); ip++)
	{
		for (unsigned int i = 0; i < index.size(); i++)
		{
			if (Connected(index[ip], index[i], s, X2new, Y2new))
				choice = 1;
			else
			{
				choice = 0;
				break;
			}
		}
		if (choice == 0)
			break;
	}
	if (choice == 1)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
}
void Maximum_Intersecting_Group(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	vector<int>output;
	vector<int>temp;
	unsigned int max = 0;
	for (unsigned int ip = 0; ip < X2new.size(); ip++)
	{
		for (unsigned int i = 0; i < X2new.size(); i++)
		{
			if (Intersecting(ip + 1, i + 1, s, X2new, Y2new))
				temp.push_back(i + 1);
		}
		for (unsigned int ip2 = 0; ip2 < temp.size(); ip2++)
		{
			for (unsigned int i2 = 0; i2 < temp.size(); i2++)
				if (!(Intersecting(temp[ip2], temp[i2], s, X2new, Y2new)))
					temp.erase(temp.begin() + i2);
		}
		if (temp.size() > max)
		{
			output.clear();
			max = temp.size();
			for (unsigned int j = 0; j < temp.size(); j++)
				output.push_back(temp[j]);
		}
		temp.clear();
	}
	for (unsigned int i = 0; i < output.size(); i++)
	{
		cout << output[i];
		if (i != output.size() - 1)
			cout << ",";
	}
	if (output.size() == 0)
		cout << "none";
	cout << endl;
}
void Maximum_Connected_Group(string s, vector<vector<float>>&X2new, vector<vector<float>>&Y2new)
{
	int red = 0;
	red = Total_Redundant_Points(s, X2new, Y2new);
	vector<int>output;
	vector<int>temp;
	unsigned int max = 0;
	for (unsigned int ip = 0; ip < X2new.size(); ip++)
	{
		for (unsigned int i = 0; i < X2new.size(); i++)
		{
			if (Connected(ip + 1, i + 1, s, X2new, Y2new))
				temp.push_back(i + 1);
		}
		for (unsigned int ip2 = 0; ip2 < temp.size(); ip2++)
		{
			for (unsigned int i2 = 0; i2 < temp.size(); i2++)
				if (!(Connected(temp[ip2], temp[i2], s, X2new, Y2new)))
					temp.erase(temp.begin() + i2);
		}
		if (temp.size() > max)
		{
			output.clear();
			max = temp.size();
			for (unsigned int j = 0; j < temp.size(); j++)
				output.push_back(temp[j]);
		}
		temp.clear();
	}
	for (unsigned int i = 0; i < output.size(); i++)
	{
		cout << output[i];
		if (i != output.size() - 1)
			cout << ",";
	}
	if (output.size() == 0)
		cout << "none";
	cout << endl;
} 


























