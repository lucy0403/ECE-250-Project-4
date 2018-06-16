#include <iostream>
#include "Quadratic_hash_table.h"

using namespace std;

int main() {
	//Search_tree<int> tree;
	Quadratic_hash_table<int> ht(-6);
	std::cout << "SIze " << ht.size() << std::endl;
	ht.size();
	ht.print();
	/*for (int i = 0; i <= 31; i++)
	{
		ht.insert(i);
		std::cout << i << std::endl;
	}
	ht.print();
	ht.insert(5);
	ht.insert(5);
	ht.insert(37);
	ht.print();
	ht.clear();
	ht.print();*/
	/*for (int i = 0; i <= 31; i++)
	{
		ht.insert(i);
		std::cout << i << std::endl;
	}
	ht.print();

	ht.clear();

	ht.print();
	for (int i = 63; i >= 31; i--)
	{
		ht.insert(i);
		std::cout << i << std::endl;
	}
	ht.print();

	ht.erase(44);
	ht.print();
	ht.insert(1000);
	ht.print();*/

	/*std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.insert(5);
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.insert(5);
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.print();
	ht.erase(5);
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.print();
	ht.insert(37);
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.print();
	ht.clear();
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.print();
	ht.insert(12);
	ht.insert(15);
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.print();
	ht.erase(15);
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.print();
	ht.insert(100000);
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.print();
	ht.insert(15);
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	ht.print();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "member 1 " << ht.member(1) << std::endl;
	std::cout << "member 15 " << ht.member(15) << std::endl;
	std::cout << "member 100000 " << ht.member(100000) << std::endl;
	std::cout << std::endl;
	ht.clear();
	std::cout << "member 3 " << ht.member(3) << std::endl;
	ht.insert(3);
	std::cout << "member 3 " << ht.member(3) << std::endl;
	std::cout << "bin 3 " << ht.bin(3) << std::endl;
	ht.erase(3);
	std::cout << "member 3 " << ht.member(3) << std::endl;
	std::cout << "bin 3 " << ht.bin(3) << std::endl;*/
	/*for (int i = 0; i < 31; i++){
	ht.insert(i);
	std::cout << i << std::endl;
	}
	ht.print();
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	for (int i = 0; i < 31; i++) {
		std::cout << "member " << i << " " << ht.member(i) << std::endl;
	}
	ht.insert(10000000);
	ht.print();
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;
	for (int i = 0; i <= 31; i++) {
		std::cout << "member " << i << " " << ht.member(i) << std::endl;
	}
	for (int i = 0; i <= 31; i++) {
		ht.erase(i);
	}
	ht.print();
	for (int i = 0; i <= 31; i++) {
		std::cout << "member " << i << " " << ht.member(i) << std::endl;
	}
	std::cout << "size " << ht.size() << std::endl;
	std::cout << "capacity " << ht.capacity() << std::endl;
	std::cout << "load factor " << ht.load_factor() << std::endl;*/



	ht.insert(3);
	ht.print();
	ht.insert(-6);
	ht.print();

	ht.insert(63);
	ht.print();

	ht.erase(31);
	ht.print();

	ht.insert(63);
	ht.print();

	return 0;
}