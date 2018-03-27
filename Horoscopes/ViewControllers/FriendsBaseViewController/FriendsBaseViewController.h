//
//  FriendsBaseViewController.h
//  Horoscopes
//
//  Created by Jasf on 12.12.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PersonObjc.h"

@interface FriendsBaseViewController : UITableViewController
@property (nonatomic, strong) NSArray<PersonObjc *> *friends;
@property (assign, nonatomic) NSInteger friendsSection;
- (void)reloadCellWithPerson:(PersonObjc *)person;
- (PersonObjc *)personFromCellAtIndexPath:(NSIndexPath *)indexPath;
@end
