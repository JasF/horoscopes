//
//  PushTimeViewController.h
//  Horoscopes
//
//  Created by Jasf on 27.12.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "viewmodels/pushtimescreenviewmodel/pushtimescreenviewmodel.h"

@interface PushTimeViewController : UIViewController
@property (assign, nonatomic) strong<horo::PushTimeScreenViewModel> viewModel;
@end
