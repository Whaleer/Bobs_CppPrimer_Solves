#include <iostream>

void counter_func(){
    static int call_count = 0;
    int auto_val = 0;

    call_count++;
    auto_val++;

    printf("call_count: %d, auto_val: %d\n", call_count, auto_val);
}

int main(){
    for(int i = 0; i < 10; i++){
        counter_func();
    }
    return 0;
}