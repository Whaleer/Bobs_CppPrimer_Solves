#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;


void process(shared_ptr<int> ptr) {
    cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main() {
    shared_ptr<int> p(new int(42));
    /**
     * @brief   std::shared_ptr<int>(p.get()) construct a temporary shared_ptr and copy it
     *          to the parameter.However it is not a copy of p. As a result, at end of this
     *          main function p will free the memory that has been freed inside process ().
     *          That's why "double freed or corruption" was generated.
     */
    process(shared_ptr<int>(p.get()));


    return 0;
}