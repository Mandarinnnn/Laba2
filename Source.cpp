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
		printf("метод move() \n");
		x = x + _x;
		y = y + _x;
	}
	virtual void ShowName() {
		printf("Point\n");
	}
	void reset();
};

void Point::reset() {//реализация метода сразу после определения 
	printf("метод reset() \n");
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
	void ShowName() {
		printf("Point3D\n");
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
	setlocale(LC_ALL, "ru");

	printf("Статическое создание:\n");
	{
		Point p1;
		Point p2(5, 10);
		Point p3(p2);
		printf("\nУничтожение статически созданных объектов:\n");
	}

	printf("\nДинамическое создание:\n");
	Point* p4=new Point();
	Point* p5=new Point(5, 10);
	Point* p6=new Point(*p5);

	printf("\nУничтожение динамически созданных объектов:\n");
	delete p4;
	delete p5;
	delete p6;


	printf("\n");
	Point* p7 = new Point(10, 12);
	printf("Вызов методов: \n");
	p7->reset();
	p7->move(5, 5);
	printf("Уничтожение объекта:\n");
	delete p7;

	printf("\nпомещение объекта наследника в переменную-указатель того же типа:\n");
	Point3D* p8 = new Point3D(1,2,3);
	printf("\nУничтожение объекта:\n");
	delete p8;

	printf("\nпомещение объекта наследника в переменную-указатель родителя:\n");
	Point* p9 = new Point3D(1, 2, 3);
	printf("\nУничтожение объекта:\n");
	delete p9;

	printf("\nкомпозиция:\n");
	Triangle* t1 = new Triangle;
	Triangle* t2 = new Triangle(*t1);

	printf("\nУничтожение объекта:\n");
	delete t1;
	delete t2;
}