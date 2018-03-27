//
//  FriendsCell.h
//  Horoscopes
//
//  Created by Jasf on 09.12.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FriendsCell : UITableViewCell
@property (strong, nonatomic) id datasource;
@property (assign, nonatomic) BOOL cellSelected;
- (void)setName:(NSString *)name
       birthday:(NSString *)birthday
       imageUrl:(NSString *)imageUrl
     zodiacName:(NSString *)zodiacName;
- (void)setActivityIndicatorAnimationEnabled:(BOOL)enabled;
@end
