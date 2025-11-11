#pragma once
#include "IShape.h"

class Square : public Shapes {
public:
	void Size()override;
	void Draw()override;
private:
	int answer = 0;
};
