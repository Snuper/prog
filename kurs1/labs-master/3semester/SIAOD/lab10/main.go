 package main

import (
	"fmt"
	"strconv"
)

type NumbFixedVariable struct {
	Data string
	Separate string
	Size_E int
}


func main() {
	fmt.Println("lab 10:")
	var input int
	var FixedVariable NumbFixedVariable
	FixedVariable.Size_E = 4
	var exp, mantiss string
	for input >= 0 {
		fmt.Print("Введите число: ")
		fmt.Scanln(&input)
		exp, mantiss = FixedVariable.CodingNumb(input)
		fmt.Println("Закодированное: ", exp, mantiss)
	}

}

func (nfv *NumbFixedVariable) CodingNumb(numb int) (string, string) {
	var exponent string
	var mantiss string
	var buff_string string
	var size_mantiss int

	for numb != 1 {
		buff_string += strconv.Itoa(numb % 2)
		numb = numb / 2
	}
	for i := len(buff_string) - 1; i >= 0 ; i-- {
		mantiss += string(buff_string[i])
	}

	buff_string = ""
	size_mantiss = len(mantiss) + 1
	for size_mantiss != 1 {
		buff_string += strconv.Itoa(size_mantiss % 2)
		size_mantiss = size_mantiss / 2
	}
	buff_string += "1"

	if (len(buff_string) <= nfv.Size_E) {
		for (nfv.Size_E - len(buff_string)) > 0 {
			buff_string += "0"
		}
	} else {
		fmt.Println("ERROR: size_E")
		return "", ""
	}

	for i := len(buff_string) - 1; i >= 0 ; i-- {
		exponent += string(buff_string[i])
	}
	return exponent, mantiss
}

func (nfv *NumbFixedVariable) AddNumb(numb int) {

}
