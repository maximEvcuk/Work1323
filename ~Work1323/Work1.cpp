#include <iostream>
#include <cmath>

class Equation {
public:

	virtual void findRoots() = 0;
	virtual ~Equation() {}

};

class LinearEquation : public Equation {
private:
	double a, b;

public:
	LinearEquation(double a, double b) : a(a), b(b) {}

	void findRoots() override {
		if (a == 0){
			if (b == 0)
				std::cout << "The equation has infinite solutions." << std::endl;
			else
				std::cout << "The equation has no solutions." << std::endl;
		}
		else {
			double root = -b / a;
			std::cout << "Root of the linear equation: " << std::endl;
		}
	}
};

class QuadraticEquation : public Equation {
private:
	double a, b, c;

public:
	QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

	void findRoots() override {
		if (a == 0){
			LinearEquation le(b, c);
			le.findRoots();
			return;
		}
		double discriminant = b * b - 4 * a * c;
		if (discriminant > 0){
			double root1 = (-b + sqrt(discriminant)) / (2 * a);
			double root2 = (-b - sqrt(discriminant)) / (2 * a);
			std::cout << "Roots of the quadratic equation: " << root1 << " and " << root2 << std::endl;
		}
		else if (discriminant == 0) {
			double root = -b / (2 * a);
			std::cout << "There is one root of the quadratic equation: " << root << std::endl;
		}
		else {
			std::cout << "The roots of the quadratic equation are complex." << std::endl;
		}
	}
};

int main() {
	Equation* eq1 = new LinearEquation(2, -4);
	eq1->findRoots();
	delete eq1;

	Equation* eq2 = new QuadraticEquation(1, -3, 2);
	eq2->findRoots();
	delete eq2;


	return 0;
}

