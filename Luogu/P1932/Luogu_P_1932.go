package main

import (
	"bufio"
	. "fmt"
	"math/big"
	"math/bits"
	"os"
)

// 整数
// 以 s 结尾的方法，s 代表 self（修改调用者）
type Int struct{ *big.Int }

func newInt(x int64) Int     { return Int{big.NewInt(x)} }
func (a Int) adds(b Int) Int { a.Add(a.Int, b.Int); return a }
func (a Int) subs(b Int) Int { a.Sub(a.Int, b.Int); return a }
func (a Int) muls(b Int) Int { a.Mul(a.Int, b.Int); return a }
func (a Int) divs(b Int) Int { a.Quo(a.Int, b.Int); return a }
func (a Int) mods(b Int) Int { a.Rem(a.Int, b.Int); return a }
func (a Int) negs() Int      { a.Neg(a.Int); return a }

// 不修改调用者
func (a Int) set(b Int) Int { a.Set(b.Int); return a }
func (a Int) cmp(b Int) int { return a.Cmp(b.Int) }
func (a Int) add(b Int) Int { return Int{new(big.Int).Add(a.Int, b.Int)} }
func (a Int) sub(b Int) Int { return Int{new(big.Int).Sub(a.Int, b.Int)} }
func (a Int) mul(b Int) Int { return Int{new(big.Int).Mul(a.Int, b.Int)} }
func (a Int) div(b Int) Int { return Int{new(big.Int).Quo(a.Int, b.Int)} }
func (a Int) mod(b Int) Int { return Int{new(big.Int).Rem(a.Int, b.Int)} }
func (a Int) neg() Int      { return Int{new(big.Int).Neg(a.Int)} }

func (a *Int) onesCount() (ones int) {
	for _, w := range a.Bits() {
		ones += bits.OnesCount(uint(w))
	}
	return ones
}

// 有理数
type rat struct{ *big.Rat }

func newRat(a, b int64) rat  { return rat{big.NewRat(a, b)} } // a/b
func (a rat) adds(b rat) rat { a.Add(a.Rat, b.Rat); return a }
func (a rat) subs(b rat) rat { a.Sub(a.Rat, b.Rat); return a }
func (a rat) muls(b rat) rat { a.Mul(a.Rat, b.Rat); return a }
func (a rat) divs(b rat) rat { a.Quo(a.Rat, b.Rat); return a }
func (a rat) negs() rat      { a.Neg(a.Rat); return a }

func (a rat) set(b rat) rat { a.Set(b.Rat); return a }
func (a rat) cmp(b rat) int { return a.Cmp(b.Rat) }
func (a rat) add(b rat) rat { return rat{new(big.Rat).Add(a.Rat, b.Rat)} }
func (a rat) sub(b rat) rat { return rat{new(big.Rat).Sub(a.Rat, b.Rat)} }
func (a rat) mul(b rat) rat { return rat{new(big.Rat).Mul(a.Rat, b.Rat)} }
func (a rat) div(b rat) rat { return rat{new(big.Rat).Quo(a.Rat, b.Rat)} }
func (a rat) neg() rat      { return rat{new(big.Rat).Neg(a.Rat)} }

func solve(in *bufio.Reader, out *bufio.Writer) {
	a := Int{new(big.Int)}
	b := Int{new(big.Int)}
	Fscan(in, &a, &b)

	Fprintln(out, a.add(b))
	Fprintln(out, a.sub(b))
	Fprintln(out, a.mul(b))
	Fprintln(out, a.div(b))
	Fprintln(out, a.mod(b))
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	T := 1
	// Fscan(in, &T)
	for ; T > 0; T-- {
		solve(in, out)
	}
}
