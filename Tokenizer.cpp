//
//  Tokenizer.cpp
//  derive
//
//  Created by Tomas Krejci on 3/13/13.
//  Copyright (c) 2013 Tomas Krejci. All rights reserved.
//

#include "Tokenizer.h"
#include <regex>
#include <iostream>

namespace sym {

    /**
     * Define types of tokens
     */
    const std::string tokenizer::regex_function_ = "sin|cos|tan|arcsin|arccos|arctan|ln|log|exp";
    const std::string tokenizer::regex_operator_ = "[-+*/()^]";
    const std::string tokenizer::regex_constant_ = "[[:digit:]]+(:?.[[:digit:]]+)?";
    const std::string tokenizer::regex_variable_ = "[[:alpha:]][[:alnum:]_]*";

    /**
     * Explode str to tokens
     *
     * while (str not empty) begin
     *   find best fitting token at the begining of str
     *   put token to the vector
     *   cut token out form beginning of the str
     * end
     */
    token_vector tokenizer::tokenize(std::string str) {
        /* Hopefully compiler will optimize this because resulting token_regex is everytime the same string.
         * I have written it like this because it is self-describing
         */
        std::string token_regex;
        token_regex += "^";
        token_regex += "(:?" + regex_function_ + ")|";
        token_regex += "(:?" + regex_operator_ + ")|";
        token_regex += "(:?" + regex_constant_ + ")|";
        token_regex += "(:?" + regex_variable_ + ")";

        std::regex r(token_regex);
        std::smatch m;

        token_vector vect;

        while (std::regex_search(str, m, r, std::regex_constants::match_not_null)) {
            vect.push_back(m[0]);
            str = str.substr(m[0].length(), std::string::npos);
        }

        return vect;
    }
}
