package main

import "fmt"

func main() {
	a := retNumb()
	if a != nil {
		fmt.Println("a not nil")
	} else {
		fmt.Println("a is nil")
	}
}

func retNumb() int {
	return nil
}
