//
//  AccountViewController.h
//  Horoscopes
//
//  Created by Jasf on 19.12.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "viewmodels/accountscreenviewmodel/accountscreenviewmodel.h"

@interface AccountViewController : UIViewController
@property (assign, nonatomic) strong<horo::AccountScreenViewModel> viewModel;
@end
