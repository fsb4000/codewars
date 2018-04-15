#ifndef SOLUTION_H
#define SOLUTION_H

#pragma once

#ifndef __cplusplus
#define noexcept
#define nullptr (void*)0
#define constexpr
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

int centuryFromYear(int year) noexcept;

#ifdef __cplusplus
}
#endif

#endif