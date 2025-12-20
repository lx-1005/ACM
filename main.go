package main

import (
	"fmt"
)

func main() {
	s := "a我bc"
	for i, c := range s {
		fmt.Println(i, c)
	}
	fmt.Println()
	for i, _ := range s {
		fmt.Println(i, s[i])
	}
	fmt.Println()
	for i, c := range s {
		fmt.Println(i, c, s[i])
	}
	fmt.Println()
}
