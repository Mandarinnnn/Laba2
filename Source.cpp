#include <iostream>

using namespace std;




class Point{

protected:
	int x;
	int y;
public:
	Point(){//конструктор по умолчанию
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y) {//конструктор с параметрами
		printf("Point(int x, int y)\n");
		this->x = x;
		this->y = y;
	}
	Point(const Point& p) {//копирующий конструктор
		printf("Point(const Point& p))\n");
		x = p.x;
		y = p.y;
	}
	virtual~Point() {//деструктор
		printf("%d, %d\n", x, y);
		printf("~Point()\n");
	}
	void move(int _x, int _y) {
		x = x + _x;
		y = y + _x;
	}
	void reset();
};

void Point::reset() {//реализация метода сразу после определения 
	x = 0;
	y = 0;
}


class Point3D : public Point {//класс наследник 

protected:
	int z;
public:
	Point3D() :Point(){//конструктор по умолчанию
		printf("Point3D()\n");
		z = 0;
	}
	Point3D(int x, int y, int z) : Point(x, y){//конструктор с параметрами
		printf("Point3D(int x, int y, int z)\n");
		this->z = z;
	}
	Point3D(const Point3D& p) {//копирующий конструктор
		printf("Point3D(const Point& p))\n");
		x = p.x;
		y = p.y;
		z = p.z;
	}
	~Point3D() {//деструктор
		printf("%d, %d, %d\n", x, y, z);
		printf("~Point3D()\n");
	}
	void changeZ(int z) {
		this->z = z;
	}
};

class Triangle {

protected://композиция
	Point* p1;
	Point* p2;
	Point* p3;
public:
	Triangle(){//конструктор по умолчанию
		printf("Triangle()\n");
		p1 = new Point();
		p2 = new Point();
		p3 = new Point();
	}
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3){//конструктор с параметрами
		printf("Triangle(int x1, int y1, int x2, int y2, int x3, int y3)\n");
		p1 = new Point(x1, y1);
		p2 = new Point(x2, y2);
		p3 = new Point(x3, y3);
	}
	Triangle(const Triangle& t) {//копирующий конструктор
		printf("Triangle(const Triangle& p))\n");
		p1 = new Point(*t.p1);
		p2 = new Point(*t.p2);
		p3 = new Point(*t.p3);
	}
	~Triangle() {//деструктор
		delete p1;
		delete p2;
		delete p3;
		printf("~Triangle()\n");
	}
};

int main()
{
	{//статическое создание
		Point p1;
		Point p2(5, 10);
		Point p3(p2);
	}

	printf("\n");
	Point* p4=new Point();// динамическое создание 
	Point* p5=new Point(5, 10);
	Point* p6=new Point(*p5);
	
	delete p4;// уничтожение динамически созданных объектов
	delete p5;
	delete p6;

	printf("\n");
	Point* p7 = new Point(10, 12);
	p7->reset();
	p7->move(5, 5);
	delete p7;

	printf("\n");
	Point3D* p8 = new Point3D(1,2,3);
	delete p8;

	printf("\n");
	Point* p9 = new Point3D(1, 2, 3);
	Point3D* p10 = new Point3D(1, 2, 3);
	printf("\n");
	delete p9;
	printf("\n");
	delete p10;

	printf("\n");
	Triangle* t1 = new Triangle;
	Triangle* t2 = new Triangle(*t1);

	delete t1;
	delete t2;
	printf("Hello, World!");

}