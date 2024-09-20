package main

import (
	"bufio"
	"fmt"
	"os"
)

func cf1921D(in *bufio.Reader, out *bufio.Writer) {

	var s string
	fmt.Println("123")
	fmt.Println(s)
	fmt.Println("123")
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	T := 1
	// fmt.Fscan(in, &T)
	for ; T > 0; T-- {
		cf1921D(in, out)
	}
	out.Flush()
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
