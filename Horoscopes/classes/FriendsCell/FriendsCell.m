//
//  FriendsCell.m
//  Horoscopes
//
//  Created by Jasf on 09.12.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#import "FriendsCell.h"
#import <SDWebImage/UIImageView+WebCache.h>

static CGFloat const kAnimationDuration = 0.5f;
static CGFloat const kHighlightedAlpha = 0.5f;
static CGFloat const kMainImageViewHalfHeight = 25.f;

@interface FriendsCell ()
@property (strong, nonatomic) IBOutlet UILabel *nameLabel;
@property (strong, nonatomic) IBOutlet UILabel *birthdayLabel;
@property (strong, nonatomic) IBOutlet UILabel *birthdayDateLabel;
@property (strong, nonatomic) IBOutlet UIImageView *mainImageView;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *mainImageViewTrailing;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *mainImageViewHeightAspectRatio;
@property (strong, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (strong, nonatomic) IBOutlet UIImageView *zodiacImageView;
@end

@implementation FriendsCell

#pragma mark - Initialization
- (void)awakeFromNib {
    [super awakeFromNib];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
    _mainImageView.layer.cornerRadius = kMainImageViewHalfHeight;
    _mainImageView.layer.masksToBounds = YES;
}

#pragma mark - Public Methods
- (void)setName:(NSString *)name
       birthday:(NSString *)birthday
       imageUrl:(NSString *)imageUrl
     zodiacName:(NSString *)zodiacName {
#ifdef CENSORED
    name = @"om mani padme hum";
    imageUrl = @"https://firebasestorage.googleapis.com/v0/b/horo-ios.appspot.com/o/om.jpg?alt=media&token=b9f82bea-98e4-48bb-874f-b6cb3eaa7e05";
#endif
    _nameLabel.text = name;
    _birthdayLabel.text = L(@"birthday");
    _birthdayDateLabel.text = birthday;
    UIImage *image = [UIImage imageNamed:zodiacName];
    _zodiacImageView.image = image;
    
    if (imageUrl.length) {
        [_mainImageView sd_setImageWithURL:[NSURL URLWithString:imageUrl]];
    }
}

- (void)setActivityIndicatorAnimationEnabled:(BOOL)enabled {
    if (enabled) {
        [_activityIndicator startAnimating];
    }
    else {
        [_activityIndicator stopAnimating];
    }
}

#pragma mark - Overriden Methods - UITableViewCell
- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated {
    UIColor *backgroundColor = (highlighted) ? [[UIColor whiteColor] colorWithAlphaComponent:kHighlightedAlpha] : [UIColor clearColor];
    [self setNeedsLayout];
    [UIView animateWithDuration:kAnimationDuration
                     animations:^{
                         self.contentView.backgroundColor = backgroundColor;
                     }];
}

@end
