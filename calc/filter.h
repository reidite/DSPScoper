#define _USE_MATH_DEFINES
#include <thread>
#include <vector>
#include "math.h"
namespace DigitalFilter {
    namespace Calc {
        class Filter {
        public:
            Filter();

            void test_signal(int sample, std::vector<double> a, std::vector<double> b);

        };
    }
}