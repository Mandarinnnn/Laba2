#include <iostream>

using namespace std;




class Point{

public:
	int x;
	int y;
	Point(){
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		printf("Point(int x, int y)\n");
		this->x = x;
		this->y = y;
	}
	Point(const Point& p) {
		printf("Point(const Point& p))\n");
		x = p.x;
		y = p.y;
	}
	~Point() {
		printf("%d, %d\n", x, y);
		printf("~Point()\n");
	}
};




int main()
{
	{//статическое создание
		Point p1;
		Point p2(5, 10);
		Point p3(p2);
	}

	Point* p1=new Point();
	Point* p2=new Point(5, 10);
	Point* p3=new Point(*p2);

	delete p1;
	delete p2;
	delete p3;





}