#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "Shape.hpp"


#include <regex>

using namespace std;

bool restart(bool& exit_event) //Function for restarting prog
{
	bool answer = false;
	while (!answer)
	{
		cout << "Do you want to repaint shapes?(Y/N)";
		char exit_prove = ' ';
		cin >> exit_prove;
		switch (exit_prove)
		{
			case 'Y':
			{
				answer = true;
				return exit_event;
			}
			case 'N':
			{
				system("cls");
				exit_event = true;
				return exit_event;
			}
		}

	}
	return exit_event;
}
void painting(string& type, int& count, int& height, int& length, int& output_type, bool& exit_event, int& radius) //Function for calling right version of drawing type
{
	DrawShape temp_shape(type, count, height, length, radius);
	if (output_type == 1)
		temp_shape.DrawStars();
	else if (output_type == 2)
		temp_shape.Draw();
	restart(exit_event);
}
void settings() //Function for getting parametres of the shape
{

	bool exit_event = false;
	while (!exit_event) {
		system("cls");
		string type = "";
		int count = 0, length = 0, height = 0, radius = 0, output_type = 0;
		bool check_answer = false;
		string str_temp;
		cmatch result;
		regex regular("([\\d])+");
		while (!check_answer)
		{
			cout << "Please enter shape type (circle, triangle, rectangle, square): ";
			cin >> type;
			if (type == "circle" || type == "triangle" || type == "rectangle" || type == "square")
				check_answer = true;
			else
				cout << "Enter correct shape!" << endl;
		}
		check_answer = false;
		while (!check_answer)
		{
			cout << "Please enter number of shapes (1-9): ";
			cin >> str_temp;
			if (regex_search(str_temp.c_str(), result, regular))
			{
				for (cmatch::size_type i = 0; i < result.size(); i++)
					count = stoi(result[i]);
				if (count > 0 && count < 10)
					check_answer = true;
			}
			str_temp = "";
		}
		check_answer = false;
		if (type == "circle")
		{
			while (!check_answer)
			{
				cout << "Please enter enter the radius of the circle (1-9): ";
				cin >> str_temp;
				if (regex_search(str_temp.c_str(), result, regular))
				{
					for (cmatch::size_type i = 0; i < result.size(); i++)
						radius = stoi(result[i]);
					if (radius > 0 && radius < 10)
						check_answer = true;
				}
				str_temp = "";
			}
		}
		else if (type == "triangle")
		{
			while (!check_answer)
			{
				cout << "Please enter height of the triangle(1-9): ";
				cin >> str_temp;
				if (regex_search(str_temp.c_str(), result, regular))
				{
					for (cmatch::size_type i = 0; i < result.size(); i++)
						height = stoi(result[i]);
					if (height > 0)
						check_answer = true;
				}
				str_temp = "";
			}
			check_answer = false;
			while (!check_answer)
			{
				cout << "Please enter length of the triangle(1-9): ";
				cin >> str_temp;
				if (regex_search(str_temp.c_str(), result, regular))
				{
					for (cmatch::size_type i = 0; i < result.size(); i++)
						length = stoi(result[i]);
					if (length > 0)
						check_answer = true;
				}
				str_temp = "";
			}
		}
		else if (type == "rectangle")
		{
			while (!check_answer)
			{
				cout << "Please enter height of the rectangle(1-9): ";
				cin >> str_temp;
				if (regex_search(str_temp.c_str(), result, regular))
				{
					for (cmatch::size_type i = 0; i < result.size(); i++)
						height = stoi(result[i]);
					if (height > 0)
						check_answer = true;
				}
				str_temp = "";
			}
			check_answer = false;
			while (!check_answer)
			{
				cout << "Please enter length of the rectangle(1-9): ";
				cin >> str_temp;
				if (regex_search(str_temp.c_str(), result, regular))
				{
					for (cmatch::size_type i = 0; i < result.size(); i++)
						length = stoi(result[i]);
					if (length > 0)
						check_answer = true;
				}
				str_temp = "";
			}
		}
		else if (type == "square")
		{
			while (!check_answer)
			{
				cout << "Please enter height of the square(1-9): ";
				cin >> str_temp;
				if (regex_search(str_temp.c_str(), result, regular))
				{
					for (cmatch::size_type i = 0; i < result.size(); i++)
						height = stoi(result[i]);
					if (height > 0)
						check_answer = true;
				}
				str_temp = "";
			}
		}

		check_answer = false;
		while (!check_answer)
		{
			cout << "Do you want to print in \"*\" or Win API?(1/2): ";
			cin >> str_temp;
			if (regex_search(str_temp.c_str(), result, regular))
			{
				for (cmatch::size_type i = 0; i < result.size(); i++)
					output_type = stoi(result[i]);
				if (output_type > 0)
					if(output_type == 1 || output_type == 2)
						check_answer = true;
			}
			str_temp = "";
		}
		
		painting(type, count, height, length, output_type, exit_event, radius);
	}

}


int main() //Main function with the console setup
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(hStdout, CONSOLE_FULLSCREEN_MODE, 0);
	settings();
	return 0;
}

