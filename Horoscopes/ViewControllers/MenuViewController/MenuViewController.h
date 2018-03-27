//
//  MenuViewController.h
//  Horoscopes
//
//  Created by Jasf on 05.11.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZodiacsLayoutController.h"
#include "viewmodels/menuscreenviewmodel/menuscreenviewmodel.h"

using namespace horo;

@interface MenuViewController : UIViewController
@property (assign, nonatomic) strong<MenuScreenViewModel> viewModel;
@property (strong, nonatomic) ZodiacsLayoutController *zodiacsLayoutController;
@property (strong, nonatomic) UIVisualEffectView *backgroundEffectView;

- (UIViewPropertyAnimator *)animator;
- (void)resetBlur;
@end
