//
//  PredictionContentViewController.h
//  Horoscopes
//
//  Created by Jasf on 02.12.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PredictionContentViewController : UIViewController
@property (assign, nonatomic) NSInteger index;
- (void)setText:(NSString *)text width:(CGFloat)width;
- (CGFloat)getHeight;
- (void)setTextColor:(UIColor *)color;
- (void)setBackgroundColor:(UIColor *)backgroundColor;
- (NSString *)text;
@end
