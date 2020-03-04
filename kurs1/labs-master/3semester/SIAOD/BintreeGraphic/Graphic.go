package graphic

import (
	"encoding/json"
	"fmt"
	"html/template"
	"net/http"
)

type Spis interface {
	getHead() *Elem
	getAmount() int
}

type Elem interface {
	getLeft() *Elem
	getRight() *Elem
	getElement() int
}

type Node struct {
	id    string
	label string
	x     int
	y     int
	size  int
}

type Edge struct {
	id     string
	sourse string
	target string
}

type Graphs struct {
	nodes []Node
	edges []Edge
}

var iValue int

func indexHendler(w http.ResponseWriter, r *http.Request) {
	t, err := template.ParseFiles("BintreeGraphic/index.html")
	if err != nil {
		fmt.Fprint(w, "error index.html")
	}

	t.ExecuteTemplate(w, "index", iValue)
}

func iHendler(w http.ResponseWriter, r *http.Request) {
	iValue++
	http.Redirect(w, r, "/"+string(iValue), 302)
}

func Init() {
	http.HandleFunc("/", indexHendler)
	http.HandleFunc("/i", iHendler)
	err := http.ListenAndServe(":80", nil)
	if err != nil {
		fmt.Println("error listen: ", err)
	}
}

func GraphBintree(s Spis) ([]byte, error) {
	var graphs Graphs
	graphs.nodes := make([]Node, s.getAmount())
	graphs.edges := make([]Edge, s.getAmount()-1)
	var i int
	if s.getHead != nil {
		GraphBintreeRecure(s.GetHead(), graphs.edges, graphs.nodes, &i)
	}
	return json.Marshal(graphs)
}

func GraphBintreeRecure(e *Elem, nodes []Node, edges []Edge, i *int, x int, y int) {
	nodes[i].id = "n" + string(i)
	nodes[i].label = string(e.getElement())
	nodes[i].size = 2
	nodes[i].x = x
	nodes[i].y = y
	if e.getLeft() != nil {
		edges[i].id = "e" + string(i)
		edges[i].sourse = "n" + string(i)
		i++
		edges[i].target = "n" + string(i)
		GraphBintreeRecure(e.getLeft(), nodes, edges, &i, x-2, y+2)
	}
	if e.getRight() != nil {
		edges[i].id = "e" + string(i)
		edges[i].sourse = "n" + string(i)
		i++
		edges[i].target = "n" + string(i)
		GraphBintreeRecure(e.getLeft(), nodes, edges, &i, x+2, y+2)
	}
}
