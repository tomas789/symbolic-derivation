//
//  main.cpp
//  derive
//
//  Created by Tomas Krejci on 3/13/13.
//  Copyright (c) 2013 Tomas Krejci. All rights reserved.
//

#include <iostream>
#include <string>
#include "Tokenizer.h"

int main(int argc, const char * argv[])
{
    std::string str("sin(x+5)*3.14");
    sym::token_vector vect(sym::tokenizer::tokenize(str));

    for (auto& item : vect) std::cout << item << " ";
    std::cout << std::endl;

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

