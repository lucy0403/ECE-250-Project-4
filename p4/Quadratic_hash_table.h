/*****************************************
* Instructions
*  - Replace 'uwuserid' with your uWaterloo User ID
*  - Select the current calendar term and enter the year
*  - List students with whom you had discussions and who helped you
*
* uWaterloo User ID:  rdpitchf @uwaterloo.ca
* Submitted for ECE 250
* Department of Electrical and Computer Engineering
* University of Waterloo
* Calender Term of Submission:  (Winter) 20663181
*
* By submitting this file, I affirm that
* I am the author of all modifications to
* the provided code.
*
* The following is a list of uWaterloo User IDs of those students
* I had discussions with in preparing this project:
*    -
*
* The following is a list of uWaterloo User IDs of those students
* who helped me with this project (describe their help; e.g., debugging):
*    -
*****************************************/

#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include "ece250.h"

enum bin_state_t { UNOCCUPIED, OCCUPIED, ERASED };

template <typename Type>
class Quadratic_hash_table {
private:
	//number of occupied elements
	int count;

	int power;

	//size of the array
	int array_size;
	int mask;

	//number of total bins
	int total_bins;
	
	//number of erased elements
	int erased_elements;

	//Array of elements and array of enum states
	Type *array;
	bin_state_t *occupied;

	int hash(Type const &) const;


public:
	Quadratic_hash_table(int = 5);
	~Quadratic_hash_table();
	int size() const;
	int capacity() const;
	double load_factor() const;
	bool empty() const;
	bool member(Type const &) const;
	Type bin( int ) const;

	void print() const;

	void insert(Type const &);
	bool erase(Type const &);
	void clear();

	// Friends

	template <typename T>
	friend std::ostream &operator<<(std::ostream &, Quadratic_hash_table<T> const &);
};

template <typename Type>
Quadratic_hash_table<Type>::Quadratic_hash_table(int m) {
	count = 0;
	if (m < 0) {
		power = 5;
	}
	else {
		power = m;
	}
	array_size = 1;
	for (int a = 0; a < m; a++)
	{
		array_size *= 2;
	}
	//array_size = 1;
	//array_size = 1 << m;

	mask = array_size - 1;
	total_bins = array_size;
	erased_elements = 0;
	array = new Type[array_size];
	occupied = new bin_state_t[array_size];

	for (int i = 0; i < array_size; ++i) {
		occupied[i] = UNOCCUPIED;
	}
}

//template <typename Type>
//Quadratic_hash_table<Type>::Quadratic_hash_table(int m) :
//	count(0), power(m),
//	array_size(32),
//	total_bins(array_size),
//	erased_elements(0),
//	array(new Type[array_size]),
//	occupied(new bin_state_t[array_size]) {
//
//	for (int i = 0; i < array_size; ++i) {
//		occupied[i] = UNOCCUPIED;
//	}
//	
//}

//Finished
//Once done, delete whatever the pointers are pointing too.
template <typename Type>
Quadratic_hash_table<Type>::~Quadratic_hash_table() {
	clear();
	delete []array;
	delete []occupied;
}
// Your implementation here

template <typename Type>
int Quadratic_hash_table<Type>::hash(Type const &k) const {

	//int number = static_cast<int>(k);
	int bin = static_cast<int>(k) % static_cast<int>(array_size);
	int New_bin;
	//std::cout << "Bin " << bin << std::endl;
	//std::cout << "New_bin " << New_bin << std::endl;
	if (bin < 0) {
		New_bin = bin + array_size;
	}
	else
	{
		New_bin = bin;
	}

	//std::cout << "New_bin " << New_bin << std::endl;
	return New_bin & mask;
}





//Finished
//The number of elements.
template <typename Type>
int Quadratic_hash_table<Type>::size() const {
	return count;
}
//Finished
//The number of total bins
template <typename Type>
int Quadratic_hash_table<Type>::capacity() const {
	return array_size;
}

//Finished
//The number of Occupied and Erased bins divided by the number of total bins
template <typename Type>
double Quadratic_hash_table<Type>::load_factor() const {
	double load_factor = static_cast<double>((count + erased_elements)) / static_cast<double>(array_size);
	return load_factor;
}
//Finished
//If there are no occupied bins, the array is empty
template <typename Type>
bool Quadratic_hash_table<Type>::empty() const {

	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Finished
template <typename Type>
bool Quadratic_hash_table<Type>::member(Type const &Obj) const {
	
	int index = hash(Obj);
	int i = 1;
	bool duplicate = false;
	//While there is already an object in the index, iterate to the next index.
	for (int a = 0; a < array_size && (UNOCCUPIED != occupied[index]); a++) {
		//If there is a duplicate already in the array, set duplicate flag.
		if (occupied[index] != ERASED) {
			if (Obj == array[index]) {
				duplicate = true;
				break;
			}
		}
		index = index + i;
		index = hash(index);
		i++;
	}
	return duplicate;
}

//Finished
template <typename Type>
Type Quadratic_hash_table<Type>::bin(int n) const {

	if (occupied[n] == OCCUPIED)
	{
		return array[n];
	}
	else
	{
		//return NULL;
	}
}



//Finished
template <typename Type>
void Quadratic_hash_table<Type>::print() const {
	for (int i = 0; i < 32; i++) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
	for (int i = 0; i < 32; i++) {
		std::cout << occupied[i] << " ";
	}
	std::cout << std::endl;
}

//Finished
template <typename Type>
void Quadratic_hash_table<Type>::insert(Type const &Obj) {

	//If the table is full throw an exception.
	if (count == total_bins) {
		throw overflow();
	}
	else if (member(Obj)){
		//check to see if the object is already in the list.
		//if the Obj is already in the list do nothing.
	}
	else
	{

		int index = hash(Obj);
		int i = 1;
		bool duplicate = false;
		//While there is already an object in the index, iterate to the next index.
		while (OCCUPIED == occupied[index]) {
			//If there is a duplicate already in the array, set duplicate flag.
			if (Obj == array[index]) {
				duplicate = true;
				break;
			}
			index = index + i;
			index = hash(index);
			i++;
		}

		//If the Obj value is already in the array do nothing, otherwise add in Obj.
		if (duplicate == false) {
			//If it is erased vs unoccupied, do different increments on count and erased_elements.
			if (ERASED == occupied[index]){
				array[index] = Obj;
				occupied[index] = OCCUPIED;
				count++;
				erased_elements--;
			}
			else {
				array[index] = Obj;
				occupied[index] = OCCUPIED;
				count++;
			}
		}
	}
}

//Finished
template <typename Type>
bool Quadratic_hash_table<Type>::erase(Type const &Obj) {

	int index = hash(Obj);
	int i = 1;
	bool duplicate = false;
	//While there is already an object in the index, iterate to the next index.
	for (int a = 0; a < array_size && UNOCCUPIED != occupied[index]; a++) {
		//If there is a duplicate already in the array, set duplicate flag.
		//Even if there is an erased item, the Obj might be passed it.
		if (occupied[index] != ERASED)
		{
			//Once you find the object, erase it.
			if (Obj == array[index]) {
				duplicate = true;
				occupied[index] = ERASED;
				erased_elements++;
				count--;
				break;
			}
		}
		index = index + i;
		index = hash(index);
		i++;
	}
	return duplicate;
}

//Finished
template <typename Type>
void Quadratic_hash_table<Type>::clear() {

	for (int i = 0; i < array_size; ++i) {
		occupied[i] = UNOCCUPIED;
	}
	count = 0;
	erased_elements = 0;
}

//Not used
template <typename T>
std::ostream &operator<<(std::ostream &out, Quadratic_hash_table<T> const &hash) {
	for (int i = 0; i < hash.capacity(); ++i) {
		if (hash.occupied[i] == UNOCCUPIED) {
			out << "- ";
		}
		else if (hash.occupied[i] == ERASED) {
			out << "x ";
		}
		else {
			out << hash.array[i] << ' ';
		}
	}

	return out;
}

#endif
