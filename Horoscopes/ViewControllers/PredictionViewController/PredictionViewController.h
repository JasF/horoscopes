//
//  PredictionViewController.h
//  Horoscopes
//
//  Created by Jasf on 28.10.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "viewmodels/predictionscreenviewmodel/predictionscreenviewmodel.h"

@interface PredictionViewController : UITableViewController
@property UIPageViewController *horoscopesPageViewController;
@property (assign, nonatomic) strong<horo::PredictionScreenViewModel> viewModel;
@property (assign, nonatomic) BOOL hideMenuButton;
@end
