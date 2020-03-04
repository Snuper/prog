package main

import (
    "fmt";
    "math/rand"
)

// Лабораторная работа №1
//
// 1). Разработать процедуру построения идеально сбалансированного дерева
//поиска (ИСДП).
// 2). Построить ИСДП из 100 вершин, распечатать обход дерева слева направо.
// 3). Для построенного дерева вычислить размер, контрольную сумму, высоту и
//среднюю высоту.
//
// 4). Дополнительное задание (на 5+):
// Реализовать графическую процедуру изображения дерева на экране.

type Bintree struct {
    head *Elem;
    elem_ptr *Elem;
}

type Elem struct {
    elem int;
    right_ptr *Elem;
    left_ptr *Elem;
}

func (bt *Bintree) Init() {
    bt.elem_ptr = new (Elem);
    bt.head = bt.elem_ptr;
}

func (bt *Bintree) Add(numb int) {
    if(bt.elem_ptr == nil) {
        bt.Init();
    }
    bt.elem_ptr = bt.head;
    for ;; {
        if bt.elem_ptr.elem == 0 {
            bt.elem_ptr.elem = numb;
            if bt.head == nil {bt.head = bt.elem_ptr}
            return
        } else {
            if bt.elem_ptr.elem > numb {
                if bt.elem_ptr.right_ptr == nil {
                    bt.elem_ptr.right_ptr = new(Elem);
                }
                bt.elem_ptr = bt.elem_ptr.right_ptr;
            } else {
                if bt.elem_ptr.left_ptr == nil {
                    bt.elem_ptr.left_ptr = new(Elem);
                }
                bt.elem_ptr = bt.elem_ptr.left_ptr;
            }
        }
    }
}

func (bt *Bintree) Search(numb int) int {
    bt.elem_ptr = bt.head
    for ;; {
        if bt.elem_ptr == nil {
            return 0;
        } else {
            if bt.elem_ptr.elem > numb {
                bt.elem_ptr = bt.elem_ptr.right_ptr;
            } else {
                if bt.elem_ptr.elem == numb {
                    return bt.elem_ptr.elem;
                } else {
                    bt.elem_ptr = bt.elem_ptr.left_ptr;
                }
            }
        }
    }
}

func (bt *Bintree) Det() {
    fmt.Println("HEAD = ", bt.head.elem);
    DetRecur(bt.head);
}

func DetRecur(elem *Elem) {
    if elem == nil {
        return
    }
    DetRecur(elem.left_ptr);
    fmt.Println(elem.elem);
    DetRecur(elem.right_ptr);
}

func (bt *Bintree) CalcInfo() (int, int, int) {
    var size int;
    var check_sum int;
    var height int;
    height = calcInfoRecur(bt.head, &size, &check_sum, height);
    return size, check_sum, height;
}

func calcInfoRecur(elem *Elem, size *int, check_sum *int, height int) (int) {
    if(elem == nil) {
        return height;
    }
    *size++;
    height++;
    *check_sum += elem.elem;
    var buff int;
    buff = calcInfoRecur(elem.left_ptr, size, check_sum, height);
    height = calcInfoRecur(elem.right_ptr, size, check_sum, height);
    if buff > height {
        return buff;
    } else {
        return height;
    }
}

func ISDP(bt Bintree, quant_1 int, quant_2 int) {
    var buff int = (quant_1 + quant_2) / 2;
    if quant_1 >= quant_2 {
        return;
    }
    fmt.Print(buff);
    bt.Add(buff);
    ISDP(bt, quant_1, buff - 1);
    ISDP(bt, buff + 1, quant_2);
}

func SDP(bt Bintree, quant int) {
    for i := 0; i < quant; i++ {
        bt.Add(rand.Intn(100));
    }
}

func main() {
    fmt.Println("job");
    var bintree Bintree;
    bintree.Init();
    ISDP(bintree, 0, 100);
    search_elem := bintree.Search(3);
    fmt.Println("search 3: ", search_elem);
    bintree.Det()
    size, check_sum, height := bintree.CalcInfo();
    fmt.Println("size = ", size, "\ncheck_sum = ", check_sum, "\nheight = ", height);
}
