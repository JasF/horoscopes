//
//  PopAnimator.m
//  Horoscopes
//
//  Created by Jasf on 09.01.2018.
//  Copyright © 2018 Freedom. All rights reserved.
//

#import "PopAnimator.h"

static CGFloat kTransitionDuration = 0.5f;

@implementation PopAnimator

#pragma mark - UIViewControllerAnimatedTransitioning
- (NSTimeInterval)transitionDuration:(nullable id <UIViewControllerContextTransitioning>)transitionContext {
    return kTransitionDuration;
}

- (void)animateTransition:(id <UIViewControllerContextTransitioning>)transitionContext {
    UIViewController* toViewController   = [transitionContext viewControllerForKey:UITransitionContextToViewControllerKey];
    UIViewController* fromViewController = [transitionContext viewControllerForKey:UITransitionContextFromViewControllerKey];
    toViewController.view.alpha = 0.0;
    [[transitionContext containerView] addSubview:toViewController.view];
    [UIView animateWithDuration:[self transitionDuration:transitionContext] animations:^{
        fromViewController.view.alpha = 0.f;
    }
                     completion:^(BOOL finished) {
                         [UIView animateWithDuration:[self transitionDuration:transitionContext] animations:^{
                             toViewController.view.alpha = 1.f;
                         } completion:^(BOOL finished) {
                             [transitionContext completeTransition:![transitionContext transitionWasCancelled]];
                         }];
                     }];
}

@end
