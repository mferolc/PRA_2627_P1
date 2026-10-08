#ifndef  LISTARRAY_H
#define LISTAARRAY_H
#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;

	void resize(int new_size);

    public:
        // miembros públicos, incluidos los heredados de List<T>
	ListArray();
	~ListArray() override;

	void insert(int pos, T e) override;
        void append(T e) override;
        void prepend(T e) override;
        T remove(int pos) override;
        T get(int pos) override;
        int search(T e) override;
        bool empty() override;
        int size() override;

	T operator[](int pos);

	friend std::ostream& operator<<(std::ostream &out,ListArray<T> &list){
		out<< "Lista =>[";

		for(int i = 0; i < list.size(); i++){
			out<<list[i];
			if(i < list.size() - 1){
				out<< ", ";
			}
		}
		out<<"]";
		return out;
	}

};

template <typename T>
ListArray<T>::ListArray(){
	arr = new T[MINSIZE];
	max = MINSIZE;
	n = 0;
}

template <typename T>
ListArray<T>::~ListArray(){
	delete[] arr;
}

template <typename T>
void ListArray<T>::resize(int new_size){
	T* new_arr = new T[new_size];
	for(int i = 0; i < n; i++){
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	max = new_size;
}

template <typename T>
int ListArray<T>::size(){
	return n;
}

template <typename T>
bool ListArray<T>::empty(){
	return n == 0;
}

template <typename T>
T ListArray<T>::get(int pos){
	if(pos < 0 || pos >= n){
		throw std::out_of_range("Posición inválida");
	}
	return arr[pos];
}

template <typename T>
T ListArray<T>::operator[](int pos){
	return get(pos);
}

#endif


    
