//
//  BaseNavigationController.h
//  Horoscopes
//
//  Created by Jasf on 26.11.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BaseNavigationController : UINavigationController
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated completion:(dispatch_block_t)completion;
@end
