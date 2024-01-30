#pragma once
template <typename ELE_TYPE>
class LVector
{
private:
	size_t dim;
	ELE_TYPE* vec_ptr = nullptr;

public:
	LVector();
	LVector(size_t dim);
	LVector(size_t dim, ELE_TYPE* new_vec_ptr);

	ELE_TYPE* get_ptr();
	int get_dim();
	ELE_TYPE get(size_t index);
	void set(size_t index, ELE_TYPE value);

	void scale(double& scalar);
	void add(LVector<ELE_TYPE>& add_vec_ptr);
	void sub(LVector<ELE_TYPE>& sub_vec_ptr);
	ELE_TYPE dot(LVector<ELE_TYPE>& dot_vec_ptr);

	ELE_TYPE& operator[](size_t index);

	~LVector();
};
