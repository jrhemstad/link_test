inline int& __attribute__((always_inline)) instance(){
    static int v;
    return v;
}


namespace A{

void set(int v){
    instance() = v;
}

int get(){
    return instance();
}

}
