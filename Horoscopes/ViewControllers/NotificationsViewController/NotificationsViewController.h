//
//  NotificationsViewController.h
//  Horoscopes
//
//  Created by Jasf on 23.12.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "viewmodels/notificationsscreenviewmodel/notificationsscreenviewmodel.h"

@interface NotificationsViewController : UITableViewController
@property (assign, nonatomic) strong<horo::NotificationsScreenViewModel> viewModel;
@end
