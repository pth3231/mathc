#include "LVector.h"
#include <stdlib.h>
#include <stdexcept>
#include <algorithm>

template <typename ELE_TYPE>
LVector<ELE_TYPE>::LVector() {
	this->dim = 0;
}

template <typename ELE_TYPE>
LVector<ELE_TYPE>::LVector(size_t dim) {
	this->dim = dim;
	this->vec_ptr = new ELE_TYPE[dim];
}

template <typename ELE_TYPE>
LVector<ELE_TYPE>::LVector(size_t dim, ELE_TYPE* new_vec_ptr) {
	this->dim = dim;
	this->vec_ptr = new ELE_TYPE[dim];
	std::copy(new_vec_ptr, new_vec_ptr + dim, this->vec_ptr);
}

template <typename ELE_TYPE>
ELE_TYPE* LVector<ELE_TYPE>::get_ptr() {
	return this->vec_ptr;
}

template <typename ELE_TYPE>
int LVector<ELE_TYPE>::get_dim() {
	return this->dim;
}

template <typename ELE_TYPE>
ELE_TYPE LVector<ELE_TYPE>::get(size_t index) {
	return this->vec_ptr[index];
}

template <typename ELE_TYPE>
void LVector<ELE_TYPE>::set(size_t index, ELE_TYPE value) {
	this->vec_ptr[index] = value;
}

template <typename ELE_TYPE>
void LVector<ELE_TYPE>::scale(double& scalar) {
	for (size_t index = 0; index < dim; ++index) {
		this->vec_ptr[index] *= scalar;
	}
}

template <typename ELE_TYPE>
void LVector<ELE_TYPE>::add(LVector<ELE_TYPE>& add_vec_ptr) {
	if (this->dim != add_vec_ptr.get_dim())
		throw std::length_error("Two LVectors do not have the same number of dimensions.");
	for (size_t index = 0; index < dim; ++index) {
		this->vec_ptr[index] += add_vec_ptr.get_ptr()[index];
	}
}

template <typename ELE_TYPE>
void LVector<ELE_TYPE>::sub(LVector<ELE_TYPE>& sub_vec_ptr) {
	if (this->dim != sub_vec_ptr.get_dim())
		throw std::length_error("Two LVectors do not have the same number of dimensions.");
	for (size_t index = 0; index < dim; ++index) {
		this->vec_ptr[index] -= sub_vec_ptr.get_ptr()[index];
	}
}

template <typename ELE_TYPE>
ELE_TYPE LVector<ELE_TYPE>::dot(LVector<ELE_TYPE>& dot_vec_ptr) {
	if (this->dim != dot_vec_ptr.get_dim())
		throw std::length_error("Two LVectors do not have the same number of dimensions.");
	ELE_TYPE result = 0;
	for (size_t index = 0; index < dim; ++index) {
		result += this->vec_ptr[index] * dot_vec_ptr.get_ptr()[index];
	}
	return result;
}

template <typename ELE_TYPE>
ELE_TYPE& LVector<ELE_TYPE>::operator[](size_t index) {
	return this->vec_ptr[index];
}

template <typename ELE_TYPE>
LVector<ELE_TYPE>::~LVector() {
	delete[] this->vec_ptr;
}

template class LVector<int>;
template class LVector<long>;
template class LVector<long long>;