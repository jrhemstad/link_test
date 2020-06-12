#pragma once

inline int& instance(){
    static int v;
    return v;
}
