#pragma once

#include "IShape.h"

class Circle : public Shapes {
public:
	void Size()override;
	void Draw()override;
private:
	float answer = 0;

};