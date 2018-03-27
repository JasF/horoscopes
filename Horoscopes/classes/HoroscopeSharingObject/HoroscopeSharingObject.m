//
//  HoroscopeSharingObject.m
//  Horoscopes
//
//  Created by Jasf on 25.01.2018.
//  Copyright © 2018 Freedom. All rights reserved.
//

#import "HoroscopeSharingObject.h"

@interface HoroscopeSharingObject ()
@property (strong, nonatomic) NSString *zodiacName;
@property (strong, nonatomic) NSString *prediction;
@end

@implementation HoroscopeSharingObject

- (id)initWithZodiacName:(NSString *)zodiacName prediction:(NSString *)prediction {
    NSCParameterAssert(zodiacName);
    NSCParameterAssert(prediction);
    if (self = [self init]) {
        _zodiacName = zodiacName;
        _prediction = prediction;
    }
    return self;
}

#pragma mark - UIActivityItemSource
- (id)activityViewControllerPlaceholderItem:(UIActivityViewController *)activityViewController {
    return [self fullText];
}

- (nullable id)activityViewController:(UIActivityViewController *)activityViewController
                  itemForActivityType:(nullable UIActivityType)activityType {
    return [self fullText];
}

- (NSString *)activityViewController:(UIActivityViewController *)activityViewController
              subjectForActivityType:(nullable UIActivityType)activityType {
    return _zodiacName;
}

#pragma mark - Private Methods
- (NSString *)fullText {
    return [NSString stringWithFormat:@"%@\n\n%@", _zodiacName, _prediction];
}

@end
