#ifndef SOLUTION_H
#define SOLUTION_H

#pragma once

#include <stdbool.h>

#ifndef __cplusplus
#define noexcept
#define nullptr (void*)0
#endif

#ifdef __cplusplus
extern "C" {
#endif

bool validParentheses(const char* parens) noexcept;

#ifdef __cplusplus
}
#endif

#endif