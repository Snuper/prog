#include <iostream>
#include <stack>
#include <cstdlib>
#include <queue>

int const N = 10;

void intIncStack(std::stack<int> &st);
void intPrintStack(std::stack<int> &st);
void intDecStack(std::stack<int> &st);
void intRandStack(std::stack<int> &st);
int intCheckSumStack(std::stack<int> &st);
int intRunNumberStack(std::stack<int> &st);
void intIncQueue(std::queue<int> &st);
void intDecQueue(std::queue<int> &st);
void intRandQueue(std::queue<int> &st);
void clearSpis(std::queue<int> &st);
void clearSpis(std::stack<int> &st);

/*typedef<class T>
struct stack {
	T *elem;
	T 
	void push();
	void del;
};*/

int main() {
	std::stack<int> st;
	std::queue<int> que;
	int const N = 10;
//заполнение списка (стека) возрастающими числами;
	intIncStack(st);
//заполнение списка (стека) убывающими числами;
	intRandStack(st);
//заполнение списка (стека) случайными числами;
	intDecStack(st);
//печать элементов списка;
	intPrintStack(st);
//подсчет контрольной суммы элементов списка;
	std::cout << "Контрольная сумма = " << intCheckSumStack(st) << std::endl;
//подсчет количества серий в списке.
	std::cout << "Кол-во серий = " << intRunNumberStack(st) << std::endl; 
//заполнение списка (очереди) возрастающими числами;
	intIncQueue(que);
//заполнение списка (очереди) убывающими числами;
	intDecQueue(que);
//заполнение списка (очереди) случайными числами;
	intRandQueue(que);
//удаление всех элементов из списка.
	clearSpis(st);
	clearSpis(que);
} 

void intIncStack(std::stack<int> &st) {
	while(st.size()) st.pop();
	for(int i = 0; i < N; i++) {
		st.push(i + 1);
	}
}

void intPrintStack(std::stack<int> &st) {
	std::stack<int> st_buff = st;
	while(st_buff.size()) {
		std::cout << st_buff.top() << std::endl;
		st_buff.pop();
	}
}

void intDecStack(std::stack<int> &st) {
	while(st.size()) st.pop();
	for(int i = N; i > 0; i--) {
		st.push(i);
	}
}

void intRandStack(std::stack<int> &st) {
	while(st.size()) st.pop();
	for(int i = 0; i < N; i++) {
		st.push(rand() % 10);
	}
}

int intCheckSumStack(std::stack<int> &st) {
	int result = 0;
	std::stack<int> st_buff = st;
	while(st_buff.size()) {
		result += st_buff.top();
		st_buff.pop();
	}
	return result;
}

int intRunNumberStack(std::stack<int> &st) {
	int result = 1;
	int buff = 0;
	std::stack<int> st_buff = st;
	while(st_buff.size() - 1) {
		buff = st_buff.top();
		st_buff.pop();
		if(st_buff.top() > buff) result++;
	}
	return result;
}

void intIncQueue(std::queue<int> &st) {
	while(st.size()) st.pop();
	for(int i = 0; i < N; i++) {
		st.push(i + 1);
	}
}

void intDecQueue(std::queue<int> &st) {
	while(st.size()) st.pop();
	for(int i = N; i > 0; i--) {
		st.push(i);
	}
}

void intRandQueue(std::queue<int> &st) {
	while(st.size()) st.pop();
	for(int i = 0; i < N; i++) {
		st.push(rand() % 10);
	}
}

void clearSpis(std::queue<int> &st) {
	while(st.size()) st.pop();
	return;
}

void clearSpis(std::stack<int> &st) {
	while(st.size()) st.pop();
	return;
}