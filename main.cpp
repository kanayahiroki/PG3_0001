#include <iostream>
#include<windows.h>

template<typename Type>
Type Min(Type a, Type b) {
	if(a<b)
	{
	return static_cast<Type>(a);
	}
	else
	{
		return static_cast<Type>(b);
	}
}

int main() {
	
	printf("%d\n", Min<int>(3, 8));

	printf("%f\n", Min<float>(8.9f, 9.9f));
	printf("%f\n", Min<double>(3.141592, 4.2526037));


	return 0;
}