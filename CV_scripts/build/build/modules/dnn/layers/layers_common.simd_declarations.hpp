#define CV_CPU_SIMD_FILENAME "/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/modules/dnn/src/layers/layers_common.simd.hpp"
#define CV_CPU_DISPATCH_MODE AVX
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODE AVX2
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODE AVX512_SKX
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODE RVV
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODES_ALL RVV, AVX512_SKX, AVX2, AVX, BASELINE

#undef CV_CPU_SIMD_FILENAME
