package main

import (
	"fmt"
	"os"
	"strconv"

	"jhpark.sinsiway.com/runclib_go/rowref"
)

func main() {
	loopCnt := 10
	rowNum := 1000000

	if len(os.Args) >= 2 {
		loopCnt, _ = strconv.Atoi(os.Args[1])
	}

	fmt.Println("#program start")
	fmt.Println()
	rr := rowref.New("test_table", rowNum)
	defer rr.Delete()

	fmt.Println("table name : ", rr.GetTableName())
	fmt.Println("row size : ", rr.GetRowSize())

	cnt := 0
	//var row *rowref.StPetraRow
	for i := 0; i < loopCnt; i++ {
		rr.Rewind()
		for rr.Next() {
			row = rr.Data()
			if row == nil {
				fmt.Println("row not found.")
				continue
			}
			cnt++
			//fmt.Println(row)
		}
	}
	fmt.Println("1cnt : ", cnt)

	fmt.Println()
	fmt.Println("#program end")
}
