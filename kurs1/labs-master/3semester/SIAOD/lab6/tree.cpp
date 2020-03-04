#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "include/json.h"

std::string ToString(int a) {
	std::ostringstream ss;
	ss << a;
	return ss.str();
}

using namespace std;

class Tree {
public:
    Tree() {
        head = NULL;
    }
    void Add(int a){
		newElem = a;
        addElementOnTree(a, head);
    };
    struct Elem {
    	int Data;
    	int Bal;
    	Elem *Left;
    	Elem *Right;
        Elem *Next;
    };
    void GraphBintree() {
    	JsonBox::Object obj;
    	int i = 0;
    	if (head != NULL) {
    		GraphBintreeRecure(head, obj, i, 0, 0, 500, 250);
    	}
    	JsonBox::Value json(obj);
    	json.writeToFile("resourse/tree.json");
		json.writeToStream(std::cout);
    }
private:
	int newElem;
    bool HR;
    bool VR;
    Elem *head;
	void addElementOnTree(int data, Elem *&p) {
        Elem *q;
        if (p == NULL) {
            p = new Elem;
            p->Data = data;
            p->Left = p->Right = NULL;
            p->Bal = 0;
            VR = true;
        } else {
            if (p->Data > data) {
                addElementOnTree(data, p->Left);
                if (VR) {
                    if (p->Bal == 0) {
                        q = p->Left;
                        p->Left = q->Right;
                        q->Right = p;
                        p = q;
						q->Bal = 1;
						VR = false;
	                    HR = true;
	                } else {
                        p->Bal = 0;
                        VR = true;
                        HR = false;
	                }
	            } else {
	                HR = false;
	            }
	        } else {
	            if (p->Data < data) {
	                addElementOnTree(data, p->Right);
	                if (VR) {
	                    p->Bal = 1;
	                    VR = false;
	                    HR = true;
	                } else {
                        if (HR) {
                            if (p->Bal == 1) {
	                            q = p->Right;
	                            p->Bal = 0;
	                            q->Bal = 0;
	                            p->Right = q->Left;
	                            q->Left = p;
	                            p = q;
	                            VR = true;
	                            HR = false;
	                        } else {
	                            HR = false;
                            }
                        }
                    }
                }
            }
        }
    }
    void GraphBintreeRecure(Elem *tr, JsonBox::Object &obj, int &i, int x, int y, int size_x, int size_y) {
    	std::string value = "n";
    	value += ToString(i);
    	obj["nodes"][i]["id"] = JsonBox::Value(value);
    	value = ToString(tr->Data);
    	obj["nodes"][i]["label"] = JsonBox::Value(value);
    	obj["nodes"][i]["x"] = JsonBox::Value(x);
    	obj["nodes"][i]["y"] = JsonBox::Value(y);
    	obj["nodes"][i]["size"] = JsonBox::Value(size_x+30);
		if (tr->Data == newElem) {
			obj["nodes"][i]["color"] = JsonBox::Value("#f00");
		} else {
			obj["nodes"][i]["color"] = JsonBox::Value("#000");
		}
    	int line = i;
    	if(tr->Left != NULL) {
    		value = "e";
    		value += ToString(i);
    		obj["edges"][i]["id"] = JsonBox::Value(value);
    		value = "n";
    		value += ToString(line);
    		obj["edges"][i]["source"] = JsonBox::Value(value);
    		i++;
    		value = "n";
    		value += ToString(i);
    		obj["edges"][i-1]["target"] = JsonBox::Value(value);
    		GraphBintreeRecure(tr->Left, obj, i, x-size_x, y+size_y, size_x/3, size_y/2);
    	}
    	if(tr->Right != NULL) {
    		value = "e";
    		value += ToString(i);
    		obj["edges"][i]["id"] = JsonBox::Value(value);
    		value = "n";
    		value += ToString(line);
    		obj["edges"][i]["source"] = JsonBox::Value(value);
    		i++;
    		value = "n";
    		value += ToString(i);
    		obj["edges"][i-1]["target"] = JsonBox::Value(value);
            if (tr->Bal == 1) {
                GraphBintreeRecure(tr->Right, obj, i, x+size_x*2, y, size_x, size_y);
            } else {
        		GraphBintreeRecure(tr->Right, obj, i, x+size_x, y+size_y, size_x/3, size_y/2);
            }
    	}
    }
};

int main() {
	Tree tree;
    bool quit = false;
    int addElem = 0;
    string inputCommand;
    srand(time(NULL));
    int quantNewElem;
    while(!quit) {
        getline(cin, inputCommand);
        if(inputCommand == "add") {
            cin >> addElem;
            tree.Add(addElem);
        } else if(inputCommand == "parseJson") {
            tree.GraphBintree();
        } else if(inputCommand == "newTree") {
            cin >> quantNewElem;
            for(int i = 0; i < quantNewElem; i++) {
                tree.Add(rand() % 1000);
            }
        }
    }
    return 0;
}
