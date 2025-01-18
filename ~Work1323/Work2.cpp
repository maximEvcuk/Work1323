#include <iostream>
#include <vector>
#include <string>

class Shape {
public:
	virtual void Show() const = 0;
	virtual std::string Save() const = 0;
	virtual void Load(const std::string &data) = 0;
	virtual ~Shape() {}
};

class Square : public Shape {
private:
	int x, y;
	int side;
public:
	Square(int x, int y, int side) : x(x), y(y), side(side) {}

	void Show() const override {
		std::cout << "Square: Top-left(" << x << ", " << y << "), Side length: " << side << std::endl;
	}

	std::string Save() const override {
		return "Square " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(side);
	}

   void Load(const std::string& data) override {
	   sscanf(data.c_str(), "Square %d %d %d ", &x, &y, &side);
   }
};

class Rectangle : Shape {
private:
	int x, y;
	int width, height;
public:
		Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height){}

		void Show() const override {
			std::cout << "Rectangle: Top-left(" << x << ", " << y << "), Width: " << width << ", Height: " << height << std::endl;
		}

		std::string Save() const override {
			return "Rectangle" + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(width) + " " + std::to_string(height);
		}

		void Load( const std::string &data) override {
			sscanf(data.c_str(), "Rectangle %d %d %d %d ", &x, &y, &width, &height);
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

	std::string Save() const override {
		 return "Circle " + std::to_string(centerX) +" " + std::to_string(centerY) + " " + std::to_string(radius);
	}

	void Load(const std::string& data) override {
		sscanf(data.c_str(), "Circle %d %d %d  ", &centerX, &centerY, &radius);

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

	std::string Save() const override {
		return "Ellipse " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(width), std::to_string(height);
	}

		void Load(const std::string & data) override {
			sscanf(data.c_str(), "Ellipse %d %d %d %d ", &x, &y, &width, &height);

		}
};

int main() {
	std::vector<Shape*> shapes;

	shapes.push_back(new Square(10, 10, 5));
	shapes.push_back(new Rectangle(20, 20, 10, 5));
	shapes.push_back(new Circle(30, 30, 7));
	shapes.push_back(new Ellipse(40, 40, 8, 5));

	std::vector<std::string> savedShapes;
	for (const auto& shape : shapes) {
		savedShapes.push_back(shape->Save());
	}

	std::vector<Shape*> loadedShapes;
	for (const auto& shapeData : savedShapes) {
		if (shapeData.find("Square") == 0) {
			Square* square = new Square(0, 0, 0);
			square->Load(shapeData);
			loadedShapes.push_back(square);
		}
		else if (shapeData.find("Rectangle") == 0) {
			Rectangle* rectangle = new Rectangle(0, 0, 0, 0);
			rectangle->Load(shapeData);
			loadedShapes.push_back(rectangle);
		}
		else if (shapeData.find("Circle") == 0) {
			Circle* circle = new Circle(0, 0, 0);
			circle->Load(shapeData);
			loadedShapes.push_back(circle);
		}
		else if (shapeData.find("Ellipse") == 0) {
			Ellipse* ellipse = new Ellipse(0, 0, 0, 0);
			ellipse->Load(shapeData);
			loadedShapes.push_back(ellipse);
		}
	}

	for (const auto& shape : loadedShapes) {
		shape->Show();
		delete shape;
	}

	for (const auto& shape : shapes) {
		delete shape;
	}

	return 0;
}

	


