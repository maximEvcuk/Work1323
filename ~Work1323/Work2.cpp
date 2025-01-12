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

class Rectangle : Shape {
private:
	int x, y;
	int width, height;
public:
		Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height){}

		void Show() const override {
			std::cout << "Rectangle: Top-left(" << x << ", " << y << "), Width: " << width << ", Height: "<< height << std::endl;
		}

		void Save(std::ofstream &out) const override {
			out << "Rectangle " << x << " " << y << " " << width << " " << height << std::endl;
		}

		void Load(std::ifstream &in) override {
			in >> x >> y >> width >> height;
		}
};

class Circle : public Shape {
private:
	int centerX, centerY;
	int radius;
public:
	Circle(int centerX, int centerY, int radius) : centerX(centerX), centerY(centerY), radius(radius) {}
	
	void Show() const override {
		std::cout << "Circle: Center (" << centerX << ", " << centerY << "), Radius: " << radius <<  std::endl;
	}

	void Save(std::ofstream &out) const override {
		out << "Circle " << centerX << " " << centerY << " " << radius << std::endl;
	}

	void Load(std::ifstream &in) override {
		in >> centerX >> centerY >> radius;
	}

};

class Ellipse : Shape {
private:
	int x, y;
	int width, height;
public:
 Ellipse(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        std::cout << "Ellipse: Top-left (" << x << ", " << y << "), Width: " << width << ", Height: " << height << std::endl;
    }

    void Save(std::ofstream &out) const override {
        out << "Ellipse " << x << " " << y << " " << width << " " << height << std::endl;
    }

    void Load(std::ifstream &in) override {
        in >> x >> y >> width >> height;
    }
};

int main() {

	std::vector<Shape*> shapes;

	shapes.push_back(new Square(10, 10, 5));
	shapes.push_back(new Rectangle(20, 20, 10, 5));
	shapes.push_back(new Circle(30, 30, 7));
	shapes.push_back(new Ellipse(40, 40, 8, 5));

	std::ofstream outFile("shapes.txt");
	for (const auto& shape : shapes) {
		shape->Save(outFile);
	}
	outFile.close();

	std::vector<Shape*> loadedShapes;
	std::ifstream inFile("shapes.txt");
	std::string shapeType;

	while (inFile >> shapeType) {
		if (shapeType == "Square") {
			Square* square = new Square(0, 0, 0);
			square->Load(inFile);
			loadedShapes.push_back(square);
		}
		else if (shapeType == "Rectangle") {
			Rectangle*
				rectangle = new Rectangle(0, 0, 0, 0);
			rectangle->Load(inFile);
			loadedShapes.push_back(rectangle);
		}
		else if (shapeType == "Circle") {
			Circle* circle = new Circle(0, 0, 0);
			circle->Load(inFile);
			loadedShapes.push_back(circle);
		}
		else if (shapeType == "Ellipse") {
			Ellipse* ellipse = new Ellipse(0, 0, 0, 0);
			ellipse->Load(inFile);
			loadedShapes.push_back(ellipse);
		}
	}
	inFile.close();

	for (const auto& shape : loadedShapes) {
		shape->Show();
		delete shape;
	}

	for (const auto& shape : shapes) {
		delete shape;
	}

	return 0;
}

