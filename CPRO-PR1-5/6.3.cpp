#include <stdio.h>
#include <math.h>


struct polygonStruct {
	//polygon structure
	int polPoint1x;
	int polPoint1y;
	int polPoint2x;
	int polPoint2y;
	int polPoint3x;
	int polPoint3y;
	int polPoint4x;
	int polPoint4y;
	int polPoint5x;
	int polPoint5y;
};

double polygonCircumference(struct polygonStruct polygon) {
	//polygon area function
	double length = 0;
	
	length = double(sqrt(pow((polygon.polPoint1x - polygon.polPoint2x), 2)		//x1-x2
					   + pow((polygon.polPoint1y - polygon.polPoint2y), 2))		//y1-y2
				  + sqrt(pow((polygon.polPoint2x - polygon.polPoint3x), 2)		//x2-x3
					   + pow((polygon.polPoint2y - polygon.polPoint3y), 2))		//y2-y3
				  + sqrt(pow((polygon.polPoint3x - polygon.polPoint4x), 2)		//x3-x4
					   + pow((polygon.polPoint3y - polygon.polPoint4y), 2))		//y3-y4
				  + sqrt(pow((polygon.polPoint4x - polygon.polPoint5x), 2)		//x4-x5
					   + pow((polygon.polPoint4y - polygon.polPoint5y), 2))		//y4-y5
				  + sqrt(pow((polygon.polPoint5x - polygon.polPoint1x), 2)		//x5-x1
					   + pow((polygon.polPoint5y - polygon.polPoint1y), 2)));	//y5-y1

	return length;
}

int main(void) {
	//polygon
	struct polygonStruct polygon;

	printf("Enter the 5 points of the polygon: \n");
	scanf_s("%d %d\n %d %d\n %d %d\n %d %d\n %d %d",
			&polygon.polPoint1x,
			&polygon.polPoint1y,
			&polygon.polPoint2x,
			&polygon.polPoint2y,
			&polygon.polPoint3x,
			&polygon.polPoint3y,
			&polygon.polPoint4x,
			&polygon.polPoint4y,
			&polygon.polPoint5x,
			&polygon.polPoint5y);

	printf("The circumference of the polygon is: %lf", polygonCircumference(polygon));

	

}
