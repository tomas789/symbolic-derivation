//
//  parser.h
//  derive
//
//  Created by Tomas Krejci on 3/13/13.
//  Copyright (c) 2013 Tomas Krejci. All rights reserved.
//

#ifndef derive_parser_h
#define derive_parser_h

#include <vector>
#include <string>

namespace sym {
    typedef std::vector<std::string> token_vector;

    class tokenizer {
        const static std::string regex_function_;
        const static std::string regex_operator_;
        const static std::string regex_constant_;
        const static std::string regex_variable_;
    public:
        static token_vector tokenize(std::string str);
    };
}

#endif
