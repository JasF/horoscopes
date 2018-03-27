//
//  NSError+Horo.h
//  Horoscopes
//
//  Created by Jasf on 22.12.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "base/horobase.h"

@interface NSError (Horo)
- (horo::error)horo_error;
@end
