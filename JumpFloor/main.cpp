#include <iostream>
class Solution {
        public:
                int jumpFloor(int number) {
                        if(number == 1)
                        {
                                return 1;
                        }
                        if(number ==2)
                        {
                                return 2;
                        }
                        return jumpFloor(number-1) + jumpFloor(number -2);
                }

};

int main()
{
        Solution* s = new Solution();
        int number = s->jumpFloor(10);
        std::cout<<number<<std::endl;
        delete s;
        return 0;
}
