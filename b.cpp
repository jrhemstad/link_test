inline float& __attribute__((always_inline)) instance(){
    static float v;
    return v;
}

namespace B{

void set(int v){
    instance() = v;
}

int get(){
    return instance();
}

}
