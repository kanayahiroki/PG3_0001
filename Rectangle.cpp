#include "Rectangle.h"

void Square::Size() {
	answer = wide* height;
}

void Square::Draw() {
	printf("短形の面積：%d\n", answer);
}
