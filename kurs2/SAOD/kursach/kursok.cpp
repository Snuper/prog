#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

#include <conio.h>
#include <vector>
#include <map>
#include <cstring>
#include <math.h>


#define N 4000

using namespace std;

void clear() {
    system("cls");
}

using namespace std;

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> elems;
    while (getline(ss, item, delim))
        elems.push_back(item);
    return elems;
}

const int KEY_SORT = 0;
const int KEY_SPIS = 1;

struct record {
    char lastname[30];
    short int hotelNumber;
    char position[22];
    char dateOfBirth[10];

    string key(int index) {
        std::vector<std::string> stSplit = split(string(dateOfBirth), '-');
        if (stSplit.empty())
            return "sa";
        string input;
        switch (index) {
            case KEY_SORT:
                input = to_string(hotelNumber);
                if (input.size() < 5) for (int i = 0; i < 5 - input.size(); i++) input = ' ' + input;
                return input + lastname;
            case KEY_SPIS:
                return to_string(hotelNumber);
        }
        return "sa";
    }

    int keySpis(int index) {
        return hotelNumber;
    }

    int keyTree() {
        std::vector<std::string> stSplit = split(string(dateOfBirth), '-');
        if (stSplit.empty())
            return -1;
        return stoi(stSplit.at(2));

    }


    string toString() {
        return lastname + to_string(hotelNumber) + position + dateOfBirth;
    }
} ttNo[N], tt[N], temp[N + 1];

#define QMAX 4000
struct queue {
    record qu[QMAX];
    int rear, frnt;
};

void init(struct queue *q) {
    q->frnt = 1;
    q->rear = 0;
    return;
}

void insert(struct queue *q, record x) {
    if (q->rear < QMAX - 1) {
        q->rear++;
        q->qu[q->rear] = x;
    } else
        printf("??????? ?????!\n");
    return;
}

int isempty(struct queue *q) {
    if (q->rear < q->frnt) return 1;
    else return 0;
}

int iii = 0;

void print(struct queue *q) {
    int h;
    if (isempty(q) == 1) {
        printf("??????? ?????!\n");
        return;
    }
    for (h = q->frnt; h <= q->rear; h++)
        cout << iii++ << ") lastname: " << q->qu[h].lastname << "\t"
             << "hotelNumber: " << q->qu[h].hotelNumber << "   \t"
             << "position: " << q->qu[h].position << "\t"
             << "dateOfBirth: " << q->qu[h].dateOfBirth << endl;
    return;
}

void printRecord(record *tt, int size) {
    if (size == -20) return;
    int index = 0;
    char letter;
    do {
        clear();
        for (int i = index; i < index + 20; ++i) {
            if (strcmp(tt[i].position, "") != 0)
                cout << (i + 1) << ") lastname: " << tt[i].lastname << "\t"
                     << "hotelNumber: " << tt[i].hotelNumber << "   \t"
                     << "position: " << tt[i].position << "\t"
                     << "dateOfBirth: " << tt[i].dateOfBirth << endl;
        }

        cin >> letter;
        switch (letter) {
            case 'a':
                return;
            case 's':
                if (index < size)
                    index += 20;
                break;
            case 'w':
                if (index > 0)
                    index -= 20;
                break;
        }
        if (letter == 'q') break;
    } while (true);
}

void hoarasort(record *a, int first, int last, int keyIndex) {

    int i = first, j = last;
    record tmp, x = a[(first + last) / 2];

    do {
        while (strcmp(a[i].key(keyIndex).c_str(), x.key(keyIndex).c_str()) < 0)
            i++;
        while (strcmp(a[j].key(keyIndex).c_str(), x.key(keyIndex).c_str()) > 0)
            j--;

        if (i <= j) {
            if (i < j) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoarasort(a, i, last, keyIndex);
    if (first < j)
        hoarasort(a, first, j, keyIndex);
}

bool vr = true, hr = true;

struct vertexDate {
    int i;
    record data;
    int balance;
    vertexDate *left;
    vertexDate *right;
};

void add_DBD(vertexDate *(&p), record x, int index) {
    if (p == NULL) {
        p = new vertexDate;
        p->data = x;
        p->i = index;
        p->left = p->right = NULL;
        p->balance = 0;
        vr = true;
    } else if (x.keyTree() < p->data.keyTree()) {
        add_DBD(p->left, x, index);
        if (vr) {
            if (p->balance == 0) {
                vertexDate *q = p->left;
                p->left = q->right;
                q->right = p;
                p = q;
                q->balance = 1;
                vr = false;
                hr = true;
            } else {
                p->balance = 0;
                vr = true;
                hr = false;
            }
        } else hr = false;
    } else if (x.keyTree() >= p->data.keyTree()) {
        add_DBD(p->right, x, index);
        if (vr) {
            p->balance = 1;
            hr = true;
            vr = false;
        } else if (hr) {
            if (p->balance == 1) {
                vertexDate *q = p->right;
                p->balance = 0;
                q->balance = 0;
                p->right = q->left;
                q->left = p;
                p = q;
                vr = true;
                hr = false;
            } else hr = false;
        }
    }
}


int dd = 0;
struct queue *q;

void show(vertexDate *p, int level) {
    if (p != NULL) {
        show(p->left, level + 1);
        //for (int i = 0; i < level; i++) cout << "      ";
        cout << dd << ") lastname: " << p->data.lastname << "\t"
             << "hotelNumber: " << p->data.hotelNumber << "   \t"
             << "position: " << p->data.position << "\t"
             << "dateOfBirth: " << p->data.dateOfBirth << endl;
        //cout << p->data.keyTree() << endl;
        show(p->right, level + 1);

    }
}

int sizeSearch = 0;

vertexDate *search(vertexDate *root, int x) {
    vertexDate *p = root;
    while (p != NULL) {
        if (x < p->data.keyTree()) p = p->left;
        else if (x > p->data.keyTree()) p = p->right;
        else break;
    }
    if (p != NULL) {
        search(p->left, x);
        sizeSearch++;

        insert(q, p->data);

        search(p->right, x);
        return p;
    } else
        return p;
}

int indexx = 0;

void Search_Binary(record arr[], int left, int right, int key, int keyIndex) {
    int midd = 0;
    while (true) {
        midd = (left + right) / 2;
        if (left > right)
            return;
        if (key < arr[midd].keySpis(keyIndex))
            right = midd - 1;
        else if (key > arr[midd].keySpis(keyIndex))
            left = midd + 1;
        else {
            while (true) {
                if (arr[midd - 1].keySpis(keyIndex) == arr[midd].keySpis(keyIndex))
                    midd--;
                else
                    break;
            }
            temp[indexx++] = arr[midd];
            while (1) {
                if (arr[midd].keySpis(keyIndex) == arr[midd + 1].keySpis(keyIndex)) {
                    temp[indexx++] = arr[midd + 1];
                    midd++;
                } else
                    break;
            }
            return;
        }
    }
}

int Med(int l, int r, vector<pair<char, double>> p) {
    double sl = 0, sr;
    int m = r;
    for (int i = l; i < r; i++) {
        sl += p[i].second;
    }
    sr = p[r].second;
    while (sl >= sr) {
        m--;
        sl -= p[m].second;
        sr += p[m].second;
    }
    if (!m) {
        return m;
    }
    return (fabs(sl - sr) < fabs(sl + p[m].second - sr + p[m].second) ? m - 1
                                                                      : m);
}
int size;

void Fano(
        int l,
        int r,
        int k,
        vector<pair<char, double>> p,
        vector<vector<int>> &c) {
    if (l < r) {
        k++;
        int m = Med(l, r, p);
        for (int i = l; i <= r; i++) {
            if (i <= m) {
                c[i].push_back(0);
            } else {
                c[i].push_back(1);
            size = r;
            }
        }
        Fano(l, m, k, p, c);
        Fano(m + 1, r, k, p, c);
    }
}

string printFano(string text) {
    map<char, int> mp;
    int count = 0;
    double fano = 0.01;
    //size/=3;
	//int size = 0;
    stringstream inp(text);
    while (1) {
        char c = inp.get();
        if (inp.eof()) {
            break;
        }

        count++;
        mp[c]++;
    }

    vector<pair<char, double>> p;

    for (auto i : mp) {
        p.push_back({i.first, i.second / (double) count});
    }

    double h = 0;

    for (auto i : p) {
        h += i.second * (-log2(i.second));
    }
    vector<vector<int>> c(p.size());

    stringstream out;

    sort(p.begin(), p.end(), [](pair<char, double> a, pair<char, double> b) {
        return a.second > b.second;
    });
    Fano(0, p.size() - 1, 0, p, c);
     size+=21;
    int mx = 0;
    for (auto i : c) {
        mx = max(mx, (int) i.size());
    }
    for (int i = 0; i < p.size(); i++) {
        out << setprecision(5) << p[i].first << " " << setw(10) << p[i].second << "\t";
        for (auto j : c[i]) {
            out << j;
        }
		out <<  "\t"  << mp.at(p[i].first) << "\t";
        out << c[i].size() << endl;
        //size = mp.at(p[i].first);
    }
    for (int i = 0; i < p.size(); i++) {
        fano += p[i].second * c[i].size();
    }


    cout << "Fano";
    cout << "\t" << setprecision(3) << fano << endl;
	cout << "size = " << size <<endl;
    return out.str();
}

void menu() {
    char letter;
    int i;

    int year;

    string raw;
    for (int i = 0; i < N; i++) {
        raw += tt[i].toString();
    }
    map<char, int> symbols;

    for (int i = 0; i < raw.length(); i++)
        symbols[raw[i]]++;

    vertexDate *root_dbd;
    q = new queue;


    do {
        clear();
        std::cout << "Welcome to the course work on SIAOD: " << std::endl;

        cout << "1) show items" << endl;
        cout << "2) sort and show: " << endl;
        cout << "3) search spis: " << endl;
        cout << "4) search bTree: " << endl;
        cout << "5) Fano code: " << endl;


        cin >> letter;
        switch (letter) {
            case '1':
                printRecord(ttNo, N - 20);
                break;
            case '2':
                hoarasort(tt, 0, 3999, KEY_SORT);
                printRecord(tt, N - 20);
                break;
            case '3':
                indexx = 0;
                hoarasort(tt, 0, 3999, KEY_SPIS);
                do {
                    clear();
                    cout << "search hotelNumber([-1] exit):";
                    cin >> year;
                    if (year == -1) break;
                    Search_Binary(tt, 0, 3999, year, KEY_SPIS);
                    if (indexx == 0) {
                        cout << "key not found!" << endl;
                        continue;
                    } else {
                        printRecord(temp, indexx - 20);
                    }
                    break;
                } while (true);
                break;
            case '4':
                dd = 0;
                if (indexx != 0) {
                    root_dbd = NULL;
                    for (i = 0; i < indexx; i++) {
                        add_DBD(root_dbd, temp[i], i);
                    }

                    clear();
                    show(root_dbd, 0);
                    cout << "search year Of Birth:";
                    cin >> year;

                    init(q);
                    search(root_dbd, year);
                    iii = 0;
                    print(q);
                    if (sizeSearch == 0) {
                        cout << "key not found!" << endl;
                        cin >> letter;
                        break;
                    }
                    sizeSearch = 0;

                    for (i = 0; i < indexx; i++)
                        temp[i] = temp[4001];
                    indexx = 0;

                    cin >> letter;
                    break;
                } else {
                    cout << "spis not found!" << endl;
                    cin >> letter;
                }
                break;
            case '5':
                clear();
                string data;
                for (int i = 0; i < N; ++i) {
                    data += tt[i].toString();
                }
                cout << printFano(data);

                cin >> letter;
                break;

        }
        if (letter == 'q') break;
    } while (true);
}

int main() {
    FILE *fp;
    fp = fopen("testBase2.dat", "rb");
    fread(&tt, sizeof(record), N, fp);
    for (int i = 0; i < N; i++)
        ttNo[i] = tt[i];
    menu();

    return 0;
}

