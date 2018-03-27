//
//  Controllers.h
//  Horoscopes
//
//  Created by Jasf on 09.12.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WebViewController.h"

@interface Controllers : NSObject
+ (instancetype)shared;
- (id<WebViewController>)webViewController;
@end
