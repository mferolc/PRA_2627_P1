#ifndef LIST_H
#define LIST_H

template <typename T> //Convierte a list en una calse generica
class List{
	public:
		//Metodos
		void insert(int pos, T e) = 0;
		void append(T e) = 0;
		void prepend(T e) = 0;
		T remove(int pos) = 0;
		T get(int pos) = 0;
		int search(T e) = 0;
		bool empty() = 0;
		int size() = 0;

	        virtual ~List() = default; 

};

#endif
