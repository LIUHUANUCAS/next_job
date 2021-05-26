package main

import (
	"fmt"

	"rsc.io/pdf"
)

func main() {
	file, err := pdf.Open("test.pdf")
	if err != nil {
		panic(err)
	}
	fmt.Println(file.Page(2).Content())
}
