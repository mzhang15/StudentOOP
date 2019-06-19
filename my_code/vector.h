
const int DEF_CAPACITY = 10;

class MyVec {
    public:
        MyVec();

        // copy control:
        MyVec(const MyVec& v2);
        ~MyVec();
        MyVec& operator=(const MyVec& v2);

        void push_back(int val);
        int size() const { return sz; }
        int operator[](int i) const; // cout << v[i] << endl;
        int& operator[](int i); // v[i] = 5；
    private:
        int* data;
        int sz;
        int capacity;
};


void print_vector(const MyVec& v);

bool operator==(const MyVec& v1, const MyVec& v2);


// 