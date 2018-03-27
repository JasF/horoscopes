//
//  WelcomeViewController.h
//  Horoscopes
//
//  Created by Jasf on 29.10.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "viewmodels/helloscreenviewmodel/helloscreenviewmodel.h"

@interface WelcomeViewController : UIViewController
@property (assign, nonatomic) strong<horo::HelloScreenViewModel> viewModel;

- (void)lockSelf;
@end
