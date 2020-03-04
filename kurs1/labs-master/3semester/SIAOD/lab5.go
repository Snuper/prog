// lab5.go
package main

import (
	"SIAOD/BintreeGraphic"
	"fmt"
)

type ABLBintree struct {
	head     *Elem
	elem_ptr *Elem
}

type Elem struct {
	elem      int
	right_ptr *Elem
	left_ptr  *Elem
	balance   int
}

func main() {
	go graphic.Init()
	var input string
	for i := true; i; {
		fmt.Print("lab5: ")
		fmt.Scanln(&input)
		switch input {
		case "stop":
			i = false
		default:
			fmt.Println(input, ": command not found")
		}
	}
	fmt.Println("COMPLETE")
}
