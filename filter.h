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

            void generated(std::vector<double> t, std::vector<double> y);
            void finishedFilter(std::vector<double> tt, std::vector<double> y_filtered);
        };
    }
}