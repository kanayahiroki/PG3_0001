#include <stdio.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main(void) {

	Shapes* shape[2];

	shape[0] = new Circle();
	shape[1] = new Square();

	printf("円の半径:4\n短形の底辺:2\n短形の高さ:3\n");

	//面積を計算
	for (int i = 0; i < 2; i++)
		shape[i]->Size();

	printf("\n");

	//面積を画面に表示
	for (int i = 0; i < 2; i++)
		shape[i]->Draw();

	//動的確保したメモリを解放
	for (int i = 0; i < 2; i++)
		delete shape[i];

	return 0;
}
