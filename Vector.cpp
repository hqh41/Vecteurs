#include "Vector.h"
#include <math.h>
#include <assert.h>
#include <iostream>
using namespace std;

Vector::Vector(int taille){
	size = taille;
	data_ = new double[taille];
	for(int i = 0; i < taille; i++){
		data_[i] = (double)(rand()%10);
	}
}

Vector :: ~Vector(){
	cout << "destructeur" << *this << endl;
	size = 0;
	delete data_;

}

int Vector::get_size() const{
	return size;
}

Vector::Vector(const Vector& v){
	size = v.get_size();
	data_ = new double(v.get_size());
	for(int i = 0; i < v.get_size(); i++){
		data_[i] = v[i];
	}
	cout << "copie constructeur" << endl;
}

double& Vector::operator[] (int i) const{
	return data_[i];
}

double& Vector::operator[] (int i){
	return data_[i];
}


Vector& Vector::operator= (const Vector& v){
	size = v.size;
	for(int i = 0; i < v.get_size(); i++){
		(*this)[i] = v[i];
	}
	return *this;
}

double Vector::norm(int p){
	double somme = 0.0;
	for(int i = 0; i < get_size(); i++){
		somme += pow((*this)[i], p);
	}
	return pow(somme, 1.0/p);
}

ostream& operator<< (ostream& os, const Vector& v1){
	for(int i = 0; i < v1.get_size(); i++){
		os << v1[i] << " ";
	}
	return os;
}

Vector operator+(Vector& v1, Vector& v2){
	Vector v(v1.get_size());
	assert(v1.get_size() == v2.get_size());
	for(int i = 0; i < v1.get_size(); i++){
		v[i] = v1[i] + v2[i];
	}
	return v;
}

Vector operator-(Vector& v1, Vector& v2){
	Vector v(v1.get_size());
	assert(v1.get_size() == v2.get_size());
	for(int i = 0; i < v1.get_size(); i++){
		v[i] = v1[i] - v2[i];
	}
	return v;
}

double operator* (Vector& v1, Vector& v2){
	double result = 0;
	for(int i = 0; i < v1.get_size(); i++){
			result += v1[i] * v2[i];
		}
	return result;
}

Vector operator* (Vector& v1, int n){
	Vector v(v1.get_size());
	for(int i = 0; i < v1.get_size(); i++){
		v[i] = v1[i];
	}
	return v;
}

Vector operator/ (Vector& v1, int n){
	Vector v(v1.get_size());
	for(int i = 0; i < v1.get_size(); i++){
			v[i] = v1[i] / n;
		}
	return v;
}
