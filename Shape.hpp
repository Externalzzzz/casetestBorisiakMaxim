#pragma once
#include <iostream>
//Main Shape class
class DrawShape {
public:
	DrawShape();
private:
	std::string shape_type;
	int shape_count;
	int shape_height;
	int shape_length;
	int shape_radius;
public: 
	DrawShape(const std::string, const int, const int, const int, const int);
	~DrawShape();
	std::string get_shape() const;
	int get_count() const;
	int get_height() const;
	int get_length() const;
	int get_radius() const;
	void set_count(int varcount);
	void set_height(int varheight);
	void set_length(int varlength);
	void set_shape(std::string varshape);
	void set_radius(int varradius);
	void Draw();
	void DrawStars();
	void Info();

};