package lab1 

import "testing"

func TestAddAndGet(t *testing.T) {
	test_values := []int{10, 20, 4, 7, 9}
	var test_list List

	for _, value := range test_values {
		test_list.Add(value)
	}

	for i, value := range test_values {
		if test_list.Get(i).(int) != value {
			t.Error("add and get not work!")
		}
	}
}

func TestRemove(t *testing.T) {
	test_values := []int{10, 20, 4, 7, 9}
	var test_list List

	for _, value := range test_values {
		test_list.Add(value)
	}

	test_values_expected := test_values[2:]
	test_list.Remove(0)
	test_list.Remove(0)

	for i, value := range test_values_expected {
		if test_list.Get(i).(int) != value {
			t.Error("remove not work!")
		}
	}

	test_values_expected = test_values_expected[:2]
	test_list.Remove(2)

	for i, value := range test_values_expected {
		if test_list.Get(i).(int) != value {
			t.Error("remove not work!")
		}
	}
}

func TestIterator(t *testing.T) {
	test_values := []int{10, 20, 4, 7, 9}
	var  test_list List

	for _, value := range test_values {
		test_list.Add(value)
	}

	index := 0
	iter := test_list.Iter()

	for iter.IsNext() {
		value := iter.Next()
		if value != test_values[index] {
			t.Error("iterator not work!")
		}
		index++
	}
}