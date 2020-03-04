package lab1

type List struct {
	size int
	head *node
}

type node struct {
	elem element
	next *node
}

type element interface {}

func (list *List) Add(new_elem element) {
	if list.head == nil {
		list.head = new(node)
		list.head.elem = new_elem
		list.size = 1
		return
	}
	nd := list.head
	for nd.next != nil { 
		nd = nd.next
	}
	nd.next = new(node)
	nd.next.elem = new_elem
	list.size++
}

func (list *List) Get(id int) element {
	if id < 0 {
		return nil
	}
	nd := list.head
	for nd != nil {
		if id == 0 {
			return nd.elem
		}
		nd = nd.next
		id--
	}
	return nil
}

func (list *List) Remove(id int) bool {
	if id < 0 {
		return false
	}
	var nd **node = &list.head
	for *nd != nil {
		if id == 0 {
			*nd = (*nd).next
			list.size--
			return true
		}
		nd = &((**nd).next)
		id--
	}
	return false
}

func (list *List) Size() int {
	return list.size
}

func (list *List) Iter() Iterator {
	var iter Iterator
	iter.this_node = list.head
	return iter
}

type Iterator struct {
	this_node *node
}

func (iter *Iterator) Next() element {
	elem := iter.this_node.elem
	iter.this_node = iter.this_node.next
	return elem
}

func (iter *Iterator) IsNext() bool {
	if iter.this_node.next != nil {
		return true
	}
	return false
}

