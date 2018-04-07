// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <unity/unity_fixture.h>

static void RunAllTests (void)
{
    RUN_TEST_GROUP (Solution);
}

int main (int argc, const char* argv[])
{
    return UnityMain (argc, argv, RunAllTests);
}
