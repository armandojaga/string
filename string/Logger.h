#pragma once

#if _DEBUG
#include <iostream>
#define LOG(msg) std::cout << msg << std::endl;
#else
#define LOG(msg)
#endif