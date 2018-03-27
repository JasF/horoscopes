//
//  HoroscopeSharingObject.h
//  Horoscopes
//
//  Created by Jasf on 25.01.2018.
//  Copyright © 2018 Freedom. All rights reserved.
//

#include "SharingObject.h"

@interface HoroscopeSharingObject : NSObject <SharingObject>
- (id)initWithZodiacName:(NSString *)string prediction:(NSString *)prediction;
@end
