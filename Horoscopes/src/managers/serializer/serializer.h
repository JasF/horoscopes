//
//  serializer.h
//  Horoscopes
//
//  Created by Jasf on 29.10.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#ifndef serializer_h
#define serializer_h

#include "base/horobase.h"

namespace horo {
  
    class _Serializer {
    public:
        virtual ~_Serializer() {}
    public:
        virtual void saveString(std::string key, std::string value) = 0;
        virtual std::string loadString(std::string key) = 0;
    };
    
    typedef reff<_Serializer> Serializer;
    
};

#endif /* serializer_h */
