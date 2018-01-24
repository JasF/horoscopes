//
//  NotificationsViewController.m
//  Horoscopes
//
//  Created by Jasf on 23.12.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#import "NotificationsViewController.h"
#import "SettingsCell.h"

typedef NS_ENUM(NSInteger, RowsCount) {
    EnablePushesRow,
    PushTimeRow,
    PushesRowsCount
};

static CGFloat const kSeparatorColorAlpha = 0.2f;

@interface NotificationsViewController () <UITableViewDelegate, UITableViewDataSource>
@property (strong, nonatomic) IBOutlet SettingsCell *enablePushesCell;
@property (strong, nonatomic) IBOutlet SettingsCell *pushTimeCell;
@property (weak, nonatomic) IBOutlet UISwitch *swither;
@end

@implementation NotificationsViewController

- (void)viewDidLoad {
    NSCParameterAssert(_viewModel.get());
    
    self.definesPresentationContext = YES;
    [super viewDidLoad];
    self.navigationController.navigationBar.translucent = YES;
    for (SettingsCell *cell in [self cellsDictionary].allValues) {
        [cell setText:L(cell.text)];
    }
    _enablePushesCell.selectionStyle = UITableViewCellSelectionStyleNone;
    self.navigationItem.title = L(@"notifications");
    _swither.on = !_viewModel->notificationsDisabled();
    if (@available (iOS 11, *)) {
        self.navigationController.navigationBar.prefersLargeTitles = NO;
    }
    [self.navigationController.navigationBar horo_makeWhite];
    self.tableView.separatorColor = [[UIColor whiteColor] colorWithAlphaComponent:kSeparatorColorAlpha];
}

- (void)dealloc {
    _viewModel->sendSettingsIfNeeded();
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    _pushTimeCell.descriptionText = [NSString stringWithFormat:@"%@:00", @(_viewModel->pushTime())];
    [self.tableView reloadData];
}

- (IBAction)menuTapped:(id)sender {
    _viewModel->menuTapped();
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return PushesRowsCount;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *dictionary = [self cellsDictionary];
    UITableViewCell *cell = dictionary[@(indexPath.row)];
    NSCAssert(cell, @"Cell for indexPath: %@ not found", indexPath);
    if (!cell) {
        return [UITableViewCell new];
    }
    return cell;
}

#pragma mark - UITableViewDelegate
- (NSIndexPath *)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *dictionary = @{@(PushTimeRow):indexPath};
    NSIndexPath *result = dictionary[@(indexPath.row)];
    return result;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == PushTimeRow) {
        _viewModel->pushTimeTapped();
    }
}

#pragma mark - Private Methods
- (NSDictionary *)cellsDictionary {
    NSDictionary *dictionary = @{@(EnablePushesRow):_enablePushesCell, @(PushTimeRow):_pushTimeCell};
    return dictionary;
}

#pragma mark - Observers
- (IBAction)enablePushSwitchChanged:(id)sender {
    _viewModel->setNotificationsDisabled(!_swither.on);
}

@end
