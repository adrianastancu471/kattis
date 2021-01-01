package main

import (
    "fmt"
)

func count_divisor(input int) int {
    var count int
    count = 1
    i := 2

    for i*i <= input {
        if input%i==0 {
            input=input/i
            count+=1
        } else {
            i+=1
        }
    }
    return count
}

func main() {
    var x int
    fmt.Scan(&x)
    fmt.Println(count_divisor(x))
}
