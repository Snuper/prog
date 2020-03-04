package main

import (
		"fmt"
		"math/rand"
)

// Лабораторная работа №9
//
// 1).Реализовать хеширование методом открытой адресации,
// использовать два способа разрешения коллизий: линейные и
// квадратичные пробы. Вывести на экран заполненные хеш-таблицы.
// 2).Подсчитать и сравнить количество коллизий при линейных и
// квадратичных пробах, построить таблицу вида:
// 3). Дополнительное задание (на 5+):
// Организовать поиск элемента с заданным ключом для методов
// прямого связывания и открытой адресации.

type  sample_type func(int, int) int;

type HashTable struct{
	N int;
	Sample sample_type;
	Elem []int;
	Collision  int;
}

func (ht *HashTable) Init(N int, Sample sample_type) {
	ht.N = N;
	ht.Sample = Sample;
	ht.Elem = make([]int, ht.N);
}

func (ht *HashTable) Add(a int) (int){
	var numb int = hashFunc(a);
	var i int;
	if a < 0 {return -2};
	for {
		if ht.Elem[numb] == 0 {
			ht.Elem[numb] = a;
			ht.Collision += i;
			return numb;
		}
		i++;
		numb = ht.Sample(numb, i);
		if i > ht.N {return -1};
	}
}

func (ht *HashTable) Linear(numb int, i int) int {
	numb += i;
	if numb > ht.N {
		numb = numb % ht.N;
	}
	return numb;
}

func (ht *HashTable) Square(numb int, i int) int {
	numb *= i;
	if numb > ht.N {
		numb = numb % ht.N;
	}
	return numb;
}

func hashFunc(a int) int{
	return a % 101
}

func main() {
	var hash_linear_sample HashTable;
	var hash_square_sample HashTable;
	hash_linear_sample.Init(101, hash_linear_sample.Linear);
	hash_square_sample.Init(101, hash_square_sample.Square);
	var rand_ch int;
	var numb int;
	fmt.Println("Кол-во ячеек: 101");
	fmt.Println("Метод.          Кол-во чисел.   Кол-во коллизий.")
	for i := 0; i < 10 && numb >= 0; i++ {
		for j := 0; j < 10 && numb >= 0; j++ {
			rand_ch = rand.Intn(100);
			numb = hash_square_sample.Add(rand_ch);
			numb = hash_linear_sample.Add(rand_ch);
		}
		fmt.Println("Квадратичный:   ", i * 10, "              ", hash_square_sample.Collision)
		fmt.Println("Линейный:       ", i * 10, "              ", hash_linear_sample.Collision)
	}
}
