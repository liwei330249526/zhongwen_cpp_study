class VLA{
private:
    const int m_len;
    int *m_arr;
public:
    VLA(int len);
};
VLA::VLA(int len){
    m_len = len;
    m_arr = new int[len];
}

//Cannot assign to non-static data member 'm_len' with const-qualified type 'const int' non-static data member 'm_len' declared const here