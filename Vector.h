#ifndef VECTOR_H
#define VECTOR_H
#include<list>
#include<iostream>
using std::list;
using std::ostream;

class Vector{
private:
	int size;
	double* data_;
public:
	Vector(int taille);
	/*析构函数自动调用*/
	~Vector();
	/*拷贝构造函数*/
	Vector(const Vector& v);
	int get_size() const;
	double& operator[] (int i) const;
	double& operator[] (int i);
	Vector& operator= (const Vector& v);
	double norm(int p);
};
ostream& operator<< (ostream& os, const Vector& v1);
Vector operator+ (Vector& v1, Vector& v2);
Vector operator- (Vector& v1, Vector& v2);
double operator* (Vector& v1, Vector& v2);
Vector operator* (Vector& v1, int n);
Vector operator/ (Vector& v1, int v2);
#endif
