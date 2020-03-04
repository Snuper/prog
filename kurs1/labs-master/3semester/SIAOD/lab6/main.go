package main

import (
	"fmt"
	"net"
	"net/http"
	"os/exec"
)

var socket net.Conn

func add(w http.ResponseWriter, r *http.Request) {
	elem := "add"
	elem += r.FormValue("elem")
	fmt.Fprint(socket, elem)
	var treeJson []byte
	n, err := socket.Read(treeJson)
	if err != nil {
		fmt.Println("Error socket read: ", err)
	}
	if n == 0 {
		fmt.Println("error: n == 0")
	}
	fmt.Fprint(w, treeJson)
}

func main() {
	tree := exec.Command("/tree")
	err := tree.Start()
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		http.ServeFile(w, r, "./index.html")
	})
	http.HandleFunc("/add", add)
	socket, err = net.Dial("tcp", "127.0.0.1:7001")
	if err != nil {
		fmt.Println("Error init socket: ", err)
	}
	fmt.Fprint(socket, "hello world")
	var buff []byte
	n, err := socket.Read(buff)
	if err != nil {
		fmt.Println("Error socket read: ", err)
	}
	if n == 0 {
		fmt.Println("error: n == 0")
	}
	fmt.Println("return: ", buff)
	err = http.ListenAndServe(":80", nil)
	if err != nil {
		fmt.Println("Error listen port 80: ", err)
	}
}
