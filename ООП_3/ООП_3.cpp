#include <iostream>
#include <list>
#include <vector>
#include <ctime>

using namespace std;

class CShape {
public:
	CShape() {

	}
	virtual ~CShape() {
		printf("Destructor CShape\n");
	}
};

class CTriangle : public CShape {
public:
	CTriangle() {
		printf("Constructor CTriangle\n");
	}
	~CTriangle() {
		printf("Destructor CTriangle\n");
	}
};

class CPoint : public CShape {
public:
	CPoint() {
		printf("Constructor CPoint\n");
	}
	~CPoint() {
		printf("Destructor CPoint\n");
	}
};

class Storage : public CShape {
private:
	CShape** vectorShape;
	int _size;
	int _k;
public:

	Storage(int size) {
		vectorShape = new CShape * [size];
		for (int i = 0; i < size; i++) {
			vectorShape[i] = NULL;
		}
		_size = size;
		_k = 0;
	}

	void resize(int size) {
		if (size > _size) {
			CShape** vectorShape1 = new CShape * [size];
			for (int i = 0; i < _size; i++) {
				vectorShape1[i] = vectorShape[i];
			}
			for (int i = _size; i < size; i++) {
				vectorShape1[i] = NULL;
			}
			_size = size;
			delete[] vectorShape;
			vectorShape = vectorShape1;
		}
	}

	void delCShape(int i) {
		if ((i < _size)) {
			if (vectorShape[i] != NULL) {
				_k--;
			}
			vectorShape[i] = NULL;
		}
		printf("delCShape\n");
	}

	void setCShape(int i, CShape* shape) {
		if (i < _size)
		{
			if (vectorShape[i] == NULL)
			{
				_k++;
			}
			vectorShape[i] = shape;
		}
		printf("setCShape\n");
	}

	CShape* getCShape(int i) {
		if ((i < _size)) {
			return vectorShape[i];
		}
		else {
			return NULL;
		}
		printf("getCShape\n");
	}

	int size() {
		return _size;
	}

	int getEn() {
		return _k;
	}

	~Storage() {

		delete[] vectorShape;
	}
};

int main() {

	srand(time(0));

	Storage myarray(10);
	for (int i = 0; i < 100; i++) {
		printf("%d\n", i);
		int randShape = rand() % 2;

		CShape* p;

		if (randShape)
			p = new CPoint();
		else
			p = new CTriangle();

		int randVoid = rand() % 2;
		if (randVoid == 0) 
			myarray.setCShape(i, p);
		else
			myarray.delCShape(i);
	}
}