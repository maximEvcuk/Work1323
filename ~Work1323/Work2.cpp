#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Shape {
public:
	virtual void Show() const = 0;
	virtual void Save(std::ofstream &out) const = 0;
	virtual void Load(std::ifstream &in) = 0;
	virtual ~Shape() {}
};

class Square : public Shape {
private:
	int x, y;
	int side;
public:
	Square(int x, int y, int side) : x(x), y(y), side(side) {}

	void Show() const override {
		std::cout << "Square: Top-left(" << x << ", " << y << "), Side lenght: " << side << std::endl;
	}

	void Save(std::ofstream &out) const override {
		out << "Square " << x << " " << y << " " << side << std::endl;
	}

void Load(std::ifstream &in) override {
	in  >> x >>  y >>  side;
   }
};


