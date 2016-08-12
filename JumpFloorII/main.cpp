#include <iostream>
class Solution {
        public:
                int jumpFloorII(int number) {
                        if(number == 0 || number == 1)
                        {
                                return 1;
                        }
                        return 2 * jumpFloorII(number-1);
                }

};

int main()
{
        Solution* s = new Solution();
        int number = s->jumpFloorII(10);
        std::cout<<number<<std::endl;
        delete s;
        return 0;
}
